//borra lista ligada

#include "Node.h"

//complejidad lineal O(n)
//borrar lista ligada 
void BorrarLista(struct Node **head){

    struct Node *tmp = *head;//nodo actual
    struct Node *snod;//siguiente nodo

    while (tmp != NULL){
       snod = tmp->next;
       delete tmp;
       tmp = snod;
    }
    *head = NULL;
   
}
