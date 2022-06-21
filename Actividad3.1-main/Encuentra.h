//verifica si se encuentra el valor dentro del arbol binario

#include "Node.h"

//complejidad lineal O(n)
bool Encuentra(struct Node* raiz, int VERIFICA){
    if (raiz == NULL){
        return false;
    }
    if (raiz->data == VERIFICA){
        return true;
    }
    bool izq=Encuentra(raiz->izquierda,VERIFICA);//checa lado izquierdo
    if(izq){//se encontro el nodo
        return true; 
    } 
    bool der=Encuentra(raiz->derecha,VERIFICA);
    return der;
}
