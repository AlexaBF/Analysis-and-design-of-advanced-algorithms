/*
Actividad Integradora 2
Última fecha de modificación: 09 Noviembre de 2021
Problema a resolver: Situación Problema 2
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int inf=999;
//archivo
ofstream archivoFinal;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   1    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Funcion Dijkstra
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
				archivoFinal<<"node "<<nodo+1<<" to node "<<i+1<<": "<<caminoCorto[i]<<endl;
    }  
	 
    cout<<endl;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   2    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Algortimo del Viajero
//recibe la matriz y el tamaño o  n = representa el número de colonias en la ciudad.
int Viajero(vector<vector<int> > tsp,int tamano){
    int sum = 0;
    int counter = 0;
    int i = 0, j = 0;//i=filas j=columnas
    int min = inf;
    map<int, int> visitedRouteList;
    visitedRouteList[0] = 1;//valida si ya se visitaron todo los nodos
    int route[tamano];
    while (i < tamano){
        //Si el contador es igual que el tamaño sale
        if (counter >= tamano - 1){ 
            break;
        }

        //Recorrido
        //Si aún no se ha visitado el nodo entonces
        if (j != i && visitedRouteList[j] == 0){
            //Mientras que el valor encontrado es menor que el valor mínimo
            if (tsp[i][j] < min){ 
                min = tsp[i][j];//actualiza el valor mínimo
                route[counter] = j + 1;
            }
        }
        j++;
	    
        //Visitas
        if (j == tamano){ 
            sum += min;//Suma de el valor mínimo
            min = inf;
            visitedRouteList[route[counter] - 1] = 1;//el nodo se marca como visitado
            j = 0; //columnas
            i = route[counter] - 1; //filas
            counter++;				
        }
    }


    cout<< "\nRuta a seguir: " << 1 <<" ";
    for (int o=0; o<tamano-1; o++){
        cout<< route[o] <<" ";
				archivoFinal<<route[o] <<" ";
    }
		archivoFinal<<1<<endl;
    cout<< 1 << endl;
    i = route[counter - 1] - 1; //Ultima pos
    min = tsp[i][j];
    sum += min;
	cout<<"El costo mínimo es: "<<sum<<endl;
	archivoFinal<<"El costo mínimo es: "<<sum<<endl;



    return sum;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   3    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//algoritmo de Breadth First Search o Busqueda en Anchura para un grafo
//recibe la matriz que representa el grafo, n= tamaño o número de colonias,
///un número entero "inicio", un número entero "fin"
// y una lista "padre" de números enteros de tamaño n
bool BFS(vector<vector<int>> grafo,int n,int inicio,int fin,int padre[]){

	bool visitado[n];
    memset(visitado, 0, sizeof(visitado));

    queue<int> q;
    q.push(inicio);
    visitado[inicio] = true;
    padre[inicio] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (visitado[v] == false && grafo[u][v] > 0) {
                q.push(v);
                padre[v] = u;
               visitado[v] = true;
            }
        }
    }

    return (visitado[fin] == true);
}


//algoritmo Bellman-Ford o Ford para obtener el camino más corto
//recibe la matriz que representa el grafo, n= tamaño o número de colonias,
///un número entero "inicio" = 0, un número entero "fin" = n-1
int Ford(vector<vector<int>> vec,int n,int inicio,int fin){
	int flujoMax=0;//Variable para realizar la suma del flujo Maximo
	int padre[n]; 

	//Acomodo del arreglo
	vector<vector<int>> grafo(n);
	for ( int i = 0 ; i < n ; i++ ){
        grafo[i].resize(n);
    }

    //inicializa el grafo
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			grafo[i][j]=vec[i][j];
		}
	}
	
	
	//Actualizaciones-> Trabajando con el residual
    while (BFS(grafo,n, inicio, fin, padre)) {
		int sumatoria=inf;

		for (int i = fin; i != inicio; i = padre[i]) {
            int u = padre[i];
            sumatoria = min(sumatoria, grafo[u][i]);
        }

        for (int j = fin; j != inicio; j = padre[j]) {
            int u = padre[j];
            grafo[u][j] -= sumatoria;
            grafo[j][u] += sumatoria;
        }

        // Flujo Máximo
        flujoMax += sumatoria;
    }
		archivoFinal<<"Flujo Máximo "<<flujoMax<<endl;
    return flujoMax;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~   4    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//algoritmo k-nearest neighbors
//recibe las coordenadas, n= tamaño o número de colonias,recibe coordenadas 
void KNN(vector<vector<int>> arr, int n, vector<vector<int>> p){
    vector<vector<float>> dist(n,vector<float> (n));
    //llenar distancia de todos los puntos de p
    for (int i = 0; i < n; i++){
        dist[i][0] =
        sqrt(
        (arr[i][0] - p[0][0]) * (arr[i][0] - p[0][0]) +
        (arr[i][1] - p[0][1]) * (arr[i][1] - p[0][1]));
    }
  

    //Revisa cual es la distancia menor a la nueva central y el nodo al que corresponde
    float menor=0, aux=0, nodoMenor=0;
    for(int x = 0; x < n; x++){
        aux = dist[x][0];
        if (x==0){
            menor = aux;
        }else if (menor > aux){
            menor = aux;
            nodoMenor = x+1;
        }
    }

    //Imprime la matriz de distancias a la nueva central
    cout << "Distancia de cada central con respecto a la nueva central\n";
		archivoFinal<<"Distancia de cada central con respecto a la nueva central\n";
    for(int x = 0; x < n; x++){
        cout<<"Central "<< x+1 <<"  [ "<<dist[x][0]<<" ] " << endl;
				archivoFinal<<"Central "<< x+1 <<"  [ "<<dist[x][0]<<" ] " << endl;
    }

    //Imprime el resultado del nodo más cercano y la distancia
    cout << "\nLa central más cercana es la número: " << nodoMenor << "\nSe encuentra a una distancia de: " << menor << endl;
		archivoFinal<< "\nLa central más cercana es la número: " << nodoMenor << "\nSe encuentra a una distancia de: " << menor << endl;
}


//lee cada archivo txt guardando la información en un vector
//recibe vector que modifica, nombre del archivo, n y m = tamaño
void leerTxt(vector<vector<int>> &vec,string archivo,int n, int m){

    //lee archivo
    string line;
    int i=0, j=0;
    fstream doc(archivo);
    while(getline(doc,line)){
        if(i<n){
            if(j<m){
                vec[i][j]=stoi(line);
                j++;
            } else {
                j=0;
                i++;
                vec[i][j]=stoi(line);
                j++;
            }
        }
    }
    doc.close();
}



int main() {

    int n=4;//representa el número de colonias en la ciudad.
   
    //se declara la matriz 
    vector<vector<int>> matriz  (n, vector<int> (n));
	vector<vector<int>> matriz2 (n, vector<int> (n));
	vector<vector<int>> matriz3 (6, vector<int> (6));
    vector<vector<int>> matriz4 (n, vector<int> (3));
    vector<vector<int>> matriz5 (1, vector<int> (3));
			//Generando archivo
		archivoFinal.open("Equipo_07_Salida_Y.txt",ios::out);
		if(archivoFinal.fail()){
			cout<<"No se abrió un archivo"<<endl;

		}
		archivoFinal<<"~~~~~~~~~~~~~ 1 ~~~~~~~~~~~~~"<<endl;
    //Lectura de archivo -> "archivo.txt"
    leerTxt(matriz, "archivo.txt", n, n);

    cout<<"\nGuardando matriz 1\n"<<endl;
		archivoFinal<<"\nGuardando matriz 1\n"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"[ "<<matriz[i][j]<<" ] ";
						archivoFinal<<"[ "<<matriz[i][j]<<" ] ";

        }
				archivoFinal<<endl;
        cout<<endl;
    }
    
	
	//Llamando al algoritmo Dijkstra
    cout<<"\n~~~~~~~~~~~~~~   1    ~~~~~~~~~~~~~~\n"<<endl;
	
    for(int i=0;i<n;i++){ //Envia por fila
        Dijkstra(n,i,matriz);
    }

    cout<<"\n~~~~~~~~~~~~~~   2    ~~~~~~~~~~~~~~\n";
		archivoFinal<<"~~~~~~~~~~~~~ 2 ~~~~~~~~~~~~~"<<endl;
    Viajero(matriz,n);

    cout<<"\n~~~~~~~~~~~~~~   3    ~~~~~~~~~~~~~~\n"<<endl;
		archivoFinal<<"~~~~~~~~~~~~~ 3 ~~~~~~~~~~~~~"<<endl;
    
    //Lectura de archivo ->"archivo2.txt"
    leerTxt(matriz2, "archivo2.txt", n, n);
    cout<<"\nGuardando matriz 2\n"<<endl;
		archivoFinal<<"\nGuardando matriz 2\n"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"[ "<<matriz2[i][j]<<" ] ";
						archivoFinal<<"[ "<<matriz2[i][j]<<" ] ";
        }
				archivoFinal<<endl;
        cout<<endl;
    }
		//Matriz, tamaño,0,n-1
    cout<<"\nFlujo Máximo: "<<Ford(matriz2,n,0,n-1)<<endl;



    //La pruebota
    leerTxt(matriz3, "archivo5.txt", 6, 6);
    cout<<"\nGuardando matriz 2.1\n"<<endl;
		archivoFinal<<"\nGuardando matriz 2.1\n"<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
					archivoFinal<<"[ "<<matriz3[i][j]<<" ] ";
            cout<<"[ "<<matriz3[i][j]<<" ] ";
        }
				archivoFinal<<endl;
        cout<<endl;
    }
    //Matriz, tamaño,0,n-1
    cout<<"\nFlujo Máximo: "<<Ford(matriz3,6,0,5)<<endl;

    cout<<"\n~~~~~~~~~~~~~~   4    ~~~~~~~~~~~~~~\n"<<endl;
		archivoFinal<<"~~~~~~~~~~~~~ 4 ~~~~~~~~~~~~~"<<endl;
    
    //Lectura de archivo ->"archivo3.txt"
    leerTxt(matriz4, "archivo3.txt", n, 2);

    cout<<"\nGuardando matriz 3\n"<<endl;
		archivoFinal<<"\nGuardando matriz 3\n"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
					archivoFinal<<"[ "<<matriz4[i][j]<<" ] ";
            cout<<"[ "<<matriz4[i][j]<<" ] ";
        }
				archivoFinal<<endl;
        cout<<endl;
    }

    //Lectura de archivo ->"archivo4.txt"
    leerTxt(matriz5, "archivo4.txt", 1, 2);
    cout<<"\nGuardando matriz 3.1\n"<<endl;
		archivoFinal<<"\nGuardando matriz 3.1\n"<<endl;
    for(int i=0;i<1;i++){
        for(int j=0;j<2;j++){
					archivoFinal<<"[ "<<matriz5[i][j]<<" ] ";
            cout<<"[ "<<matriz5[i][j]<<" ] ";
        }
				archivoFinal<<endl<<endl;
        cout<<endl<<endl;
    }

    KNN(matriz4, n, matriz5);
		archivoFinal.close();

    return 0;
}
