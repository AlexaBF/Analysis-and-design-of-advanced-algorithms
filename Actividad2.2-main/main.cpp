//operaciones con listas ligadas
//llamar todas las funciones, entradas y salidas en este main 

#include "Inserta_a_lista.h"
#include "Imprime.h"
#include "Reverse.h"
#include "Concat.h"
#include "Equals.h"

#include <iostream>
using namespace std;

int main(){
    struct Node *head1=NULL;//iniciar lista ligada_1
    struct Node *head2=NULL;//iniciar lista ligada_2
    int m=-1,n=-1,dato;//variables de entrada
    while(m<0){ //evaluar entrada para lista 1
        cin>>m;
    }
    while(m>0){//crear lista ligada 1
        cin>>dato;
        Inserta_a_lista(&head1,dato);
        m--;
    }

    while(n<0){//evaluar entrada para lista 2
        cin>>n;
    }
    while(n>0){//crear lista ligada 2
        cin>>dato;
        Inserta_a_lista(&head2,dato);
        n--;
    }

    Reverse(&head1);//invierte lista ligada 1
    Reverse(&head2);//invierte lista ligada 2
    Imprime(head1);//imprime lista ligada 1
    Imprime(head2);//imprime lista ligada 2
    Concat(head1,head2);//unir listas
    if (head2==NULL && head1!=NULL){
        Imprime(head1);
    }else{
        Imprime(head2);//reversed list 2 + reversed list 1
    }

    if((Equals(head1,head2))==0){
        cout<<"false"<<endl;
    }else{
        cout<<"true"<<endl;
    }
    

    //complejidad lineal O(n)
    //borrar lista ligada 1
    while (head2!=NULL ){
        head2=head2->next;//nodo final
        delete head2;//borrar lista
    }
    head1=NULL;
    

    //borrar lista ligada 2
    while (head2!=NULL ){
        head2=head2->next;//nodo final
        delete head2;//borrar lista

    }

    head2=NULL;

    
    return 0;
}
