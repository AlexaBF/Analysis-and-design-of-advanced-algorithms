//recorrido por grafo
//Alexa Basurto Flores
//A01422793
//16/11/2020

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;




/*//Matriz de Adyacencia y un entero representado el nodo incial.
void DFS(vector<int> matriz,int nodo_inicial){
    string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26 letras
    int tam=sqrt(matriz.size());
    int matrix[tam][tam];
    vector<string> procesado;
    vector<string> pila;
    vector <string> lista;

    int k=0,f=0,q=0;
    string dato_entrada;
    
    for (int i = 0; i < nodo_inicial; i++){
        dato_entrada="";
        if (i>=26){ // si el tamanio de la matriz es mayor a z saca dos letras al principio de la lista  
            dato_entrada = dato_entrada + alfabeto[k] + alfabeto[f];
        }
        else{//las primeras 26 letras hasta z
            dato_entrada =alfabeto[i];
        }
        for (int j = 0; j < nodo_inicial; j++){
            dato_entrada="";
            if (j>=26){
                dato_entrada= dato_entrada + alfabeto[k]+ alfabeto[q];
                q++;
            }
            else{
                dato_entrada=alfabeto[j];
                
            }
        }
        q=0;
        if(i>=26){
            f++;
        }
        if(i%26==0 && i>26){
            k++;
        }
        
    }

     //procesado.push_back(dato_entrada);
    pila.push_back(dato_entrada);


    //crear matriz

    int tamanio=sqrt(matriz.size());
    int recorre=0;
    for (int i = 0; i < tamanio; i++){
        for (int j = 0; j < tamanio; j++){
            matrix[i][j]=matriz[recorre];
            recorre ++;
        }   
    }
    k=0, f=0,q=0;
    dato_entrada="";
    lista.push_back("para");
    for (int i = 0; i < tamanio; i++){
        if (i>=26){ // si el tamanio de la matriz es mayor a z saca dos letras al principio de la lista
            
            dato_entrada = dato_entrada + alfabeto[k] + alfabeto[f];
            lista.push_back(dato_entrada);

        }
        else{//las primeras 26 letras hasta z

            dato_entrada =alfabeto[i];
            lista.push_back(dato_entrada);

        }
        
        for (int j = 0; j < tamanio; j++){
            if (j>=26 && matrix[i][j] == 0 ){
                q++;
            }

            if (matrix[i][j] == 1){
                dato_entrada="";
                if (j>=26){
 
                    dato_entrada= dato_entrada + alfabeto[k]+ alfabeto[q];

                    lista.push_back(dato_entrada);

                    q++;
                    
                }
                else{
                    dato_entrada=alfabeto[j];
                    lista.push_back(dato_entrada);

                }               
            } 
        }

        q=0;
        if(i>=26){
            f++;
        }
        if(i%26==0 && i>26){
            k++;
        }
        dato_entrada="";
        
        lista.push_back("para");//indicador donde termina la lista
    }

    vector<string> evalua;
    string busca="";
    while(!pila.empty()){//mientras la pila no este vacia
        procesado.push_back( pila[0] );//marcar como procesado
        busca+=pila[0];
        pila.erase(pila.begin());//elimina el primer elemento
        for (int j = 0; j < lista.size(); j++){
            if(busca == lista[j] && lista[j-1]=="para"){
                if(count(procesado.begin(),procesado.end(),busca) != true){
                    evalua.push_back(busca);
                    
                }
                
            }
        }
        sort(evalua.begin(), evalua.end());//acomoda alfabeticamente
        for(int k=0;k < evalua.size();k++){
            pila.push_back(evalua[k]);
        }
        evalua.clear();

        
    }
} 
*/

/*
//MATRIZ DE ADYACENCIA Y UN ENTERO REPRESENTANDO EL NODO INICIAL
void DFS(vector<vector<int> > MATRIZ , int nodo_inicial){
    string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26 letras
    vector<string> procesado;
    vector<string> pila;
    vector<vector<string> > MAT;
    int tamanio=MATRIZ.size();
    int k=0, f=0,q=0;
    string dato_entrada="";
    
    
    for (int i = 0; i < tamanio; i++){
        vector<string> tmp;
        if (i>=26){ // si el tamanio de la matriz es mayor a z saca dos letras al principio de la lista
            
            dato_entrada = dato_entrada + alfabeto[k] + alfabeto[f];
            tmp.push_back(dato_entrada);

        }
        else{//las primeras 26 letras hasta z

            dato_entrada =alfabeto[i];
            tmp.push_back(dato_entrada);

        }
        
        for (int j = 0; j < tamanio; j++){
            if (j>=26 && MATRIZ[i][j] == 0 ){
                q++;
            }

            if (MATRIZ[i][j] == 1){
                dato_entrada="";
                if (j>=26){
 
                    dato_entrada= dato_entrada + alfabeto[k]+ alfabeto[q];

                    tmp.push_back(dato_entrada);

                    q++;
                    
                }
                else{
                    dato_entrada=alfabeto[j];
                    tmp.push_back(dato_entrada);

                }               
            } 
        }

        q=0;
        if(i>=26){
            f++;
        }
        if(i%26==0 && i>26){
            k++;
        }
        dato_entrada="";
        tmp.push_back("para");
        MAT.push_back(tmp);//llenar matriz con letras
    }
    
    tamanio=sqrt(MATRIZ.size());
    //pila.push_back(MAT[nodo_inicial][nodo_inicial]);
    dato_entrada="";
    vector<string> PILA;
    PILA.push_back(MAT[nodo_inicial][nodo_inicial]);
    while(!PILA.empty()){
        cout<<PILA[0]<<" ";

        procesado.push_back(PILA[0]);
        PILA.erase(PILA.begin());
        for (int i = 0; i < tamanio; i++){
            dato_entrada += MAT[nodo_inicial][i];
            if(dato_entrada == "para"){
                break;
            }
            else if( count(procesado.begin(), procesado.end(), dato_entrada) != 1 ){
                pila.push_back(dato_entrada);
            }
            dato_entrada="";
        }
        for (int i = pila.size() ; i > 0; i--){
            PILA.insert(PILA.begin(),pila[i]);
        }
        pila.clear();//limpiar 
        for(int indica=0;indica<26;indica++){
            string entra="";
            entra+=alfabeto[indica];
            if(PILA[0] == entra){
                nodo_inicial= indica;
            }
        }

        
    }
    

}*/

