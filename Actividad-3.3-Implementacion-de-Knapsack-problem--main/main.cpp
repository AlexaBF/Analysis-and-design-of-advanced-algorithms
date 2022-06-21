/*
Actividad 3.3 Implementación de "Knapsack problem"
Última fecha de modificación: 16 Octubre de 2021
Problema a resolver: Algoritmo de la mochila
*/

#include <iostream>
#include <vector>
using namespace std;
/*
La entrada al programa es un número N que representa el número de elementos posibles disponibles,
seguido de N enteros que representan el valor de cada uno de esos elementos,
seguido de N enteros que representan los pesos asociados a cada elemento.
por último, un entero W, que representa el peso máximo o capacidad de la mochila.

Número de elementos	3
Beneficios	1
            2
            3
Pesos	    4
            5
            1
Peso máximo de la mochila	4
*/

void Knapsack(int n, int w, vector<int> peso, vector<int> beneficio){
    //Declaración de arreglo de beneficios
    int B[n][w];
    
    //Inicialización
    for(int a=0;a<w;a++){
        B[0][a]=0;
    }
    for(int a=0;a<n;a++){
       B[a][0]=0;
    }

    //Knapsack
    for(int i=1;i<=n-1;++i){
        for(int j=1;j<=w-1;++j){
            if(j-peso[i]<0){  //Si el peso del objeto es menor se hace la asignación de uno de los pesos anteriores
                B[i][j]=B[i-1][j];
            }
            else{//Elemento que podría ser parte de la solución
                //Si el peso del objeto es menor al peso total de la mochila 
                B[i][j]= max(B[i-1][j], B[i-1][j-peso[i]] + beneficio[i]);
            }
        }
    }

    //Imprimir Matriz
    cout<<"\n\nMatriz Generada\n\n"<<endl;
    int valorBeneficio=-1;
    for(int u=0;u<w;u++){
      for(int i=0;i<n;i++){
        cout<<"[ "<<B[i][u]<<" ]";
        if(B[i][u]>valorBeneficio){
          valorBeneficio=B[i][u];
        }
      }
      cout<<endl;
    }
    cout<<"\n\nBeneficio Óptimo: "<<valorBeneficio<<endl;
}


int main(){
    int n; //cantidad de elementos
    int b; //valor de cada uno de los elementos
    int p; //peso asociado a los elementos
    int w; //peso maximo

    vector <int> beneficio;//guarda valores de beneficio
    vector <int> peso;//guarda valores de peso

    cout<<"Ingrese la cantidad de elmentos"<<endl;
    cin>>n;
    //valida que la entreda n sea un número positivo
    while(n<0 || n==0 ){
      cout<<"No puedes ingresar números negativos o menores que 0, vuelve a intentarlo"<<endl;
      cin>>n;
    }
    n++;
    beneficio.push_back(0);
    cout<<"Ingrese el beneficio de cada uno de los elementos"<<endl;
    for(int i=1;i<n;i++){
      cin>>b;
      beneficio.push_back(b);
    }

    peso.push_back(0);
    cout<<"Ingrese el peso de cada uno de los elementos"<<endl;
     for(int i=1;i<n;i++){
      cin>>p;
      peso.push_back(p);
    }

    cout<<"Ingrese el peso maximo"<<endl;
    cin>>w;
    w++;

    //Arreglo de elementos
    cout<<"\nPeso/Beneficio"<<endl;
    for(int i=0;i<n;i++){
        cout<<"[ "<<peso[i]<<" " << beneficio[i]<<" ] \n"<<endl;
    }
    
    //llama a la función
    //la funcion toma n= cantidad de elementos, w = el peso máximo
    //peso = vector con  el peso de cada elemento
    //beneficio = vector con  el beneficio de cada elemento
    Knapsack(n,w,peso,beneficio);
    

    /*
    La salida del programa debe ser la ganancia (o beneficio) óptimo.
    Ejemplo de salida:
        Beneficio óptimo	3
    Matriz generada:
        < mostrar matriz final >
    */
    return 0;
}