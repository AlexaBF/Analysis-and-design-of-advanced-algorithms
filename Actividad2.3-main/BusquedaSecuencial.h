//busqueda de las ips

#pragma once
#include "Node.h"
#include "Ip.h"

#include "Inserta_a_lista.h"

#include <string>
#include <iostream>
using namespace std;

//complejidad Lineal O(n)
struct Node * BusqSecuencial(struct Node *head, string IP_MAYOR ,string IP_MENOR){
  struct Node *lista=NULL;
  string line="";
  bool flag=false;
  IP_MAYOR=Ip(IP_MAYOR);
  IP_MENOR=Ip(IP_MENOR);
  
  struct Node *tmp=head;//crear nodo temporal
  while (tmp!=NULL){
    if (tmp->IP.compare(IP_MAYOR) == 0){
      while (tmp->IP != IP_MENOR){
        line+= tmp->MES + " " + (tmp->FECHA) + " " + (tmp->HORA) + " " + (tmp->IP) + ":" + to_string(tmp->PUERTO) + " " + (tmp->ERROR) + "\n";
        Inserta_a_lista(&lista,line);
        tmp=tmp->next;
        line="";

      }
      if (tmp->IP.compare(IP_MENOR) == 0){
        line+= tmp->MES + " " + (tmp->FECHA) + " " + (tmp->HORA) + " " + (tmp->IP) + ":" + to_string(tmp->PUERTO) + " " + (tmp->ERROR) + "\n";
        Inserta_a_lista(&lista,line);
        line="";
      }
      return lista;
    }
    
    tmp=tmp->next;
    
  }
  return lista;
  
}
