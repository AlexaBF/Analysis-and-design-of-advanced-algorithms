//imprime lista

#include "Node.h"

#include <iostream>
using namespace std;

//complejidad Lineal O(n)
void Imprime(struct Node *h){//copia de head (apuntador a head)
    
    struct Node *tmp=h;//crear nodo temporal
    while (tmp!=NULL){
        cout<<tmp->MES<<" "<<tmp->FECHA<<" "<<tmp->HORA<<" "<<tmp->IP<<":"<<tmp->PUERTO<<" "<<tmp->ERROR;
        tmp=tmp->next;
    }
    
}
