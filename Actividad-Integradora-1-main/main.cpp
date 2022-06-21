/*
Actividad Integradora 1
Última fecha de modificación: 22 Septiembre de 2021
Integrantes:
-Alexa Basurto Flores A01422793
-Karla Trejo Pichardo A01422942
-Magie Yáñez Dávila A01423011
Problema a resolver: Análisis de código malicioso
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Funcion para implementar Knuth–Morris–Pratt (KMP) 
//Complejidad lineal O(n) en el peor caso
void KMP(vector<char> transmission,vector<char> mcode){
   //Longitudes
 int trans=transmission.size(); //Longitud del archivo 
 int m=mcode.size(); //Longitud de archivo mcode1
 bool validar=false;  

  vector<int>lps(m + 1,0); //Vector donde se guarda el procesamiento

  //Validaciones 
  if(m==0){ //el archivo transmission es de menor tamaño de el malicioso
    cout<<"Archivo mcode no válido"<<endl;
    return;
  }
  if(trans<m){ //el archivo transmission es de menor tamaño de el malicioso
    cout<<"Archivo transmission no válido"<<endl;
    return;
  }
  //Procesamiento del vector
  for (int i = 1; i < m; i++){
      int j=lps[i+1];
      while(j>0 && mcode[j] != mcode[i]) {
        j = lps[j];
      }

      if (j > 0 || mcode[j] == mcode[i]) {
            lps[i + 1] = j + 1;
        }
    }
  cout<<endl;
    //Comprobaciones
  for (int i=0,j=0;i<trans;i++){
      if (transmission[i]==mcode[j]){
        if(++j==m){
          cout<<"(true) "<<"Posición inicial: "<<i-j+1<<" Posición final: "<<i+j+1<<endl;
          validar=true;
        }
      }
      else if (j > 0){
          j = lps[j];
          i--;
      }
  } 
  if (validar == 0){
    cout<<"(false) "<< "Cadena no encontrada en la transmision"<<endl;
  }  
}

//Funcion para leer archivos .txt
//regresa un vector tipo char
vector<char> leerTxt(vector<char> vec,string archivo){
    fstream doc;
    char unaLinea;
    //Lectura de archivo
    doc.open(archivo);//abre archivo
    
    if(doc.fail()){
      cout<<"No se encontró el archivo"<<endl;
    }else{
      while (!doc.eof()){
        doc>>unaLinea;
        if (!doc.eof()){
        vec.push_back(unaLinea);//guarda caracteres de cada linea en un vector tipo char
        }
      }
      doc.close();//cierra archivo
    }
    return vec;//regrasa vector tipo char con datos de l .txt
}

vector<string> leerTxtStr(vector<string> vec,string archivo){
  fstream doc;
  string unaLinea;
  string lineas;
  //Lectura de archivo
  doc.open(archivo);//abre archivo
  if(!doc.fail()){
    while (!doc.eof()){
      getline (doc, unaLinea);//guarda caracteres de cada linea en un vector tipo string
      vec.push_back(unaLinea);
      }
    }
    doc.close();//cierra archivo
    return vec;//regrasa vector tipo string con datos del .txt
  }
    
//Función para realizar análisis de las substrings encontradas en cada archivo de texto Transmission1 y Transmisison2.
//Complejidad de la función substrT O(m*n)
void substrT (vector <string> transmission, vector <string> &substrT, vector <int> &posiT){
  int j = 0, k, i;
  int sum = 0;
  //Divide el texto y guarda la división en un arreglo
  for (k=0; k < transmission.size(); k++) {
    j=transmission[k].size(); //tamaño
    for (i = 0; i < transmission[k].size(); i++){
      substrT.push_back(transmission[k].substr(i, j));
      posiT.push_back(sum);
      sum++;
      j--;   
    } 
    sum++;
  }
}

/* Función para realizar comparativa entre las substrings encontradas, además de mostrar pantalla la cadena común más larga encontrada. 
Complejidad de la función comparativaSubstr O(m*n) */
void comparativaSubstr (vector <string> substrT1, vector <int> posiT1, vector <string> substrT2, vector <int> posiT2) {
  int subStrSize = 0;
  string subStr = "";
  for (int j = 0; j < substrT1.size(); j++) {
    for (int k = 0; k < substrT2.size(); k++) {
      if (substrT1[j] == substrT2[k]) {
        if (substrT1[j].size() > subStrSize) { //Si la posición encontrada es mayor que el tamaño encontrado anteriormente, sustituye
          subStrSize = substrT1[j].size();
          subStr = substrT1[j];
        }
      }
    }
  }
  if (subStr != "")
  {
    cout  << endl <<endl<<endl<< "Sub-String más largo: " << subStr << endl;
    cout << endl << "Posiciones en la Transmission1: " << endl;
    for (int j = 0; j < substrT1.size(); j++) {
      if (substrT1[j] == subStr) {
        cout<<"Posición inicial: "<<posiT1[j]+1<<" Posición final: "<<posiT1[j]+subStrSize+1<<endl;
      }
    }

  cout << endl << "Posiciones en la Transmission2: " << endl;
    for (int j = 0; j < substrT2.size(); j++) {
      if(substrT2[j ]== subStr){
        cout<<"Posición inicial: "<<posiT2[j]+1<<" Posición final: "<<posiT2[j]+subStrSize+1<<endl;
      }
    }
  }
  else {
    cout <<endl<<endl<< "No se encontró un substring compartido en ambas transmisiciones"<< endl;
  }
}


