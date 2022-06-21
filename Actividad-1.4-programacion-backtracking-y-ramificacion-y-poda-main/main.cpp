/*
Actividad 1.4 Implementación de la técnica de programación "backtracking" y "ramificación y poda"
Última fecha de modificación: 30 de Agosto de 2021
Integrantes:
-Alexa Basurto Flores A01422793
-Karla Trejo Pichardo A01422942
-Magie Yáñez Dávila A01423011
Problema a resolver: Rat in a maze
*/
#include <iostream>
#include <vector>
using namespace std;

bool esSeguro (vector<vector<int>> mapa, int i, int j, int n){
    /* Función de comprobación para ver si los caminos que se estan probando ir para encontrar una solución son validos.
    ENTRADAS: mapa; matriz de vectores del problema al laberinto.
              i; valor que indica la fila en donde se esta probando.
              j; valor que indica la columna en donde se esta probando.
              n; El valor que indica el tamaño de la matriz.
    SALIDAS: Regresa true si las variables de entrada son validas y si la es un camino (1)  la posición actual.
            Regresa false si las variables no son validas o es una pared (0) la posicion actual*/
    if ( (i >= 0 && i < n) && (j >= 0 && j < n) && (mapa[i][j] == 1))
        return true;
    return false;
}

bool findPath(vector<vector<int>> mapa,vector<vector<int>> solucion,int i, int j, int n){
    /* Función de para encontrar las posibles soluciones del laberinto.
    ENTRADAS: mapa; matriz de vectores del problema al laberinto.
              solucion; matriz de vectores que mapea la solución elegida del laberinto.
              i; valor que indica la fila que se va a probar.
              j; valor que indica la columna que se va a probar.
              n; El valor que indica el tamaño de la matriz.
    SALIDAS: Regresa si encuentra una solución al problema.
            Regresa false si no encuentra ningun camino con la solución deseada*/
    if(i==n-1 && j==n-1 && mapa[i][j] == 1){ //caso base
        solucion[i][j]=1;//Si entra aquí es porque encontró la salida
        cout<<"Backtracking"<<endl;
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<" [ "<<solucion[i][j]<<" ] ";
        }
        cout<<endl;
    }
        return true;
    }
    
    if (esSeguro(mapa,i, j, n)) 
    {
        // Checa si el bloque donde está ya está considerada como solución. 
        if (solucion[i][j] == 1)
            return false;
        // Si no estaba como parte de la solución, lo agrega como parte.
        solucion[i][j] = 1;
        // Se mueve a la siguiente casilla
        if(findPath(mapa,solucion,i,j+1,n)==true) //Moviendo a la derecha
            return true;
        
        if(findPath(mapa,solucion,i+1,j,n)==true){//Moviendo hacia abajo
            return true;
        }
        if(findPath(mapa,solucion,i,j-1,n)==true){//Moviendo hacia la izquierda
            return true;
        }
        if(findPath(mapa,solucion,i-1,j,n)==true){//Moviendo hacia arriba
            return true;
        }
        solucion[i][j]=0;// Si entra aqui, este camino no era solución, entonces lo borra.
        return false;
    }
    return false; 
}

//----------------------------------------------------------------------------------------------------------------------

bool esSeguro (vector<vector<int>> mapa, int i, int j, int n, int pasosI, int pasosMaximo){
    /* Función de comprobación para ver si los caminos que se estan probando ir para encontrar una solución son validos.
    ENTRADAS: mapa; matriz de vectores del problema al laberinto.
              i; valor que indica la fila en donde se esta probando.
              j; valor que indica la columna en donde se esta probando.
              n; El valor que indica el tamaño de la matriz.
              pasosI; El valor inicial de los pasos a dar para salir del laberinto
              pasosMaximo; El valor máximo de los pasos a dar para salir del laberinto
    SALIDAS: Regresa true si las variables de entrada son validas y si la es un camino (1)  la posición actual.
            Regresa false si las variables no son validas o es una pared (0) la posicion actual*/
    if ( (i >= 0 && i < n) && (j >= 0 && j < n) && (mapa[i][j] == 1) && (pasosI < pasosMaximo) ){
        return true;}
    
    return false;
}

