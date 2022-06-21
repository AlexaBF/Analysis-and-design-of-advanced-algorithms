//invierte el contenido de la lista ligada,
//regesando un pointer al inicio de nueva lista

#include "Node.h"

//complejidad lineal O(n)
struct Node * Reverse(struct Node **h){
    if((*h) == NULL){//en caso de que la lista este vacia
        return (*h);//regresa un apuntador al inicio de la lista 
    }else{
        struct Node *tmp=(*h);//nodo actual
        struct Node *pnod=NULL;//nodo previo al actual
        struct Node *snod=NULL;//nodo siguiente al nodo actual
        
        while(tmp != NULL){
            snod = tmp->next;
            tmp->next = pnod;
            pnod = tmp;
            tmp = snod;
        }
        (*h)=pnod;//head apunta al ultimo listo de la lista
        return *h;//regreso puntero a inicio lista
    }
    
}

