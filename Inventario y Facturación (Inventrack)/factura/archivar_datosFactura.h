#pragma once
#pragma warning(disable : 4244)
#include <list>
#include <cmath>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
#include <iterator>
#include <iomanip>
#include <map>
#include <ctime>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

namespace archivoFactura {

	// Funci�n que permite registrar los datos en la factura y guardarlos como un historial general
	inline void registrarFactura(string numFact, string fEmision, string hEmision, string client, string vendedor,
								 string pComprado, string cantComprada, string pUnit, string descuento, string totalFact) {
		ofstream file;
		file.open("factura\\Registro de facturas.txt", ios::app);// Se abre el archivo en modo de agregar al final

		//Se agregan los datos enviados hacia el archivo
		file << numFact << "|" << fEmision << "|" << hEmision << "|" << client << "|" << vendedor << "|" << pComprado << "|" 
			 << cantComprada << "|" << pUnit << "|" << descuento << "|" << totalFact << endl;

		//Se cierra el archivo
		file.close();
	}

	// Funci�n que presenta en un DataGridView los productos adicionados que el cliente desea adquirir
	inline void agregarProducto_en_dgv(DataGridView^ dgv, String^ producto, float cantidad, float precioUnit,
		float descuento) {
		// Creamos una nueva fila en el dgv, que almacenar� los campos del producto en cuesti�n
		DataGridViewRow^ row = gcnew DataGridViewRow();
		row->CreateCells(dgv);

		// Asignamos los valores de las celdas en base al �ndice de la columna
		row->Cells[0]->Value = producto;  // �ndice de la columna "Producto"
		row->Cells[1]->Value = cantidad;  // �ndice de la columna "Cantidad"
		row->Cells[2]->Value = precioUnit;  // �ndice de la columna "Precio_unit"
		row->Cells[3]->Value = descuento;  // �ndice de la columna "Descuento"

		// Se agrega la fila en el DataGridView
		dgv->Rows->Add(row);
	}

	// Funci�n que cuenta el n�mero de facturas generadas
	inline int numFact(string filepath) {
		string numfact = "";
		ifstream file;
		file.open(filepath, ios::in); //Se abre el archivo en forma de lectura

		string line;
		//Se lee una l�nea entera del archivo y se verifica si contiene "FAC-"
		while (getline(file, line)) {
			size_t pos = line.find("FAC-");
			if (pos != string::npos) {
				numfact = line.substr(pos + 4, 4); // Se obtienen los �ltimos 4 caracteres despu�s de "FAC-"
			}
		}
		file.close();

		if (numfact.empty()) {
			return 1; // En caso de no haber a�n una factura en el registro, se manda 1 para reconocerla como primera factura
		}

		// Convertimos de string a entero el valor de la cadena
		int lastNum = stoi(numfact);
		return lastNum + 1; //Se devuelve el n�mero de facturas + 1 para indicar una nueva factura
	}

	// Funci�n que permite realizar las operaciones aritm�ticas al adicionar un producto
	inline void calcularTotal(DataGridView^ dgv, TextBox^% subTotal, TextBox^% masIVA, TextBox^% totalPagar) {

		double subtotal = 0;
		double total = 0;
		double IVA = 0.15;

		// Recorremos todas las filas dependiendo de la celda encabezada especificada
		for (int i = 0; i < dgv->Rows->Count; i++) {
			double cant = Convert::ToDouble(dgv->Rows[i]->Cells[1]->Value);
			double pUnit = Convert::ToDouble(dgv->Rows[i]->Cells[2]->Value);
			double descuento_porciento = Convert::ToDouble(dgv->Rows[i]->Cells[3]->Value);

			// Se convierte el descuento del porcentaje a decimal
			double descuento = descuento_porciento / 100;

			// Se obtiene el total del producto aplic�ndole el descuento
			double totalProduct = cant * pUnit * (1 - descuento);

			// Ya calculado el total del producto, se ingresa en la fila de "Total"
			dgv->Rows[i]->Cells[4]->Value = totalProduct.ToString("N2");
			
			// Se suman todos los totales para dar con el subtotal y total a pagar de los productos
			subtotal += totalProduct;
			total += totalProduct;
		}

		// Ya finalizado el recorrido, se calcula el valor total a pagar con el IVA inclu�do (+15% en Nicaragua)
		double mIVA = total * IVA;
		double total_conIVA = total + mIVA;

		subTotal->Text = subtotal.ToString("N2");
		masIVA->Text = mIVA.ToString("N2");
		totalPagar->Text = total_conIVA.ToString("N2");
	}

	inline void obtenerMetodoPago(ComboBox^ comboBox) {
		// Se abre el archivo en modo de lectura
		ifstream infile;
		infile.open("factura\\Metodo de pago.txt");

		// Se lee cada l�nea del archivo y se a�ade al comboBox
		string line;
		while (getline(infile, line)) {
			// El std::string se convierte a System::String
			System::String^ lineStr = gcnew System::String(line.c_str());

			// Los datos en System::String se a�aden al comboBox
			comboBox->Items->Add(lineStr);
		}

		// Se cierra el archivo
		infile.close();
	}

	// Funci�n que permite la obtenci�n de las iniciales del nombre de un cliente
	inline string obtenerIniciales(string client) {
		// Tomaremos las iniciales del cliente atendido:
		string initials;
		initials += client[0]; // Obtenemos la primera inicial desde el primer caracter de la cadena

		// Se hace un ciclo empezando despu�s de la primera inicial hasta terminar con el largo de la cadena
		for (size_t i = 1; i < client.length(); i++) {
			// En caso de que el anterior caracter al actual sea un espacio en blanco, significa que estamos en otra inicial de la cadena
			if (client[i - 1] == ' ') {
				initials += client[i];
			}
		}

		return initials; // Devolvemos las iniciales ya concatenadas
	}

