#pragma once
#pragma warning(disable : 4244)
#include <list>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

namespace archivoProducto {

	// Función que permite crear o abrir un archivo de texto, en el cual se almacenen registros de productos
	inline void registrarProducto(string code, string group, string desc, string uMedida, float exist,
		float mExist, string ubic, float pUnit, string fExp) {

		ofstream file;
		file.open("productos\\Registro de productos.txt", ios::app);// Se abre el archivo en modo de agregar al final

		//Se agregan los datos enviados hacia el archivo
		file << code << "|" << group << "|" << desc << "|" << uMedida << "|" << exist << "|" << mExist << "|"
			<< ubic << "|" << pUnit << "|" << fExp << endl;

		//Se cierra el archivo
		file.close();
	}

	// Función que cuenta el número de productos de un grupo dado en un archivo
	inline int numProduct(string filename, string group) {
		int cont = 0;
		ifstream file;
		file.open(filename, ios::in); //Se abre el archivo en forma de lectura

		list<string> lines; //Se crea una lista que almacenará cada línea del archivo
		string line;

		//Se lee una línea entera del archivo y se agrega a la lista
		while (getline(file, line)) {
			lines.push_back(line);
		}

		//Se recorren las líneas almacenadas en las lista
		for (auto it = lines.begin(); it != lines.end(); ++it) {
			size_t pos = it->find("|" + group + "|"); //Se busca la subcadena <<,group,>> en el archivo
			if (pos != string::npos) { //Si pos es igual a npos significa que no se encontró el grupo en la línea actual
				cont++; //Caso contrario, se sumará +1 para indicar la presencia de un producto registrado en el grupo
			}
		}
		file.close();

		return cont; //Se devuelve el número (no sus existencias en general)...
		//...de productos almacenados en el grupo
	}

