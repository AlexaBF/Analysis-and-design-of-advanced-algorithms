#pragma once
#include <iostream>
#include <vector>

using namespace std;

//O(n)
void imprime(vector<int> solucion,vector <int> disponible,int n){
    vector <int> tabla;//cuantas veces se tiene que dar la moneda
    int aparece=0;
    for (int i = 0; i < n; i++){
        int ele=disponible[i];
        for (int j = 0; j < solucion.size(); j++){
            if(ele == solucion[j]){
                aparece+=1;
            }
        }
        tabla.push_back(aparece);
        aparece=0;
    }
    
    cout<<"Monedas                    Cambio"<<endl;
    for (int i = n -1; i >=0; i--){
        cout<<disponible[i]<<"                              "<<tabla[i]<<endl;
    }
}


vector<int> calcula(int ARRAY[], int CAMBIO, int k) {
    int M[CAMBIO+1],S[CAMBIO+1];
    M[0] = 0;
    S[0] = 0;

    for(int j=1; j<=CAMBIO; j++) {
        int LLEVA=0,COMPARA = 100000;//para no salirse del limite

        for(int i=1; i<=k; i++) {
            if( j >= ARRAY[i]) {
                if((1+M[j-ARRAY[i]]) < COMPARA) {
                    COMPARA = 1+M[j-ARRAY[i]];
                    LLEVA = i;
                }
            }
        }
        M[j] = COMPARA;
        S[j] = LLEVA;
    }

    vector<int> solucion;
    int RES = CAMBIO;
    while(RES>0) {
        //cout<<ARRAY[S[RES]]<<endl;
        solucion.push_back(ARRAY[S[RES]]);
        RES = RES-ARRAY[S[RES]];
    }
    
    return solucion;
  
  
}



void Dinamica(vector<int>disponible, int cambio, int N){
    int monedas [N+1] ;
    vector <int> solucion;


    for (int i = 0; i < N; i++) {
        monedas[i+1] = disponible[i];
    }

    
    solucion = calcula(monedas,cambio,N);
    imprime(solucion,disponible,N);
}