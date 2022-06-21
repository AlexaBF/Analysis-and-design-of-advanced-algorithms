//inserta a lista doblemente ligada

#pragma once
#include "Ip.h"
#include "Node.h"

#include <string>
#include <iostream>
using namespace std;



//complejidad lineal O(n)
void Inserta_a_lista(struct Node **h,string newData){//(direccion de header, dato a introducir)
    //crear nuevo nodo
    struct Node* Nuevo_nodo = new Node();  
    
    int pos1,pos2,pos3,pos4,pos5;//posicion de espacios en la linea de entrada
    
    for (int i = 0; i < 4; i++){//hay cuatro espacios en total
        if(i==0){
            pos1=newData.find(" ");//espacio antes de fecha
            
        }else if (i==1){
            pos2=newData.find(" ",pos1+1);//espacio antes de hora
            
        }else if (i==2){
            pos3=newData.find(" ",pos2+1);//espacio antes de ip
        }else{
            pos4=newData.find(" ",pos3+1);//espacio antes de Error
            pos5=newData.find(":",pos3+1);//inicio de puerto
            
        }
    }


    string mes=newData.substr(0, pos1);//tomar solo la parte de mes del string original
    string fecha=newData.substr(pos1+1,(pos2-(pos1+1)));//tomar solo la parte de fecha
    string hora=newData.substr(pos2+1,(pos3-(pos2+1)));//tomar solo la parte de Hora
    string ip=newData.substr(pos3+1,(pos5-(pos3+1)));//tomar solo la parte de IP
    string puerto=newData.substr(pos5+1,(pos4-(pos5+1)));//tomar solo la parte de Puerto
    string error=newData.substr(pos4+1,(( (newData.length())) )-(pos4+1));//tomar solo la parte de error


    ip=Ip(ip);
    //guardar datos en Nuevo_nodo
    Nuevo_nodo->MES=mes;
    Nuevo_nodo->FECHA=fecha;
    Nuevo_nodo->HORA=hora;
    Nuevo_nodo->IP=ip;
    Nuevo_nodo->PUERTO=stoi(puerto);
    Nuevo_nodo->ERROR=error;


    //crear Nuevo_nodo->next =final de la lista
    //el puntero de Nuevo_nodo apunta a 
    Nuevo_nodo->next = NULL; 

    if((*h)==NULL){//si la lista esta vacia
        (*h)=Nuevo_nodo;
        Nuevo_nodo->previo=NULL;
    }else{
        struct Node *tmp=(*h);//nodo temporal
        while (tmp->next!=NULL){

            tmp=tmp->next;//nodo final
        }
         
        //nodo final apunta al nuevo_nodo   
        tmp->next= Nuevo_nodo; 
        Nuevo_nodo->previo=tmp;
        
        
    }
}
