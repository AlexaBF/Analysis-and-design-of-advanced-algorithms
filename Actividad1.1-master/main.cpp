/*
codificar tres formas de sumar arreglos:
-suma iterativa
-suma recursiva
-suma directa
autora: Alexa Basurto Flores  A01422793
fecha: 30/08/2020
*/
#include <iostream>
using namespace std;
//
//complejidad lineal O(n)
int sumaIterativa(int n){
  int suma=0;
  for (int i = 1; i <=n; i++){
    suma+=i;
  }
  return suma;
}
//
//complejidad lineal O(n)
int sumaRecursiva(int n){
  if (n==0){
    return 0;
  }
  else{
    return n + sumaRecursiva(n-1);
  }
}
//
//complejidad  O(n) lineal
int sumaDirecta(int n){
  return (n*(n+1))/2;  //formula suma de Gauss
}


int main(){
  int k;//cantidad de enteros 
  cin>>k;
  
  while (k<1 || k>10000){  //evaluar si esta dentro del rango
    cout<<"'k' fuera del rango, intente de nuevo"<<endl;
    cin>>k;
  }
  int num[k];//crear un array con el tamaño de k

  for (int i = 0; i < k; i++){//O(n)
    cin>>num[i];          //ingresar los elementos del array
    while (num[i]<1 || num[1]>100000){  //verificar que los elementos esten dentro del rango 
      cout<<"'n' fuera de rango, intente de nuevo"<<endl;
      cin>>num[i];
    }
  }
  
  for (int i = 0; i < k; i++){   //meter cada elemento del array en cada función O(n)
    //mostrar el resultado de cada elemento como se indica en la actividad
    cout<<sumaIterativa(num[i])<<" "<<sumaRecursiva(num[i])<<" "<<sumaDirecta(num[i])<<endl;
  }
  
  return 0;
}
