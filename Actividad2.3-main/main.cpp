//ejecuta todos los documentos h


#include "Inserta_a_lista.h"
#include "Imprime.h"
#include "BorrarLista.h"
#include "MergeSort.h"
#include "BusquedaSecuencial.h"
#include "SortA.h"
#include "SortD.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
  struct Node *head=NULL;
  struct Node *busca=NULL;
  string line;//linea que se sacara del doc txt
  fstream myfile;
  myfile.open ("bitacora.txt"); //abrir doc y leerlo 
  while(getline(myfile, line)){ //leer linea de archivo 
    
    Inserta_a_lista(&head,line);//agregar linea a lista

  }
  myfile.close(); //cerrar archivo

  MergeSort(&head);
  
  string IP_MAYOR;
  string IP_MENOR;
  cin>>IP_MAYOR;
  cin>>IP_MENOR;

  busca=BusqSecuencial(head,IP_MAYOR,IP_MENOR);

  
  busca=SortD(busca);
  

  Imprime(busca);

  head=SortA(head);
  
  
  //agregar al archivo sortedData orden ascendente
  ofstream out;
  out.open ("SortedData.txt");
  while (head!=NULL){
    out<<head->MES<<" "<<head->FECHA<<" "<<head->HORA<<" "<<head->IP<<":"<<head->PUERTO<<" "<<head->ERROR<<"\n";
    head=head->next;
  }

  out.close();

  BorrarLista(&head);
  BorrarLista(&busca);
  return 0;
}
