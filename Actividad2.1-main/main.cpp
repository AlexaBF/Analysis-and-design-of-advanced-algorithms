//Implementación de un ADT de estructura de datos lineales (Listas Ligadas)
//se llaman todas las funciones, entradas y salidas en este main 

#include "Inserta_al_inicio.h"
#include "Inserta_al_final.h"
#include "Elimina_al_inicio.h"
#include "Elimina_al_final.h"
#include "Imprime.h"

#include <iostream>
using namespace std;

int main(){
    int entrada=-1,x;//declarar variables de entrada de usuario
    struct Node *head=NULL;//crear header/inicio lista
    

    //complejidad lineal O(n)
    while (entrada!=0){
        cin>>entrada;
        if (entrada==1){//inserta al inicio
            cin>>x;
            Inserta_al_inicio(&head,x);//(direccion de header, dato a introducir)

        }else if(entrada==2){//Inserta al final
            cin>>x;
            Inserta_al_final(&head,x);//(direccion de header, dato a introducir)

        }else if(entrada==3){//Elimina inicio
            Elimina_al_inicio(&head);//(direccion de header)

        }else if(entrada==4){//Elimina final
            Elimina_al_final(&head);//(direccion de header)

        }else if(entrada==5){//Imprime
            Imprime(head);//(copia de head)
        }
        
    }

    //complejidad lineal O(n)
    while (head->next!=NULL){//borrar lista ligada
        head=head->next;//nodo final
        delete head;//borrar lista
    }
    head=NULL;
    
    return 0;
}
