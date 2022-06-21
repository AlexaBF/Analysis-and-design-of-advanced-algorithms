//clase para crear tabla de hash
//A01422793 Alexa Basurto Flores
//28/11/2020

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Tabla_Hash{
protected:
    string arreglo[97];//declarar arreglo
    int lleno;//indica cuando la tabla este llena

public:
    Tabla_Hash();
    void ins(string dato);
    void del(string llave);
    void print();
    void search(string llave);
    ~Tabla_Hash();
};

Tabla_Hash::Tabla_Hash(){
}


//1. insertar  (si la tabla ya esta llena, mandar mensaje "tabla llena, imposible insertar",
// si ya existe la placa, mandar mensaje "imposible insertar, placa duplicada")
void Tabla_Hash::ins(string dato){
    int pos;
    pos=dato.find(" ");// posicion del primer espacio
    string llave = dato.substr(0,pos);// llave de la cadena de datos
    int suma = 0;

    //complejidad O(n)
    for (int i = 0; i < llave.size(); i++){
        suma += int(llave[i]);//sumar ASCII de cada char
    }

    int pos_tabla = suma % 97;//operacion de %97 para obtener la posicion hash

    string encuentra;
    bool indica = false;

    //verificar que llave no sea duplicada 
    //complejidad O(1)
    for (int i = 0; i < 97; i++){
        encuentra = "";
        encuentra+= arreglo[i].substr(0,pos);
        if(llave == encuentra){
            indica = true;//indica que la llave es duplicada
            break;
        }
    }
    

    if(lleno == 97){//cuando la tabla esta llena
        cout<<"tabla llena, imposible insertar"<<endl;
    }else if(indica == true){//cuando los datos ya se encuentran en la tabla
        cout<<"imposible insertar, placa duplicada"<<endl;
    }else{

        //si la posicion de hash que se obtuvo ya esta ocupada
        if(arreglo[pos_tabla] != ""){

            //complejidad O(n)
            while (arreglo[pos_tabla] != ""){
                pos_tabla ++;
                if (pos_tabla == 96){
                    pos_tabla=0;
                }
            }
            
            arreglo[pos_tabla]= dato;//una vez que se encuentra un espacio meter dato

        }else{//si el espacio esta vacio de primera instancia
            arreglo[pos_tabla]= dato;
        }

        lleno++;//indicar que se inserto un elemento en la tabla
    }


}



//eliminar una llave
void Tabla_Hash::del(string llave){
    string placa;
    //complejidad O(1)
    for (int i = 0; i < 97; i++){
        placa = "";
        placa = arreglo[i].substr(0, arreglo[i].find(" ") );//agarrar solo la placa de cada elemento
        if(llave == placa){
            arreglo[i]="";//eliminar elemento
            break;
        } 
    }

    lleno--;//indicar que se elimino un elemento de la tabla
}




//3. imprime la tabla 
//(se muestra el índice, se muestran todos los datos de la tabla, un dato por línea)
void Tabla_Hash::print(){
    //complejidad O(1)
    for (int i = 0; i < 97; i++){
        cout<<i<<" "<<arreglo[i]<<endl;
    }
    
}





//4. buscar un dato  (si el dato no esta se imprime "dato no encontrado")
void Tabla_Hash::search(string llave){
    string placa;
    bool indica=true;

    //complejidad O(1)
    for (int i = 0; i < 97; i++){
        placa = "";
        placa = arreglo[i].substr(0, arreglo[i].find(" ") );
        if(llave == placa){
            cout<<arreglo[i]<<endl;//si la llave que se busca esta en la tabla imprimela
            indica = false;
            break;
        }
        
    }

    if(indica == true){//si el dato no esta en la tabla
        cout<<"dato no encontrado"<<endl;;
    }
}


Tabla_Hash::~Tabla_Hash(){
}
