/*
Actividad 3.1b Implementación de "Tries"
Última fecha de modificación: 09 Octubre de 2021
Integrantes:  
-Alexa Basurto Flores A01422793
-Karla Trejo Pichardo A01422942
-Magie Yáñez Dávila A01423011
Problema a resolver: Estructura de datos TRIE
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

/*
Estructura TRIE, nos ayuda a determinar si una palabra está terminada o no, además de que también toma en consideración un arreglo del tamaño del abecedario
*/
struct Trie{ 
    struct Trie *abecedario[26];
    bool finalPalabra;
};

/*
Estructura obtener nodo, nos ayuda a encontrar determinado nodo.
*/

struct Trie * obtenerNodo(){
    struct Trie *pNode =  new Trie;
    pNode->finalPalabra = false;
 
    for (int i = 0; i < 26; i++){
        pNode->abecedario[i] = NULL;
    }
    return pNode;
};

/*
Función insertar. Esta función nos ayuda a realizar la inserción de un nodo. 
Esta función es llamada desde el main para realizar las inserciones de la palabra ingresada por el usuario.
*/
void insertar(struct Trie * root,string palabra){
    struct Trie *p=root;
    int n = palabra.length();
    char data;

    for (int i = 0; i < n; i++){
        int llave=palabra[i]-'a'; //llave  caracter
        if(!p->abecedario[llave]){
            p->abecedario[llave]=obtenerNodo();
        }
        p=p->abecedario[llave];
    }
    p->finalPalabra=true;
}


/*
Función DFS. Función que nos ayuda a realizar el recorrido DFS de forma recursiva. 
*/
void DFS(struct Trie* root, char str[], int nivel){
    
    /*if (root->finalPalabra){//si termina el recorrido de una rama
        //str[nivel] = '\0';
        //cout<<str << " ";
    }*/

    for (int i = 0; i < 26; i++){//recorre cada rama o cada abecedario
        if (root->abecedario[i]){
            str[nivel] = i + 'a';
            //cout<<"str[nivel]: "<<str[nivel]<<endl;
            //lleva.push_back(str[nivel]);
            cout<<str[nivel]<<" ";
            //cout<<"nivel: "<<nivel<<endl;
            DFS(root->abecedario[i], str, nivel++);
        } 
    } 
}


/*
Función Búsqueda. Esta función nos ayuda a realizar la búsqueda de los nodos, de tal forma que devuelve 0 o 1 si se encuentra o no la palabra a buscar determinada por el usuario.
*/
bool Busqueda(struct Trie *root, string palabra){
    struct Trie *busca = root;
    int indica=0;
	for (int i = 0; i < palabra.length(); i++){
		indica = palabra[i] - 'a';
		if (!busca->abecedario[indica]){
            cout<<busca->abecedario[indica];
            return false;
        }
		busca = busca->abecedario[indica];
	}
    //regressa 1 si es que la palabra se encuentra en la estructura
    //o regresa 0 si es que no se encuentra en l estructura 
	return (busca->finalPalabra);
}

int main() {
    /*
    Escribe un programa en C++ que implemente una estructura de datos TRIE. 
    Escribe también un programa que permita verificar su funcionalidad. 
    La entrada al programa es un número N, seguido de N palabras, 
    que serán insertadas a la estructura.
    Después se lee un dato M seguido de M palabras a buscar en la estructura.
    */

    int n;//numero de datos en la estructura
    int m;//numero de datos a buscar en la estructura
    string k;
    vector<string> palabras; //datos en la estructura
    vector<string> palabrasB; //palabras a buscar dentro de la estructura
    cout<<"Ingrese la cantidad de datos en la estructura"<<endl;
    cin>>n;

      //Validación 
      while(n<-1 || n==0  ){
        cout<<"Vuelve a ingresar el valor "<<endl;
        cin>>n;
    }


    //Ingresando las palabras al arreglo
    cout<<"Ingrese las palabras a colocar"<<endl;
    for(int i=0;i<n;i++){
        cin>>k;
        palabras.push_back(k);
    }

    
    //Tamaño del arreglo
    int tamano = palabras.size();

    struct Trie *root = obtenerNodo();

    for(int i=0;i<tamano;i++){
        insertar(root,palabras[i]);
    }

    cout<<"Ingresa la cantidad a palabras a buscar"<<endl;
    cin>>m;
          //Validación 
      while(m<-1 || m==0 || m>n  ){
        cout<<"Vuelve a ingresar el valor "<<endl;
        cin>>n;
    }
    
    cout<<"Ingresa las palabras a buscar"<<endl;
    for (int i=0;i<m;i++){
        cin>>k;
        palabrasB.push_back(k);
    }
 
    //Imprime DFS
    cout<<"\n----------Salida DFS----------"<<endl;
    char str[100];
    DFS(root, str, 0);
    cout<<"\n------------------------------"<<endl;


    cout<<"\nBuscando palabras"<<endl;
    for (int i=0;i<m;i++){
        if(Busqueda(root,palabrasB[i]) ){
            cout<<palabrasB[i]<<" true"<<endl;
        }else{
            cout<<palabrasB[i]<<" false"<<endl;
        }
    }

    /*La salida del programa es el recorrido DFS del TRIE, 
    seguido de M booleanos correspondientes al resultado 
    de buscar cada una de las M palabras en la estructura.*/

    return 0;
}