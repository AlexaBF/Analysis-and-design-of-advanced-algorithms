//Revisa si dos listas ligadas tienen el mismo contenido.
//Salida	true / false

#include "Node.h"

//complejidad lineal O(n)
bool Equals(struct Node *h1,struct Node *h2){//(copia lista 1,copia lista2)
    if (h1==NULL && h2==NULL){
        return true;
    }else if((h1==NULL && h2!=NULL)||(h2==NULL && h1!=NULL)){
        return false;
    }else{
    
        struct Node *tmp_1=(h1);//nodo temporal para lista 1
        struct Node *tmp_2=(h2);//nodo temporal para lista 2
        while (tmp_1->next!=NULL && tmp_2->next!=NULL){
            if(tmp_1->data != tmp_2->data){
                return false;
            }
            tmp_1=tmp_1->next;//nodo final
            tmp_2=tmp_2->next;//nodo final
        }
        return true;
    }
}