bool ramiPoda(vector<vector<int>> mapa,vector<vector<int>> solucion,int i, int j, int n, int pasosI, int pasosMaximo){
    /* Función de para encontrar las posibles soluciones del laberinto.
    ENTRADAS: mapa; matriz de vectores del problema al laberinto.
              solucion; matriz de vectores que mapea la solución elegida del laberinto.
              i; valor que indica la fila que se va a probar.
              j; valor que indica la columna que se va a probar.
              n; El valor que indica el tamaño de la matriz.
              pasosI; El valor inicial de los pasos a dar para salir del laberinto
              pasosMaximo; El valor máximo de los pasos a dar para salir del laberinto
    SALIDAS: Regresa si encuentra una solución al problema con las limitaciones dadas.
            Regresa false si no encuentra ningun camino con la solución deseada*/
    if(i==n-1 && j==n-1 && mapa[i][j] == 1 && pasosI <= pasosMaximo){ //caso base
        solucion[i][j]=1;
        pasosI ++;//Si entra aquí es porque encontró la salida
        cout<<"Ramificación y Poda"<<endl;
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<" [ "<<solucion[i][j]<<" ] ";
        }
        cout<<endl;
    }
        return true;
    }
    
    if (esSeguro(mapa,i, j, n, pasosI, pasosMaximo) )
    {
        pasosI ++;
        // Checa si el bloque donde está ya está considerada como solución. 
        if (solucion[i][j] == 1)
            return false;
        // Si no estaba como parte de la solución, lo agrega como parte.
        solucion[i][j] = 1;
        // Se mueve a la siguiente casilla
        if(ramiPoda(mapa,solucion,i,j+1,n, pasosI, pasosMaximo)==true) //Moviendo a la derecha
            return true;
        
        if(ramiPoda(mapa,solucion,i+1,j,n, pasosI,pasosMaximo)==true){//Moviendo hacia abajo
            return true;
        }
        if(ramiPoda(mapa,solucion,i,j-1,n, pasosI, pasosMaximo)==true){//Moviendo hacia la izquierda
            return true;
        }
        if(ramiPoda(mapa,solucion,i-1,j,n, pasosI, pasosMaximo)==true){//Moviendo hacia arriba
            return true;
        }
        solucion[i][j]=0;// Si entra aqui, este camino no era solución, entonces lo borra.
        return false;
    }
    return false; 
}

int valorValidoInt(int valor){
    /*FUNCION: función para validar que los valores de entrada sean numeros reales.
    ENTRADA: int valor; valor que se debera validar.
    SALIDA: El valor cuando sea aceptable (un valor real). */
	while( ( cin>>valor ).fail() || valor<=0) { 
			cin.clear(); 
			fflush(stdin); 
			cout<<".:Entrada Invalida:."<<endl;
			cout<<"Ingrese un valor para dato: ";  
		}
	cin.clear(); 
	fflush(stdin); 
	return valor;
}

bool valorValidoBool(bool valor){
    /*FUNCION: función para validar que los valores de entrada sean numeros reales.
    ENTRADA: int valor; valor que se debera validar.
    SALIDA: El valor cuando sea aceptable (un valor real). */
	while( ( cin>>valor ).fail() || valor<0 || valor>1) { 
			cin.clear(); 
			fflush(stdin); 
			cout<<".:Entrada Invalida:."<<endl;
			cout<<"Ingrese un valor para dato: ";  
		}
	cin.clear(); 
	fflush(stdin); 
	return valor;
}


int main() {
  /*
    El programa recibe dos números enteros M y N, seguido de M líneas de N valores booleanos(0|1) separados por un espacio, 
    por la entrada estándar que representan el laberinto. Un 1 representa una casilla en la que es posible moverse, un 0 es una
    casilla por la que NO se puede pasar. 
    El origen o casilla de inicio es siempre la casilla (0,0) y la salida o meta es siempre la casilla (M-1, N-1).*/
    int M,pasosMaximo;
    bool valor;
    cout<<"Inserte número de filas y columnas: ";
    M=valorValidoInt(M);

    cout<<"Ingresa los pasos maximo: ";
    pasosMaximo=valorValidoInt(pasosMaximo);
    
    //Declaracion de matriz original y matrz solucion
    vector<vector<int>> matriz (M);
    vector<vector<int>> solucion (M);
    vector<vector<int>> solucionBB (M);

    //Dimensiona matriz original
    for ( int i = 0 ; i < M ; i++ ){
        matriz[i].resize(M);
    }
    
    //Dimensiona matriz solucion
    for ( int i = 0 ; i < M ; i++ ){
        solucion[i].resize(M);
    }
   
    //Dimensiona matriz solucion
    for ( int i = 0 ; i < M ; i++ ){
        solucionBB[i].resize(M);
    }
   
    //Llenar matriz
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            cout<<"["<<i<<"]"<<"["<<j<<"]: ";
            valor=valorValidoBool(valor);
            matriz[i][j]=valor;
        }
    }

    //Imprimir matriz original
    cout<<endl;
    cout<<"Laberinto "<<endl;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            cout<<" [ "<<matriz[i][j]<<" ] ";
        }
        cout<<endl;
    }
    
//----------------------------------------------------------------------------------------------------------
    //Llenar matriz
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
          solucion[i][j]=0; 
        }
    }

    //Llenar matriz
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
          solucionBB[i][j]=0;
        }
    }

    findPath(matriz,solucion,0,0,M);
    cout<<endl;
    ramiPoda(matriz,solucion,0,0,M,0,pasosMaximo);

//---------------------------------------------------------------------------------------------------------- 
/*
    La salida del programa es una matriz de valores booleanos (0|1) que representan el camino para salir del laberinto. Primero debe mostrarse 
    la solución utilizando la técnica de backtracking, y luego utilizando la técnica de ramificación y poda.
  */
    return 0;  
}