	/* Función que inserta los datos del archivo.txt a un componente de tipo dataGridView, el cual permite
	   su correcta visualización*/
	inline void mostrarProductos(DataGridView^ dgv_products) {
		try {
			string filename = "productos\\Registro de productos.txt";

			// Crear una tabla con las columnas correspondientes
			System::Data::DataTable^ table = gcnew System::Data::DataTable();
			table->Clear();
			table->Columns->Add("Código", String::typeid);
			table->Columns->Add("Grupo", String::typeid);
			table->Columns->Add("Descripción", String::typeid);
			table->Columns->Add("U. Medida", String::typeid);
			table->Columns->Add("Existencias", float::typeid);
			table->Columns->Add("Exist. min.", float::typeid);
			table->Columns->Add("Ubicación", String::typeid);
			table->Columns->Add("Precio unit.", float::typeid);
			table->Columns->Add("F. Exp", String::typeid);

			// Lista bidimensional que se encargará de llenar cada celda de la tabla
			list<list<string>> datos;

			// Se abre el archivo donde están registrados los productos
			ifstream file;
			file.open(filename, ios::in);

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

				// Cerrar el archivo después de leer los datos
				file.close();

				// Llenar la tabla con los datos de la lista bidimensional
				for (auto it = datos.begin(); it != datos.end(); ++it) {
					// Crear una fila para la tabla
					System::Data::DataRow^ fila = table->NewRow();

					// Agregar los datos de la lista a la fila
					int i = 0;
					for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
						if (i == 4 || i == 5) {
							// Convertir los campos de existencias y precios a entero
							float valor = std::stof(*it2);
							fila[i] = valor;
						}
						else if (i == 7) {
							// Convertir el campo de precio unitario a flotante
							float valor = std::stof(*it2);
							fila[i] = valor;
						}
						else {
							// Agregar los campos de texto tal cual
							System::String^ valor = gcnew System::String((*it2).c_str());
							fila[i] = valor;
						}
						++i;
					}

					// Agregar la fila a la tabla
					table->Rows->Add(fila);
				}
				// Asignar la tabla como fuente de datos del DataGridView
				dgv_products->DataSource = table;
			}
		}
		catch (const std::exception& e) {
			MessageBox::Show("Ocurrió un error al mostrar los productos: " + gcnew System::String(e.what()));
		}
	}

	// Función que permite buscar un producto cualquiera en base a lo contenido en el datagridview
	inline void buscarProducto(DataGridView^ dgv, String^ search, bool% found, String^% codeProduct, String^% groupProduct, String^% descProduct, String^% uMeasureProduct,
		String^% existProduct, String^% existMinProduct, String^% ubicProduct, String^% pUnitProduct, String^% fExpProduct) {

		/* Como se puede observar en el pase de parámetros en la función, se utiliza "%" (puntero de seguimiento)...
		   ...como derivado de "&" (referencia), ya que se trabaja con tipos de variable distintas. En este caso, String^...
		   ...es un tipo de referencia a un objeto de tipo System::String.*/

		found = false; // Se inicia la variable como falsa
		for (int i = 0; i < dgv->RowCount; i++) {
			// Se busca el producto en base al código
			DataGridViewCell^ codeCell = dgv->Rows[i]->Cells["Código"];
			/* Se realiza esta condición ya que si el producto buscado no se encuentra en la tabla,...
			...la variable tomaría un valor nulo y por ende resultaría en una excepción en el programa.*/
			String^ code = (codeCell->Value != nullptr) ? codeCell->Value->ToString() : String::Empty;

			//Se busca el producto en base a la descripción escrita en el buscador
			DataGridViewCell^ descCell = dgv->Rows[i]->Cells["Descripción"];
			String^ description = (descCell->Value != nullptr) ? descCell->Value->ToString() : String::Empty;

			/* En caso de que el código o la descripción coincidan con el término de búsqueda, ...
			...se extraen todos los datos para su posible modificación*/
			if (code->ToLower()->Contains(search->ToLower()) || description->ToLower()->Contains(search->ToLower())) {
				dgv->ClearSelection();
				found = true; // El producto fue encontrado, se le da un valor de verdadero a la variable
				// Se selecciona la fila correspondiente
				dgv->Rows[i]->Selected = true;
				dgv->CurrentCell = dgv->Rows[i]->Cells[0];
				// Nos ubicamos en donde se encuentra el producto
				dgv->FirstDisplayedScrollingRowIndex = i;

				// Extraemos la información del producto por cada campo
				codeProduct = dgv->Rows[i]->Cells["Código"]->Value->ToString();
				groupProduct = dgv->Rows[i]->Cells["Grupo"]->Value->ToString();
				descProduct = dgv->Rows[i]->Cells["Descripción"]->Value->ToString();
				uMeasureProduct = dgv->Rows[i]->Cells["U. Medida"]->Value->ToString();
				existProduct = dgv->Rows[i]->Cells["Existencias"]->Value->ToString();
				existMinProduct = dgv->Rows[i]->Cells["Exist. min."]->Value->ToString();
				ubicProduct = dgv->Rows[i]->Cells["Ubicación"]->Value->ToString();
				pUnitProduct = dgv->Rows[i]->Cells["Precio unit."]->Value->ToString();
				fExpProduct = dgv->Rows[i]->Cells["F. Exp"]->Value->ToString();

				// El producto ya fue encontrado, no es necesario seguir con la búsqueda
				break;
			}
		}
		if (!found) {
			MessageBox::Show("El producto buscado no se encuentra en el registro.", "Producto no encontrado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	// Función que modifica los datos de un producto seleccionado del datagridview, actualizando el archivo de texto en su proceso
	inline void modificarProducto(string searchedCode, string searchedGroup, string newdesc, string new_uMeasure, string new_exist, string new_minExist,
		string newubic, string new_pUnit, string new_fExp) {
		// Abrimos el archivo donde se encuentran registrados los productos
		ifstream inputFile;
		inputFile.open("productos\\Registro de productos.txt", ios::in);

		if (!inputFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos el archivo temporal para escribir en él
		ofstream outputFile;
		outputFile.open("productos\\temp.txt", ios::out);

		if (!outputFile.is_open()) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		string line;
		// Se declaran variables que luego le serán dadas sus nuevos valores
		string code_infile, group_infile, desc_infile, uMeasure_infile, exist_infile, minExist_infile, ubic_infile, pUnit_infile, fExp_infile;

		bool found = false;

		while (getline(inputFile, line)) {
			// Se separa cada campo según el delimitador usado (en este caso "|")
			stringstream ss(line);
			getline(ss, code_infile, '|');
			getline(ss, group_infile, '|');
			getline(ss, desc_infile, '|');
			getline(ss, uMeasure_infile, '|');
			getline(ss, exist_infile, '|');
			getline(ss, minExist_infile, '|');
			getline(ss, ubic_infile, '|');
			getline(ss, pUnit_infile, '|');
			getline(ss, fExp_infile);

			// Se verifica si la línea actual coincide con los campos buscados
			if (code_infile == searchedCode && group_infile == searchedGroup) {
				found = true;
				// Actualizar los campos correspondientes con los nuevos valores
				desc_infile = newdesc;
				uMeasure_infile = new_uMeasure;
				exist_infile = new_exist;
				minExist_infile = new_minExist;
				ubic_infile = newubic;
				pUnit_infile = new_pUnit;
				fExp_infile = new_fExp;

				// Escribimos la línea modificada en el archivo temporal
				stringstream ss;
				ss << code_infile << "|" << group_infile << "|" << desc_infile << "|" << uMeasure_infile << "|" << exist_infile << "|"
					<< minExist_infile << "|" << ubic_infile << "|" << pUnit_infile << "|" << fExp_infile << endl;
				string nuevaLinea = ss.str();
				outputFile << nuevaLinea;
			}
			else {
				// Copiamos la línea original tal como está en el archivo temporal
				outputFile << line << endl;
			}
		}

		if (found) {
			MessageBox::Show("Producto modificado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("El producto que se intentó modificar no existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		// Cerramos ambos archivos
		inputFile.close();
		outputFile.close();

		//Eliminamos el archivo original
		if (remove("productos\\Registro de productos.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("productos\\temp.txt", "productos\\Registro de productos.txt") != 0) {
			MessageBox::Show("El producto que se intentó modificar no existe.");
		}
	}

	// Función que elimina un producto seleccionado del datagridview y actualiza el archivo de texto
	inline void eliminarProducto(string searchedCode, string searchedGroup) {
		// Abrimos el archivo donde se encuentran registrados los productos
		ifstream inputFile;
		inputFile.open("productos\\Registro de productos.txt", ios::in);

		if (!inputFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos el archivo temporal para escribir en él
		ofstream outputFile;
		outputFile.open("productos\\temp.txt", ios::out);

		if (!outputFile.is_open()) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		String^ desc; // Variable que mostrará la descripcion del producto eliminado
		string line;
		string code_infile, group_infile, desc_infile, uMeasure_infile, exist_infile, minExist_infile, ubic_infile, pUnit_infile, fExp_infile;

		bool found = false;

		while (getline(inputFile, line)) {
			// Se separa cada campo según el delimitador usado (en este caso "|")
			stringstream ss(line);
			getline(ss, code_infile, '|');
			getline(ss, group_infile, '|');
			getline(ss, desc_infile, '|');
			getline(ss, uMeasure_infile, '|');
			getline(ss, exist_infile, '|');
			getline(ss, minExist_infile, '|');
			getline(ss, ubic_infile, '|');
			getline(ss, pUnit_infile, '|');
			getline(ss, fExp_infile);

			// Se verifica si la línea actual coincide con los campos buscados
			if (code_infile == searchedCode && group_infile == searchedGroup) {
				desc = gcnew String(desc_infile.c_str());
				found = true;
				continue; // Salta la escritura de la línea en el archivo temporal
			}

			// Copiamos la línea original tal como está en el archivo temporal
			outputFile << line << endl;
		}

		if (found) {
			MessageBox::Show("El producto <<" + desc + ">> ha sido eliminado exitosamente", "Eliminado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("El producto que se intentó eliminar no existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		// Cerramos ambos archivos
		inputFile.close();
		outputFile.close();

		//Eliminamos el archivo original
		if (remove("productos\\Registro de productos.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("productos\\temp.txt", "productos\\Registro de productos.txt") != 0) {
			MessageBox::Show("No se puede renombrar el archivo temporal.");
		}
	}

	// Función que permite realizar una búsqueda de un producto por código, extrayendo datos esenciales para la facturación
	inline void buscarProductos_porCodigo(string searchedCode, string% desc, string% uMeasure, string% exist,
		string% pUnit) {

		// Se abre el archivo donde están registrados los productos en modo de lectura
		ifstream file;
		file.open("productos\\Registro de productos.txt", ios::in);

		bool found = false;

		string line;
		// Variables que permitirán extraer la información según el campo especificado
		string code_inFile, group_inFile, desc_inFile, uMeasure_inFile, exis_inFile, emin_inFile, ubic_inFile, pUnit_inFile, fExp_inFile;

		// Se lee lo contenido del archivo línea por línea
		while (getline(file, line)) {
			// Se separa campo según el delimitador usado (en este caso '|')
			stringstream ss(line);

			getline(ss, code_inFile, '|');
			getline(ss, group_inFile, '|');
			getline(ss, desc_inFile, '|');
			getline(ss, uMeasure_inFile, '|');
			getline(ss, exis_inFile, '|');
			getline(ss, emin_inFile, '|');
			getline(ss, ubic_inFile, '|');
			getline(ss, pUnit_inFile, '|');
			getline(ss, fExp_inFile);

			if (searchedCode == code_inFile) {
				desc = desc_inFile;
				uMeasure = uMeasure_inFile;
				exist = exis_inFile;
				pUnit = pUnit_inFile;
				found = true;
				break; // Como ya encontramos el código, no es necesario continuar con la búsqueda
			}
		}

		// En caso de no encontrar el código, se muestra un mensaje de excepción
		if (!found) {
			MessageBox::Show("Código no encontrado", "Búsqueda", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	/* Función que permite agregar existencias al inventario de un producto en específico, además de...
	...verificar sus precios unitarios y generando alertas si es necesario */
	inline void realizarCompras(string fEmit, string hEmit,
		string codeProd, float purchasedStocks, float acqPrice, float totalPayment) {
		// Abrimos el archivo donde se encuentran registrados los productos
		ifstream inputFile;
		inputFile.open("productos\\Registro de productos.txt", ios::in);

		if (!inputFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos el archivo temporal para escribir en él
		ofstream outputFile;
		outputFile.open("productos\\temp.txt", ios::out);

		if (!outputFile.is_open()) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		string line;
		// Se declaran variables que luego le serán dadas sus nuevos valores
		string code_infile, group_infile, desc_infile, uMeasure_infile, exist_infile, minExist_infile, ubic_infile, pUnit_infile, fExp_infile;

		while (getline(inputFile, line)) {
			// Se separa cada campo según el delimitador usado (en este caso "|")
			stringstream ss(line);
			getline(ss, code_infile, '|');
			getline(ss, group_infile, '|');
			getline(ss, desc_infile, '|');
			getline(ss, uMeasure_infile, '|');
			getline(ss, exist_infile, '|');
			getline(ss, minExist_infile, '|');
			getline(ss, ubic_infile, '|');
			getline(ss, pUnit_infile, '|');
			getline(ss, fExp_infile);

			// Se verifica si la línea actual coincide con los campos que se buscan.
			if (code_infile == codeProd)
			{
				// Convertimos a flotante el número de 
				float totalPurchased = stof(exist_infile);

				// Se realiza la suma de existencias al inventario
				float new_exist = totalPurchased + purchasedStocks;

				// Escribimos la línea modificada en el archivo temporal
				stringstream ss;
				ss << code_infile << "|" << group_infile << "|" << desc_infile << "|" << uMeasure_infile << "|" << new_exist << "|"
					<< minExist_infile << "|" << ubic_infile << "|" << pUnit_infile << "|" << fExp_infile << endl;
				string nuevaLinea = ss.str();
				outputFile << nuevaLinea;

				/* Ahora, dentro de esta condición, almacenamos diversos campos de la compra...,
				...a fin de realizar un historial de las mismas*/
				ofstream purchaseHistory;
				purchaseHistory.open("productos\\Historial de compras.txt", ios::app);

				purchaseHistory << fEmit << "|" << hEmit << "|" << codeProd << "|"
					<< desc_infile << "|" << purchasedStocks << "|"
					<< uMeasure_infile << "|" << acqPrice << "|" << totalPayment << endl;

				purchaseHistory.close();
			}
			else {
				// Copiamos la línea original tal como está en el archivo temporal
				outputFile << line << endl;
			}
		}

		// Cerramos ambos archivos
		inputFile.close();
		outputFile.close();

		//Eliminamos el archivo original
		if (remove("productos\\Registro de productos.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("productos\\temp.txt", "productos\\Registro de productos.txt") != 0) {
			MessageBox::Show("El producto que se intentó modificar no existe.");
		}
	}

	/* Función que permite verificar el precio de un producto comprado por el registrado en el inventrario...
	...generando una alerta si el precio es mayor o menor. */
	inline void verificar_precioCompras(string code, string desc, float unitPrice) {
		ifstream inputFile;
		inputFile.open("productos\\Registro de productos.txt", ios::in);

		if (!inputFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos el archivo temporal para escribir en él
		ofstream outputFile;
		outputFile.open("productos\\temp.txt", ios::out);

		if (!outputFile.is_open()) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		string line;
		// Se declaran variables que luego le serán dadas sus nuevos valores
		string code_infile, group_infile, desc_infile, uMeasure_infile, exist_infile, minExist_infile, ubic_infile, pUnit_infile, fExp_infile;

		/* Verificamos si el código del producto comprado coincide con el código registrado...
		...y si su precio en compra es mayor que en inventario */
		while (getline(inputFile, line)) {
			// Se separa cada campo según el delimitador usado (en este caso "|")
			stringstream ss(line);
			getline(ss, code_infile, '|');
			getline(ss, group_infile, '|');
			getline(ss, desc_infile, '|');
			getline(ss, uMeasure_infile, '|');
			getline(ss, exist_infile, '|');
			getline(ss, minExist_infile, '|');
			getline(ss, ubic_infile, '|');
			getline(ss, pUnit_infile, '|');
			getline(ss, fExp_infile);

			// Se verifica si la línea actual coincide con los campos buscados
			if (code_infile == code && unitPrice > stod(pUnit_infile)) {
				string Message = "El precio unitario en registro para <<" + desc + ">> es de C$" + pUnit_infile +
					". Para evitar posibles pérdidas, se ajustó el valor registrado en inventario al último en compra";

				MessageBox::Show(gcnew String(Message.c_str()), "Discrepancia de precios", MessageBoxButtons::OK, MessageBoxIcon::Information);
				// Actualizar los campos correspondientes con los nuevos valores
				pUnit_infile = to_string(unitPrice);

				// Escribimos la línea modificada en el archivo temporal
				stringstream ss;
				ss << code_infile << "|" << group_infile << "|" << desc_infile << "|" << uMeasure_infile << "|" << exist_infile << "|"
					<< minExist_infile << "|" << ubic_infile << "|" << pUnit_infile << "|" << fExp_infile << endl;
				string nuevaLinea = ss.str();
				outputFile << nuevaLinea;
			}
			else {
				// Copiamos la línea original tal como está en el archivo temporal
				outputFile << line << endl;
			}
		}

		// Cerramos ambos archivos
		inputFile.close();
		outputFile.close();

		//Eliminamos el archivo original
		if (remove("productos\\Registro de productos.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("productos\\temp.txt", "productos\\Registro de productos.txt") != 0) {
			MessageBox::Show("No se puede renombrar el archivo temporal.");
		}
	}
	// Función que permite rellenar un control de tipo comboBox en base a elementos en archivos de texto
	inline void mostrarGrupos(ComboBox^ comboBox) {
		// Se abre el archivo en modo de lectura
		ifstream infile;
		infile.open("grupos\\Registro de grupos.txt");

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

	/* Función que retorna la fecha local del ordenador, a fin de especificar el tiempo de diferencia...
	...en alertas*/
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
		ss << setw(2) << setfill('0') << dia << "/"
			<< setw(2) << setfill('0') << mes << "/"
			<< setw(2) << setfill('0') << anio;

		return ss.str();
	}

	/* Función que permite enviar mensajes de alerta que incluyen información relacionada a un...
	...producto, en torno a la proximidad de una fecha de expiración o cuando la cantidad de...
	...existencias es menor o igual a la cantidad mínima especificada*/
	inline void notificarAlertas(int% totalAlertas, bool verifyPrice) {
		// Removemos el archivo de alertas antes de verificar de nuevo, en caso de haberse realizado cambios en el proceso
		remove("avisos\\Registro de alertas.txt");

		// Creamos un archivo en modo de escritura y con el mismo nombre que permitirá agregar alertas actualizadas
		ofstream file;
		file.open("avisos\\Registro de alertas.txt", ios::app);

		string line;
		// Variables que permitirán extraer la información según el campo especificado
		string code_inFile, group_inFile, desc_inFile, uMeasure_inFile, exis_inFile, emin_inFile, ubic_inFile, pUnit_inFile, fExp_inFile;

		ifstream registeredProds;
		registeredProds.open("productos\\Registro de productos.txt", ios::in);

		// Obtenemos la fecha actual
		string fActual = obtenerFecha();

		while (getline(registeredProds, line)) {
			// Se separa campo según el delimitador usado (en este caso '|')
			stringstream ss(line);

			getline(ss, code_inFile, '|');
			getline(ss, group_inFile, '|');
			getline(ss, desc_inFile, '|');
			getline(ss, uMeasure_inFile, '|');
			getline(ss, exis_inFile, '|');
			getline(ss, emin_inFile, '|');
			getline(ss, ubic_inFile, '|');
			getline(ss, pUnit_inFile, '|');
			getline(ss, fExp_inFile);

			// Verificamos la cantidad de existencias y existencias mínimas
			if (stod(exis_inFile) <= stod(emin_inFile)) {
				// Se guarda el posible mensaje de alerta en una variable de tipo string
				string alertMessage = "Un producto alcanzó la cantidad de existencias mínimas|El producto <<" 
					+ desc_inFile + ">> tiene una cantidad actual de <<" + exis_inFile + " " + uMeasure_inFile + 
					">>, llegando al rango de existencias mínimas requeridas <<" + emin_inFile + " " + uMeasure_inFile + 
					">>. Le recomendamos su obtención de más cantidades, a fin de cumplir con lo establecido.";

				file << alertMessage << endl;
			}

			// Verificamos el precio unitario contra las cantidades en compra realizadas
			if (verifyPrice) {
				//verificar_precioCompras(code_inFile, desc_inFile, stod(pUnit_inFile));
			}

			// En caso de que no sea un campo vacío, comprobamos la fecha
			if (fExp_inFile != "-") {
				stringstream date(fExp_inFile);
				stringstream actualDate(fActual);
				string separate;

				// Fecha de expiración separada por campos:
				getline(date, separate, '/');
				int fExp_Day = stoi(separate);
				getline(date, separate, '/');
				int fExp_Month = stoi(separate);
				getline(date, separate);
				int fExp_Year = stoi(separate);

				// Fecha actual separada por campos:
				getline(actualDate, separate, '/');
				int actualDay = stoi(separate);
				getline(actualDate, separate, '/');
				int actualMonth = stoi(separate);
				getline(actualDate, separate);
				int actualYear = stoi(separate);

				// Se crea una estructura de tiempo con los datos dados
				tm fExp_Date = { 0, 0, 0, fExp_Day, fExp_Month - 1, fExp_Year - 1900 };
				tm actual_Date = { 0, 0, 0, actualDay, actualMonth - 1, actualYear - 1900 };

				// Convertimos las estructuras de tiempo a tiempos de calendario
				time_t fExp_Time = mktime(&fExp_Date);
				time_t actualTime = mktime(&actual_Date);

				// Se calcula la diferencia entre las dos fechas en segundos
				time_t difference = fExp_Time - actualTime;
				// Calculamos la cantidad de días entre las dos fechas
				int secCant = 60 * 60 * 24; // Esto indica la cantidad de segundos en un día
				int days = difference / secCant;
				if (days <= 0) {
					// El producto ha expirado
					string alertMessage = "Producto expirado|El producto << " 
						+ desc_inFile + " >> ha expirado desde hace " +
						to_string(-1 * days) + " días. Por favor, tome las medidas necesarias.";

					file << alertMessage;
					totalAlertas++;
				}
				else if (days <= 7) {
					// El producto está próximo a expirar en menos de 7 días
					string alertMessage = "Producto cercano a expirar|El producto <<"
						+ desc_inFile + ">> está próximo a expirar en " + to_string(days)
						+ " días. Por favor, tome las medidas necesarias.";

					file << alertMessage;
					totalAlertas++;
				}
			}
		}

		// Cerramos los archivos
		registeredProds.close();
		file.close();
	}

	// Función que permite mostrar las alertas en un textbox
	inline void mostrarAlertas(RichTextBox^ richTextBox) {

		// Se abre el archivo de registro de alertas en modo lectura
		ifstream file;
		file.open("avisos\\Registro de alertas.txt");

		if (!file.is_open()) { // Verificamos si el archivo no se pudo abrir correctamente
			MessageBox::Show("Error al abrir el archivo");
			return;
		} // En caso de que el archivo esté vacío, mostramos el siguiente texto
		else if (file.peek() == ifstream::traits_type::eof()) {
			richTextBox->SelectionFont = gcnew System::Drawing::Font(richTextBox->Font, System::Drawing::FontStyle::Bold);
			richTextBox->AppendText("\n\n\n\n\n\n\n\n\n\n\t\t\t\tPor este momento, no hay avisos que mostrar.");
		}

		// Leemos el contenido del archivo línea por línea
		string line;
		string title, description;
		while (getline(file, line)) {
			stringstream ss(line);
			getline(ss, title, '|');
			getline(ss, description);

			// Convertimos la línea a formato de System::String y la agregamos al contenido
			String^ txtTitle = gcnew String(title.c_str());
			String^ txtDesc = gcnew String(description.c_str());

			// Agregamos el título con un estilo de fuente diferente
			richTextBox->SelectionFont = gcnew System::Drawing::Font(richTextBox->Font, System::Drawing::FontStyle::Bold);
			richTextBox->AppendText(gcnew String(title.c_str()) + "\n\n");

			// Agregamos la descripción con el estilo de fuente predeterminado
			richTextBox->SelectionFont = richTextBox->Font;
			richTextBox->AppendText(gcnew String(description.c_str()) + "\n");
			
			richTextBox->SelectionFont = richTextBox->Font;
			richTextBox->AppendText("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		}

		// Cerramos el archivo
		file.close();
	}

	/* Función que regresa el valor monetario que el inventario tiene; es decir,...
	...todas sus existencias, multiplicadas por sus precios unitarios.*/
	inline double obtener_valorInventario() {
		// Se abre en formato de lectura el archivo donde están registrados los productos
		ifstream file;
		file.open("productos\\Registro de productos.txt");

		string line;
		// Variables que permitirán extraer la información según el campo especificado
		string code_inFile, group_inFile, desc_inFile, uMeasure_inFile, exis_inFile, emin_inFile, ubic_inFile, pUnit_inFile, fExp_inFile;
		double totalValue = 0.00; // Declaramos una variable que contendrá el valor del inventario
		while (getline(file, line)) {
			// Se separa campo según el delimitador usado (en este caso '|')
			stringstream ss(line);

			getline(ss, code_inFile, '|');
			getline(ss, group_inFile, '|');
			getline(ss, desc_inFile, '|');
			getline(ss, uMeasure_inFile, '|');
			getline(ss, exis_inFile, '|');
			getline(ss, emin_inFile, '|');
			getline(ss, ubic_inFile, '|');
			getline(ss, pUnit_inFile, '|');
			getline(ss, fExp_inFile);

			// Se realiza la siguiente operación:
			totalValue += (stod(exis_inFile) * stod(pUnit_inFile));
		}
		
		// Cerramos el archivo
		file.close();
		
		return totalValue; // Retornamos el valor obtenido del inventario
	}

	/* Función que regresa el valor total de las inversiones hacia el inventario; es decir,...
	...todo el saldo de las compras realizadas a favor de un producto ya registrado*/
	inline double obtener_valorInvertido() {
		//Se abre el archivo donde se almacena el historial de compras en formato de lectura
		ifstream file;
		file.open("productos\\Historial de compras.txt");

		string line;
		// Variables que obtendrán el valor de cada campo del archivo de historial de compras
		string date_inFile, hour_inFile, code_inFile, desc_inFile, cant_inFile, uM_inFile, unitPrice, totalPayment;
		double totalInvestments = 0.00; // Declaramos una variable que contendrá el monto invertido
		while (getline(file, line)) {
			// Se separa campo según el delimitador usado (en este caso '|')
			stringstream ss(line);

			getline(ss, date_inFile, '|');
			getline(ss, hour_inFile, '|');
			getline(ss, code_inFile, '|');
			getline(ss, desc_inFile, '|');
			getline(ss, cant_inFile, '|');
			getline(ss, uM_inFile, '|');
			getline(ss, unitPrice, '|');
			getline(ss, totalPayment);

			// Sumamos el total de cada compra:
			totalInvestments += stod(totalPayment);
		}

		// Cerramos el archivo
		file.close();

		return totalInvestments; // Retornamos las inversiones obtenidas por las compras
	}
}