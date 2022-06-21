//crea e inserta un nodo al BST


#include "Node.h"

//complejidad constante O(1)
struct Node *Crear_Nodo(int dato_nuevo){//crear nodo en el arbol binario 
    struct Node *temp=new struct Node; //nodo temporal
    temp->data=dato_nuevo;//guardar dato_nuevo en el nodo
    temp->izquierda=NULL;
    temp->derecha=NULL;
    return temp; //regresar direccion del nuevo nodo
} 
//complejidad lineal O(n)
struct Node* Insertar_nodo(struct Node* arbol_b, int dato_nuevo){ 
    if (arbol_b == NULL){//si el arbol esta vacio solo crea el nuevo nodo
        return Crear_Nodo(dato_nuevo); 
    }
    //recorre el arbol y compara para insertar dato_nuevo
    if (dato_nuevo < arbol_b->data){//si el dato nuevo es menor 
        arbol_b->izquierda=Insertar_nodo(arbol_b->izquierda,dato_nuevo); 
    }
    else if(dato_nuevo > arbol_b->data){ //si el dato nuevo es mayor
        arbol_b->derecha=Insertar_nodo(arbol_b->derecha,dato_nuevo);    
    }
    return arbol_b;//regresa arbol modificado
} 
