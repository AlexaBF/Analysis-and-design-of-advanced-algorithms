//imprime la lista ligada 

#include "Node.h"

#include <iostream>
using namespace std;

//complejidad Lineal O(n)
void Imprime(struct Node *h){//copia de head (apuntador a head)
    struct Node *tmp=h;//crear nodo temporal
    while (tmp!=NULL){
        cout<<tmp->data<<endl;
        tmp=tmp->next;
    }
    
}
