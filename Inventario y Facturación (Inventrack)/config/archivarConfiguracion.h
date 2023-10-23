#pragma once
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

namespace archivoConfiguracion {
	//Función que permite cambiar datos especiales para el encabezado de las facturas
	inline void guardarCambios(string bussinessName, string bussinessDir, string bussinessTel,
						string bussinessMail) {
		// Eliminamos la versión anterior para ingresar las configuraciones en el nuevo
		const char* filePath = "config\\Configuraciones guardadas";
		remove(filePath);

		// Abrir el archivo en modo de escritura
		ofstream file(filePath, ios::out);

		// Agregar los datos enviados al archivo
		file << bussinessName << "|" << bussinessDir << "|" << bussinessTel << "|" << bussinessMail << endl;

		// Cerrar el archivo
		file.close();
	}

	// Función que enviará los datos contenidos en el archivo al encabezado de facturas
	inline void verDatos(String^% bussinessName, String^% bussinessDir, String^% bussinessTel, String^% bussinessMail) {
		// Abrimos en formato de lectura el archivo donde se almacena la configuración actual de las facturas
		ifstream file;
		file.open("config\\Configuraciones guardadas", ios::in);

		string line;
		string bName, bDir, bTel, bMail;
		while (getline(file, line)) {
			// Obtenemos los campos el arhcivos separados por el delimitador '|'
			stringstream ss(line);
			getline(ss, bName, '|');
			getline(ss, bDir, '|');
			getline(ss, bTel, '|');
			getline(ss, bMail);

			// Pasamos los valores a las variables pasadas por referencia
			bussinessName = gcnew String(bName.c_str());
			bussinessDir = gcnew String(bDir.c_str());
			bussinessTel = gcnew String(bTel.c_str());
			bussinessMail = gcnew String(bMail.c_str());
		}
	}
}