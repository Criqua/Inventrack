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

	// Función que permite registrar los datos en la factura y guardarlos como un historial general
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

	// Función que presenta en un DataGridView los productos adicionados que el cliente desea adquirir
	inline void agregarProducto_en_dgv(DataGridView^ dgv, String^ producto, float cantidad, float precioUnit,
		float descuento) {
		// Creamos una nueva fila en el dgv, que almacenará los campos del producto en cuestión
		DataGridViewRow^ row = gcnew DataGridViewRow();
		row->CreateCells(dgv);

		// Asignamos los valores de las celdas en base al índice de la columna
		row->Cells[0]->Value = producto;  // Índice de la columna "Producto"
		row->Cells[1]->Value = cantidad;  // Índice de la columna "Cantidad"
		row->Cells[2]->Value = precioUnit;  // Índice de la columna "Precio_unit"
		row->Cells[3]->Value = descuento;  // Índice de la columna "Descuento"

		// Se agrega la fila en el DataGridView
		dgv->Rows->Add(row);
	}

	// Función que cuenta el número de facturas generadas
	inline int numFact(string filepath) {
		string numfact = "";
		ifstream file;
		file.open(filepath, ios::in); //Se abre el archivo en forma de lectura

		string line;
		//Se lee una línea entera del archivo y se verifica si contiene "FAC-"
		while (getline(file, line)) {
			size_t pos = line.find("FAC-");
			if (pos != string::npos) {
				numfact = line.substr(pos + 4, 4); // Se obtienen los últimos 4 caracteres después de "FAC-"
			}
		}
		file.close();

		if (numfact.empty()) {
			return 1; // En caso de no haber aún una factura en el registro, se manda 1 para reconocerla como primera factura
		}

		// Convertimos de string a entero el valor de la cadena
		int lastNum = stoi(numfact);
		return lastNum + 1; //Se devuelve el número de facturas + 1 para indicar una nueva factura
	}

	// Función que permite realizar las operaciones aritméticas al adicionar un producto
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

			// Se obtiene el total del producto aplicándole el descuento
			double totalProduct = cant * pUnit * (1 - descuento);

			// Ya calculado el total del producto, se ingresa en la fila de "Total"
			dgv->Rows[i]->Cells[4]->Value = totalProduct.ToString("N2");
			
			// Se suman todos los totales para dar con el subtotal y total a pagar de los productos
			subtotal += totalProduct;
			total += totalProduct;
		}

		// Ya finalizado el recorrido, se calcula el valor total a pagar con el IVA incluído (+15% en Nicaragua)
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

		// Se lee cada línea del archivo y se añade al comboBox
		string line;
		while (getline(infile, line)) {
			// El std::string se convierte a System::String
			System::String^ lineStr = gcnew System::String(line.c_str());

			// Los datos en System::String se añaden al comboBox
			comboBox->Items->Add(lineStr);
		}

		// Se cierra el archivo
		infile.close();
	}

	// Función que permite la obtención de las iniciales del nombre de un cliente
	inline string obtenerIniciales(string client) {
		// Tomaremos las iniciales del cliente atendido:
		string initials;
		initials += client[0]; // Obtenemos la primera inicial desde el primer caracter de la cadena

		// Se hace un ciclo empezando después de la primera inicial hasta terminar con el largo de la cadena
		for (size_t i = 1; i < client.length(); i++) {
			// En caso de que el anterior caracter al actual sea un espacio en blanco, significa que estamos en otra inicial de la cadena
			if (client[i - 1] == ' ') {
				initials += client[i];
			}
		}

		return initials; // Devolvemos las iniciales ya concatenadas
	}

	// Función que permite crear un diseño de un recibo de factura según los datos pasados por el dgv
	inline void diseñarFactura(string numFact, string client, string fEmision, string hEmision, string cashier, string nomEmpresa, string dirEmpresa, 
							   string telEmpresa, string emailEmpresa, double masIVA) {
		// Primero creamos un archivo con nombre único, tomando en cuenta los datos enviados por parámetro dentro de la función:

		// Tomaremos las iniciales del cliente atendido por medio de esta función:
		string initials = obtenerIniciales(client);

		// Concatenamos los campos de número de factura, iniciales de cliente y la fecha dada de la factura para hacer única la factura
		string filename = "factura\\facturas generadas\\" + numFact + "_" + initials + "_" + fEmision + ".txt";

		// Creamos el archivo con nombre del resultado de la concatenación
		ofstream file;
		file.open(filename, ios::out);
		file.imbue(locale("")); // Manipulamos el archivo para que los valores obtengan una cantidad en forma de moneda

		// Se verifica que los archivos se hayan abierto correctamente 
		if (!file.is_open()) {
			MessageBox::Show("Error. El archivo de origen de diseño de factura no puede abrirse");
			return;
		}

		// Abrimos el archivo donde está registrada la información de la factura
		ifstream registeredBills;
		registeredBills.open("factura\\Registro de facturas.txt", ios::in);

		if (!registeredBills.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		list<string> lines; // Creamos una lista que almacenará todos los datos relacionados al número de la factura
		string line;

		while (getline(registeredBills, line)) {
			// Obtenemos el número de factura actual
			size_t pos = line.find("|");
			if (pos != string::npos) {
				string numFact_inFile = line.substr(0, pos);

				// Agregaremos lineas a la lista sí y solo sí el número de factura actual es el mismo al contenido en el registro
				if (numFact == numFact_inFile) {
					lines.push_back(line);
				}
			}
		}

		// Recorremos todos los datos incluídos en la lista y los ubicamos en el diseño de la factura:
		
		// Encabezado de la factura:
		file << "\t\t\t\t========================================" << endl;
		file << "\t\t\t\tNúmero de factura: " << numFact << endl;
		file << "\t\t\t\tFecha de emisión: " << fEmision << endl;
		file << "\t\t\t\tHora: " << hEmision << endl;
		file << "\t\t\t\t========================================" << endl;
		file << "\t\t\t\t" << nomEmpresa << endl;
		file << "\t\t\t\t" << dirEmpresa << endl;
		file << "\t\t\t\t" << emailEmpresa << endl;
		file << "\t\t\t\t" << telEmpresa << endl;
		file << "\t\t\t\t========================================" << endl;
		file << endl << "Cliente: " << client << endl;
		file << "Le atendió: " << cashier << endl;
		file << "-------------------------------------------------------------------------------------------------------" << endl;

		// Detalle de los productos:
		file << left << setw(50) << "Producto" << setw(15) << "Cantidad" << setw(15) << "Precio Unit." << setw(15) << "Descuento" << setw(15) << "Total" << endl;
		file << "-------------------------------------------------------------------------------------------------------" << endl;
		
		// Declaramos variables que respectan a cada campo en el registro de facturas
		string nFact, fE, hE, nClient, nCashier, prod, cant, pU, dscount, total;

		// Recorremos las líneas almacenadas de la lista ANTES de la última línea, ya que en ella hay mas campos almacenados
		for (auto it = lines.begin(); it != prev(lines.end()); ++it) {
			string fileLine = *it;
			istringstream iss(fileLine);

			// Extraemos los campos según el delimitador '|'
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
		// Nos ubicamos a la última línea del archivo
		string lastLine = *prev(lines.end());

		string formaPago, subtotal, totalpago, pagado, devuelto;
		istringstream iss(lastLine);

		// Extraemos los campos según el delimitador '|'
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
		/* Extraemos los datos de la última línea, ya que tenemos campos adicionales como forma de pago,...
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
		file << "\t\t\t\t\t¡Gracias por elegirnos! :)";

		file.close();
		registeredBills.close();
	}

	// Función que permite guardar los datos de la factura en un archivo de texto
	inline void registrar_datosFactura_delDGV(DataGridView^ dgv, string numFact, string fEmision, string hEmision, string client, string cashier, 
											  string subtotal, string payMethod, string totalPayment, string totalPaid, string change) {
		try {
			// Se abre el archivo en formato de añadir al final
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

				// Verificamos es el último producto
				if (i == dgv->Rows->Count - 1) {
					string finalLine = numFact + "|" + fEmision + "|" + hEmision + "|" + client + "|" + cashier + "|" + prod + "|"
						+ cant + "|" + pUnit + "|" + dscount + "|" + totalProd + "|" + payMethod + "|" + subtotal + "|"
						+ totalPayment + "|" + totalPaid + "|" + change;
					/*Registramos los valores del último producto, pero añadimos campos adicionales como...
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
					// En caso de haber más de un producto comprado agregamos los siguientes datos:
					registrarFactura(numFact, fEmision, hEmision, client, cashier, prod, cant, pUnit, dscount, totalProd);
				}
			}
			String^ successMessage = "¡Factura registrada exitosamente! Se ha diseñado un recibo con los datos agregados. Puede verlo en la siguiente dirección: factura\\facturas generadas.";
			MessageBox::Show(successMessage, "Movimiento exitoso", MessageBoxButtons::OK, MessageBoxIcon::Information);

			file.close();
		}
		catch (const std::exception& e) {
			MessageBox::Show("Ocurrió un error al realizar la factura: " + gcnew System::String(e.what()));
		}
	}

	// Función que permite modificar los datos del inventario luego de hacer una factura exitosa o al haber anulado una
	inline void actualizarInventario(string numFact, bool isCancelled) {
		// Abrimos el archivo donde se encuentran las facturas en modo de lectura
		ifstream billFile;
		billFile.open("factura\\Registro de facturas.txt", ios::in);

		// Se verifica que los archivos se hayan abierto correctamente 
		if (!billFile.is_open()) {
			MessageBox::Show("Error. El archivo de de factura no puede abrirse");
			return;
		}

		list<string> billedProd; // Creamos una lista que almacenará todos los datos relacionados al número de la factura
		string line;

		// Almacenamos todas las líneas que coincidan con el código de factura que editaremos
		while (getline(billFile, line)) {
			// Obtenemos el número de factura actual
			size_t pos = line.find("|");
			if (pos != string::npos) {
				string numFact_inFile = line.substr(0, pos);

				// Agregaremos lineas a la lista sí y solo sí el número de factura actual es el mismo al contenido en el registro
				if (numFact == numFact_inFile) {
					billedProd.push_back(line);
				}
			}
		}

		// Recorremos todas líneas almacenadas de la lista
		for (auto it = billedProd.begin(); it != billedProd.end(); ++it) {
			string fileLine = *it;
			istringstream iss(fileLine);

			// Se declaran variables que respectan a cada campo del registro de facturas
			string nFact, fE, hE, nClient, nCashier, prod, cant, pU, dscount, total;

			// Extraemos los campos según el delimitador '|'
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

			// Creamos un archivo temporal en el cual se modificarán los datos necesarios en modo de escritura
			ofstream modifyProd;
			modifyProd.open("productos\\temp.txt", ios::out);

			if (!modifyProd.is_open()) {
				MessageBox::Show("Error. El archivo temporal no puede abrirse");
				return;
			}

			/* Verificamos en el archivo de registro de producto las líneas que coincidan con la descripción del producto,...
			... y en caso de haber concordancia nos ubicamos en la línea y modificamos sus existencias en caso de que la factura...
			... haya sido anulada (devolvemos existencias) o registrada (restamos existencias)*/
			string prodLine;
			while (getline(prodFile, prodLine)) {
				stringstream ss(prodLine);

				// Se declaran variables que luego les serán asignados sus nuevos valores
				string code_infile, group_infile, desc_infile, uMeasure_infile, exist_infile, minExist_infile, ubic_infile, pUnit_infile, fExp_infile;

				// Extraemos los campos del registro de productos según el delimitador '|'
				getline(ss, code_infile, '|');
				getline(ss, group_infile, '|');
				getline(ss, desc_infile, '|');
				getline(ss, uMeasure_infile, '|');
				getline(ss, exist_infile, '|');
				getline(ss, minExist_infile, '|');
				getline(ss, ubic_infile, '|');
				getline(ss, pUnit_infile, '|');
				getline(ss, fExp_infile);

				// Si la descripción del producto coincide con la descripción incluida en el registro de facturas, entonces modificamos esa línea
				if (prod == desc_infile) {
					float newExist = 0;
					// Dependiendo de si la factura fue anulada o registrada, restamos o sumamos las existencias
					if (isCancelled == true) {
						newExist = stof(exist_infile) + stof(cant);
					}
					else {
						newExist = stof(exist_infile) - stof(cant);
					}

					// Escribimos la línea modificada en el archivo temporal
					modifyProd << code_infile << "|" << group_infile << "|" << desc_infile << "|" << uMeasure_infile << "|" << newExist << "|"
						<< minExist_infile << "|" << ubic_infile << "|" << pUnit_infile << "|" << fExp_infile << endl;
				}
				else {
					// De lo contrario, agregamos la línea sin modificar en la lista especificada
					 modifyProd << prodLine << endl;
				}
			}

			/* Cerramos los archivos al final de cada iteración y luego los volvemos a abrir para que siempre se posicionen...
			...al inicio y continue comparando en caso de que se haya adicionado más de un producto en compra*/
			prodFile.close();
			modifyProd.close();

			// Reflejamos los cambios en inventario desde el producto que tenemos facturado hasta ahora por la iteración
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

	// Función que permite mostrar los datos registrados del registro de facturas y los ubica en un dgv para su correcta visualización
	inline void mostrar_historialFacturas(DataGridView^ dgv) {
		try {
			// Abrimos el archivo donde tenemos registrados los datos de las facturas realizadas
			ifstream file;
			file.open("factura\\Historial de facturas.txt", ios::in);

			// Se crea una tabla con las columnas correspondientes
			System::Data::DataTable^ table = gcnew System::Data::DataTable();
			table->Clear();
			table->Columns->Add("No. Fact", String::typeid);
			table->Columns->Add("Fecha de emisión", String::typeid);
			table->Columns->Add("Cliente", String::typeid);
			table->Columns->Add("Vendedor", String::typeid);
			table->Columns->Add("Forma de pago", String::typeid);
			table->Columns->Add("Subtotal", String::typeid);
			table->Columns->Add("Total facturado", String::typeid);
			table->Columns->Add("Total pagado", String::typeid);
			table->Columns->Add("Total devuelto", String::typeid);

			// Lista bidimensional que se encargará de llenar cada celda de la tabla
			list<list<string>> datos;

			if (!file.is_open()) {
				MessageBox::Show("No se puede mostrar la tabla de registro.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else {
				// Se leen los datos del archivo línea por línea
				string line;
				while (getline(file, line)) {
					// Se crea una lista que almacenará los datos de una linea
					list<string> datos_linea;

					// Separar los campos de la línea por el delimitador '|'
					istringstream ss(line);
					string campo;
					while (getline(ss, campo, '|')) {
						// Agregar el campo a la lista de datos de la línea
						datos_linea.push_back(campo);
					}

					// Agregar la lista de datos de la línea a la lista bidimensional
					datos.push_back(datos_linea);
				}

				// Se cierra el archivo después de leer los datos
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
			MessageBox::Show("Ocurrió un error al mostrar las facturas: " + gcnew System::String(e.what()));
		}
	}

	// Función que permite buscar una factura cualquiera en base a lo contenido en el dgv
	inline void buscarFactura(DataGridView^ dgv, String^ searched_nFact, String^% numFact, bool% found, 
							  String^ %Client, String^ %fEmision) {
		found = false; // Se inicia la variable como falsa

		for (int i = 0; dgv->RowCount; i++) {
			//Se busca la factura en base a su número escrito en el buscador
			DataGridViewCell^ cell = dgv->Rows[i]->Cells["No. Fact"];
			/* Se realiza esta condición ya que si la factura buscada no se encuentra en la tabla, la variable tomaría un valor nulo
				y por ende resultaría en una excepción en el programa.*/
			String^ nFact = (cell->Value != nullptr) ? cell->Value->ToString() : String::Empty;

			// Verificamos si se ha encontrado la factura
			if (nFact->ToLower()->Contains(searched_nFact->ToLower())) {
				found = true; // La factura fue encontrada, se le da un valor de verdadero a la variable
				// Se selecciona la fila correspondiente
				dgv->Rows[i]->Selected = true;
				dgv->CurrentCell = dgv->Rows[i]->Cells[0];
				// Nos ubicamos en donde se encuentra el número de factura
				dgv->FirstDisplayedScrollingRowIndex = i;

				numFact = searched_nFact;
				// Extraemos información de la factura de campos de fecha de emisión y cliente
				fEmision = dgv->Rows[i]->Cells["Fecha de emisión"]->Value->ToString();
				string client_fullName = conversion::to_stdstring(dgv->Rows[i]->Cells["Cliente"]->Value->ToString());

				// Obtenemos las iniciales del nombre del cliente y cambiamos de std::string a System::String
				Client = gcnew String(obtenerIniciales(client_fullName).c_str());

				// La factura ya fue encontrada, no es necesario seguir con la búsqueda
				break;
			}
		}
		if (!found) {
			MessageBox::Show("La factura buscada no se encuentra en el historial.", "Factura no encontrada", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	// Función que permite mostrar el diseño del recibo de la factura en un TextBox
	inline void verFactura(string nFact, string clientInitials, string fEmision, TextBox^ textBox) {
		// Concatenamos según la estructura en la que se guarda el recibo de factura
		string filepath = "factura\\facturas generadas\\" + nFact + "_" + clientInitials + "_" + fEmision + ".txt";

		try {
			// Se abre el archivo en modo lectura
			ifstream file;
			file.open(filepath);

			if (!file.is_open()) { // Verificamos si el archivo no se pudo abrir correctamente
				MessageBox::Show("Error al abrir el archivo");
				return;
			}

			list<string> lines; // Lista que almacenará las líneas del archivo de texto

			// Leemos el contenido del archivo línea por línea
			string line;
			while (getline(file, line)) {
				lines.push_back(line); // Agregamos la línea a la lista
			}

			// Cerramos el archivo
			file.close();

			// Se agregan las líneas al TextBox en el orden correcto
			for (const string& line : lines) {
				// Convertimos la línea a formato de System::String y la agregamos al TextBox
				String^ txtLine = gcnew String(line.c_str());
				textBox->AppendText(txtLine + Environment::NewLine);
			}
		}
		catch (const std::exception& e) {
			MessageBox::Show("Error al leer el archivo: " + gcnew String(e.what()));
		}
	}

	/* Función que permite registrar ciertos campos a un archivo de texto, a fin de facilitar una reseña estadística...
	...sobre la cantidad de veces que los clientes realizan compras en el lugar de trabajo*/
	inline void registrar_frecuenciaClientes() {
		/* Abrimos dos archivos en modo de lectura que contienen los clientes registrados e información relacionada...
		...a sus actividades en facturación*/
		ifstream clientsFile;
		clientsFile.open("clientes\\Registro de clientes.txt", ios::in);

		// Se verifica si se pudo acceder correctamente en ambos
		if (!clientsFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos un archivo en el que se guardará información para la muestra de la frecuencia de clientes
		ofstream clientFrequency;
		clientFrequency.open("factura\\Frecuencia de clientes.txt", ios::app);

		// Cálculo del total de facturas
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

		string lineClient, lineHistory; // Declaramos dos variables que leeran cada línea de los archivos especificados

		// Recorremos ambos archivos al mismo tiempo
		while (getline(clientsFile, lineClient)) {
			float frequency = 0; // Cantidad de veces que el cliente se ha presentado y ha sido facturado en la empresa
			float totalPaid = 0; // Saldo total que el cliente ha gastado en productos de la empresa
			// Variables para el archivo "Registro de clientes.txt"
			string id, tel, names, surnames;

			// Se separa cada campo según el delimitador (en este caso '|')
			stringstream ssClient(lineClient);
			getline(ssClient, id, '|');
			getline(ssClient, tel, '|');
			getline(ssClient, names, '|');
			getline(ssClient, surnames);

			ifstream historyFile;
			historyFile.open("factura\\Historial de facturas.txt", ios::in);

			// Concatenamos los nombres y apellidos para obtener el nombre completo
			/* Usamos System::String para trabajar correctamente con aquellos clientes que tengan acento...
			...ya que este tipo de cadena admite carácteres Unicode.*/
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
				...entonces se hace una suma total de las veces que frecuenta el lugar e invierte en todo el período*/
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
			// Se escribe la información en el archivo de frecuencia de clientes
			clientFrequency << fullName << "|" << totalPaid << "|" << visitPercentage << endl;

			historyFile.close();
		}

		clientsFile.close();
		clientFrequency.close();
	}

	/* Función que permite registrar ciertos campos a un archivo de texto, a fin de facilitar una reseña estadística...
	...sobre qué productos han sido los mas y menos comprados en el lugar de trabajo*/
	inline void registrar_comportamientoProductos(string umedida) {
		/* Abrimos dos archivos en modo de lectura que contienen los productos registrados e información relacionada...
		...a sus actividades en facturación*/
		ifstream prodsFile;

		// Creamos un archivo en el que se guardará información para el análisis de la venta de productos
		ofstream salesAnalysis;
		salesAnalysis.open("factura\\Venta de productos.txt", ios::app);

		/* Se utiliza un contenedor de tipo map para convertir los datos a unos homogéneos entre sí...
		...con esta práctica el código puede hacerse más compacto y menos repetitivo*/
		map<string, double> conversionFactors = {
		{"u", 1},					// Unidad
		{"mg", 0.00000220462},      // Miligramo a Libra
		{"g", 0.00220462},			// Gramo a Libra
		{"kg", 2.20462},			// Kilogramo a Libra
		{"lb", 1},					// Libra
		{"oz", 0.0625},				// Onza a Libra
		{"mL", 0.001},				// Mililitro a Litro
		{"L", 1},					// Litro
		{"gal", 3.78541}			// Galón a Litro
		};

		// Cálculo del total de productos vendidos (por tipo de unidad de medida)
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
				// Extraemos los campos según el delimitador '|'
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

				/* Abrimos el archivo de "Registro de productos.txt" para comprobar la unidad de medida y si no sólo está...
				...en factura, sino que también en inventario*/
				prodsFile.open("productos\\Registro de productos.txt", ios::in);

				string lineProd; // Variable que permitirá leer línea por línea el contenido del archivo
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

						// Se actualizan los totales según el tipo de unidad
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

		string lineProd, lineReg; // Declaramos dos variables que leeran cada línea de los archivos especificados

		// Recorremos el archivo de "Registro de productos.txt"
		prodsFile.open("productos\\Registro de productos.txt", ios::in); // Volvemos a abrir el archivo para 

		while (getline(prodsFile, lineProd)) {
			// Variables para el archivo "Registro de productos.txt"
			string code, group, desc, uM;

			// Se separa cada campo necesitado según el delimitador (en este caso '|')
			stringstream ssP(lineProd);
			getline(ssP, code, '|');
			getline(ssP, group, '|');
			getline(ssP, desc, '|');
			getline(ssP, uM, '|');

			// Abrimos el archivo donde están registrados los movimimientos de cada producto
			ifstream soldProds;
			soldProds.open("factura\\Registro de facturas.txt", ios::in);

			double purchasedAmount = 0; // Cantidad total de ventas de un producto en base a su descripción
			double totalProfits = 0; // Total de ganancias que el producto ha ofrecido

			string lineReg; // Variable que permitirá obtener cada línea del archivo
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
				
				/* Comparamos si la descripción del producto contenido en el registro de productos es igual al de
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

			// El análisis será tomado según el tipo de unidad seleccionado por el usuario
			/* Verificamos si el total general vendido para esa unidad es mayor a cero,...
			...a fin de evitar indeterminaciones (es decir, valor no numérico (NaN)*/
			if (umedida == "unidad" && totalUnits > 0) {
				if (uM == "u") {
					preference = (purchasedAmount / totalUnits) * 100;
					// Redondeamos el número dado a dos decimales
					preference = round(preference * 100) / 100.0;

					// Se escribe la información en el archivo de ventas de productos
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

	/* Función que permite registrar ciertos campos a un archivo de texto, a fin de facilitar un resumen entre dos fechas escogidas
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
		
		// Calculamos la cantidad de días entre las dos fechas
		int secCant = 60 * 60 * 24; // Esto indica la cantidad de segundos en un día
		int days = difference / secCant;

		// Creamos un archivo de texto donde se guardarán las facturas entre el rango de fechas dado
		ofstream file;
		file.open("factura\\Reporte de facturas.txt", ios::app);

		list<string> time_inRange; // Lista donde se almacenarán las fechas entre las dos fechas dadas
		// Imprimir todas las fechas entre las dos fechas dadas en el archivo
		for (int i = 0; i <= days; i++) {
			struct tm tInfo; // Obtenemos la estructura de tiempo local de una forma segura
			localtime_s(&tInfo, &fromTime);
			// Convertimos los valores enteros a cadenas de texto para ubicarlas en la lista:

			/* En caso de que el mes sea menor o igual a 9, agregamos un cero detrás, para coincidir, con el
			...formato que trabaja nuestro sistema*/
			string day = (tInfo.tm_mday <= 9) ? "0" + to_string(tInfo.tm_mday) : to_string(tInfo.tm_mday);
			// Lo mismo pasa con los meses
			string month = (tInfo.tm_mon + 1) <= 9 ? "0" + to_string(tInfo.tm_mon + 1) : to_string(tInfo.tm_mon + 1);
			string year = to_string(tInfo.tm_year + 1900);
			
			// Concatenamos la estructura de la fecha
			string date = day + "-" + month + "-" + year;

			time_inRange.push_back(date);

			// Agregamos un día a la fecha (convirtiendo el valor a long long para evitar pérdida de datos
			fromTime += 60 * 60 * 24;
		}

		int numLines = 0; // Variable que en el recorrido se irá sumando en caso de agregarse líneas
		// Recorremos todas líneas almacenadas de la lista
		for (string dateLine : time_inRange) {

			// Abrimos en modo de lectura el archivo donde se encuentran guardadas las facturas hasta el momento
			ifstream billHistory;
			billHistory.open("factura\\Historial de facturas.txt", ios::in);

			string lineHistory; // Línea que almacenará el contenido de cada línea del archivo
			while (getline(billHistory, lineHistory)) {
				stringstream ssDate(lineHistory);
				string nFact, fEmit; // Variable que tomará el valor del campo de fecha de emisión
				// Obtenemos la fecha de emisión de la factura, ubicada en el segundo campo
				getline(ssDate, nFact, '|');
				getline(ssDate, fEmit, '|');

				/*Si la fecha dada por el rango es igual a la contenida en el historial,
				...copiamos toda la línea*/
				if (dateLine == fEmit) {
					file << lineHistory << endl;
					numLines++;
				}
			}

			/* Cerramos el archivo por cada iteración finalizada para ubicarnos en...
			...la primera línea del archivo en caso de haber más iteraciones*/
			billHistory.close();
		}

		/* Si el número de líneas agregadas al reporte no presentaron ninguna adición, entonces...
		...presentamos un mensaje de excepción*/
		if (numLines == 0) {
			MessageBox::Show("No se encontró ninguna factura en el rango de fechas especificado", "Reporte de facturas",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	/* Función que permite anular una factura (especificada su código), de tal modo que se eliminen todos sus registros y de paso,...
	...devolver los artículos vendidos al inventario.*/
	inline void anularFactura(string nFact, string clientInitials, string fEmit) {
		// Concatenamos para obtener la ruta de acceso del recibo de la factura a anular
		string receiptFilepath = "factura\\facturas generadas\\" + nFact + "_" + clientInitials + "_" + fEmit + ".txt";

		// Eliminamos ("anulamos") el archivo 
		if (remove(receiptFilepath.c_str()) != 0) {
			// En caso de que el proceso de anulación no haya sido correcto, enviamos un mensaje de error
			MessageBox::Show("Error al anular la factura", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else {
			// Mostramos un mensaje de éxito al anular la factura de manera correcta
			String^ message = "Factura <<" + gcnew String(nFact.c_str()) + ">> anulada exitosamente";
			MessageBox::Show(message, "Anular factura", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		/* Otros archivos como "Historial de facturas.txt" y "Registro de facturas.txt" tienen el código...
		...de la factura anulada con sus datos; por tanto, actualizaremos la información que hay dentro de estas.*/

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

		// Creamos dos archivos temporales, donde se reflejarán los cambios
		ofstream modifyRegister;
		modifyRegister.open("factura\\temp_registro.txt", ios::out);

		ofstream modifyHistory;
		modifyHistory.open("factura\\temp_historial.txt", ios::out);

		// Se verifica si ambos fueron creados correctamente
		if (!(modifyRegister.is_open() || modifyHistory.is_open())) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		string lineReg, lineHist; // Declaramos dos variables que leeran cada línea de los archivos especificados
		
		// Variables para el archivo "Registro de facturas.txt" e "Historial de facturas.txt"
		string codeFac, codeFac2;

		// Recorremos el archivo de "Registro de facturas.txt"
		while (getline(registeredBills, lineReg)) {
			// Se separa cada campo según el delimitador usado (en este caso '|')
			stringstream ssReg(lineReg);
			getline(ssReg, codeFac, '|');

			// Si el número de la factura anulada es igual a la contenida en la línea del registro...
			if (nFact == codeFac) {
				// Devolvemos la cantidad dada por el producto al inventario
				actualizarInventario(nFact, true);
				MessageBox::Show("Se han devuelto las mercancías vendidas de la factura anulada", "Inventario actualizado", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				// Copiamos la línea tal y como está en el archivo temporal
				modifyRegister << lineReg << endl;
			}
		}

		// También se recorre el archivo de "Historial de facturas.txt"
		while (getline(billHistory, lineHist)) {
			stringstream ssHist(lineHist);
			getline(ssHist, codeFac2, '|');

			// Si el número de la factura anulada es diferente a la contenida en la línea del historial...
			if (nFact != codeFac2) {
				// Simplemente copiamos la línea en el archivo temporal
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

	// Función que retorna la fecha local del ordenador, a fin de especificar el tiempo en el que se realizó la factura
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

	// Función que retorna la hora local del ordenador, a fin de especificar el tiempo en el que se realizó la factura
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

	/* Función que regresa el valor total de las ventas obtenidas a través del monto...
	...de las facturas efectuadas*/
	inline double obtener_valorVentas() {
		// Se abre el archivo de historial de facturas en formato de lectura
		ifstream file;
		file.open("factura\\Historial de facturas.txt");

		string line;
		// Variables que obtendrán el valor de cada campo del archivo de historial de facturas
		string nFact, fEmit, client, cashier, payMethod, subTotal, total_wIVA;
		double totalSales = 0.00; // Declaramos una variable que obtendrá el valor de lo registrado en factura
		while (getline(file, line)) {
			// Se separa campo según el delimitador usado (en este caso '|')
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