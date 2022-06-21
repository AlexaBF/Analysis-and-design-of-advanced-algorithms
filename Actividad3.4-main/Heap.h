//clase para implementar el arbol tipo heap

#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Heap{
protected:
    
    vector<string> arbol;

public:
    Heap();

    void push(string);
    void ARBOL_ACOMODA(vector< string >& );
    void pop();
    void print();
    void top();
    bool empty();
    void size();

    string linea(string);

    ~Heap();
};

//---------------CONSTRUCTOR-------------------------------------
Heap::Heap(){
}
//---------------------------------------------------------------



//---------------------------------------PUSH--------------------------------------
//agrega elementos al arbol tipo heap
//complejidad constante O(1)
void Heap::push(string _dato){
    int indica=0;

    _dato = linea(_dato);//agrega ceros a linea 

    //si linea se encuentra en el arbol no meter al arbol
    for (int i = 0; i < ( ( arbol.size() ) ); i++){
        if(arbol[i] == _dato){
            indica = 1;
            break;
        }
    }  

    //ingresa dato al arbol
    if (indica == 0){
        arbol.push_back(_dato);
        ARBOL_ACOMODA(arbol);
    }


}
//---------------------------------------------------------------------------------




//---------------------------------------ACOMODOA ARBOL PARA QUE SEA MAXHEAP--------------------------------------
//mergesort para el arbol O(log(n))
//complejidad lineal O(n)
void MAXHEAP(vector<string>& lista_nums, int k, int size_){
    int mayor_prioridad;//el mayor de todos los elementos del arbol
    int hijo_izquierdo = (2*k) + 1;
    int hijo_derecho = hijo_izquierdo + 1;

    if(hijo_izquierdo < size_ && lista_nums[hijo_izquierdo] > lista_nums[k]){//checar lado izq
        mayor_prioridad = hijo_izquierdo;
    }  
    else{
        mayor_prioridad = k;
    }  
    if(hijo_derecho < size_ && lista_nums[hijo_derecho] > lista_nums[mayor_prioridad]){//checar lado derecho
        mayor_prioridad = hijo_derecho;
    }   

    if(mayor_prioridad != k){
        swap(lista_nums[k], lista_nums[mayor_prioridad]);//cambiar numeros evaluados
        MAXHEAP(lista_nums, mayor_prioridad, size_);//volver a acomodar
    }
}
//complejidad log O(log(n))
void Heap::ARBOL_ACOMODA(vector<string>& lista_nums){
    for(int k = ( (arbol.size()) / 2); k >= 0; k--){
        MAXHEAP(lista_nums, k, ( arbol.size() ) );//acomoda por partes 
    }
}
//----------------------------------------------------------------------------------------------------------------




//------------------------------------------------POP-----------------------------------------------------------
//Saca de la fila priorizada el dato que tiene mayor prioridad
//complejidad lineal O(n)
void Heap::pop(){
    if(empty() == false){//si el arbol tiene elementos

        string ultimo = arbol[ (arbol.size()) - 1]; 

        top();//sacar a pantalla el elemento que se va a quitar
        
        //borra el ultimo elemento de arbol
        arbol.erase(arbol.begin() + ( (arbol.size()) - 1));

        arbol[0] = ultimo; //cambiar el primero con el ultimo elemento de izq a der
    
        
    
        //acomodar los elementos restantes
        MAXHEAP(arbol, 0, ( arbol.size() ) ); 

    }else{//si el arbol esta vacio
        cout<<endl;
    }

}
//-----------------------------------------------------------------------------------------------------------




//-----------------------------------------PRINT------------------------------------------------------------
//Imprime la fila priorizada, terminando con un salto de línea, primero el dato que tiene mayor prioridad.
//complejidad lineal O(1)
void Heap::print(){
    for (int i = 0; i < ( arbol.size() ); i++){
        cout<<arbol[i]<<" ";
    }
    cout<<endl;   
}
//--------------------------------------------------------------------------------------------------------




//--------------------------------------------SIZE-------------------------------------------------------
//Regresa la cantidad de datos que tiene la fila priorizada
//complejidad lineal O(1)
void Heap::size(){
    cout<<arbol.size()<<endl;
}
//--------------------------------------------------------------------------------------------------------




//---------------------------------------- QUITAR CEROS -------------------------------------------------------
string sin_cero(string STR){//quita ceros de ip
    for (int i = 0; i < (STR.length() ) ; i++){//recorre ip
        if( (STR[0]) == '0'){//si empieza con 0 quita cero del inicio
            STR.erase(STR.begin());
        }else{//sale de ciclo si no empieza con 0
            break;
        }
    }
    return STR; 
}

