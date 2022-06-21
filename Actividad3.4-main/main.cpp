//llenar arbol de los datos en el txt
//imprimir los 5 ip mas grandes en el arbol 

#include "Heap.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    Heap ARBOL;
   
    string line;//linea que se sacara del doc txt
    fstream myfile;
    myfile.open ("bitacora.txt"); //abrir doc y leerlo 

    while(getline(myfile, line)){ //leer linea de archivo 

        ARBOL.push(line); //agregar linea al arbol

    }
    
    for (int i = 0; i < 5; i++){//Imprime los 5 ips mas grandes 
        ARBOL.pop();
    }

    myfile.close(); //cerrar archivo

    return 0;
}
