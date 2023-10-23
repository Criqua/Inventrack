#pragma once
#include <list>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

namespace archivoProveedores {
	
	//Funci�n que permite crear o abrir cualquier archivo dado su nombre, ad�mas de a�adir texto en �l
	inline void registrarProveedores(string ID, string telNumb, string names, string surnames,
							  string workSite, string material) {

		ofstream file;
		file.open("proveedores\\Registro de proveedores.txt", ios::app); //Se abre el archivo en modo de agregar al final

		//Se agregan los datos enviados hacia el archivo
		file << ID << "|" << telNumb << "|" << names << "|" << surnames << "|" << workSite << "|" << material << endl;

		//Se cierra el archivo
		file.close();
	}

	// Funci�n que permite mostrar los registros en archivos de texto en un datagridview
	inline void mostrarProveedores(DataGridView^ dgv_prov) {
		try {
			string filepath = "proveedores\\Registro de proveedores.txt";

			// Crear una tabla con las columnas correspondientes
			System::Data::DataTable^ table = gcnew System::Data::DataTable();
			table->Clear();
			table->Columns->Add("C�dula", String::typeid);
			table->Columns->Add("Tel�fono", String::typeid);
			table->Columns->Add("Nombres", String::typeid);
			table->Columns->Add("Apellidos", String::typeid);
			table->Columns->Add("Lugar de trabajo", String::typeid);
			table->Columns->Add("Material", String::typeid);

			// Lista bidimensional que se encargar� de llenar cada celda de la tabla
			list<list<string>> datos;

			// Se abre el archvo donde est�n registrados los proveedores
			ifstream file;
			file.open(filepath, ios::in);

			if (!file.is_open()) {
				MessageBox::Show("No se puede mostrar la tabla de registro.");
				return;
			}
			else {
				//Se leen los datos del archivo linea por linea
				string line;
					
				while (getline(file, line)) {
					// Se crea una lista que almacenar� los datos de una l�nea
					list<string> datos_linea;

					// Separar los campos de la l�nea por el delimitador '|'
					istringstream ss(line);
					string campo;

					while (getline(ss, campo, '|')) {
						//Agregar el campo a la lista de datos de la l�nea
						datos_linea.push_back(campo);
					}

					// Agregar la lista de datos de la l�nea a la lista bidimensional
					datos.push_back(datos_linea);
				}

				// Cerrar el archivo despu�s de leer los datos
				file.close();

				// Llenar la tabla con los datos de la lista bidimensional
				for (auto it = datos.begin(); it != datos.end(); ++it) {
					// Se crea una fila para la tabla
					System::Data::DataRow^ fila = table->NewRow();

					// Agregar los datos de la lista a la fila
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
				// Se asigna la tabla como fuente de datos del datagridview
				dgv_prov->DataSource = table;
			}
		}
		catch (const std::exception& e) {
			MessageBox::Show("Ocurri� un error al mostrar los proveedores: " + gcnew System::String(e.what()));
		}
	}

	inline void buscarProveedor(DataGridView^ dgv, String^ search, bool% found,String^% IDProv, String^% telProv, String^% namesProv,
								String^% surnamesProv, String^% workSite, String^% material) {
		/* Como se puede observar en el pase de par�metros en la funci�n, se utiliza "%" (puntero de seguimiento)...
		...como derivado de "&" (referencia), ya que se trabaja con tipos de variable distintas. En este caso, String^...
		...es un tipo de referencia a un objeto de tipo System::String.*/

		found = false; // Se inicia la variable como falsa
		for (int i = 0; i < dgv->RowCount; i++) {
			//Se busca el proveedor en base al n�mero de c�dula ingresada en el buscador
			DataGridViewCell^ cell = dgv->Rows[i]->Cells["C�dula"];
			/* Se realiza esta condici�n ya que si el cliente buscado no se encuentra en la tabla, la variable tomar�a un valor nulo
			   y por ende resultar�a en una excepci�n en el programa.*/
			String^ nProv = (cell->Value != nullptr) ? cell->Value->ToString() : String::Empty;

			//En caso de que se haya encontrado la ID del proveedor, se extraen todos los datos para su posible modificaci�n
			if (nProv->ToLower()->Contains(search->ToLower())) {
				dgv->ClearSelection();
				found = true; // El proveedor fue encontrado, se le da un valor de verdadero a la variable
				// Se selecciona la fila correspondiente
				dgv->Rows[i]->Selected = true;
				dgv->CurrentCell = dgv->Rows[i]->Cells[0];
				// Nos ubicamos en donde se encuentra el proveedor
				dgv->FirstDisplayedScrollingRowIndex = i;

				// Extraemos la informaci�n del proveedor por cada campo
				IDProv = dgv->Rows[i]->Cells["C�dula"]->Value->ToString();
				telProv = dgv->Rows[i]->Cells["Tel�fono"]->Value->ToString();
				namesProv = dgv->Rows[i]->Cells["Nombres"]->Value->ToString();
				surnamesProv = dgv->Rows[i]->Cells["Apellidos"]->Value->ToString();
				workSite = dgv->Rows[i]->Cells["Lugar de trabajo"]->Value->ToString();
				material = dgv->Rows[i]->Cells["Material"]->Value->ToString();

				// El proveedor ya fue encontrado, no es necesario seguir con la b�squeda
				break;
			}
		}
		if (!found) {
			MessageBox::Show("La c�dula del proveedor buscado no se encuentra en el registro.", "Producto no encontrado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	// Funci�n que modifica los datos de un proveedor seleccionado del datagridview, actualizando el archivo de texto en su proceso
	inline void modificarProveedores(string searchedID, string new_IDProv, string new_telProv, string new_namesProv, string new_surnamesProv, string new_workSiteProv, string new_materialProv) {
		// Abrimos el archivo donde se encuentran registrados los proveedores
		ifstream inputFile;
		inputFile.open("proveedores\\Registro de proveedores.txt", ios::in);

		if (!inputFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos el archivo temporal para escribir en �l
		ofstream outputFile;
		outputFile.open("proveedores\\temp.txt", ios::out);

		if (!outputFile.is_open()) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		string line;
		// Se declaran variables que luego le ser�n dadas sus nuevos valores
		string IDProv_infile, telProv_infile, namesProv_infile, surnamesProv_infile, workSite_infile, material_infile;

		bool found = false;

		while (getline(inputFile, line)) {
			// Se separa cada campo seg�n el delimitador usado (en este caso "|")
			stringstream ss(line);
			getline(ss, IDProv_infile, '|');
			getline(ss, telProv_infile, '|');
			getline(ss, namesProv_infile, '|');
			getline(ss, surnamesProv_infile, '|');
			getline(ss, workSite_infile, '|');
			getline(ss, material_infile, '|');

			// Se verifica si la l�nea actual coincide con el campo buscado
			if (searchedID == IDProv_infile) {
				found = true;
				// Actualizar los campos correspondientes con los nuevos valores
				IDProv_infile = new_IDProv;
				telProv_infile = new_telProv;
				namesProv_infile = new_namesProv;
				surnamesProv_infile = new_surnamesProv;

				// Escribimos la l�nea modificada en el archivo temporal
				stringstream ss;
				ss << IDProv_infile << "|" << telProv_infile << "|" << namesProv_infile << "|" << surnamesProv_infile << endl;
				string nuevaLinea = ss.str();
				outputFile << nuevaLinea;
			}
			else {
				// Copiamos la l�nea original tal como est� en el archivo temporal
				outputFile << line << endl;
			}
		}

		if (found) {
			MessageBox::Show("Proveedor modificado exitosamente.", "�xito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("El proveedor que se intent� modificar no existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		// Cerramos ambos archivos
		inputFile.close();
		outputFile.close();

		//Eliminamos el archivo original
		if (remove("proveedores\\Registro de proveedores.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("proveedores\\temp.txt", "proveedores\\Registro de proveedores.txt") != 0) {
			MessageBox::Show("No se pudo renombrar el archivo auxiliar.");
		}
	}

	// Funci�n que elimina un proveedor seleccionado del datagridview y actualiza el archivo de texto
	inline void eliminarProveedor(string searchedID) {
		// Abrimos el archivo donde se encuentran registrados los proveedores
		ifstream inputFile;
		inputFile.open("proveedores\\Registro de proveedores.txt", ios::in);

		if (!inputFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos el archivo temporal para escribir en �l
		ofstream outputFile;
		outputFile.open("proveedores\\temp.txt", ios::out);

		if (!outputFile.is_open()) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		String^ prov; // Variable que mostrar� la descripcion del producto eliminado
		string line;
		string IDProv_infile, telProv_infile, namesProv_infile, surnamesProv_infile, workSite_infile, material_infile;

		bool found = false;

		while (getline(inputFile, line)) {
			// Se separa cada campo seg�n el delimitador usado (en este caso "|")
			stringstream ss(line);
			getline(ss, IDProv_infile, '|');
			getline(ss, telProv_infile, '|');
			getline(ss, namesProv_infile, '|');
			getline(ss, surnamesProv_infile, '|');
			getline(ss, workSite_infile, '|');
			getline(ss, material_infile, '|');

			// Se verifica si la l�nea actual coincide con los campos buscados
			if (IDProv_infile == searchedID) {
				prov = gcnew String(IDProv_infile.c_str());
				found = true;
				continue; // Salta la escritura de la l�nea en el archivo temporal
			}

			// Copiamos la l�nea original tal como est� en el archivo temporal
			outputFile << line << endl;
		}

		if (found) {
			MessageBox::Show("El proveedor, con c�dula: <<" + prov + ">> ha sido eliminado exitosamente", "Eliminado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("El proveedor que se intent� eliminar no existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		// Cerramos ambos archivos
		inputFile.close();
		outputFile.close();

		//Eliminamos el archivo original
		if (remove("proveedores\\Registro de proveedores.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("proveedores\\temp.txt", "proveedores\\Registro de proveedores.txt") != 0) {
			MessageBox::Show("El proveedor que se intent� eliminar no existe.");
		}
	}
}