string Puerto_sin_cero(string puerto){//quitar ceros agregados a puerto
    for (int i = 0; i < (puerto.length() - 1) ; i++){//recorre puerto
        if (puerto[0] == '0'){//si empieza con 0 quita cero del inicio
            puerto.erase(puerto.begin());
        }else{//sale del ciclo si no inicia con 0
            break;
        }   
    }
    return puerto; 
}

string Ip_sin_cero(string ip){//quitar cero agregado de ip
    int pos1,pos2,pos3,pos4;
    //dividir IP
    for (int i = 0; i < 4; i++){//hay cuatro espacios en total
        if(i==0){
            pos1=ip.find(".");//punto 1
            
        }else if (i==1){
            pos2=ip.find(".",pos1+1);//punto 2
            
        }else if (i==2){
            pos3=ip.find(".",pos2+1);//punto 3
        }else{
            pos4=ip.find(":",pos3+1);//inicio puerto
            
        }
    }
    string ip1=ip.substr(0,pos1);//cambiar string a int antes del primer punto
    string ip2=ip.substr(pos1+1,(pos2- (pos1+1) ));//despues del primer punto hasta el segundo
    string ip3=ip.substr(pos2+1,(pos3- (pos2+1) ));//despues del segundo punto hasta el tercero
    string ip4=ip.substr(pos3+1,(pos4- (pos3+1) ));//despues del tercer punto hasta los : del puerto
    string ip5=ip.substr(pos4+1,(  (ip.length())  - (pos4+1) ));//despues del tercer punto hasta los : del puerto
   
    ip1=sin_cero(ip1);
    ip2=sin_cero(ip2);
    ip3=sin_cero(ip3);
    ip4=sin_cero(ip4);
    ip5=Puerto_sin_cero(ip5);

    string Ip=ip1 + "." + ip2 + "." + ip3 + "." + ip4 + ":" + ip5;
    return Ip;

}


string linea_sin_cero(string linea_recibida){//quitar ceros de la linea
    int pos1,pos2,pos3,pos4,pos5;//posicion de espacios en la linea de entrada
    string LINEA;

    for (int i = 0; i < 4; i++){//hay cuatro espacios en total
        if(i==0){
            pos1=linea_recibida.find(":");//inicio de puerto
            
            pos2=linea_recibida.find(" ",pos1+1);//espacio antes de fecha

        }else if (i==1){
            pos3=linea_recibida.find(" ",pos2+1);//espacio antes de Hora
            
        }else if (i==2){
            pos4=linea_recibida.find(" ",pos3+1);//espacio antes de mes

        }else{
            pos5=linea_recibida.find(" ",pos4+1);//espacio antes de Error
            
        }
    }

    string ip=linea_recibida.substr(0, pos1);//tomar solo la parte de ip del string original
    string puerto=linea_recibida.substr(pos1+1,(pos2-(pos1+1)));//tomar solo la parte de puerto
    string fecha=linea_recibida.substr(pos2+1,(pos3-(pos2+1)));//tomar solo la parte de fecha
    string hora=linea_recibida.substr(pos3+1,(pos4-(pos3+1)));//tomar solo la parte de hora
    string mes=linea_recibida.substr(pos4+1,(pos5-(pos4+1)));//tomar solo la parte de mes
    string error=linea_recibida.substr(pos5+1,(( (linea_recibida.length())) )-(pos5+1));//tomar solo la parte de error

    string i_p = ip + ":"+ puerto;
    ip=Ip_sin_cero(i_p);//quitar ceros agregados

    LINEA="";
    LINEA= mes + " " + fecha + " " + hora + " " + ip + " " +  error ;

    return LINEA;
}
//--------------------------------------------------------------------------------------------------------




//---------------------------------------TOP-------------------------------------------------------------
//Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
//complejidad lineal O(1)
void Heap::top(){
    if(empty() == false){//si el arbol tiene elementos
        string top ;
        top=linea_sin_cero( arbol[0] );//quita ceros de la linea
        cout<<top<<endl;
    }else{//si el arbol esta vacio

        cout<<-1<<endl;
    }
    
}
//---------------------------------------------------------------------------------------------------------



//---------------------------------------EMPTY-------------------------------------------------------------
//Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.
//complejidad lineal O(1)
bool Heap::empty(){
    if( (arbol.size()) > 0){//si el arbol tiene elementos
        return false;
    }else{//si el arbol esta vacio
        return true;
    }
}
//---------------------------------------------------------------------------------------------------------



