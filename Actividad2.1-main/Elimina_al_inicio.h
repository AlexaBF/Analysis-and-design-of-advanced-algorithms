//Eliminar al elemento que se encuentra al inicio de la lista ligada. 
//Si la lista esta vacia, se escribe la palabra ERROR

#include "Node.h"

#include <iostream>
using namespace std;

//complejidad constante O(1)
void Elimina_al_inicio(struct Node **h){//(direccion de header)
    if (*h==NULL){//si la lista esta vacia
        cout<<"ERROR"<<endl;
    }
    else{
        //crear nuevo nodo temporal
        struct Node *tmp = (*h);
        (*h)=(*h)->next;//cambiar a donde apunta header
        delete tmp;//liberar espacio se nodo temporal
        
    }

}
