#pragma once
#include "archivar_datosFactura.h"

namespace codigofac {
	// Funci�n que permite generar un c�digo autom�tico de factura, a partir del n�mero de facturas generada
	inline string generarCodigo_fac() {
		string billpath = "factura\\Registro de facturas.txt";
		string numecod = "0000"; // Todos los valores luego del gui�n del c�digo tendr�n este formato
		string billInitials = "FAC";
		string codefac;

		// Obtenemos el n�mero de facturas contenidas en el archivo de "Registro de facturas.txt" seg�n su c�digo
		int totalBills = archivoFactura::numFact(billpath);

		// Formateamos el n�mero de factura con ceros a la izquierda
		int newFact = stoi(numecod) + totalBills;
		numecod = "0000" + to_string(newFact); // Se vuelve a convertir a cadena
		// El l�mite ser� de 9999 facturas, pero por mientras se eliminar�n los d�gitos adicionales si hay m�s de cuatro
		numecod = numecod.substr(numecod.size() - 4);

		codefac = billInitials + "-" + numecod; //Se concatena para obtener la estructuraci�n deseada del c�digo: ([FAC] + [-] + [secuencia de n�mero respecto a �ltima factura + 1])

		return codefac; //Se retorna el c�digo ya estructurado
	}
}