//--------------------------------AGREGAR CERO PARA ACOMODAR-------------------------------------------------------
string cero(string STR){//agrega ceros a ip 
    //si tiene tres digitos esta completa la ip

    if(STR.length()==2){//si tienen 2 digitos, agrega 0 al inicio
        STR.insert(0,"0");
    }else if(STR.length()==1){//si tienen 1 digito, agrega 00 al inicio
        STR.insert(0,"00");
    }
    return STR; 
}

string Puerto(string puerto){//agrega cero al puerto
    //si tiene cuatro digitos esta completo el puerto

    if(puerto.length()==2){//si tienen 2 digitos, agrega 00 al inicio
        puerto.insert(0,"00");
    }else if(puerto.length()==1){//si tienen 1 digito, agrega 000 al inicio
        puerto.insert(0,"000");
    }else if(puerto.length() == 3){//si tienen 3 digitos, agrega 0 al inicio
        puerto.insert(0,"0");
    }
    return puerto; 
}

string Ip(string ip){//agrega ceros a la ip
    
    int pos1,pos2,pos3,pos4,pos5;
    //dividir IP
    for (int i = 0; i < 4; i++){//hay cuatro espacios/signos en total ( _ . _ . _ . _ : _) en total
        if(i==0){
            pos1=ip.find(".");//punto 1
            
        }else if (i==1){
            pos2=ip.find(".",pos1+1);//punto 2
            
        }else if (i==2){
            pos3=ip.find(".",pos2+1);//punto 3
        }else{
            pos4=ip.find(":",pos3+1);//comienzo puerto
            pos5=ip.find("\n",pos4+1);//fin puerto
        }
    }
    string ip1=ip.substr(0,pos1);//( ip1 . _ . _ . _ : _)
    string ip2=ip.substr(pos1+1,(pos2- (pos1+1) ));// ( _ . ip2 . _ . _ : _)
    string ip3=ip.substr(pos2+1,(pos3- (pos2+1) ));// ( _ . _ . ip3 . _ : _)
    string ip4=ip.substr(pos3+1,(pos4- (pos3+1) ));// ( _ . _ . _ . ip4 : _)
    string ip5=ip.substr(pos4+1,(pos5- (pos4+1) ));// ( _ . _ . _ . _ : ip5 )
    
    //colocar cero en ip llamando funciones
    ip1=cero(ip1);
    ip2=cero(ip2);
    ip3=cero(ip3);
    ip4=cero(ip4);
    ip5=Puerto(ip5);

    string Ip=ip1 + "." + ip2 +"." + ip3 + "." + ip4 + ":" + ip5;
    return Ip;

}

string Heap::linea(string newData){//separa la linea por datos para agregar ceros y poder acomodar de manera correcta
    int pos1,pos2,pos3,pos4,pos5;//posicion de espacios en la linea de entrada
    string LINEA;

    for (int i = 0; i < 4; i++){//hay cuatro espacios en total
        if(i==0){
            pos1=newData.find(" ");//espacio antes de fecha
            
        }else if (i==1){
            pos2=newData.find(" ",pos1+1);//espacio antes de hora
            
        }else if (i==2){
            pos3=newData.find(" ",pos2+1);//espacio antes de ip
        }else{
            pos4=newData.find(" ",pos3+1);//espacio antes de Error
            pos5=newData.find(":",pos3+1);//inicio de puerto
            
        }
    }

    string mes=newData.substr(0, pos1);//tomar solo la parte de mes del string original
    string fecha=newData.substr(pos1+1,(pos2-(pos1+1)));//tomar solo la parte de fecha
    string hora=newData.substr(pos2+1,(pos3-(pos2+1)));//tomar solo la parte de Hora
    string ip=newData.substr(pos3+1,(pos5-(pos3+1)));//tomar solo la parte de IP
    string puerto=newData.substr(pos5+1,(pos4-(pos5+1)));//tomar solo la parte de Puerto
    string error=newData.substr(pos4+1,(( (newData.length())) )-(pos4+1));//tomar solo la parte de error

    string i_p = ip + ":"+ puerto;

    ip=Ip(i_p);//llama funcion para agrgar ceros

    LINEA="";
    LINEA= ip + " " + fecha + " " + hora + " " + mes + " " +  error ;

    return LINEA;
}
//---------------------------------------------------------------------------------------------------------



//----------------------------------------DESTRUCTOR-------------------------------------------------------
Heap::~Heap(){
}
//---------------------------------------------------------------------------------------------------------
