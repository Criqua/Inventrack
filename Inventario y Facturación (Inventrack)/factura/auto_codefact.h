#pragma once
#include "archivar_datosFactura.h"

namespace codigofac {
	// Función que permite generar un código automático de factura, a partir del número de facturas generada
	inline string generarCodigo_fac() {
		string billpath = "factura\\Registro de facturas.txt";
		string numecod = "0000"; // Todos los valores luego del guión del código tendrán este formato
		string billInitials = "FAC";
		string codefac;

		// Obtenemos el número de facturas contenidas en el archivo de "Registro de facturas.txt" según su código
		int totalBills = archivoFactura::numFact(billpath);

		// Formateamos el número de factura con ceros a la izquierda
		int newFact = stoi(numecod) + totalBills;
		numecod = "0000" + to_string(newFact); // Se vuelve a convertir a cadena
		// El límite será de 9999 facturas, pero por mientras se eliminarán los dígitos adicionales si hay más de cuatro
		numecod = numecod.substr(numecod.size() - 4);

		codefac = billInitials + "-" + numecod; //Se concatena para obtener la estructuración deseada del código: ([FAC] + [-] + [secuencia de número respecto a última factura + 1])

		return codefac; //Se retorna el código ya estructurado
	}
}