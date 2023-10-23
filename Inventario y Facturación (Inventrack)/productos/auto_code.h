#pragma once
#include "archivarProductos.h"
#include <algorithm>

using namespace std;

namespace codigo {
    /*Función que permite generar un código para X producto, tomando en cuenta en qué grupo estará contenido...
    ...y la cantidad de productos registrados en ese grupo*/
    inline string generarCodigo(string group) {
        string productpath = "productos\\Registro de productos.txt";
        string numecod = "0000"; //Todos los valores luego del guión del código tendrán este formato
        string code;
        string groupInitials = group.substr(0, 3); //Se obtienen las tres letras iniciales del grupo 
        transform(groupInitials.begin(), groupInitials.end(), groupInitials.begin(), ::toupper); //Se transforma la cadena de texto en mayúscula
        
        //Se comprueba si el grupo escogido cuenta con las tres mismas iniciales de otros grupo que le preceden
        ifstream registroGrupos;
        registroGrupos.open("grupos\\Registro de grupos.txt", ios::in); //Se abre el archivo en forma de lectura
        int groupCount = 0; // Entero que tomará un conteo con los grupos que tengan las mismas iniciales al actual
        string line;
        while (getline(registroGrupos, line)) {
            string groupLineInitials = line.substr(0, 3);
            transform(groupLineInitials.begin(), groupLineInitials.end(), groupLineInitials.begin(), ::toupper);
            
            if (groupLineInitials == groupInitials) {
                // En caso de ser así, se incrementa el contador del subhijo del grupo
                groupCount++;

                /* Realizamos una condición en la que si el grupo tomado es igual a la línea...
                ...en el registro de grupos, dejamos de sumarle subhijos, ya que el grupo se encuentra ubicado...
                ...de forma líneal en los archivos*/
                if (line == group) {
                    break; // Salimos del ciclo para dejar de contar más subhijos
                }
            }
        }
        registroGrupos.close();

        //Obtenemos el número de productos registrados en el grupo
        int totalp_inGroup = archivoProducto::numProduct(productpath, group);
        // Se convierte la cadena a entero (stoi [String TO Int] y se le suma + 1 por cada registrada de productos, y se reescriben los ceros cuando...
        // ... la cantidad de productos registrada sea mayor de 9, 99 ó 999
        int num_incremental = stoi(numecod) + totalp_inGroup + 1;
        numecod = "0000" + to_string(num_incremental); // Se vuelve a convertir a cadena
        // El límite será de 9999 productos, pero por mientras se eliminarán los dígitos adicionales si hay más de cuatro
        numecod = numecod.substr(numecod.size() - 4);

        // code = groupInitials + "-" + numecod;
        // 
        // Se construye el código del producto con la estructura deseada
        code = groupInitials;
        if (groupCount > 1) {
            // Concatenamos el valor del subhijo obtenido para el grupo con iniciales repetidas
            code += "(" + to_string(groupCount) + ")";
        }
        //Se concatena para obtener la estructuración deseada del código: ([3 iniciales] + [-] + [secuencia de número respecto al producto anterior])
        code += "-" + numecod;

        return code; //Se retorna el código ya estructurado
    }
}