//abrir documento bitacora2.txt para meterlo en una tabla de hash
//A01422793 Alexa Basurto Flores
//29/11/2020

#include "Tabla_Hash.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int main(){
    Tabla_Hash TABLA;
    string line;//linea que se sacara del doc txt
    string linea;
    fstream myfile;
    myfile.open ("bitacora2.txt"); //abrir doc y leerlo

    int n;
    cin>>n;

    vector<string> DATOS;
    string entrada;
    for(int i =0; i<n ;i++){
        cin>>entrada;
        DATOS.push_back(entrada);
    }


    while(getline(myfile, line)){ //leer linea de archivo

        TABLA.ins(line);//agrgar linea

    }
    myfile.close();

    cout<<endl;
    for (int i = 0; i < DATOS.size(); i++){
        TABLA.search(DATOS[i]);
        cout<<endl;
    }


    return 0;
}