	// Funci�n que permite crear un dise�o de un recibo de factura seg�n los datos pasados por el dgv
	inline void dise�arFactura(string numFact, string client, string fEmision, string hEmision, string cashier, string nomEmpresa, string dirEmpresa, 
							   string telEmpresa, string emailEmpresa, double masIVA) {
		// Primero creamos un archivo con nombre �nico, tomando en cuenta los datos enviados por par�metro dentro de la funci�n:

		// Tomaremos las iniciales del cliente atendido por medio de esta funci�n:
		string initials = obtenerIniciales(client);

		// Concatenamos los campos de n�mero de factura, iniciales de cliente y la fecha dada de la factura para hacer �nica la factura
		string filename = "factura\\facturas generadas\\" + numFact + "_" + initials + "_" + fEmision + ".txt";

		// Creamos el archivo con nombre del resultado de la concatenaci�n
		ofstream file;
		file.open(filename, ios::out);
		file.imbue(locale("")); // Manipulamos el archivo para que los valores obtengan una cantidad en forma de moneda

		// Se verifica que los archivos se hayan abierto correctamente 
		if (!file.is_open()) {
			MessageBox::Show("Error. El archivo de origen de dise�o de factura no puede abrirse");
			return;
		}

		// Abrimos el archivo donde est� registrada la informaci�n de la factura
		ifstream registeredBills;
		registeredBills.open("factura\\Registro de facturas.txt", ios::in);

		if (!registeredBills.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		list<string> lines; // Creamos una lista que almacenar� todos los datos relacionados al n�mero de la factura
		string line;

		while (getline(registeredBills, line)) {
			// Obtenemos el n�mero de factura actual
			size_t pos = line.find("|");
			if (pos != string::npos) {
				string numFact_inFile = line.substr(0, pos);

				// Agregaremos lineas a la lista s� y solo s� el n�mero de factura actual es el mismo al contenido en el registro
				if (numFact == numFact_inFile) {
					lines.push_back(line);
				}
			}
		}

		// Recorremos todos los datos inclu�dos en la lista y los ubicamos en el dise�o de la factura:
		
		// Encabezado de la factura:
		file << "\t\t\t\t========================================" << endl;
		file << "\t\t\t\tN�mero de factura: " << numFact << endl;
		file << "\t\t\t\tFecha de emisi�n: " << fEmision << endl;
		file << "\t\t\t\tHora: " << hEmision << endl;
		file << "\t\t\t\t========================================" << endl;
		file << "\t\t\t\t" << nomEmpresa << endl;
		file << "\t\t\t\t" << dirEmpresa << endl;
		file << "\t\t\t\t" << emailEmpresa << endl;
		file << "\t\t\t\t" << telEmpresa << endl;
		file << "\t\t\t\t========================================" << endl;
		file << endl << "Cliente: " << client << endl;
		file << "Le atendi�: " << cashier << endl;
		file << "-------------------------------------------------------------------------------------------------------" << endl;

		// Detalle de los productos:
		file << left << setw(50) << "Producto" << setw(15) << "Cantidad" << setw(15) << "Precio Unit." << setw(15) << "Descuento" << setw(15) << "Total" << endl;
		file << "-------------------------------------------------------------------------------------------------------" << endl;
		
		// Declaramos variables que respectan a cada campo en el registro de facturas
		string nFact, fE, hE, nClient, nCashier, prod, cant, pU, dscount, total;

		// Recorremos las l�neas almacenadas de la lista ANTES de la �ltima l�nea, ya que en ella hay mas campos almacenados
		for (auto it = lines.begin(); it != prev(lines.end()); ++it) {
			string fileLine = *it;
			istringstream iss(fileLine);

			// Extraemos los campos seg�n el delimitador '|'
			getline(iss, nFact, '|');
			getline(iss, fE, '|');
			getline(iss, hE, '|');
			getline(iss, nClient, '|');
			getline(iss, nCashier, '|');
			getline(iss, prod, '|');
			getline(iss, cant, '|');
			getline(iss, pU, '|');
			getline(iss, dscount, '|');
			getline(iss, total, '|');

			// Agregamos los campos correspondientes al archivo 
			file << left << setw(50) << prod << setw(15) << cant << setw(15) << pU << setw(15) << dscount << setw(15) << total << endl;
		}
		// Nos ubicamos a la �ltima l�nea del archivo
		string lastLine = *prev(lines.end());

		string formaPago, subtotal, totalpago, pagado, devuelto;
		istringstream iss(lastLine);

		// Extraemos los campos seg�n el delimitador '|'
		getline(iss, nFact, '|');
		getline(iss, fE, '|');
		getline(iss, hE, '|');
		getline(iss, nClient, '|');
		getline(iss, nCashier, '|');
		getline(iss, prod, '|');
		getline(iss, cant, '|');
		getline(iss, pU, '|');
		getline(iss, dscount, '|');
		getline(iss, total, '|');
		getline(iss, formaPago, '|');
		getline(iss, subtotal, '|');
		getline(iss, totalpago, '|');
		getline(iss, pagado, '|');
		getline(iss, devuelto, '|');

		// Agregamos los campos finales al archivo 
		file << left << setw(50) << prod << setw(15) << cant << setw(15) << pU << setw(15) << dscount << setw(15) << total << endl;
		/* Extraemos los datos de la �ltima l�nea, ya que tenemos campos adicionales como forma de pago,...
		...subtotal, total con IVA, */
		file << "-------------------------------------------------------------------------------------------------------" << endl;
		file << setw(95) << "Subtotal: " << subtotal << endl;
		string mIVA = conversion::to_stdstring(masIVA.ToString("N2"));
		file << setw(95) << "+15% IVA: " << mIVA << endl;
		file << setw(95) << "Total (IVA incluido): " << totalpago << endl;
		file << "-------------------------------------------------------------------------------------------------------" << endl;
		file << "Forma de pago: " << formaPago << endl;
		file << "Total pagado: " << pagado << endl;
		file << "Monto devuelto: " << devuelto << endl;
		file << endl;
		file << "\t\t\t\t\t�Gracias por elegirnos! :)";

		file.close();
		registeredBills.close();
	}

	// Funci�n que permite guardar los datos de la factura en un archivo de texto
	inline void registrar_datosFactura_delDGV(DataGridView^ dgv, string numFact, string fEmision, string hEmision, string client, string cashier, 
											  string subtotal, string payMethod, string totalPayment, string totalPaid, string change) {
		try {
			// Se abre el archivo en formato de a�adir al final
			ofstream file;
			file.open("factura\\Registro de facturas.txt", ios::app);

			// Se recorren todas las filas del datagridview
			for (int i = 0; i < dgv->Rows->Count; i++) {
				// Convertimos los valores de System::String a std::string
				string prod = conversion::to_stdstring(dgv->Rows[i]->Cells[0]->Value->ToString());
				string cant = conversion::to_stdstring(dgv->Rows[i]->Cells[1]->Value->ToString());
				string pUnit = conversion::to_stdstring(dgv->Rows[i]->Cells[2]->Value->ToString());
				string dscount = conversion::to_stdstring(dgv->Rows[i]->Cells[3]->Value->ToString());
				string totalProd = conversion::to_stdstring(dgv->Rows[i]->Cells[4]->Value->ToString());

				// Verificamos es el �ltimo producto
				if (i == dgv->Rows->Count - 1) {
					string finalLine = numFact + "|" + fEmision + "|" + hEmision + "|" + client + "|" + cashier + "|" + prod + "|"
						+ cant + "|" + pUnit + "|" + dscount + "|" + totalProd + "|" + payMethod + "|" + subtotal + "|"
						+ totalPayment + "|" + totalPaid + "|" + change;
					/*Registramos los valores del �ltimo producto, pero a�adimos campos adicionales como...
					...la forma de pago, el subtotal, total con IVA y vuelto de efectivo*/
					file << finalLine << endl;

					// Agregamos los datos finales a otro archivo llamado Historial de facturas.txt
					ofstream historialFact;
					historialFact.open("factura\\Historial de facturas.txt", ios::app);

					historialFact << numFact << "|" << fEmision << "|" << client << "|" << cashier << "|" << payMethod << "|" << subtotal << "|"
						<< totalPayment << "|" + totalPaid << "|" << change << endl;

					historialFact.close(); // Cerramos el archivo
				}
				else {
					// En caso de haber m�s de un producto comprado agregamos los siguientes datos:
					registrarFactura(numFact, fEmision, hEmision, client, cashier, prod, cant, pUnit, dscount, totalProd);
				}
			}
			String^ successMessage = "�Factura registrada exitosamente! Se ha dise�ado un recibo con los datos agregados. Puede verlo en la siguiente direcci�n: factura\\facturas generadas.";
			MessageBox::Show(successMessage, "Movimiento exitoso", MessageBoxButtons::OK, MessageBoxIcon::Information);

			file.close();
		}
		catch (const std::exception& e) {
			MessageBox::Show("Ocurri� un error al realizar la factura: " + gcnew System::String(e.what()));
		}
	}

	// Funci�n que permite modificar los datos del inventario luego de hacer una factura exitosa o al haber anulado una
	inline void actualizarInventario(string numFact, bool isCancelled) {
		// Abrimos el archivo donde se encuentran las facturas en modo de lectura
		ifstream billFile;
		billFile.open("factura\\Registro de facturas.txt", ios::in);

		// Se verifica que los archivos se hayan abierto correctamente 
		if (!billFile.is_open()) {
			MessageBox::Show("Error. El archivo de de factura no puede abrirse");
			return;
		}

		list<string> billedProd; // Creamos una lista que almacenar� todos los datos relacionados al n�mero de la factura
		string line;

		// Almacenamos todas las l�neas que coincidan con el c�digo de factura que editaremos
		while (getline(billFile, line)) {
			// Obtenemos el n�mero de factura actual
			size_t pos = line.find("|");
			if (pos != string::npos) {
				string numFact_inFile = line.substr(0, pos);

				// Agregaremos lineas a la lista s� y solo s� el n�mero de factura actual es el mismo al contenido en el registro
				if (numFact == numFact_inFile) {
					billedProd.push_back(line);
				}
			}
		}

		// Recorremos todas l�neas almacenadas de la lista
		for (auto it = billedProd.begin(); it != billedProd.end(); ++it) {
			string fileLine = *it;
			istringstream iss(fileLine);

			// Se declaran variables que respectan a cada campo del registro de facturas
			string nFact, fE, hE, nClient, nCashier, prod, cant, pU, dscount, total;

			// Extraemos los campos seg�n el delimitador '|'
			getline(iss, nFact, '|');
			getline(iss, fE, '|');
			getline(iss, hE, '|');
			getline(iss, nClient, '|');
			getline(iss, nCashier, '|');
			getline(iss, prod, '|');
			getline(iss, cant, '|');
			getline(iss, pU, '|');
			getline(iss, dscount, '|');
			getline(iss, total, '|');

			// Abrimos el archivo donde se encuentran almacenados los productos en modo de lectura
			ifstream prodFile;
			prodFile.open("productos\\Registro de productos.txt", ios::in);

			if (!prodFile.is_open()) {
				MessageBox::Show("Error. El archivo de Registrodeproductos no puede abrirse");
				return;
			}

			// Creamos un archivo temporal en el cual se modificar�n los datos necesarios en modo de escritura
			ofstream modifyProd;
			modifyProd.open("productos\\temp.txt", ios::out);

			if (!modifyProd.is_open()) {
				MessageBox::Show("Error. El archivo temporal no puede abrirse");
				return;
			}

			/* Verificamos en el archivo de registro de producto las l�neas que coincidan con la descripci�n del producto,...
			... y en caso de haber concordancia nos ubicamos en la l�nea y modificamos sus existencias en caso de que la factura...
			... haya sido anulada (devolvemos existencias) o registrada (restamos existencias)*/
			string prodLine;
			while (getline(prodFile, prodLine)) {
				stringstream ss(prodLine);

				// Se declaran variables que luego les ser�n asignados sus nuevos valores
				string code_infile, group_infile, desc_infile, uMeasure_infile, exist_infile, minExist_infile, ubic_infile, pUnit_infile, fExp_infile;

				// Extraemos los campos del registro de productos seg�n el delimitador '|'
				getline(ss, code_infile, '|');
				getline(ss, group_infile, '|');
				getline(ss, desc_infile, '|');
				getline(ss, uMeasure_infile, '|');
				getline(ss, exist_infile, '|');
				getline(ss, minExist_infile, '|');
				getline(ss, ubic_infile, '|');
				getline(ss, pUnit_infile, '|');
				getline(ss, fExp_infile);

				// Si la descripci�n del producto coincide con la descripci�n incluida en el registro de facturas, entonces modificamos esa l�nea
				if (prod == desc_infile) {
					float newExist = 0;
					// Dependiendo de si la factura fue anulada o registrada, restamos o sumamos las existencias
					if (isCancelled == true) {
						newExist = stof(exist_infile) + stof(cant);
					}
					else {
						newExist = stof(exist_infile) - stof(cant);
					}

					// Escribimos la l�nea modificada en el archivo temporal
					modifyProd << code_infile << "|" << group_infile << "|" << desc_infile << "|" << uMeasure_infile << "|" << newExist << "|"
						<< minExist_infile << "|" << ubic_infile << "|" << pUnit_infile << "|" << fExp_infile << endl;
				}
				else {
					// De lo contrario, agregamos la l�nea sin modificar en la lista especificada
					 modifyProd << prodLine << endl;
				}
			}

			/* Cerramos los archivos al final de cada iteraci�n y luego los volvemos a abrir para que siempre se posicionen...
			...al inicio y continue comparando en caso de que se haya adicionado m�s de un producto en compra*/
			prodFile.close();
			modifyProd.close();

			// Reflejamos los cambios en inventario desde el producto que tenemos facturado hasta ahora por la iteraci�n
			// Eliminamos el archivo original
			if (remove("productos\\Registro de productos.txt") != 0) {
				MessageBox::Show("No se puede borrar el archivo de origen.");
			}

			// Renombramos el archivo temporal con el nombre del archivo original
			if (rename("productos\\temp.txt", "productos\\Registro de productos.txt") != 0) {
				MessageBox::Show("No se pudo renombrar el archivo temporal.");
			}
		}

		// Cerramos el archivo
		billFile.close();
	}

	// Funci�n que permite mostrar los datos registrados del registro de facturas y los ubica en un dgv para su correcta visualizaci�n
	inline void mostrar_historialFacturas(DataGridView^ dgv) {
		try {
			// Abrimos el archivo donde tenemos registrados los datos de las facturas realizadas
			ifstream file;
			file.open("factura\\Historial de facturas.txt", ios::in);

			// Se crea una tabla con las columnas correspondientes
			System::Data::DataTable^ table = gcnew System::Data::DataTable();
			table->Clear();
			table->Columns->Add("No. Fact", String::typeid);
			table->Columns->Add("Fecha de emisi�n", String::typeid);
			table->Columns->Add("Cliente", String::typeid);
			table->Columns->Add("Vendedor", String::typeid);
			table->Columns->Add("Forma de pago", String::typeid);
			table->Columns->Add("Subtotal", String::typeid);
			table->Columns->Add("Total facturado", String::typeid);
			table->Columns->Add("Total pagado", String::typeid);
			table->Columns->Add("Total devuelto", String::typeid);

			// Lista bidimensional que se encargar� de llenar cada celda de la tabla
			list<list<string>> datos;

			if (!file.is_open()) {
				MessageBox::Show("No se puede mostrar la tabla de registro.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else {
				// Se leen los datos del archivo l�nea por l�nea
				string line;
				while (getline(file, line)) {
					// Se crea una lista que almacenar� los datos de una linea
					list<string> datos_linea;

					// Separar los campos de la l�nea por el delimitador '|'
					istringstream ss(line);
					string campo;
					while (getline(ss, campo, '|')) {
						// Agregar el campo a la lista de datos de la l�nea
						datos_linea.push_back(campo);
					}

					// Agregar la lista de datos de la l�nea a la lista bidimensional
					datos.push_back(datos_linea);
				}

				// Se cierra el archivo despu�s de leer los datos
				file.close();

				// Se llena la tabla con los datos de la lista bidimensional
				for (auto it = datos.begin(); it != datos.end(); ++it) {
					// Se crea una fila para la tabla
					System::Data::DataRow^ fila = table->NewRow();

					// Se agregan los datos de la lista a la fila
					int i = 0;
					for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
						// Agregar los campos de texto tal cual
						System::String^ valor = gcnew System::String((*it2).c_str());
						fila[i] = valor;
						i++;
					}

					// Se agrega la fila a la tabla
					table->Rows->Add(fila);
				}
				// Asignar la tabla como fuente de datos del DataGridView
				dgv->DataSource = table;
			}
		}
		catch (const std::exception& e) {
			MessageBox::Show("Ocurri� un error al mostrar las facturas: " + gcnew System::String(e.what()));
		}
	}

	// Funci�n que permite buscar una factura cualquiera en base a lo contenido en el dgv
	inline void buscarFactura(DataGridView^ dgv, String^ searched_nFact, String^% numFact, bool% found, 
							  String^ %Client, String^ %fEmision) {
		found = false; // Se inicia la variable como falsa

		for (int i = 0; dgv->RowCount; i++) {
			//Se busca la factura en base a su n�mero escrito en el buscador
			DataGridViewCell^ cell = dgv->Rows[i]->Cells["No. Fact"];
			/* Se realiza esta condici�n ya que si la factura buscada no se encuentra en la tabla, la variable tomar�a un valor nulo
				y por ende resultar�a en una excepci�n en el programa.*/
			String^ nFact = (cell->Value != nullptr) ? cell->Value->ToString() : String::Empty;

			// Verificamos si se ha encontrado la factura
			if (nFact->ToLower()->Contains(searched_nFact->ToLower())) {
				found = true; // La factura fue encontrada, se le da un valor de verdadero a la variable
				// Se selecciona la fila correspondiente
				dgv->Rows[i]->Selected = true;
				dgv->CurrentCell = dgv->Rows[i]->Cells[0];
				// Nos ubicamos en donde se encuentra el n�mero de factura
				dgv->FirstDisplayedScrollingRowIndex = i;

				numFact = searched_nFact;
				// Extraemos informaci�n de la factura de campos de fecha de emisi�n y cliente
				fEmision = dgv->Rows[i]->Cells["Fecha de emisi�n"]->Value->ToString();
				string client_fullName = conversion::to_stdstring(dgv->Rows[i]->Cells["Cliente"]->Value->ToString());

				// Obtenemos las iniciales del nombre del cliente y cambiamos de std::string a System::String
				Client = gcnew String(obtenerIniciales(client_fullName).c_str());

				// La factura ya fue encontrada, no es necesario seguir con la b�squeda
				break;
			}
		}
		if (!found) {
			MessageBox::Show("La factura buscada no se encuentra en el historial.", "Factura no encontrada", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	// Funci�n que permite mostrar el dise�o del recibo de la factura en un TextBox
	inline void verFactura(string nFact, string clientInitials, string fEmision, TextBox^ textBox) {
		// Concatenamos seg�n la estructura en la que se guarda el recibo de factura
		string filepath = "factura\\facturas generadas\\" + nFact + "_" + clientInitials + "_" + fEmision + ".txt";

		try {
			// Se abre el archivo en modo lectura
			ifstream file;
			file.open(filepath);

			if (!file.is_open()) { // Verificamos si el archivo no se pudo abrir correctamente
				MessageBox::Show("Error al abrir el archivo");
				return;
			}

			list<string> lines; // Lista que almacenar� las l�neas del archivo de texto

			// Leemos el contenido del archivo l�nea por l�nea
			string line;
			while (getline(file, line)) {
				lines.push_back(line); // Agregamos la l�nea a la lista
			}

			// Cerramos el archivo
			file.close();

			// Se agregan las l�neas al TextBox en el orden correcto
			for (const string& line : lines) {
				// Convertimos la l�nea a formato de System::String y la agregamos al TextBox
				String^ txtLine = gcnew String(line.c_str());
				textBox->AppendText(txtLine + Environment::NewLine);
			}
		}
		catch (const std::exception& e) {
			MessageBox::Show("Error al leer el archivo: " + gcnew String(e.what()));
		}
	}

	/* Funci�n que permite registrar ciertos campos a un archivo de texto, a fin de facilitar una rese�a estad�stica...
	...sobre la cantidad de veces que los clientes realizan compras en el lugar de trabajo*/
	inline void registrar_frecuenciaClientes() {
		/* Abrimos dos archivos en modo de lectura que contienen los clientes registrados e informaci�n relacionada...
		...a sus actividades en facturaci�n*/
		ifstream clientsFile;
		clientsFile.open("clientes\\Registro de clientes.txt", ios::in);

		// Se verifica si se pudo acceder correctamente en ambos
		if (!clientsFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos un archivo en el que se guardar� informaci�n para la muestra de la frecuencia de clientes
		ofstream clientFrequency;
		clientFrequency.open("factura\\Frecuencia de clientes.txt", ios::app);

		// C�lculo del total de facturas
		int totalFacturas = 0;

		ifstream countBills;
		countBills.open("factura\\Historial de facturas.txt", ios::in);
		
		if (countBills.is_open()) {
			string lineCount;
			while (getline(countBills, lineCount)) {
				totalFacturas++; // Contamos el total de facturas, para luego calcularlo con el porcentaje de visitas
			}
			countBills.close();
		}

		string lineClient, lineHistory; // Declaramos dos variables que leeran cada l�nea de los archivos especificados

		// Recorremos ambos archivos al mismo tiempo
		while (getline(clientsFile, lineClient)) {
			float frequency = 0; // Cantidad de veces que el cliente se ha presentado y ha sido facturado en la empresa
			float totalPaid = 0; // Saldo total que el cliente ha gastado en productos de la empresa
			// Variables para el archivo "Registro de clientes.txt"
			string id, tel, names, surnames;

			// Se separa cada campo seg�n el delimitador (en este caso '|')
			stringstream ssClient(lineClient);
			getline(ssClient, id, '|');
			getline(ssClient, tel, '|');
			getline(ssClient, names, '|');
			getline(ssClient, surnames);

			ifstream historyFile;
			historyFile.open("factura\\Historial de facturas.txt", ios::in);

			// Concatenamos los nombres y apellidos para obtener el nombre completo
			/* Usamos System::String para trabajar correctamente con aquellos clientes que tengan acento...
			...ya que este tipo de cadena admite car�cteres Unicode.*/
			String^ client_fullName = gcnew String((names + " " + surnames).c_str());
			
			while (getline(historyFile, lineHistory)) {
				// Variables para el archivo "Historial de facturas.txt"
				string nFact, fEmit, client, cashier, payMethod, subTotal, total_wIVA;
				stringstream ssBills(lineHistory);
				getline(ssBills, nFact, '|');
				getline(ssBills, fEmit, '|');
				getline(ssBills, client, '|');
				getline(ssBills, cashier, '|');
				getline(ssBills, payMethod, '|');
				getline(ssBills, subTotal, '|');
				getline(ssBills, total_wIVA, '|');
				
				String^ clientFact = gcnew String(client.c_str());
				/* Si hay coincidencia entre el nombre en registro de clientes y el cliente en factura,...
				...entonces se hace una suma total de las veces que frecuenta el lugar e invierte en todo el per�odo*/
				if (client_fullName == clientFact) {
					frequency++;
					// Eliminamos la coma de la cadena, para que al convertirla a flotante no haya problemas en la suma
					total_wIVA.erase(remove(total_wIVA.begin(), total_wIVA.end(), ','), total_wIVA.end());
					totalPaid += stof(total_wIVA);
				}
			}

			/* Calculamos el porcentaje de visita del cliente a la empresa, cambiando el valor de "frequency" a float para que los
			...datos no se trunquen*/
			float visitPercentage = (frequency / totalFacturas) * 100;
			string fullName = conversion::to_stdstring(client_fullName);
			// Se escribe la informaci�n en el archivo de frecuencia de clientes
			clientFrequency << fullName << "|" << totalPaid << "|" << visitPercentage << endl;

			historyFile.close();
		}

		clientsFile.close();
		clientFrequency.close();
	}

	/* Funci�n que permite registrar ciertos campos a un archivo de texto, a fin de facilitar una rese�a estad�stica...
	...sobre qu� productos han sido los mas y menos comprados en el lugar de trabajo*/
	inline void registrar_comportamientoProductos(string umedida) {
		/* Abrimos dos archivos en modo de lectura que contienen los productos registrados e informaci�n relacionada...
		...a sus actividades en facturaci�n*/
		ifstream prodsFile;

		// Creamos un archivo en el que se guardar� informaci�n para el an�lisis de la venta de productos
		ofstream salesAnalysis;
		salesAnalysis.open("factura\\Venta de productos.txt", ios::app);

		/* Se utiliza un contenedor de tipo map para convertir los datos a unos homog�neos entre s�...
		...con esta pr�ctica el c�digo puede hacerse m�s compacto y menos repetitivo*/
		map<string, double> conversionFactors = {
		{"u", 1},					// Unidad
		{"mg", 0.00000220462},      // Miligramo a Libra
		{"g", 0.00220462},			// Gramo a Libra
		{"kg", 2.20462},			// Kilogramo a Libra
		{"lb", 1},					// Libra
		{"oz", 0.0625},				// Onza a Libra
		{"mL", 0.001},				// Mililitro a Litro
		{"L", 1},					// Litro
		{"gal", 3.78541}			// Gal�n a Litro
		};

		// C�lculo del total de productos vendidos (por tipo de unidad de medida)
		double totalUnits = 0;
		double totalVolume = 0.00;
		double totalWeight = 0.00;

		// Abrimos el archivo donde se encuentran todos los productos y sus cantidades compradas
		ifstream count_billedProds;
		count_billedProds.open("factura\\Registro de facturas.txt", ios::in);
		
		if (count_billedProds.is_open()) {

			string lineAmount;
			while (getline(count_billedProds, lineAmount)) {
				stringstream ss(lineAmount);
				// Variables para el archivo de "Registro de facturas.txt"
				string nFac, fEm, hEm, client, cashier, descProd, purchasedAmount, pU, dscount, total;
				// Extraemos los campos seg�n el delimitador '|'
				getline(ss, nFac, '|');
				getline(ss, fEm, '|');
				getline(ss, hEm, '|');
				getline(ss, client, '|');
				getline(ss, cashier, '|');
				getline(ss, descProd, '|');
				getline(ss, purchasedAmount, '|');
				getline(ss, pU, '|');
				getline(ss, dscount, '|');
				getline(ss, total, '|');

				/* Abrimos el archivo de "Registro de productos.txt" para comprobar la unidad de medida y si no s�lo est�...
				...en factura, sino que tambi�n en inventario*/
				prodsFile.open("productos\\Registro de productos.txt", ios::in);

				string lineProd; // Variable que permitir� leer l�nea por l�nea el contenido del archivo
				while (getline(prodsFile, lineProd)) {
					stringstream ssP(lineProd);
					
					string code, group, desc, uM;

					getline(ssP, code, '|');
					getline(ssP, group, '|');
					getline(ssP, desc, '|');
					getline(ssP, uM, '|');

					if (descProd == desc) {
						// Convertimos la cantidad a una unidad base elegida (Kilogramos o Litros)
						double amount = stod(purchasedAmount) * conversionFactors[uM];

						// Se actualizan los totales seg�n el tipo de unidad
						if (uM == "u") {
							totalUnits += amount;
						}
						else if (uM == "mg" || uM == "g" || uM == "kg" || uM == "lb" || uM == "oz") {
							totalWeight += amount;
						}
						else if (uM == "mL" || uM == "L" || uM == "gal") {
							totalVolume += amount;
						}
					}
				}
				prodsFile.close();
			}
			count_billedProds.close();
		}
		prodsFile.close(); // Cerramos el archivo de "Registro de productos.txt"

		string lineProd, lineReg; // Declaramos dos variables que leeran cada l�nea de los archivos especificados

		// Recorremos el archivo de "Registro de productos.txt"
		prodsFile.open("productos\\Registro de productos.txt", ios::in); // Volvemos a abrir el archivo para 

		while (getline(prodsFile, lineProd)) {
			// Variables para el archivo "Registro de productos.txt"
			string code, group, desc, uM;

			// Se separa cada campo necesitado seg�n el delimitador (en este caso '|')
			stringstream ssP(lineProd);
			getline(ssP, code, '|');
			getline(ssP, group, '|');
			getline(ssP, desc, '|');
			getline(ssP, uM, '|');

			// Abrimos el archivo donde est�n registrados los movimimientos de cada producto
			ifstream soldProds;
			soldProds.open("factura\\Registro de facturas.txt", ios::in);

			double purchasedAmount = 0; // Cantidad total de ventas de un producto en base a su descripci�n
			double totalProfits = 0; // Total de ganancias que el producto ha ofrecido

			string lineReg; // Variable que permitir� obtener cada l�nea del archivo
			while (getline(soldProds, lineReg)) {
				// Variables para el archivo "Registro de facturas.txt"
				string nFac, fEm, hEm, client, cashier, descProd, cant, pU, dscount, total;
				stringstream ssReg(lineReg);
				getline(ssReg, nFac, '|');
				getline(ssReg, fEm, '|');
				getline(ssReg, hEm, '|');
				getline(ssReg, client, '|');
				getline(ssReg, cashier, '|');
				getline(ssReg, descProd, '|');
				getline(ssReg, cant, '|');
				getline(ssReg, pU, '|');
				getline(ssReg, dscount, '|');
				getline(ssReg, total, '|');
				
				/* Comparamos si la descripci�n del producto contenido en el registro de productos es igual al de
				...cualquier concepto de compra efectuada en factura*/
				if (desc == descProd) {
					purchasedAmount += stod(cant); // Convertimos la cadena a double
					// Eliminamos la coma de la cadena, para que al convertirla a double no haya problemas en la suma
					total.erase(remove(total.begin(), total.end(), ','), total.end());
					totalProfits += stod(total); //Obtenemos el saldo de las compras realizadas sobre el producto
				}
			}

			/* Calculamos el porcentaje de preferencia en base a los totales dados del mapa...
			...y su tipo de unidad*/
			double preference = 0.00;

			// El an�lisis ser� tomado seg�n el tipo de unidad seleccionado por el usuario
			/* Verificamos si el total general vendido para esa unidad es mayor a cero,...
			...a fin de evitar indeterminaciones (es decir, valor no num�rico (NaN)*/
			if (umedida == "unidad" && totalUnits > 0) {
				if (uM == "u") {
					preference = (purchasedAmount / totalUnits) * 100;
					// Redondeamos el n�mero dado a dos decimales
					preference = round(preference * 100) / 100.0;

					// Se escribe la informaci�n en el archivo de ventas de productos
					salesAnalysis << desc << "|" << uM << "|" << purchasedAmount << "|" << totalProfits
						<< "|" << preference << endl;
				}
			}
			else if (umedida == "peso" && totalWeight > 0) {
				if (uM == "mg" || uM == "g" || uM == "kg" || uM == "lb" || uM == "oz") {
					preference = (purchasedAmount / totalWeight) * 100;

					preference = round(preference * 100) / 100.0;

					salesAnalysis << desc << "|" << uM << "|" << purchasedAmount << "|" << totalProfits
						<< "|" << preference << endl;
				}
			}
			else if (umedida == "volumen" && totalVolume > 0) {
				if (uM == "mL" || uM == "L" || uM == "gal") {
					preference = (purchasedAmount / totalVolume) * 100;

					preference = round(preference * 100) / 100.0;
					salesAnalysis << desc << "|" << uM << "|" << purchasedAmount << "|" << totalProfits
						<< "|" << preference << endl;
				}
			}

			soldProds.close();
		}
		// Cerramos los archivos
		prodsFile.close();
		salesAnalysis.close();
	}

	/* Funci�n que permite registrar ciertos campos a un archivo de texto, a fin de facilitar un resumen entre dos fechas escogidas
	...por el usuario en torno a las facturas efectuadas en dicho lapso.*/
	inline void registrar_reporteFactura(string firstDate, string secondDate) {
		// Convertimos los valores de las fechas a enteros, separando cada campo de "/" a su respectivo lugar
		stringstream fDate(firstDate);
		stringstream sDate(secondDate);
		string separate;

		// Campos de las fechas "Desde"
		getline(fDate, separate, '/');
		int fromDay = stoi(separate);
		getline(fDate, separate, '/');
		int fromMonth = stoi(separate);
		getline(fDate, separate);
		int fromYear = stoi(separate);

		// Campos de las fechas "Hasta"
		getline(sDate, separate, '/');
		int toDay = stoi(separate);
		getline(sDate, separate, '/');
		int toMonth = stoi(separate);
		getline(sDate, separate);
		int toYear = stoi(separate);

		// Se crea una estructura de tiempo con los datos dados
		tm fromDate = { 0, 0, 0, fromDay, fromMonth - 1, fromYear - 1900 };
		tm toDate = { 0, 0, 0, toDay, toMonth - 1, toYear - 1900 };

		// Convertimos las estructuras de tiempo a tiempos de calendario
		time_t fromTime = mktime(&fromDate);
		time_t toTime = mktime(&toDate);
	
		// Se calcula la diferencia entre las dos fechas en segundos
		time_t difference = toTime - fromTime;
		
		// Calculamos la cantidad de d�as entre las dos fechas
		int secCant = 60 * 60 * 24; // Esto indica la cantidad de segundos en un d�a
		int days = difference / secCant;

		// Creamos un archivo de texto donde se guardar�n las facturas entre el rango de fechas dado
		ofstream file;
		file.open("factura\\Reporte de facturas.txt", ios::app);

		list<string> time_inRange; // Lista donde se almacenar�n las fechas entre las dos fechas dadas
		// Imprimir todas las fechas entre las dos fechas dadas en el archivo
		for (int i = 0; i <= days; i++) {
			struct tm tInfo; // Obtenemos la estructura de tiempo local de una forma segura
			localtime_s(&tInfo, &fromTime);
			// Convertimos los valores enteros a cadenas de texto para ubicarlas en la lista:

			/* En caso de que el mes sea menor o igual a 9, agregamos un cero detr�s, para coincidir, con el
			...formato que trabaja nuestro sistema*/
			string day = (tInfo.tm_mday <= 9) ? "0" + to_string(tInfo.tm_mday) : to_string(tInfo.tm_mday);
			// Lo mismo pasa con los meses
			string month = (tInfo.tm_mon + 1) <= 9 ? "0" + to_string(tInfo.tm_mon + 1) : to_string(tInfo.tm_mon + 1);
			string year = to_string(tInfo.tm_year + 1900);
			
			// Concatenamos la estructura de la fecha
			string date = day + "-" + month + "-" + year;

			time_inRange.push_back(date);

			// Agregamos un d�a a la fecha (convirtiendo el valor a long long para evitar p�rdida de datos
			fromTime += 60 * 60 * 24;
		}

		int numLines = 0; // Variable que en el recorrido se ir� sumando en caso de agregarse l�neas
		// Recorremos todas l�neas almacenadas de la lista
		for (string dateLine : time_inRange) {

			// Abrimos en modo de lectura el archivo donde se encuentran guardadas las facturas hasta el momento
			ifstream billHistory;
			billHistory.open("factura\\Historial de facturas.txt", ios::in);

			string lineHistory; // L�nea que almacenar� el contenido de cada l�nea del archivo
			while (getline(billHistory, lineHistory)) {
				stringstream ssDate(lineHistory);
				string nFact, fEmit; // Variable que tomar� el valor del campo de fecha de emisi�n
				// Obtenemos la fecha de emisi�n de la factura, ubicada en el segundo campo
				getline(ssDate, nFact, '|');
				getline(ssDate, fEmit, '|');

				/*Si la fecha dada por el rango es igual a la contenida en el historial,
				...copiamos toda la l�nea*/
				if (dateLine == fEmit) {
					file << lineHistory << endl;
					numLines++;
				}
			}

			/* Cerramos el archivo por cada iteraci�n finalizada para ubicarnos en...
			...la primera l�nea del archivo en caso de haber m�s iteraciones*/
			billHistory.close();
		}

		/* Si el n�mero de l�neas agregadas al reporte no presentaron ninguna adici�n, entonces...
		...presentamos un mensaje de excepci�n*/
		if (numLines == 0) {
			MessageBox::Show("No se encontr� ninguna factura en el rango de fechas especificado", "Reporte de facturas",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	/* Funci�n que permite anular una factura (especificada su c�digo), de tal modo que se eliminen todos sus registros y de paso,...
	...devolver los art�culos vendidos al inventario.*/
	inline void anularFactura(string nFact, string clientInitials, string fEmit) {
		// Concatenamos para obtener la ruta de acceso del recibo de la factura a anular
		string receiptFilepath = "factura\\facturas generadas\\" + nFact + "_" + clientInitials + "_" + fEmit + ".txt";

		// Eliminamos ("anulamos") el archivo 
		if (remove(receiptFilepath.c_str()) != 0) {
			// En caso de que el proceso de anulaci�n no haya sido correcto, enviamos un mensaje de error
			MessageBox::Show("Error al anular la factura", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else {
			// Mostramos un mensaje de �xito al anular la factura de manera correcta
			String^ message = "Factura <<" + gcnew String(nFact.c_str()) + ">> anulada exitosamente";
			MessageBox::Show(message, "Anular factura", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		/* Otros archivos como "Historial de facturas.txt" y "Registro de facturas.txt" tienen el c�digo...
		...de la factura anulada con sus datos; por tanto, actualizaremos la informaci�n que hay dentro de estas.*/

		// Abrimos los archivos anteriormente mencionados
		ifstream registeredBills;
		registeredBills.open("factura\\Registro de facturas.txt", ios::in);

		ifstream billHistory;
		billHistory.open("factura\\Historial de facturas.txt", ios::in);

		// Se verifica si se pudo acceder correctamente en ambos
		if (!(registeredBills.is_open() || billHistory.is_open())) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos dos archivos temporales, donde se reflejar�n los cambios
		ofstream modifyRegister;
		modifyRegister.open("factura\\temp_registro.txt", ios::out);

		ofstream modifyHistory;
		modifyHistory.open("factura\\temp_historial.txt", ios::out);

		// Se verifica si ambos fueron creados correctamente
		if (!(modifyRegister.is_open() || modifyHistory.is_open())) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		string lineReg, lineHist; // Declaramos dos variables que leeran cada l�nea de los archivos especificados
		
		// Variables para el archivo "Registro de facturas.txt" e "Historial de facturas.txt"
		string codeFac, codeFac2;

		// Recorremos el archivo de "Registro de facturas.txt"
		while (getline(registeredBills, lineReg)) {
			// Se separa cada campo seg�n el delimitador usado (en este caso '|')
			stringstream ssReg(lineReg);
			getline(ssReg, codeFac, '|');

			// Si el n�mero de la factura anulada es igual a la contenida en la l�nea del registro...
			if (nFact == codeFac) {
				// Devolvemos la cantidad dada por el producto al inventario
				actualizarInventario(nFact, true);
				MessageBox::Show("Se han devuelto las mercanc�as vendidas de la factura anulada", "Inventario actualizado", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				// Copiamos la l�nea tal y como est� en el archivo temporal
				modifyRegister << lineReg << endl;
			}
		}

		// Tambi�n se recorre el archivo de "Historial de facturas.txt"
		while (getline(billHistory, lineHist)) {
			stringstream ssHist(lineHist);
			getline(ssHist, codeFac2, '|');

			// Si el n�mero de la factura anulada es diferente a la contenida en la l�nea del historial...
			if (nFact != codeFac2) {
				// Simplemente copiamos la l�nea en el archivo temporal
				modifyHistory << lineHist << endl;
			}
		}

		// Cerramos los archivos
		registeredBills.close();
		billHistory.close();
		modifyRegister.close();
		modifyHistory.close();

		//Eliminamos el archivo original
		if (remove("factura\\Registro de facturas.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("factura\\temp_registro.txt", "factura\\Registro de facturas.txt") != 0) {
			MessageBox::Show("No se pudo renombrar el archivo");
		}

		//Eliminamos el archivo original
		if (remove("factura\\Historial de facturas.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("factura\\temp_historial.txt", "factura\\Historial de facturas.txt") != 0) {
			MessageBox::Show("No se pudo renombrar el archivo.");
		}
	}

	// Funci�n que retorna la fecha local del ordenador, a fin de especificar el tiempo en el que se realiz� la factura
	inline string obtenerFecha() {
		// Se obtiene el tiempo actual
		time_t tiempo_actual = time(nullptr);
		time(&tiempo_actual);

		// Obtener la estructura de tiempo local de forma segura
		struct tm tiempo_local;
		localtime_s(&tiempo_local, &tiempo_actual);

		// Se obtiene la hora en partes
		int anio = tiempo_local.tm_year + 1900;
		int mes = tiempo_local.tm_mon + 1;
		int dia = tiempo_local.tm_mday;

		// Se formatea la hora como string para obtener la estructura deseada
		ostringstream ss;
		ss << setw(2) << setfill('0') << dia << "-"
			<< setw(2) << setfill('0') << mes << "-"
			<< setw(2) << setfill('0') << anio;

		return ss.str();
	}

	// Funci�n que retorna la hora local del ordenador, a fin de especificar el tiempo en el que se realiz� la factura
	inline string obtenerHora() {
		// Se obtiene el tiempo actual
		time_t tiempo_actual = time(nullptr);
		time(&tiempo_actual);

		// Se obtiene la estructura de tiempo local de forma segura
		struct tm tiempo_local;
		localtime_s(&tiempo_local, &tiempo_actual);

		// Se obtiene la hora en partes
		int hora = tiempo_local.tm_hour;
		int minuto = tiempo_local.tm_min;

		// Se formatea la hora como string para obtener la estructura deseada
		ostringstream ss;
		ss << setw(2) << setfill('0') << hora << ":"
			<< setw(2) << setfill('0') << minuto;

		return ss.str();
	}

	/* Funci�n que regresa el valor total de las ventas obtenidas a trav�s del monto...
	...de las facturas efectuadas*/
	inline double obtener_valorVentas() {
		// Se abre el archivo de historial de facturas en formato de lectura
		ifstream file;
		file.open("factura\\Historial de facturas.txt");

		string line;
		// Variables que obtendr�n el valor de cada campo del archivo de historial de facturas
		string nFact, fEmit, client, cashier, payMethod, subTotal, total_wIVA;
		double totalSales = 0.00; // Declaramos una variable que obtendr� el valor de lo registrado en factura
		while (getline(file, line)) {
			// Se separa campo seg�n el delimitador usado (en este caso '|')
			stringstream ss(line);

			getline(ss, nFact, '|');
			getline(ss, fEmit, '|');
			getline(ss, client, '|');
			getline(ss, cashier, '|');
			getline(ss, payMethod, '|');
			getline(ss, subTotal, '|');
			getline(ss, total_wIVA, '|');

			// Eliminamos la coma de la cadena, para que al convertirla a flotante no haya problemas en la suma
			total_wIVA.erase(remove(total_wIVA.begin(), total_wIVA.end(), ','), total_wIVA.end());
			// Sumamos el valor de cada saldo total con IVA de las facturas
			totalSales += stod(total_wIVA);
		}

		// Cerramos el archivo
		file.close();

		return totalSales; // Retornamos el valor obtenido de las ventas
	}
}