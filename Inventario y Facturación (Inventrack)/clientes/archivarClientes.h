#pragma once
#include <list>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

namespace archivoCliente{
	//Funci�n que permite agregar los datos de un cliente a un archivo de texto
	inline void registrarCliente(string ID, string telNumb, string names, string surnames) {

		ofstream file;
		file.open("clientes\\Registro de clientes.txt", ios::app); //Se abre el archivo en modo de agregar al final

		//Se agregan los datos enviados hacia el archivo
		file << ID << "|" << telNumb << "|" << names << "|" << surnames << endl;

		//Se cierra el archivo
		file.close();
	}

	// Funci�n que permite mostrar los registros de archivos de texto en un datagridview
	inline void mostrarClientes(DataGridView^ dgv_clients) {
		try {
			string filepath = "clientes\\Registro de clientes.txt";

			// Crear una tabla con las columnas correspondientes
			System::Data::DataTable^ table = gcnew System::Data::DataTable();
			table->Clear();
			table->Columns->Add("C�dula", String::typeid);
			table->Columns->Add("Tel�fono", String::typeid);
			table->Columns->Add("Nombres", String::typeid);
			table->Columns->Add("Apellidos", String::typeid);

			// Lista bidimensional que se encargar� de llenar cada celda de la tabla
			list<list<string>> datos;

			// Se abre el archivo donde est�n registrados los clientes
			ifstream file;
			file.open(filepath, ios::in);

			if (!file.is_open()) {
				MessageBox::Show("No se puede mostrar la tabla de registro.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else {

				// Se leen los datos del archivo l�nea por l�nea
				string line;
				while (getline(file, line)) {
					// Se crea una lista que almacenar� los datos de una l�nea
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

				// Cerrar el archivo despu�s de leer los datos
				file.close();

				// Llenar la tabla con los datos de la lista bidimensional
				for (auto it = datos.begin(); it != datos.end(); ++it) {
					// Crear una fila para la tabla
					System::Data::DataRow^ fila = table->NewRow();

					// Agregar los datos de la lista a la fila
					int i = 0;
					for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
						// Agregar los campos de texto tal cual
						System::String^ valor = gcnew System::String((*it2).c_str());
						fila[i] = valor;
						i++;
					}

					// Agregar la fila a la tabla
					table->Rows->Add(fila);
				}
				// Asignar la tabla como fuente de datos del datagridview
				dgv_clients->DataSource = table;
			}
		}
		catch (const std::exception& e) {
			MessageBox::Show("Ocurri� un error al mostrar los clientes: " + gcnew System::String(e.what()));
		}
	}

	// Funci�n que permite buscar un producto cualquiera en base a lo contenido en el datagridview
	inline void buscarCliente(DataGridView^ dgv, String^ search, bool% found, String^% IDClient, String^% telClient, String^% namesClient,
							   String^% surnamesClient){
		/* Como se puede observar en el pase de par�metros en la funci�n, se utiliza "%" (puntero de seguimiento)... 
		   ...como derivado de "&" (referencia), ya que se trabaja con tipos de variable distintas. En este caso, String^...
		   ...es un tipo de referencia a un objeto de tipo System::String.*/

		found = false; // Se inicia la variable como falsa
		for (int i = 0; i < dgv->RowCount; i++) {
			//Se busca el cliente en base al n�mero de c�dula ingresada en el buscador
			DataGridViewCell^ cell = dgv->Rows[i]->Cells["C�dula"];
			/* Se realiza esta condici�n ya que si el proveedor buscado no se encuentra en la tabla, la variable tomar�a un valor nulo
               y por ende resultar�a en una excepci�n en el programa.*/
			String^ nClient = (cell->Value != nullptr) ? cell->Value->ToString() : String::Empty;

			//En caso de que se haya encontrado la ID del cliente, se extraen todos los datos para su posible modificaci�n
			if (nClient->ToLower()->Contains(search->ToLower())) {
				dgv->ClearSelection();
				found = true; // El cliente fue encontrado, se le da un valor de verdadero a la variable
				// Se selecciona la fila correspondiente
				dgv->Rows[i]->Selected = true;
				dgv->CurrentCell = dgv->Rows[i]->Cells[0];
				// Nos ubicamos en donde se encuentra el cliente
				dgv->FirstDisplayedScrollingRowIndex = i;

				// Extraemos la informaci�n del cliente por cada campo
				IDClient = dgv->Rows[i]->Cells["C�dula"]->Value->ToString();
				telClient = dgv->Rows[i]->Cells["Tel�fono"]->Value->ToString();
				namesClient = dgv->Rows[i]->Cells["Nombres"]->Value->ToString();
				surnamesClient = dgv->Rows[i]->Cells["Apellidos"]->Value->ToString();

				// El cliente ya fue encontrado, no es necesario seguir con la b�squeda
				break;
			}
		}
		if (!found) {
			MessageBox::Show("La c�dula del cliente buscado no se encuentra en el registro.", "Producto no encontrado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	// Funci�n que modifica los datos de un cliente seleccionado del datagridview, actualizando el archivo de texto en su proceso
	inline void modificarClientes(string searchedID, string new_IDClient, string new_telClient, string new_namesClient, string new_surnamesClient) {
		// Abrimos el archivo donde se encuentran registrados los clientes
		ifstream inputFile;
		inputFile.open("clientes\\Registro de clientes.txt", ios::in);

		if (!inputFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos el archivo temporal para escribir en �l
		ofstream outputFile;
		outputFile.open("clientes\\temp.txt", ios::out);

		if (!outputFile.is_open()) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		string line;
		// Se declaran variables que luego le ser�n dadas sus nuevos valores
		string IDClient_infile, telClient_infile, namesClient_infile, surnamesClient_infile;

		bool found = false;

		while (getline(inputFile, line)) {
			// Se separa cada campo seg�n el delimitador usado (en este caso "|")
			stringstream ss(line);
			getline(ss, IDClient_infile, '|');
			getline(ss, telClient_infile, '|');
			getline(ss, namesClient_infile, '|');
			getline(ss, surnamesClient_infile, '|');

			// Se verifica si la l�nea actual coincide con el campo buscado
			if (searchedID == IDClient_infile) {
				found = true;
				// Actualizar los campos correspondientes con los nuevos valores
				IDClient_infile = new_IDClient;
				telClient_infile = new_telClient;
				namesClient_infile = new_namesClient;
				surnamesClient_infile = new_surnamesClient;

				// Escribimos la l�nea modificada en el archivo temporal
				stringstream ss;
				ss << IDClient_infile << "|" << telClient_infile << "|" << namesClient_infile << "|" << surnamesClient_infile << endl;
				string nuevaLinea = ss.str();
				outputFile << nuevaLinea;
			}
			else {
				// Copiamos la l�nea original tal como est� en el archivo temporal
				outputFile << line << endl;
			}
		}

		if (found) {
			MessageBox::Show("Cliente modificado exitosamente.", "�xito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("El cliente que se intent� modificar no existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		// Cerramos ambos archivos
		inputFile.close();
		outputFile.close();

		//Eliminamos el archivo original
		if (remove("clientes\\Registro de clientes.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("clientes\\temp.txt", "clientes\\Registro de clientes.txt") != 0) {
			MessageBox::Show("No se pudo renombrar el archivo auxiliar.");
		}
	}

	// Funci�n que modifica los datos de un cliente seleccionado del datagridview, actualizando el archivo de texto en su proceso
	inline void eliminarClientes(string searchedIDClient) {
		// Abrimos el archivo donde se encuentran registrados los clientes
		ifstream inputFile;
		inputFile.open("clientes\\Registro de clientes.txt", ios::in);

		if (!inputFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos el archivo temporal para escribir en �l
		ofstream outputFile;
		outputFile.open("clientes\\temp.txt", ios::out);

		if (!outputFile.is_open()) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		String^ ID; // Variable que mostrar� la descripcion del producto eliminado
		string line;
		bool found = false;
		string IDClient_infile, telClient_infile, namesClient_infile, surnamesClient_infile;

		while (getline(inputFile, line)) {
			// Se separa cada campo seg�n el delimitador usado (en este caso "|")
			stringstream ss(line);
			// Actualizar los campos correspondientes con los nuevos valores
			getline(ss, IDClient_infile, '|');
			getline(ss, telClient_infile, '|');
			getline(ss, namesClient_infile, '|');
			getline(ss, surnamesClient_infile, '|');

			// Se verifica si la l�nea actual coincide con los campos buscados
			if (IDClient_infile == searchedIDClient) {
				ID = gcnew String(IDClient_infile.c_str());
				found = true;
				continue; // Salta la escritura de la l�nea en el archivo temporal
			}

			// Copiamos la l�nea original tal como est� en el archivo temporal
			outputFile << line << endl;
		}

		if (found) {
			MessageBox::Show("El cliente con c�dula: <<" + ID + ">> ha sido eliminado exitosamente", "Eliminado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("El cliente que se intent� eliminar no existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		// Cerramos ambos archivos
		inputFile.close();
		outputFile.close();

		//Eliminamos el archivo original
		if (remove("clientes\\Registro de clientes.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("clientes\\temp.txt", "clientes\\Registro de clientes.txt") != 0) {
			MessageBox::Show("El archivo temporal no puede ser renombrado.");
		}
	}

	// Funci�n que permite obtener el nombre completo del cliente y agreg�ndolo a un ComboBox
	inline void obtenerClientes(ComboBox^ comboBox) {
		// Se abre el archivo en modo de lectura
		ifstream infile;
		infile.open("clientes\\Registro de clientes.txt");

		// Se lee cada l�nea del archivo y se a�ade al comboBox
		string line;
		string IDClient_infile, telClient_infile, namesClient_infile, surnamesClient_infile;

		while (getline(infile, line)) {
			// Se separa cada campo seg�n el delimitador usado (en este caso "|")
			stringstream ss(line);
			// Obtenemos los valores registrados del archivo (usando solamente los nombres y apellidos)
			getline(ss, IDClient_infile, '|');
			getline(ss, telClient_infile, '|');
			getline(ss, namesClient_infile, '|');
			getline(ss, surnamesClient_infile, '|');

			// Concatenamos los nombre y apellidos para obtener el nombre completo
			string fullname = namesClient_infile + " " + surnamesClient_infile;

			// El std::string se convierte a System::String
			System::String^ lineStr = gcnew System::String(fullname.c_str());

			// Los datos en System::String se a�aden al comboBox
			comboBox->Items->Add(lineStr);
		}

		// Se cierra el archivo
		infile.close();
	}
}