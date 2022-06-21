/*
Actividad 2.2. Implementación de "Hash String"
Última fecha de modificación: 07 Septiembre de 2021
Integrantes:
-Alexa Basurto Flores A01422793
-Karla Trejo Pichardo A01422942
-Magie Yáñez Dávila A01423011
Problema a resolver: Hash string
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

/* 
Función de cálculo para realizar la suma de los ASCII de cada char del arreglo establecido por la lectura del archivo txt. Además de que se realiza la concatenación para la salida tamaño n/4
ENTRADA: arreglo que contiene código ASCII del txt datos,cantidad de lineas y tamaño del texto leído.
SALIDA: Representación del texto en hexadecimal y concatenación de los mismos.

*/

void calculo(vector<vector<int>> arregloASCII, int cantLin,int n){
    vector<int> ans;//guarda la suma de las columnas con el %256
    vector<string> hex;//guarda valores en hexadecimal
    vector<string> concatena;//guarda el resultado 
    char hex_string[20];
    int lleva;
    int suma=0;
    int m,l;
    int operacion=0;

    cout<<endl;//-------
    for(int i=0;i<n;i++){//recorre cada columna
        suma = 0;
        for(int j=0;j<=cantLin;j++){//recorre dato en cada fila
            m=arregloASCII[j][i];
            suma+=m;// suma datos de cada columna
        }
       // cout<<"SUMA: "<<suma<<endl;
        suma = suma % 256;
        ans.push_back(suma);
    }

    cout<<endl;
    cout<<"Representación hexadecimal"<<endl;
   //Conversión a hexadecimal
    for(int h=0;h<n;h++){
        l=ans[h];
        sprintf(hex_string, "%X", l);
        hex.push_back(hex_string);
        cout<<"[ "<<hex[h]<<" ] ";
    }

    //Concatenación
    int contador=0;
    string concatenador="";
    for(int h=0;h<n;h++){

      if(contador<n/4){
         //Concatena
        concatenador+=hex[h];
       //Actualiza contador
        contador=contador+1;
      }else{

        h-=1;
        //Reinicia valor
        contador=0;
        //Guarda el valor de la concatenación en el arreglo de resutlados (push_back)
        concatena.push_back(concatenador);
        concatenador="";
      }
    }
    concatena.push_back(concatenador);
    cout<<endl<<endl;
    cout<<"Concatenación"<<endl;
    //Vector de resutlador
    for(int i=0; i<concatena.size(); i++){
      cout<<concatena[i]<<" ";
    }
}



//Aplicación principal
int main() {
    /*
    reciba el nombre de un archivo de texto,
    seguido de un entero n, 
    donde n es un entero múltiplo de 4 y  (16 <= n <=64)
    */
    int n=16;
    string nombreArchivo;
    cout<<"Ingresa el valor de N"<<endl;
    while( ( cin>>n ).fail() || (n%4)!=0 || n<16 || n>64) { 
        cin.clear(); 
        fflush(stdin); 
        cout<<".:Entrada Invalida:."<<endl;
        cout<<"Ingrese un valor para dato: "; 
	}
    
    cout<<"Ingresa el nombre del archivo de texto"<<endl;
    cin>>nombreArchivo;
    nombreArchivo = nombreArchivo + ".txt";
    string unaLinea;
    string  linea;
    fstream doc;
    doc.open(nombreArchivo);
    
    if(doc.fail()){
      cout<<"No se encontró el archivo"<<endl;
    }else{
      cout<<endl;
      cout<<"Lectura del texto "<<endl;

      while (!doc.eof()){
        
        getline(doc,unaLinea);
        unaLinea.erase(remove(unaLinea.begin(),unaLinea.end(),' '),unaLinea.end());
        cout<<" "<<unaLinea<<" "<<endl;
        linea += unaLinea + "\n";
      }
      doc.close();
      cout<<endl;
      
      //Lectura caracter por caracter
      int tamTxt = linea.size();
      int cantLin = tamTxt/n;
      int y = 0;
      string nstr(to_string(n));
      vector< vector<int>> arregloASCII(cantLin+1, vector<int>(n,n));
      vector< vector<string>> arregloTexto(cantLin+1, vector<string>(n,nstr));
    
      for (int j = 0 ; j <= cantLin; j++)
      {
        for (int k = 0; k < n; k++)
        {
          if(y == tamTxt-1)
          {
            y++;
          }
          if (y < tamTxt)
          {
            arregloASCII[j][k] = linea[y];
            arregloTexto[j][k] = linea[y];
            y++;
          }
        }
      }

      cout << "Arreglo ASCII :";
      for (int j = 0 ; j <= cantLin; j++)
      {
        cout << endl;
        for (int k = 0; k < n; k++)
        {
          cout << "["<< arregloASCII[j][k] << "] ";
        }
      }
      cout << endl << endl;

      cout << "Arreglo texto :";
      for (int j = 0 ; j <= cantLin; j++)
      {
        cout << endl;
        for (int k = 0; k < n; k++)
        {
          cout << "["<< arregloTexto[j][k] << "] ";
        }
      }
      cout<<endl;

      calculo(arregloASCII,cantLin,n);
    }

    /*
    La salida es una cadena de longitud n/4 que es una representación hexadecimal que corresponde al hasheo del archivo de texto de entrada de acuerdo con las siguientes reglas:

    el entero n determina el número de columnas que contendrá una tabla donde se irán acomodando los caracteres del archivo de texto(incluyendo saltos de líneas) en los renglones que sean necesarios 
    Si el numero de caracteres en el archivo de entrada no es múltiplo de n, el último renglón se "rellena" con el valor de n 
    En un arreglo a de longitud n se calcula a[i] = (la suma de los ASCII de cada char en la columna) % 256

    la salida se genera concatenando la representación hexadecimal (mayúsculas) a dos dígitos de cada posición en el arreglo. La longitud de la cadena de salida será de n/4.
    */
}