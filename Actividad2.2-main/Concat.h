//Concatena lista1 + lista2

#include "Node.h"

//complejidad lineal O(n)
void Concat(struct Node *h1,struct Node *h2){//(copia lista 1,copia lista2)
    if(h1==NULL && h2!=NULL){
        return;
    }else if(h2==NULL && h1!=NULL){
        return;
    }else if(h1==NULL && h2==NULL){
        return;
    }else{
        struct Node *tmp=(h2);//nodo temporal
        while (tmp->next!=NULL){
            tmp=tmp->next;//nodo final
        }
        tmp->next=h1;
    }
}
