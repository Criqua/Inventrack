#pragma once
#include "SystemString_toStdString.h"
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <unordered_set>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

namespace archivoAcceso {
	// Función que permite agregar un nuevo usuario, además de asignarle un rol determinado
	inline void agregarUsuario(string userCode, string newUser, string password, string role) {
		// Abrimos el archivo en formato de escritura al final
		ofstream file;
		file.open("admin\\Usuarios permitidos.txt", ios::app);

		// Agregamos los datos pasados por parámetro
		file << userCode << newUser << "|" << password << "|" << role << endl;
	}

	// Función que elimina un usuario del sistema 
	inline void eliminarUsuario(string user_toDelete) {
		// Abrimos el archivo donde se encuentran registrados los usuarios
		ifstream inputFile;
		inputFile.open("admin\\Usuarios permitidos.txt", ios::in);

		if (!inputFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos el archivo temporal para escribir en él
		ofstream outputFile;
		outputFile.open("admin\\temp.txt", ios::out);

		if (!outputFile.is_open()) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		string line; // Variable que leerá cada línea del archivo
		// Declaramos variables que serán utilizadas para contener la inf. de cada campo del archivo
		string usercode, username;

		bool found = false;

		while (getline(inputFile, line)) {
			// Se separa cada campo según el delimitador usado (en este caso "|")
			stringstream ss(line);
			getline(ss, usercode, '|');
			getline(ss, username, '|');

			// Se verifica si el usuario a eliminar coincide con el código del usuario 
			if (usercode == user_toDelete) {
				found = true;
				continue; // Saltamos la escritura de la línea en el archivo temporal
			}

			// Copiamos la línea original tal como está en el archivo temporal
			outputFile << line << endl;
		}

		// En caso de que el usuario a eliminar fue encontrado, mostramos un mensaje de eliminación efectiva
		if (found) {
			string userInfo = username + " (" + usercode + ")";
			MessageBox::Show("Usuario << " + gcnew String(userInfo.c_str()) + " >> eliminado exitosamente", "Eliminar usuario",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		// Cerramos ambos archivos
		inputFile.close();
		outputFile.close();

		//Eliminamos el archivo original
		if (remove("admin\\Usuarios permitidos.txt") != 0) {
			MessageBox::Show("No se puede borrar el archivo de origen.");
		}

		// Renombramos el archivo temporal con el nombre del archivo original
		if (rename("admin\\temp.txt", "admin\\Usuarios permitidos.txt") != 0) {
			MessageBox::Show("No se puede renombrar el archivo temporal.");
		}
	}

	// Función que verifica si una contraseña es lo más segura posible
	inline void verificarContrasenia(TextBox^ textBox, ErrorProvider^ errorProvider, int% error) {
		// Convertimos lo contenido en el textbox en una cadena aceptable para C++
		string password = conversion::to_stdstring(textBox->Text);

		// Verificamos el tamaño de la contraseña
		if (password.length() < 8) {
			errorProvider->SetError(textBox, "La contraseña debe tener al menos 8 caracteres.");
			textBox->Focus(); // Obtenemos el foco del textbox que obtuvo el error
			error++;
			return;
		}

		// Inicializamos variables booleanas que indicarán lo contenido de una contraseña
		bool hasSymbol = false;
		bool hasNumber = false;
		bool hasCapital = false;

		// Verificamos cada caracter de la contraseña
		for (char p : password) {
			if (p == '|') { // Se verifica si el carácter es '|', nuestro caracter reservado para dividir campos
				errorProvider->SetError(textBox, "La contraseña no puede contener el caracter reservado '|'.");
				error++;
				return;
			}
			if (ispunct(p)) { // Se verifica si es un símbolo especial...
				hasSymbol = true;
			}
			else if (isdigit(p)) {  // ...Si es un número...
				hasNumber = true;
			}
			else if (isupper(p)) { // ...Si está en mayúscula.
				hasCapital = true;
			}

			// Si todos los requisitos se cumplen, no es necesario continuar con la verificación
			if (hasSymbol && hasNumber && hasCapital) {
				// Como la entrada es correcta, no se asigna ningún error
				errorProvider->SetError(textBox, "");
				return;
			}
		}

		// Si se llegó a este punto significa que algunos o todos los requisitos no fueron cumplidos; se retorna falso
		errorProvider->SetError(textBox, "La contraseña debe tener al menos: un caracter en mayúscula, un número y un símbolo especial.");
		error++;
	}

	// Función que verifica si el usuario y/o contraseña ingresada es correcto a momento de iniciar sesión
	inline void verificarAcceso(string enteredUsername, string enteredPassword, bool% hasEntered,
		String^% uName, String^% uRole) {
		/* Abrimos el archivo donde se encuentran ubicados los registros de los usuarios que tienen acceso...
		...al sistema y sus contraseñas*/
		ifstream file;
		file.open("admin\\Usuarios permitidos.txt");

		// Recorremos todo el archivo línea por línea
		string line;
		while (getline(file, line)) {
			// Separamos los campos según el delimitador usado (en este caso '|')
			stringstream ss(line);
			string usercode, username, password, role;

			getline(ss, usercode, '|');
			getline(ss, username, '|');
			getline(ss, password, '|');
			getline(ss, role);

			// Verificamos en todo el archivo si hay igualdad en los campos ingresados por el usuario
			if ((enteredUsername == username || enteredUsername == usercode) && enteredPassword == password) {
				hasEntered = true;
				// Obtenemos el primer nombre del usuario como forma de saludo
				string firstName;
				size_t spacePos = username.find(' ');

				// Se verifica si el caracter especificado fue encontrado
				if (spacePos != string::npos) {
					// Tomamos la subcadena desde el inicio hasta antes de llegar al espacio
					firstName = username.substr(0, spacePos);
				}

				// Mostramos un mensaje de bienvenida con el primer nombre del usuario
				string welcomeMessage = "Inicio de sesión exitoso. ¡Bienvenido, " + firstName + "!";
				MessageBox::Show(gcnew String(welcomeMessage.c_str()), "Inicio de sesión",
					MessageBoxButtons::OK, MessageBoxIcon::Information);

				/* Enviamos información relacionada del usuario a los formularios para verificar...
				...el grado de manipulación que el usuario tiene en el sistema*/
				uName = gcnew String(enteredUsername.c_str());
				uRole = gcnew String(role.c_str());

				return; // El registro ya fue encontrado; no es necesario seguir recorriendo el archivo
			}
		}

		// Como se recorrió todo el archivo y no hubo coincidencia entre los registros, se devuelve falso
		hasEntered = false;
		MessageBox::Show("Error al iniciar sesión. Vuelva a intentarlo", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	// Función que permite rellenar un control de tipo comboBox en base a elementos en archivos de texto
	inline void mostrarUsuarios(ComboBox^ comboBox) {
		// Se abre el archivo en modo de lectura
		ifstream infile;
		infile.open("admin\\Usuarios permitidos.txt");

		// Se lee cada línea del archivo y se añade al comboBox
		string line;
		string usercode, username;
		while (getline(infile, line)) {
			stringstream ss(line);
			getline(ss, usercode, '|');
			getline(ss, username, '|');

			// Dentro del comboBox también se mostrará el código en paréntesis
			string uCode_and_uName = username + " (" + usercode + ")";
			// El std::string se convierte a System::String
			System::String^ lineStr = gcnew System::String(uCode_and_uName.c_str());

			// Los datos en System::String se añaden al comboBox
			comboBox->Items->Add(lineStr);
		}

		// Se cierra el archivo
		infile.close();
	}

	// Función que permite buscar un determinado usuario, obteniendo sus datos en el proceso
	inline void buscarUsuario(string searchedUser, string% username, string% userID, string% userRole) {
		// Abrimos el archivo donde se encuentran registrados los usuarios
		ifstream file;
		file.open("admin\\Usuarios permitidos.txt", ios::in);

		string line;
		// Declaramos variables que extraerán el valor de cada campo del archivo
		string userCode_inFile, username_inFile, pword_inFile, userRole_inFile;

		bool found = false; // Variable booleana que verificará si se ha encontrado el usuario

		// Transformaremos la cadena enviada y a comparar en mayúsculas
		transform(searchedUser.begin(), searchedUser.end(), searchedUser.begin(), ::toupper);

		while (getline(file, line)) {
			stringstream ss(line);
			// Separamos cada campo según el delimitador usado (en este caso '|')
			getline(ss, userCode_inFile, '|');
			getline(ss, username_inFile, '|');
			getline(ss, pword_inFile, '|');
			getline(ss, userRole_inFile);

			// Transformamos el nombre en mayúsculas. Para el código no es necesario hacer este proceso
			string uName = username_inFile;
			// Se pasó el valor a otra variable para no afecta su vista previa al tenerse el nombre en mayúsculas
			transform(uName.begin(), uName.end(), uName.begin(), ::toupper);
			// Verificamos si hay coincidencia del usuario buscado con el código o nombre inscrito en el archivo
			if (searchedUser == userCode_inFile || searchedUser == uName) {
				userID = userCode_inFile;
				username = username_inFile;
				userRole = userRole_inFile;

				// Como se encontró el usuario, pasamos un valor verdadero al booleano
				found = true;
				break; // Salimos del ciclo, ya no es necesario seguir buscando
			}
		}

		// En caso de no encontrarse el usuario, mostramos un mensaje de error
		if (!found) {
			MessageBox::Show("Usuario no encontrado", "Error en la búsqueda", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	inline void modificarRol(string username, string role) {
		// Se abre el archivo donde están registrados los usuarios en formato de lectura
		ifstream file;
		file.open("admin\\Usuarios permitidos.txt");

		// Se crea un archivo temporal que guardará los cambios realizados
		ofstream modifiedFile;
		modifiedFile.open("admin\\temp.txt");

		// Variables utilizadas para obtener el valor de cada campo especificado
		string line;
		string uCode, uName, pWord, uRole;

		while (getline(file, line)) {
			// Se separan los campos según el delimitador usado ('|')
			stringstream ss(line);
			getline(ss, uCode, '|');
			getline(ss, uName, '|');
			getline(ss, pWord, '|');
			getline(ss, uRole);

			// Verificamos si la línea actual coincide con el usuario especificado
			if (username == uName) {
				// Si es así, se agrega la línea modificada
				modifiedFile << uCode << "|" << uName << "|" << pWord << '|' << role << endl;
			}
			else {
				// De otro modo, se copia la línea tal como estaba en el registro original
				modifiedFile << line << endl;
			}
		}

		// Se cierran los archivos
		file.close();
		modifiedFile.close();

		// Se borra el archivo original y se renombra el temporal
		if (remove("admin\\Usuarios permitidos.txt") != 0) {
			MessageBox::Show("No se pudo eliminar el archivo original.");
		}

		if (rename("admin\\temp.txt", "admin\\Usuarios permitidos.txt")) {
			MessageBox::Show("No se pudo renombrar el archivo temporal.");
		}
	}

	// Función que atribuye un código aleatorio único para identificar a un usuario
	inline string generar_codigoUsuario() {
		// Variable booleana que verificará si el código generado es igual a los registrados para algún usuario
		bool uniqueCode = false;
		string code; // Variable con la que guardaremos el código generado

		// Abrimos el archivo donde se encuentran registrados los usuarios en formato de lectura
		ifstream file;
		file.open("admin\\Usuarios permitidos.txt", ios::in);

		// Declaramos un conjunto desordenado que obtendrá todos los códigos del archivo
		unordered_set<string> existingCodes;

		string line;
		// Declaramos el campo que tomaremos en cuenta del archivo para extraer su valor
		string code_inFile;
		while (getline(file, line)) {
			stringstream ss(line);
			// Se obtiene el código guardado de la línea actual sobre la inf. del usuario 
			getline(ss, code_inFile, '|');
			existingCodes.insert(code_inFile); // Guardamos el código en el conjunto
		}

		// Cerramos el archivo
		file.close();

		do {
			// Se generarán 7 números aleatorios
			srand(static_cast<unsigned int>(time(nullptr)));
			for (int i = 0; i < 7; i++) {
				int randNum = rand() % 10;
				code += to_string(randNum);
			}

			// Se genera una letra aleatoria al final de identificador
			char randLetter = 'A' + rand() % 26;
			code += randLetter;

			/* Verificamos si el código generado ya existe según los códigos almacenados...
			...en el conjunto por el número de coincidencias*/
			if (existingCodes.count(code) == 0) {
				// Si el código no se encuentra en el conjunto (es único), se marca como válido
				uniqueCode = true;
			}

		} while (!uniqueCode);

		return code; // Se retorna el valor del código
	}
}