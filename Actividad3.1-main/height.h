//consigue la altura del arbol

#include "Node.h"

//complejidad lineal O(n)
int maximo(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }

}
//complejidad lineal O(n)
int height(struct Node *raiz){
    int altura=0;
    if(raiz == NULL){
        return altura;
    }
    altura=maximo(height(raiz->izquierda), height(raiz->derecha)) + 1;
    return altura;
}
