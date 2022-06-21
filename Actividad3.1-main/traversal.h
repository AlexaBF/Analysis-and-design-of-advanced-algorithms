//Imprimir recorrido Preorden
//Imprimir recorrido Inorden
//Imprimir recorrido Postorden
//Imprimir recorrido Nivel por Nivel

#include "Node.h"

#include <queue> 

//complejidad lineal O(n)
void Preorden(struct Node *raiz){ 
    if (raiz != NULL){ 
        cout<<raiz->data<<" "; 
        Preorden(raiz->izquierda); 
        Preorden(raiz->derecha); 
    } 
} 

//complejidad lineal O(n)
void Inorden(struct Node *raiz){ 
    if (raiz != NULL){ 
        Inorden(raiz->izquierda); 
        cout<<raiz->data<<" "; 
        Inorden(raiz->derecha); 
    } 
} 

//complejidad lineal O(n)
void Postorden(struct Node *raiz){ 
    if (raiz != NULL){ 
        Postorden(raiz->izquierda); 
        Postorden(raiz->derecha); 
        cout<<raiz->data<<" "; 
    } 
} 

//complejidad lineal O(n)
void Nivel(struct Node *raiz){  
    // Base Case  
    if (raiz == NULL){
        return;
    }
    queue<struct Node *> por_nivel;//crear cola para guardar datos por nivel 
    por_nivel.push(raiz);//inicializa la cola
    while (por_nivel.empty() == false){  
        int size_arbol_hijos=por_nivel.size();//variables que se encuentran en ese nivel  
        while (size_arbol_hijos > 0){  
            struct Node *tmp = por_nivel.front();//toma el primer valor de la cola
            cout << tmp->data<<" ";//muestra el valor en ese nivel
            por_nivel.pop();//lo borra de la cola
            if (tmp->izquierda != NULL){
                por_nivel.push(tmp->izquierda);//agrega su hijo izquierdo
            } 
            if (tmp->derecha != NULL){
                por_nivel.push(tmp->derecha);//agrega su hijo derecho
            } 
            size_arbol_hijos--;  
        }  
    }  
}


//complejidad lineal O(n)
void traversal(struct Node *raiz,int Indicador){
    if(raiz == NULL){
        cout<<endl;
    }
    else{
        if(Indicador == 1){
        Preorden(raiz);
        cout<<endl;
        }
        else if(Indicador == 2){
            Inorden(raiz);
            cout<<endl;
        }
        else if(Indicador == 3){
            Postorden(raiz);
            cout<<endl;
        }else{
            Nivel(raiz);
            
        }
    }
}
