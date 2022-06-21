//Inseta un elemento al inicio de la lista ligada

#include "Node.h"

//complejidad constante O(1)
void Inserta_al_inicio(struct Node **h,int newData){//(direccion de header, dato a introducir)
    //pasos para insertar un nodo al inicio de una lista:
    //crear el nuevoNodo
    struct Node *tmp= new Node;
    //guardamos la info / data
    tmp ->data=newData;
    //nuevo nodo->next=lo que guarda Head
    tmp ->next=(*h);
    //hago que Head apunte al nuevoNodo
    (*h)=tmp;
}
