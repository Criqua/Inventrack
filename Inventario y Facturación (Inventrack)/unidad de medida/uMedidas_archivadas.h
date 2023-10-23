#pragma once
#include <fstream>
#include <string>

using namespace std;
using namespace System::Windows::Forms;

namespace uMeasure {

	inline void mostrarMedidas_ComboBox(string filepath, ComboBox^ comboBox) {
		string unit = filepath;
		// Se abre el archivo en modo de lectura
		ifstream infile;
		infile.open(unit);

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
}