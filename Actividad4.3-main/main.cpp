//Actividad integradora 4.3
//Alexa Basurto Flores A01422793
//23/11/2020
#include "Grafo.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main(){
    Grafo GRAFO;
    string line;//linea que se sacara del doc txt
    string linea;
    fstream myfile;
    myfile.open ("bitacora2.txt"); //abrir doc y leerlo 

    while(getline(myfile, line)){ //leer linea de archivo 
    
        GRAFO.INGRESA(line);//agrgar linea

    }

    GRAFO.ACOMODA();

    GRAFO.IMPRIME();
    
    return 0;
}