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
	// Funci�n que permite agregar un nuevo usuario, adem�s de asignarle un rol determinado
	inline void agregarUsuario(string userCode, string newUser, string password, string role) {
		// Abrimos el archivo en formato de escritura al final
		ofstream file;
		file.open("admin\\Usuarios permitidos.txt", ios::app);

		// Agregamos los datos pasados por par�metro
		file << userCode << newUser << "|" << password << "|" << role << endl;
	}

	// Funci�n que elimina un usuario del sistema 
	inline void eliminarUsuario(string user_toDelete) {
		// Abrimos el archivo donde se encuentran registrados los usuarios
		ifstream inputFile;
		inputFile.open("admin\\Usuarios permitidos.txt", ios::in);

		if (!inputFile.is_open()) {
			MessageBox::Show("Error. El archivo de origen no puede abrirse");
			return;
		}

		// Creamos el archivo temporal para escribir en �l
		ofstream outputFile;
		outputFile.open("admin\\temp.txt", ios::out);

		if (!outputFile.is_open()) {
			MessageBox::Show("Error. No se pudo acceder al archivo temporal.");
			return;
		}

		string line; // Variable que leer� cada l�nea del archivo
		// Declaramos variables que ser�n utilizadas para contener la inf. de cada campo del archivo
		string usercode, username;

		bool found = false;

		while (getline(inputFile, line)) {
			// Se separa cada campo seg�n el delimitador usado (en este caso "|")
			stringstream ss(line);
			getline(ss, usercode, '|');
			getline(ss, username, '|');

			// Se verifica si el usuario a eliminar coincide con el c�digo del usuario 
			if (usercode == user_toDelete) {
				found = true;
				continue; // Saltamos la escritura de la l�nea en el archivo temporal
			}

			// Copiamos la l�nea original tal como est� en el archivo temporal
			outputFile << line << endl;
		}

		// En caso de que el usuario a eliminar fue encontrado, mostramos un mensaje de eliminaci�n efectiva
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

	// Funci�n que verifica si una contrase�a es lo m�s segura posible
	inline void verificarContrasenia(TextBox^ textBox, ErrorProvider^ errorProvider, int% error) {
		// Convertimos lo contenido en el textbox en una cadena aceptable para C++
		string password = conversion::to_stdstring(textBox->Text);

		// Verificamos el tama�o de la contrase�a
		if (password.length() < 8) {
			errorProvider->SetError(textBox, "La contrase�a debe tener al menos 8 caracteres.");
			textBox->Focus(); // Obtenemos el foco del textbox que obtuvo el error
			error++;
			return;
		}

		// Inicializamos variables booleanas que indicar�n lo contenido de una contrase�a
		bool hasSymbol = false;
		bool hasNumber = false;
		bool hasCapital = false;

		// Verificamos cada caracter de la contrase�a
		for (char p : password) {
			if (p == '|') { // Se verifica si el car�cter es '|', nuestro caracter reservado para dividir campos
				errorProvider->SetError(textBox, "La contrase�a no puede contener el caracter reservado '|'.");
				error++;
				return;
			}
			if (ispunct(p)) { // Se verifica si es un s�mbolo especial...
				hasSymbol = true;
			}
			else if (isdigit(p)) {  // ...Si es un n�mero...
				hasNumber = true;
			}
			else if (isupper(p)) { // ...Si est� en may�scula.
				hasCapital = true;
			}

			// Si todos los requisitos se cumplen, no es necesario continuar con la verificaci�n
			if (hasSymbol && hasNumber && hasCapital) {
				// Como la entrada es correcta, no se asigna ning�n error
				errorProvider->SetError(textBox, "");
				return;
			}
		}

		// Si se lleg� a este punto significa que algunos o todos los requisitos no fueron cumplidos; se retorna falso
		errorProvider->SetError(textBox, "La contrase�a debe tener al menos: un caracter en may�scula, un n�mero y un s�mbolo especial.");
		error++;
	}

	// Funci�n que verifica si el usuario y/o contrase�a ingresada es correcto a momento de iniciar sesi�n
	inline void verificarAcceso(string enteredUsername, string enteredPassword, bool% hasEntered,
		String^% uName, String^% uRole) {
		/* Abrimos el archivo donde se encuentran ubicados los registros de los usuarios que tienen acceso...
		...al sistema y sus contrase�as*/
		ifstream file;
		file.open("admin\\Usuarios permitidos.txt");

		// Recorremos todo el archivo l�nea por l�nea
		string line;
		while (getline(file, line)) {
			// Separamos los campos seg�n el delimitador usado (en este caso '|')
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
				string welcomeMessage = "Inicio de sesi�n exitoso. �Bienvenido, " + firstName + "!";
				MessageBox::Show(gcnew String(welcomeMessage.c_str()), "Inicio de sesi�n",
					MessageBoxButtons::OK, MessageBoxIcon::Information);

				/* Enviamos informaci�n relacionada del usuario a los formularios para verificar...
				...el grado de manipulaci�n que el usuario tiene en el sistema*/
				uName = gcnew String(enteredUsername.c_str());
				uRole = gcnew String(role.c_str());

				return; // El registro ya fue encontrado; no es necesario seguir recorriendo el archivo
			}
		}

		// Como se recorri� todo el archivo y no hubo coincidencia entre los registros, se devuelve falso
		hasEntered = false;
		MessageBox::Show("Error al iniciar sesi�n. Vuelva a intentarlo", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	// Funci�n que permite rellenar un control de tipo comboBox en base a elementos en archivos de texto
	inline void mostrarUsuarios(ComboBox^ comboBox) {
		// Se abre el archivo en modo de lectura
		ifstream infile;
		infile.open("admin\\Usuarios permitidos.txt");

		// Se lee cada l�nea del archivo y se a�ade al comboBox
		string line;
		string usercode, username;
		while (getline(infile, line)) {
			stringstream ss(line);
			getline(ss, usercode, '|');
			getline(ss, username, '|');

			// Dentro del comboBox tambi�n se mostrar� el c�digo en par�ntesis
			string uCode_and_uName = username + " (" + usercode + ")";
			// El std::string se convierte a System::String
			System::String^ lineStr = gcnew System::String(uCode_and_uName.c_str());

			// Los datos en System::String se a�aden al comboBox
			comboBox->Items->Add(lineStr);
		}

		// Se cierra el archivo
		infile.close();
	}

	// Funci�n que permite buscar un determinado usuario, obteniendo sus datos en el proceso
	inline void buscarUsuario(string searchedUser, string% username, string% userID, string% userRole) {
		// Abrimos el archivo donde se encuentran registrados los usuarios
		ifstream file;
		file.open("admin\\Usuarios permitidos.txt", ios::in);

		string line;
		// Declaramos variables que extraer�n el valor de cada campo del archivo
		string userCode_inFile, username_inFile, pword_inFile, userRole_inFile;

		bool found = false; // Variable booleana que verificar� si se ha encontrado el usuario

		// Transformaremos la cadena enviada y a comparar en may�sculas
		transform(searchedUser.begin(), searchedUser.end(), searchedUser.begin(), ::toupper);

		while (getline(file, line)) {
			stringstream ss(line);
			// Separamos cada campo seg�n el delimitador usado (en este caso '|')
			getline(ss, userCode_inFile, '|');
			getline(ss, username_inFile, '|');
			getline(ss, pword_inFile, '|');
			getline(ss, userRole_inFile);

			// Transformamos el nombre en may�sculas. Para el c�digo no es necesario hacer este proceso
			string uName = username_inFile;
			// Se pas� el valor a otra variable para no afecta su vista previa al tenerse el nombre en may�sculas
			transform(uName.begin(), uName.end(), uName.begin(), ::toupper);
			// Verificamos si hay coincidencia del usuario buscado con el c�digo o nombre inscrito en el archivo
			if (searchedUser == userCode_inFile || searchedUser == uName) {
				userID = userCode_inFile;
				username = username_inFile;
				userRole = userRole_inFile;

				// Como se encontr� el usuario, pasamos un valor verdadero al booleano
				found = true;
				break; // Salimos del ciclo, ya no es necesario seguir buscando
			}
		}

		// En caso de no encontrarse el usuario, mostramos un mensaje de error
		if (!found) {
			MessageBox::Show("Usuario no encontrado", "Error en la b�squeda", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	inline void modificarRol(string username, string role) {
		// Se abre el archivo donde est�n registrados los usuarios en formato de lectura
		ifstream file;
		file.open("admin\\Usuarios permitidos.txt");

		// Se crea un archivo temporal que guardar� los cambios realizados
		ofstream modifiedFile;
		modifiedFile.open("admin\\temp.txt");

		// Variables utilizadas para obtener el valor de cada campo especificado
		string line;
		string uCode, uName, pWord, uRole;

		while (getline(file, line)) {
			// Se separan los campos seg�n el delimitador usado ('|')
			stringstream ss(line);
			getline(ss, uCode, '|');
			getline(ss, uName, '|');
			getline(ss, pWord, '|');
			getline(ss, uRole);

			// Verificamos si la l�nea actual coincide con el usuario especificado
			if (username == uName) {
				// Si es as�, se agrega la l�nea modificada
				modifiedFile << uCode << "|" << uName << "|" << pWord << '|' << role << endl;
			}
			else {
				// De otro modo, se copia la l�nea tal como estaba en el registro original
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

	// Funci�n que atribuye un c�digo aleatorio �nico para identificar a un usuario
	inline string generar_codigoUsuario() {
		// Variable booleana que verificar� si el c�digo generado es igual a los registrados para alg�n usuario
		bool uniqueCode = false;
		string code; // Variable con la que guardaremos el c�digo generado

		// Abrimos el archivo donde se encuentran registrados los usuarios en formato de lectura
		ifstream file;
		file.open("admin\\Usuarios permitidos.txt", ios::in);

		// Declaramos un conjunto desordenado que obtendr� todos los c�digos del archivo
		unordered_set<string> existingCodes;

		string line;
		// Declaramos el campo que tomaremos en cuenta del archivo para extraer su valor
		string code_inFile;
		while (getline(file, line)) {
			stringstream ss(line);
			// Se obtiene el c�digo guardado de la l�nea actual sobre la inf. del usuario 
			getline(ss, code_inFile, '|');
			existingCodes.insert(code_inFile); // Guardamos el c�digo en el conjunto
		}

		// Cerramos el archivo
		file.close();

		do {
			// Se generar�n 7 n�meros aleatorios
			srand(static_cast<unsigned int>(time(nullptr)));
			for (int i = 0; i < 7; i++) {
				int randNum = rand() % 10;
				code += to_string(randNum);
			}

			// Se genera una letra aleatoria al final de identificador
			char randLetter = 'A' + rand() % 26;
			code += randLetter;

			/* Verificamos si el c�digo generado ya existe seg�n los c�digos almacenados...
			...en el conjunto por el n�mero de coincidencias*/
			if (existingCodes.count(code) == 0) {
				// Si el c�digo no se encuentra en el conjunto (es �nico), se marca como v�lido
				uniqueCode = true;
			}

		} while (!uniqueCode);

		return code; // Se retorna el valor del c�digo
	}
}