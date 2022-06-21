//topological sort para grafo act4.2
//Alexa Basurto Flores A01422793
//18/11/2020
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//crea lista de adjacencia
vector<int> entrada;
void loadGraph(int n, int m){//(numero de vertices, numero de arcos)
    char ALFABETO [] = {'A','B','C','D','E','F','G','H','I','J','K','L',
    'M','N','O','P','Q','R','S','T','U','V','X','Y','Z'};

    char de,para;
    vector<char> entrada_letra;
    
    //recibir datos 
    //complejidad O(n) lineal
    for(int i=0; i < m; i++){
        cin>>de>>para; 
        entrada_letra.push_back(de);
        entrada_letra.push_back(para);
    }
    
    //cambia letra a numero
    //complejidad O(n) lineal
    for(int j=0;j<entrada_letra.size();j++){
        //complejidad O(1)
        for(int i=0;i<26;i++){
            if(entrada_letra[j] == ALFABETO[i]){
                entrada.push_back(i);
            }
        }

    } 
      
}



//O(V+E) complejidad O(vertices + arcos)
//algoritmo de kahn
void topologicalSort(vector<int> entrada,int n,int m){//(lista de adjacencia, vertices, arcos)
    int inicia, apunta;
    vector<int> GRADO_ENTRADA(n, 0);//grados de entrada inicialiazrlos en cero

    queue <int> COLA;//cola para guardar resultado
    vector <int> LISTA[n]; //lista de adjacencia

    //complejidad O(n) lineal
    for(int i=0; i < m; i++){
        inicia=entrada[i*2];//toma datos de la lista del origen
        apunta=entrada[(i*2)+1];//toma datos de la lista a la destinacion
        GRADO_ENTRADA[apunta]++; 
        LISTA[inicia].push_back(apunta); //agregar arco de inicia a apunta
    }
    
    //complejidad O(n) lineal
    for(int i = 0; i < n; i++){
        if(GRADO_ENTRADA[i]==0){ 
            //los nodos que tengan un grado de entrada igual a cero son 
            //los primeros en ser evaluados para agregar a cola
            COLA.push(i);
        }
    }

    vector <int> letras;
    int PROCESADO = 0;//nodos procesados
    while(!COLA.empty()){//mientras hay nodos sin evaluar
        PROCESADO++;//nodos procesados
        //complejidad O(n) lineal
        for(int x: LISTA[COLA.front()]){//recorrer cada dato en lista para ir sacando nodos
            //reduce el grado de entrada del nodo que se esta evaluando 
            //que seria el que tiene menor grado de entrada
            GRADO_ENTRADA[x]--;
            if(GRADO_ENTRADA[x]==0){
                COLA.push(x);
            } 
        }

        letras.push_back(COLA.front() );//agrgar datos al vector para poder traducirlos con letras

        COLA.pop();
        
    }

    if(PROCESADO == n){ 
        char ALFABETO [] = {'A','B','C','D','E','F','G','H','I','J','K','L',
        'M','N','O','P','Q','R','S','T','U','V','X','Y','Z'};
        // complejidad O(n)
        for (int i = 0; i < letras.size(); i++){
            //complejidad O(1)
            for (int j = 0; j < 26; j++){
                if(letras[i]==j){
                    cout<<ALFABETO[j]<<" ";//sacar letra
                }
            }
            
        }
    }
    
   
}


bool isTree(vector<int> entrada,int n,int m){//(lista de adjacencia, vertices, arcos)
    int esarbol=1;
    int apunta;
    vector<int> GRADO_ENTRADA(n, 0);//grados de entrada
    //O(n)
    for(int i=0; i < m; i++){
        apunta=entrada[(i*2)+1];
        GRADO_ENTRADA[apunta]++; // Incrementing indegree
    }
    //O(n)
    for(int i = 0; i < n; i++){
        if(GRADO_ENTRADA[i]==0){ 
            esarbol++;//si hay nodos con grado de entrada cero
        }
    }

    if(esarbol>1){
        
        return false;
    }
    else{
        
        return true;
    }
}


int main(){
    int n,m;
    bool x;
    cin>>n;//cantidad de vertices
    if(n>0 && n<703){

        cin>>m;//cantidad de arcos

        loadGraph(n,m);//funcion para la lista
        x=isTree(entrada,n,m);//dice si es arbol
        if(x==false){
            cout<<"false"<<endl;
        }else{
            cout<<"true"<<endl;
        }
        //sort de kahn
        topologicalSort(entrada,n,m);
        
    }
   
   
   return 0;
}

