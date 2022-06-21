//en que nivel esta un numero del arbol binario(se utilizo el codigo para los ancestros)

#include "Node.h"

#include <stack>

//complejidad lineal
int whatLevelamI(struct Node *raiz, int ENCONTRAR){
    int nivel=0;
    if (raiz == NULL){
        return -1;
    }
    stack<struct Node* > datos;
    while(true){//viaja por todo el arbol
        while (raiz && raiz->data != ENCONTRAR){
            datos.push(raiz);
            raiz = raiz->izquierda;
        }
        if (raiz && raiz->data == ENCONTRAR){
            break;
        }
        if (datos.top()->derecha == NULL){
            raiz = datos.top();
            datos.pop();
            while (!datos.empty() && datos.top()->derecha == raiz){
                raiz = datos.top();
                datos.pop();
            }
        }
        raiz = datos.empty()? NULL: datos.top()->derecha;
    }
    while (!datos.empty()){
        nivel++;
        datos.pop();
    }
    return nivel;
}
