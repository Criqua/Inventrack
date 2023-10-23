#pragma once
#include "archivarProductos.h"
#include <algorithm>

using namespace std;

namespace codigo {
    /*Funci�n que permite generar un c�digo para X producto, tomando en cuenta en qu� grupo estar� contenido...
    ...y la cantidad de productos registrados en ese grupo*/
    inline string generarCodigo(string group) {
        string productpath = "productos\\Registro de productos.txt";
        string numecod = "0000"; //Todos los valores luego del gui�n del c�digo tendr�n este formato
        string code;
        string groupInitials = group.substr(0, 3); //Se obtienen las tres letras iniciales del grupo 
        transform(groupInitials.begin(), groupInitials.end(), groupInitials.begin(), ::toupper); //Se transforma la cadena de texto en may�scula
        
        //Se comprueba si el grupo escogido cuenta con las tres mismas iniciales de otros grupo que le preceden
        ifstream registroGrupos;
        registroGrupos.open("grupos\\Registro de grupos.txt", ios::in); //Se abre el archivo en forma de lectura
        int groupCount = 0; // Entero que tomar� un conteo con los grupos que tengan las mismas iniciales al actual
        string line;
        while (getline(registroGrupos, line)) {
            string groupLineInitials = line.substr(0, 3);
            transform(groupLineInitials.begin(), groupLineInitials.end(), groupLineInitials.begin(), ::toupper);
            
            if (groupLineInitials == groupInitials) {
                // En caso de ser as�, se incrementa el contador del subhijo del grupo
                groupCount++;

                /* Realizamos una condici�n en la que si el grupo tomado es igual a la l�nea...
                ...en el registro de grupos, dejamos de sumarle subhijos, ya que el grupo se encuentra ubicado...
                ...de forma l�neal en los archivos*/
                if (line == group) {
                    break; // Salimos del ciclo para dejar de contar m�s subhijos
                }
            }
        }
        registroGrupos.close();

        //Obtenemos el n�mero de productos registrados en el grupo
        int totalp_inGroup = archivoProducto::numProduct(productpath, group);
        // Se convierte la cadena a entero (stoi [String TO Int] y se le suma + 1 por cada registrada de productos, y se reescriben los ceros cuando...
        // ... la cantidad de productos registrada sea mayor de 9, 99 � 999
        int num_incremental = stoi(numecod) + totalp_inGroup + 1;
        numecod = "0000" + to_string(num_incremental); // Se vuelve a convertir a cadena
        // El l�mite ser� de 9999 productos, pero por mientras se eliminar�n los d�gitos adicionales si hay m�s de cuatro
        numecod = numecod.substr(numecod.size() - 4);

        // code = groupInitials + "-" + numecod;
        // 
        // Se construye el c�digo del producto con la estructura deseada
        code = groupInitials;
        if (groupCount > 1) {
            // Concatenamos el valor del subhijo obtenido para el grupo con iniciales repetidas
            code += "(" + to_string(groupCount) + ")";
        }
        //Se concatena para obtener la estructuraci�n deseada del c�digo: ([3 iniciales] + [-] + [secuencia de n�mero respecto al producto anterior])
        code += "-" + numecod;

        return code; //Se retorna el c�digo ya estructurado
    }
}