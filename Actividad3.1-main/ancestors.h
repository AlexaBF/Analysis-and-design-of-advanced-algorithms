//consigue los acestros de un numero

#pragma once
#include "Node.h"

#include <stack>
#include <vector>
using namespace std;

//complejidad lineal O(n)
void ancestors(struct Node *raiz, int ENCONTRAR){
    vector<int> numeros;
    if(raiz == NULL){
        return;
    }
    stack<struct Node* > datos;//guarda los ancestros
    while(true){//examina todo el arbol binario hasta que encuentre el numero ENCONTRAR
        while(raiz && raiz->data != ENCONTRAR){//checa el lado izquierdo
            datos.push(raiz);
            raiz=raiz->izquierda;
        }
        if(raiz && raiz->data == ENCONTRAR){//sale de examinar , enontro ENCONTRAR
            break;
        }
        if(datos.top()->derecha == NULL){//checa derecha
            raiz=datos.top();
            datos.pop();
            while(!datos.empty() && datos.top()->derecha == raiz){
                raiz=datos.top();
                datos.pop();
            }
        }
        raiz=datos.empty()? NULL: datos.top()->derecha;
    }
    while(!datos.empty()){//guarda datos del stack en vector
        numeros.push_back(datos.top()->data);
        datos.pop();
    }
    for(int i = (numeros.size() - 1) ; i >=0 ; i--){//imprime vector
        cout<<numeros[i]<<" ";
    }
    numeros.clear();//limpia vector
}