//BFS
/*
void BFS(vector<string> LISTA,int inicio){
    vector<string> nodos;
    vector<string> FILA;
    string dato="";   

    for(int i=0;i<LISTA.size();i++){//inicializar nodos en espera
        dato+=LISTA[i];
        if(dato != "para" && count(nodos.begin(),nodos.end(),dato)){
            
            nodos.push_back(dato);
            
        }
        dato="";
    }


    sort(nodos.begin(),nodos.end());
    dato="";
    if(LISTA[inicio] == "para"){
        dato+=LISTA[inicio+1];
    }else{
        dato+=LISTA[inicio];
    }
    
    FILA.push_back(dato);
    
    dato="";
    int indi=0;
    LISTA.erase(nodos.begin());
    while (!FILA.empty()){
        cout<<FILA[0]<<" ";
        for (int i = 0; i < nodos.size(); i++){
            dato+=FILA[0];
            if(dato == nodos[i]){
                nodos.erase(nodos.begin() + i);
                break;
            }
            dato="";
        }
        for (int j = 0; j < LISTA.size(); j++){
            dato+=LISTA[j];
            if (indi=j && LISTA[j]!="para"){
                FILA.push_back(dato);

            }
            indi++;
            dato="";
        }
    }
}*/

















int main(){
    vector<string> lista;//para lista de adyacencia 
    int tamanio;
    cin>>tamanio;

    int matriz[tamanio][tamanio];//declarar dimension matriz

    string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26 letras

    //crear matriz
    //O(n)
    for (int i = 0; i < tamanio; i++){
        for (int j = 0; j < tamanio; j++){
            cin>>matriz[i][j];
        }   
    }


    //imprime matriz
    //-----------------------MATRIZ DE ADYACENCIAS-----------------------
    //complejidad O(n)
    for (int i = 0; i < tamanio; i++){
        for (int j = 0; j < tamanio; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    //-----------------------LISTA DE ADYACENCIAS-----------------------

    int k=0,f=0,q=0;
    string dato_entrada;
    //complejidad O(n)
    for (int i = 0; i < tamanio; i++){
        if (i>=26){ // si el tamanio de la matriz es mayor a z saca dos letras al principio de la lista
            
            dato_entrada = dato_entrada + alfabeto[k] + alfabeto[f];
            lista.push_back(dato_entrada);

        }
        else{//las primeras 26 letras hasta z

            dato_entrada =alfabeto[i];
            lista.push_back(dato_entrada);

        }
        
        
        for (int j = 0; j < tamanio; j++){
            if (j>=26 && matriz[i][j] == 0 ){
                q++;
            }

            if (matriz[i][j] == 1){//si estan conectados los nodos
                dato_entrada="";
                if (j>=26){

                    dato_entrada= dato_entrada + alfabeto[k]+ alfabeto[q];

                    lista.push_back(dato_entrada);//agrgar letra a la lista

                    q++;
                    
                }
                else{
                    dato_entrada=alfabeto[j];

                    lista.push_back(dato_entrada);//agrgar letra a la lista

                }
                
            }
            
        }

        q=0;
        //en caso de que sean dos letras
        if(i>=26){
            f++;
        }
        if(i%26==0 && i>26){
            k++;
        }
        dato_entrada="";
        //
        lista.push_back("para");//indicador donde termina la lista
    }
    cout<<endl;


    //O(n)
    //imprime lista
    for(int i = 0; i<lista.size(); i++){
     
        if (lista[i]== "para" || i==lista.size() ){
            cout<<endl;
        }else if(lista[i+1]== "para"){
            cout<<lista[i];
       
        }else{
            cout<<lista[i]<<" - ";
        }
    }
    cout<<endl;



    vector<vector<int> >matrix;   

    //crear vector de vectores
    for (int i = 0; i < tamanio; i++){
        vector<int> temp;
        for (int j = 0; j < tamanio; j++){
            temp.push_back(matriz[i][j]);
            
        } 
        matrix.push_back(temp); 
    }

    
    //BFS(lista,0);
    cout<<endl;
    //DFS(matrix,0);
    cout<<endl;

    
    return 0;
}

