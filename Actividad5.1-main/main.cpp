//actividad 5.1 hash
//A01422793 Alexa Basurto Flores
//28/11/2020

#include "Tabla_Hash.h"

#include <iostream>
#include <string>

using namespace std;
int main(){
    Tabla_Hash tabla;

    bool indicador = true;
    int entrada;

    string placa,marca,modelo,anio,dato;

    while(indicador){

        cin>>entrada;
        

        switch (entrada){
        //1. insertar  
        case 1:
            cin>>placa;
            cin>>marca;
            cin>>modelo;
            cin>>anio;
            dato="";
            dato+=placa+" "+marca+" " + modelo +" "+ anio;
            tabla.ins(dato);
            
            break;


        //2. eliminar
        case 2:
            cin>>placa;
            tabla.del(placa);
            
            break;

        //3. imprime la tabla
        case 3:
            //code
            tabla.print();
            cout<<endl;
            break;


        //4. buscar un dato
        case 4:
            cin>>placa;
            
            tabla.search(placa);
            cout<<endl;
            break;


        //0. salir
        case 0:
            indicador = false;
            
            break;
        
        default:
            break;
        }

    }


    return 0;
}