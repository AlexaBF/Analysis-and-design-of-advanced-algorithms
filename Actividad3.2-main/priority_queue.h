//clase para implementar el arbol tipo heap

#pragma once

#include <iostream>
#include <vector>
using namespace std;

class priority_queue{
protected:
    //datos
    int SIZE_ARBOL;
    vector<int> arbol;
public:
    priority_queue(/* args */);
    void push(int);
    void ARBOL_ACOMODA(vector<int>& );
    void pop();
    void print();
    void top();
    bool empty();
    void size();
    ~priority_queue();
};

//---------------CONSTRUCTOR-------------------------------------
priority_queue::priority_queue(){
}
//---------------------------------------------------------------



//---------------------------------------PUSH--------------------------------------
//agrega elementos al arbol tipo heap
//complejidad constante O(1)
void priority_queue::push(int _dato){
    int indica=0;
    //si dato se encuentra en el arbol no meter al arbol
    for (int i = 0; i < SIZE_ARBOL; i++){
        if(arbol[i] == _dato){
            indica = 1;
            break;
        }
    }  
    if (indica == 0){
        arbol.push_back(_dato);
        SIZE_ARBOL++; 
        ARBOL_ACOMODA(arbol);
    }
}
//---------------------------------------------------------------------------------




//---------------------------------------ACOMODOA ARBOL PARA QUE SEA MAXHEAP--------------------------------------
//mergesort para el arbol O(log(n))
//complejidad lineal O(n)
void MAXHEAP(vector<int>& lista_nums, int k, int size_){

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
void priority_queue::ARBOL_ACOMODA(vector<int>& lista_nums){
    for(int k = (SIZE_ARBOL/ 2); k >= 0; k--){
        MAXHEAP(lista_nums, k, SIZE_ARBOL);//acomoda por partes 
    }
}
//----------------------------------------------------------------------------------------------------------------




//------------------------------------------------POP-----------------------------------------------------------
//Saca de la fila priorizada el dato que tiene mayor prioridad
//complejidad lineal O(n)
void priority_queue::pop(){
    if(empty() == false){//si el arbol tiene elementos

        int ultimo = arbol[SIZE_ARBOL - 1]; 

        top();//sacar a pantalla el elemento que se va a quitar
        
        //borra el ultimo elemento de arbol
        arbol.erase(arbol.begin() + (SIZE_ARBOL - 1));

        arbol[0] = ultimo; //cambiar el primero con el ultimo elemento de izq a der
    
        //cambiar el tamanio del arbol
        SIZE_ARBOL--; 
    
        //acomodar los elementos restantes
        MAXHEAP(arbol, 0, SIZE_ARBOL); 

    }else{//si el arbol esta vacio
        cout<<endl;
    }

}
//-----------------------------------------------------------------------------------------------------------





//-----------------------------------------PRINT------------------------------------------------------------
//Imprime la fila priorizada, terminando con un salto de línea, primero el dato que tiene mayor prioridad.
//complejidad lineal O(1)
void priority_queue::print(){
    for (int i = 0; i < SIZE_ARBOL; i++){
        cout<<arbol[i]<<" ";
    }
    cout<<endl;   
}
//--------------------------------------------------------------------------------------------------------




//--------------------------------------------SIZE-------------------------------------------------------
//Regresa la cantidad de datos que tiene la fila priorizada
//complejidad lineal O(1)
void priority_queue::size(){
    cout<< SIZE_ARBOL <<endl;
}
//--------------------------------------------------------------------------------------------------------




//---------------------------------------TOP-------------------------------------------------------------
//Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
//complejidad lineal O(1)
void priority_queue::top(){
    if(empty() == false){//si el arbol tiene elementos
        int top = arbol[0];
        cout<<top<<endl;
    }else{//si el arbol esta vacio

        cout<<-1<<endl;
    }
    
}
//---------------------------------------------------------------------------------------------------------



//---------------------------------------EMPTY-------------------------------------------------------------
//Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.
//complejidad lineal O(1)
bool priority_queue::empty(){
    if(SIZE_ARBOL > 0){//si el arbol tiene elementos
        return false;
    }else{//si el arbol esta vacio
        return true;
    }
}
//---------------------------------------------------------------------------------------------------------



//----------------------------------------DESTRUCTOR-------------------------------------------------------
priority_queue::~priority_queue(){
}
//---------------------------------------------------------------------------------------------------------
