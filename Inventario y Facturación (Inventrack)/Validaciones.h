#pragma once
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>
#include "SystemString_toStdString.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

namespace validate {
	// Funci�n que valida si un textBox se encuentra vac�o, donde pasamos como referencia una variable booleana que permite verificar las entradas
	inline void isTxtBox_notEmpty(TextBox^ textBox, ErrorProvider^ errorProvider, String^ mensajeError, int% error) {
        // En caso de que est� vac�a se muestra el mensaje de error dado
        if (textBox->Text->Trim() == "") { // La funci�n de Trim es no tomar en cuenta los espacios en blanco al inicio y al final como caracteres
            errorProvider->SetError(textBox, mensajeError);
            textBox->Focus(); // Obtenemos el foco del textbox que obtuvo el error
            error++;
            return;
        }
        else {
            // Caso contrario, la entrada es correcta
            errorProvider->SetError(textBox, "");
        }
	}

    // Funci�n que valida si un comboBox se encuentra vac�o
    inline void isComboBox_notEmpty(ComboBox^ comboBox, ErrorProvider^ errorProvider, String^ mensajeError, int% error) {
        // Se verifica si el valor es igual a "-1", ya que esto significa que no se ha seleccionado un elemento del comboBox que van de 0 a N
        // Si es as�, mostramos el mensaje de error dado (comboBox->SelectedIndex == -1)
        if (comboBox->Text == "") {
            errorProvider->SetError(comboBox, mensajeError);
            comboBox->Focus(); // Obtenemos el foco del comboBox que obtuvo el error
            error++;
            return;
        }
        else {
            // Caso contrario, la entrada es correcta
            errorProvider->SetError(comboBox, "");
        }
    }

    // Funci�n que valida si el valor de un textBox es un entero positivo
    inline void isTxtBox_posInt(TextBox^ textBox, ErrorProvider^ errorProvider, String^ mensajeError, int% error) {
        
        int isEmpty = 0; // Variable temporal que permite omitir los dem�s errores y enfocarse en si el campo est� vac�o
        int num;

        // Primero verificamos que el textbox no est� vac�o
        isTxtBox_notEmpty(textBox, errorProvider, "Este campo es obligatorio.", isEmpty);
        if (isEmpty > 0) {
            error++;
            return;
        }

        // Verificar si el valor es decimal
        if (textBox->Text->Contains(".") || textBox->Text->Contains(",")) {
            errorProvider->SetError(textBox, mensajeError);
            textBox->Focus(); // Obtener el foco del textbox que obtuvo el error
            error++;
            return;
        }

        // Analizamos el textBox como si de un valor entero se tratase
        if (!Int32::TryParse(textBox->Text, num) || num <= 0) {
            // En caso de no serlo, se muestra un mensaje de error
            errorProvider->SetError(textBox, mensajeError);
            textBox->Focus(); // Obtenemos el foco del textbox que obtuvo el error
            error++;
        }
        else {
            // Caso contrario, la entrada es correcta
            errorProvider->SetError(textBox, "");
        }
    }

    // Funci�n que valida si el valor de un textBox es un flotante positivo
    inline void isTxtBox_posFloat(TextBox^ textBox, ErrorProvider^ errorProvider, String^ mensajeError, int% error) {
       
        int isEmpty = 0; // Variable temporal que permite omitir los dem�s errores y enfocarse en si el campo est� vac�o
        float num;

        isTxtBox_notEmpty(textBox, errorProvider, "Este campo es obligatorio.", isEmpty);
        if (isEmpty > 0) {
            error++;
            return;
        }

        // Analizamos el textBox como si de un valor flotante se tratase
        if (!Single::TryParse(textBox->Text, num) || num <= 0) {
            // En caso de no serlo, se muestra un mensaje de error
            errorProvider->SetError(textBox, mensajeError);
            textBox->Focus(); // Obtenemos el foco del textbox que obtuvo el error
            error++;
        }
        else {
            // Caso contrario, la entrada es correcta
            errorProvider->SetError(textBox, "");
        }
    }

    // Funci�n que compara los valores num�ricos de dos textBoxes y verifica si el segundo es mayor que otro
    inline void isTxtBox_greaterThan(TextBox^ textBox1, TextBox^ textBox2, ErrorProvider^ errorProvider, String^ mensajeError, int error) {
        float num1, num2;

        // Cambiamos los valores de los textBoxes a flotantes
        Single::TryParse(textBox1->Text, num1);
        Single::TryParse(textBox2->Text, num2);

        // En caso de que el valor del primer textBox sea menor que el segundo se env�a un mensaje de error y retorna un valor false
        if (num1 < num2) {
            errorProvider->SetError(textBox2, mensajeError);
            textBox2->Focus(); // Obtenemos el foco del textbox que obtuvo el error
            error++;
        }
        else {
            // Caso contrario, el primer textBox es mayor que el segundo y la entrada es correcta
            errorProvider->SetError(textBox1, "");
        }
    }

