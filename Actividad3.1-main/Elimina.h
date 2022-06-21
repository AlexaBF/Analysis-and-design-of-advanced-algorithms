//Eliminar nodos del arbol binario


#include "Node.h"

#include <queue>

//complejidad lineal O(n)
struct Node * min(struct Node* raiz){//encuentra el valor menor
    struct Node* tmp = raiz;
    while (tmp && tmp ->izquierda != NULL){
		tmp=tmp->izquierda;
	}
    return tmp;
}
//complejidad lineal O(n)
struct Node* Elimina(struct Node *raiz, int dato_a_eliminar){
    if (raiz == NULL){//cuando el arbol llegue al final
		return raiz;
	}
    if (dato_a_eliminar < raiz->data){//si el dato_a_eliminar es menor a raiz
		raiz->izquierda = Elimina(raiz->izquierda,dato_a_eliminar);
	}
    else if (dato_a_eliminar > raiz->data){//si el dato_a_eliminar es mayor a raiz
		raiz->derecha = Elimina(raiz->derecha,dato_a_eliminar);
	}
    else{ //si el dato_a_eliminar es la raiz
        //tiene un hijo (izquierda o derecha)
        if (raiz->izquierda == NULL){
            struct Node *temp=raiz->derecha;
			delete raiz;
            return temp;
        }
        else if (raiz->derecha == NULL){
            struct Node *temp=raiz->izquierda;
			delete raiz;
            return temp;
        }
        //tiene dos hijos (izquierda y derecha)
        struct Node* temp=min(raiz->derecha);
        raiz->data=temp->data;
        raiz->derecha=Elimina(raiz->derecha,temp->data);
    }
    return raiz;
}
