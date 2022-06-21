//Eliminar al elemento que se encuentra al final de la lista ligada. 
//Si la lista esta vacia, se escribe la palabra ERROR

#include "Node.h"

#include <iostream>
using namespace std;

//complejidad lineal O(n)
void Elimina_al_final(struct Node **h){//(direccion header)
    struct Node *tmp=(*h);//crear nodo temporal
    struct Node *pnod=new Node;//crear nodo que apunta al penultimo nodo

    if(*h==NULL){//la lista esta vacia
        cout<<"ERROR"<<endl;
    }
    else{
        while (tmp->next!=NULL){
            pnod=tmp;//apunta al penultimo nodo
            tmp=tmp->next;//ultimo nodo
        }
        pnod->next=NULL;//penultimo nodo apunta al final(NULL)
    
    }
    delete tmp;//se elimina el nodo final/temporal

}