    // Funci�n que compara los valores num�ricos de dos textBoxes y verifica si el primero es mayor que otro
    inline void isTxtBox2_greaterThan(TextBox^ textBox1, TextBox^ textBox2, ErrorProvider^ errorProvider, String^ mensajeError, int error) {
        float num1, num2;

        // Cambiamos los valores de los textBoxes a flotantes
        Single::TryParse(textBox1->Text, num1);
        Single::TryParse(textBox2->Text, num2);

        // En caso de que el valor del primer textBox sea menor que el segundo se env�a un mensaje de error y retorna un valor false
        if (num1 > num2) {
            errorProvider->SetError(textBox1, mensajeError);
            textBox2->Focus(); // Obtenemos el foco del textbox que obtuvo el error
            error++;
        }
        else {
            // Caso contrario, el primer textBox es mayor que el segundo y la entrada es correcta
            errorProvider->SetError(textBox1, "");
        }
    }

    // Funci�n que compara la descripci�n a registrar de un producto con los guardados en el archivo, verificando si hay igualdad
    inline void isDesc_thesame(TextBox^ descripcion, ErrorProvider^ errorProvider, String^ mensajeError, int% error) {
        int isEmpty = 0;

        // Primero verificamos que el textbox no est� vac�o
        isTxtBox_notEmpty(descripcion, errorProvider, "Este campo es obligatorio.", isEmpty);
        if (isEmpty > 0) {
            error++;
            return;
        }

        // Abrimos el archivo de registro de producto
        ifstream file;
        file.open("productos\\Registro de productos.txt");

        // Con esta variable extraeremos la cadena de texto de descripci�n en el archivo por cada l�nea
        string line;
        // Se lee cada l�nea del archivo
        while (getline(file, line)) {
            stringstream ss(line);
            string code, group, desc_inFile;

            // Extraemos los campos anteriores a la descripci�n
            getline(ss, code, '|');
            getline(ss, group, '|');
            getline(ss, desc_inFile, '|'); // Extraemos la descripci�n del archivo de registro de productos
            
            /* Convertimos tanto la descripci�n ingresada como la descripci�n del archivo a may�sculas...
            ...y a std::string para que la comparaci�n sea homog�nea*/
            string desc = conversion::to_stdstring(descripcion->Text->Trim());
            transform(desc.begin(), desc.end(), desc.begin(), ::toupper);
            transform(desc_inFile.begin(), desc_inFile.end(), desc_inFile.begin(), ::toupper);

            // Realizamos la comparaci�n
            if (desc == desc_inFile) {
                // En caso de que la descripcion a registrar y las incluidas en el archivo sean iguales se env�a un mensaje de error
                errorProvider->SetError(descripcion, mensajeError);
                descripcion->Focus(); // Obtenemos el foco del textbox que obtuvo el error
                error++;
                return; // Salimos de la funci�n, ya no es necesario seguir recorriendo
            }
        }
        
        // Como se recorrieron todas las l�neas del archivo y no hubo igualdad en la validaci�n, damos por correcta la entrada
        errorProvider->SetError(descripcion, "");
    }

    // Funci�n que compara la c�dulas de un proveedor o cliente con los guardados en el archivo, verificando si hay igualdad
    inline void isID_thesame(TextBox^ ID, string filepath, ErrorProvider^ errorProvider, String^ mensajeError, int% error) {

        // Primeramente verificamos si su textbox se encuentra vac�o o si el texto contenido es el mismo al placeholder
        if (ID->Text->Trim() == "NNN-NNNNNN-NNNNL" || ID->Text->Trim() == "") {
            errorProvider->SetError(ID, "Este campo es obligatorio");
            ID->Focus(); // Obtenemos el foco del textbox que obtuvo el error
            error++;
            return;
        }

        // Abrimos el archivo en base a la ruta especificada
        ifstream file;
        file.open(filepath);

        // Con esta variable extraeremos la cadena de texto de ID en el archivo por cada l�nea
        string line;
        // Se lee cada l�nea del archivo
        while (getline(file, line)) {
            stringstream ss(line);
            string ID_inFile;

            // Extraemos la ID de la ruta del archivo enviado por par�metro
            getline(ss, ID_inFile, '|');

            /* Convertimos tanto la ID ingresada como la ID del archivo a may�sculas...
            ...y a std::string para que la comparaci�n sea homog�nea*/
            string id = conversion::to_stdstring(ID->Text->Trim());
            transform(id.begin(), id.end(), id.begin(), ::toupper);
            transform(ID_inFile.begin(), ID_inFile.end(), ID_inFile.begin(), ::toupper);

            // Realizamos la comparaci�n
            if (id == ID_inFile) {
                // En caso de que la ID a registrar y las incluidas en el archivo sean iguales se env�a un mensaje de error
                errorProvider->SetError(ID, mensajeError);
                ID->Focus(); // Obtenemos el foco del textbox que obtuvo el error
                error++;
                return; // Salimos de la funci�n, ya no es necesario seguir recorriendo
            }
        }

        // Como se recorrieron todas las l�neas del archivo y no hubo igualdad en la validaci�n, damos por correcta la entrada
        errorProvider->SetError(ID, "");
    }

