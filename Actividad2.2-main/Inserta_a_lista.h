//Inseta un elemento al final de la lista ligada

#include "Node.h"

//complejidad lineal O(n)
void Inserta_a_lista(struct Node **h,int newData){//(direccion de header, dato a introducir)
    //crear nuevo nodo
    struct Node* Nuevo_nodo = new Node();  
    
    //guardar dato en Nuevo_nodo
    Nuevo_nodo->data = newData;   

    //crear Nuevo_nodo->next =final de la lista
    //el puntero de Nuevo_nodo apunta a 
    Nuevo_nodo->next = NULL; 

    if((*h)==NULL){//si la lista esta vacia
        (*h)=Nuevo_nodo;
    }else{
        struct Node *tmp=(*h);//nodo temporal
        while (tmp->next!=NULL){

            tmp=tmp->next;//nodo final
        }
         
        //nodo final apunta al nuevo_nodo   
        tmp->next= Nuevo_nodo; 
    }



}
