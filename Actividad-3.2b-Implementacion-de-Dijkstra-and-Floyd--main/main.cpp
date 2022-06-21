/*
Actividad 3.2b Implementación de "Dijkstra and Floyd"
Última fecha de modificación: 12 Septiembre de 2021
Integrantes:
-Alexa Basurto Flores A01422793
-Karla Trejo Pichardo A01422942
-Magie Yáñez Dávila A01423011
Problema a resolver: Encontrar el recorrido más corto
*/
#include <iostream>
#include <vector>
#include<climits>
using namespace std;
int inf=999;

//funcion Dijkstra
//recibe el tamaño de la matriz, la fila de la matriz y la matriz
void Dijkstra(int n,int nodo,vector<vector<int>> mat){
    
	int caminoCorto[n],visitado[n]; //Arreglos de respuesta y validación
    int minNode,minVal;//valores minimos analizados

    //Inicialización del arreglo donde se guardará el resultado  
	for(int i=0;i<n;i++){
        caminoCorto[i] = mat[nodo][i];
    }
		
    //Inicialización del arreglo que valida las visitas
    for(int i =0;i<n;i++){
        visitado[i]=0;
    }
    //inicia con el primer nodo y lo marca como visitado
	visitado[nodo] = 1;

    int cuenta = 1;//cuenta para iteracion del while	
	while(cuenta<n){
		minVal = inf;
		
    //Validacion si el nodo ha sido visitado o no
		for(int i=0;i<n;i++){
			if(visitado[i] == 0 && caminoCorto[i]<minVal){
				minVal = caminoCorto[i];
				minNode = i;
			}
        }
		visitado[minNode] = 1; //Ya fue visitado
		
    //Iteracion para encontrar el camino más corto
		for(int i=0;i<n;i++){
			if(visitado[i] == 0){ //Si no ha visitado el nodo obtiene el mínimo
				caminoCorto[i] = min(caminoCorto[i],minVal+mat[minNode][i]);
            }
        }			
		cuenta++; 
	}
    
	
    //Imprime el valor
	for(int i=0;i<n;i++){
        cout<<"node "<<nodo+1<<" to node "<<i+1<<": "<<caminoCorto[i]<<endl;
    }    
    cout<<endl;
}

//funcion FloydWarshall
//recibe la matriz, y el tamaño de la matriz
void FloydWarshall( vector<vector<int>> res, int n){
    int i, j ,k;

    //recorre cada arco de la matriz original res
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                //matriz[i,j] = min(matriz[i,j],matriz[i,k] + matriz[k,1j])
                if (res[i][k] + res[k][j] < res[i][j]){
                    res[i][j] = res[i][k] + res[k][j];
                }
            }
        }
    }
     
    cout<<"Floyd"<<endl;
    //imprime resultado
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"[ "<<res[i][j]<<" ] ";
        }
        cout<<endl;
    }

}

int main() {
    /*
    El primer número representa el número de nodos, los siguientes valores en la matriz, el valor en la posición 
    i,j representan el peso del arco del nodo i al nodo j. Si no hay un arco entre el nodo i y el nodo j, el valor
    en la matriz debe ser -1.
    */

    int n;//dimensión matriz
    int valor;
    cout<<"Inserte número de filas y columnas: ";
    cin>>n;

    //valida que la entreda n sea un número positivo
    while(n<0 || n==0 ){
      cout<<"No puedes ingresar números negativos o menores que 0, vuelve a intentarlo"<<endl;
      cin>>n;

    }

    //se declara la matriz 
    vector<vector<int>> matriz (n);
    //inicializar la matriz 
    for ( int i = 0 ; i < n ; i++ ){
        matriz[i].resize(n);
    }


    //VALORES EN LA MATRIZ
    cout<<"Ingresa los valores de la matriz "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>valor;
            if(valor==-1){
                matriz[i][j]=inf;
            }else{
                matriz[i][j]=valor;
            }  
        }
    }
  
    //IMPRIMIENDO LA MATRIZ
    //imprime matriz original
    cout<<endl;
    cout<<"Entrada"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matriz[i][j]==inf){
                cout<<"[ -1 ] ";
            }else{
                cout<<"[ "<<matriz[i][j]<<" ] ";
            }
        }
        cout<<endl;
    }

    //Llamando al algoritmo Dijkstra y FloydWarshall
    cout<<"\nDijkstra\n"<<endl;
    for(int i=0;i<n;i++){ //Envia por fila
        Dijkstra(n,i,matriz);
    }
        
    FloydWarshall(matriz,n);


    /*
    La salida del programa es, primero con el algoritmo de Dijkstra la distancia del 
    nodo i al nodo j para todos los nodos, y luego, la matriz resultado del algoritmo 
    de Floyd
    */
    
    return 0;


}