    // Funci�n que verifica si la fecha de expiraci�n ingresada es menor a la actual o si su formato est� mal
    inline void isDate_correct(TextBox^ date, ErrorProvider^ errorProvider, bool verifyOutdating,int% error) {

        // Redactamos algunos mensajes indicadores de errores de entrada del usuario
        String^ emptyTxtBox_Message2 = "Este campo es obligatorio, pero puede no rellenarlo ingresando cualquier caracter <<->>.";
        String^ wrongStruct = "El formato de fecha ingresado no es el correcto (debe ser dd/mm/aaaa)";
        String^ fixDate = "La fecha de vencimiento del producto es anterior a la fecha actual. No se puede procesar.";

        // Primeramente verificamos si su textbox se encuentra vac�o o si el texto contenido es el mismo al placeholder
        if (date->Text->Trim() == "dd/mm/aaaa" || date->Text->Trim() == "") {
            errorProvider->SetError(date, emptyTxtBox_Message2);
            date->Focus(); // Obtenemos el foco del textbox que obtuvo el error
            error++;
            return;
        }

        // Ya que no fue as�, cambiamos el valor del textbox a uno manejable para C++ est�ndar
        string dateNow = conversion::to_stdstring(date->Text);
        
        // Obtener la fecha y hora actual
        time_t currentTime;
        time(&currentTime);

        // Obtener la estructura de tiempo local de forma segura
        struct tm timeInfo;
        localtime_s(&timeInfo, &currentTime);

        // Obtener los componentes de la fecha actual
        int currYear = timeInfo.tm_year + 1900;
        int currMonth = timeInfo.tm_mon + 1;
        int currDay = timeInfo.tm_mday;

        istringstream ss(dateNow);
        int day, month, year;
        char slash1, slash2;

        /* Analizamos si la estructura de la fecha ingresada es correcta (dd / mm / aaaa)...
        ...permitiendo tanto el uso de '/' como '-'*/
        if (date->Text == "-") {
            return;
        }
        else if (!(ss >> day >> slash1 >> month >> slash2 >> year) || ((slash1 != '/' && slash2 != '/') && (slash1 != '-' && slash2 != '-'))) {
            // Si entr� a la condici�n, quiere decir que hubo un error de formato
            errorProvider->SetError(date, wrongStruct);
            date->Focus(); // Obtenemos el foco del textbox que obtuvo el error
            error++;
            return;
        }

        if (verifyOutdating == true) {
            // Verificamos si la fecha ingresada es posterior al d�a actual, para evitar registro de productos vencidos
            if (year > currYear || (year == currYear && month > currMonth) || (year == currYear && month == currMonth && day > currDay)) {
                // De ser as�, la entrada es correcta y continuamos el proceso de registro
                return;
            }
            else {
                // En caso de ser inferior, se procede a permitirle hacer una decisi�n
                String^ messageText = "La fecha de expiraci�n de este producto es inferior a la fecha actual. �Est� seguro de que desea continuar con el proceso de registro?";
                String^ messageTitle = "Importante";
                System::Windows::Forms::DialogResult result = MessageBox::Show(messageText, messageTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

                if (result == System::Windows::Forms::DialogResult::Yes) {
                    // De elegir "S�", continuamos con el proceso de registro
                    return;
                }
                else {
                    // De elegir "No", interrumpimos el proceso de registro autom�ticamente
                    errorProvider->SetError(date, fixDate);
                    date->Focus(); // Obtenemos el foco del textbox que obtuvo el error
                    error++;
                    return;
                }
            }
        }
    }

    // Funci�n que verifica si una fecha es mayor que otra
    inline void is_toDate_lessthan(TextBox^ fromDate, TextBox^ toDate, ErrorProvider^ errorProvider, String^ mensajeError, 
                                    int% error) {

        // Se obtienen las fechas ingresadas y se cambian a std::string
        string fromDateStr = conversion::to_stdstring(fromDate->Text);
        string toDateStr = conversion::to_stdstring(toDate->Text);

        // Convertimos los valores de las fechas a enteros, separando cada campo de "/" a su respectivo lugar
        stringstream fDate(fromDateStr);
        stringstream sDate(toDateStr);
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

        // Se verifica si la fecha "desde" es mayor que la fecha "hasta"
        if (fromYear > toYear || (fromYear == toYear && fromMonth > toMonth) || 
            (fromYear == toYear && fromMonth == toMonth && fromDay > toDay)) {
            // En caso de ser as� obtenemos el foco para el textbox "desde"
            errorProvider->SetError(fromDate, mensajeError);
            error++;
        }
        else {
            // Caso contrario, la entrada es correcta
            errorProvider->SetError(fromDate, "");
        }
    }
}