int main() {
    /*
    5 archivos de texto (de nombre fijo, no se piden al usuario) que contienen
    exclusivamente caracteres del 0 al 9, caracteres entre A y F y saltos de línea.
    */
  
    //Declaracion de vectores tipo char de transmission y mcode
    vector<char> transmission1;
    vector<char> transmission2;
    vector<char> mcode1;
    vector<char> mcode2;
    vector<char> mcode3;
    vector<string> t1;
    vector<string> t2;

    vector<string> substrT1; //Vector para almacenar substring de Transmission1 
    vector<string> substrT2; //Vector para almacenar substring de Transmission2 
    vector<int> posiT1; // Recorrer (Almacenar posición inicial de substring)
    vector<int> posiT2; // Recorrer (Almacenar posición inicial de substring)
    
    //Lectura de archivos transmission
    transmission1 = leerTxt(transmission1,"transmission1.txt");
    t1 = leerTxtStr (t1,"transmission1.txt");
    transmission2 = leerTxt(transmission2,"transmission2.txt");
    t2 = leerTxtStr (t2,"transmission2.txt");

    //Lectura de archivos mcode
    mcode1 = leerTxt(mcode1,"mcode1.txt");
    mcode2 = leerTxt(mcode2,"mcode2.txt");
    mcode3 = leerTxt(mcode3,"mcode3.txt");

    //Lectura
    cout<<endl<<endl<<"Archivo transmission1"<<endl;
    for(int i=0;i<t1.size();i++)
        cout<<t1[i];
    cout<<endl<<endl<<"Archivo transmission2"<<endl;
    for(int i=0;i<t2.size();i++)
        cout<<t2[i];

    //Lectura
    cout<<endl<<endl<<"Archivo mcode1"<<endl;
    for(int i=0;i<mcode1.size();i++)
        cout<<mcode1[i];
    cout<<endl<<endl<<"Archivo mcode2"<<endl;
    for(int i=0;i<mcode2.size();i++)
        cout<<mcode2[i];
    cout<<endl<<endl<<"Archivo mcode3"<<endl;
    for(int i=0;i<mcode3.size();i++)
        cout<<mcode3[i];
    
    //Llamando a la función
    cout<<endl<<endl<<" T R A N S M I S S I O N   1"<<endl;
    cout<<endl<<"mcode 1 ";
    KMP(transmission1,mcode1);
    cout<<endl<<"mcode 2 ";
    KMP(transmission1,mcode2);
    cout<<endl<<"mcode 3 ";
    KMP(transmission1,mcode3);

    cout<<endl<<" T R A N S M I S S I O N   2"<<endl;
    cout<<endl<<"mcode 1 ";
    KMP(transmission2,mcode1);
    cout<<endl<<"mcode 2 ";
    KMP(transmission2,mcode2);
    cout<<endl<<"mcode 3 ";
    KMP(transmission2,mcode3);

    //Llamado a función apra análisis de subtrings
    substrT(t1,substrT1,posiT1);
    substrT(t2,substrT2,posiT2);
    comparativaSubstr(substrT1, posiT1, substrT2, posiT2);
    
    
    /*
    ----------- SALIDA -------------
    parte 1 
      (true | false) si es que el archivo transmission1.txt contiene el código (secuencia de chars) contenido en el archivo mcode1.txt   
      (true | false) si es que el archivo transmission1.txt contiene el código (secuencia de chars) contenido en el archivo mcode2.txt 
      (true | false) si es que el archivo transmission1.txt contiene el código (secuencia de chars) contenido en el archivo mcode3.txt 
      (true | false) si es que el archivo transmission2.txt contiene el código (secuencia de chars) contenido en el archivo mcode1.txt 
      (true | false) si es que el archivo transmission2.txt contiene el código (secuencia de chars) contenido en el archivo mcode2.txt 
      (true | false) si es que el archivo transmission2.txt contiene el código (secuencia de chars) contenido en el archivo mcode3.txt 

    parte2

     posiciónInicial posiciónFinal (para archivo de transmisión1) 
     posiciónInicial posiciónFinal (para archivo de transmisión2) 
     
    parte3 

      posiciónInicial posiciónFinal (de substring común más largo entre archivos de transmisión

    */ 
}