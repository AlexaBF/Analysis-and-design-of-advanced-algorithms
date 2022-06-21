//se juntan todos los archivos h para ejcutar el programa

#include "Node.h"
#include "Insertar_nodo.h"
#include "Elimina.h"
#include "traversal.h"
#include "height.h"
#include "ancestors.h"
#include "Encuentra.h"
#include "whatLevelamI.h"

#include <iostream>
using namespace std;

int main(){
    struct Node *raiz=NULL;
    int n;//datos a insertar
    int dato;
    cin>>n;//cuantos nodos quiero insertar
    if(n> 0){
        cin>>dato;//dato a insertar en arbol

//  ------------ INSERTAR NODOS ----------------
        raiz=Insertar_nodo(raiz,dato);//inicializar arbol con el primer dato/nodo

        for (int i = 0; i < n-1; i++){//inserta datos al arbol binario
            cin>>dato;
            Insertar_nodo(raiz,dato);
        }
    }

//  ------------ ELIMINAR NODOS ----------------
    int m;
    cin>>m;//nodos a eliminar
    if(m>0){
        cin>>dato;//dato a eliminar
        raiz=Elimina(raiz,dato);
        for (int i = 0; i < m-1; i++){
            cin>>dato;//dato a eliminar
            raiz=Elimina(raiz,dato);
        }
    }

//    ------------ IMPRIME RECORRIDOS ----------------
    for (int i = 1; i <=4; i++){
        traversal(raiz,i);
    }

//  ------------ IMPRIME ALTURA DEL ARBOL ----------------

    cout<<"\n"<<height(raiz)<<endl;

//  ------------ IMPRIME ANCESTROS ----------------
    int q;// número de valores a desplegar sus ancestros
    cin>>q;
    for(int  i = 0; i < q; i++){
        cin>>dato;
        if(Encuentra(raiz,dato)){
            ancestors(raiz,dato);
            cout<<endl;
        }

    }

//  ------------ IMPRIME NIVEL DONDE SE ENCUENTRA ----------------
    int r; // número de valores a desplegar en que nivel se encuentran
    cin>>r;
    for(int i = 0; i < r; i++){
        cin>>dato;
        if(Encuentra(raiz,dato)){
            cout<<whatLevelamI(raiz,dato);
        }else{
            cout<<-1;
        }
        cout<<endl;
    }

    return 0;
}
