#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "MEStoNUM.h"
#include "NUMtoMES.h"
#include "mergeSort.h"
#include "busqSecuencial.h"
#include "imprimirDatos.h"

using namespace std;

int main(){
  vector<string> ORIGINAL;//vector con archivo original
  vector<string> DESCENDIENTE;//par la salida sortedData muestra la lista de manera descendiente
  string line;//linea que se sacara del doc txt
  int FECHA;
  int MES;
  string BUSCA;//variable para la busqueda usuario
  vector<int> BUSCAR_LINEA;//donde estan los indices de la informacion a buscar de input
  
  fstream myfile;
  myfile.open ("bitacora.txt"); //abrir doc y leerlo 
  while(getline(myfile, line)){ //leer linea de archivo 
    ORIGINAL.push_back(line);//agregar linea al vector
  }
  myfile.close(); //cerrar archivo

  
  ORIGINAL = MEStoNUM(ORIGINAL);
  
  
  int SIZE=ORIGINAL.size();

  MERGESORT(ORIGINAL, 0, SIZE-1);

  DESCENDIENTE = NUMtoMES(ORIGINAL);

  


  //agregar al archivo sortedData cada linea del vector ORIGINAL
  //orden descendente
  ofstream out;
  out.open ("sortedData.txt");
  for(int i=(SIZE)-1;i>=0;i--){ 
    out <<DESCENDIENTE[i]<<"\n";
  }
  out.close();
  
  
  //entradas usuario 
  cin>>FECHA;
  cin>>MES;
  if(FECHA<10 && MES<10){
    BUSCA="0" + to_string(MES)+ " 0" + to_string(FECHA);
  }else if(FECHA<10){
    BUSCA=to_string(MES) + " 0" + to_string(FECHA);
  }else if(MES<10){
    BUSCA= "0" + to_string(MES)+ " " + to_string(FECHA);
  }else{
    BUSCA=to_string(MES)+ " " + to_string(FECHA);
  }

  BUSCAR_LINEA = busqSecuencial(ORIGINAL, BUSCA);
  ORIGINAL = NUMtoMES(ORIGINAL);
  imprimirDatos(ORIGINAL,BUSCAR_LINEA);


  return 0;
}