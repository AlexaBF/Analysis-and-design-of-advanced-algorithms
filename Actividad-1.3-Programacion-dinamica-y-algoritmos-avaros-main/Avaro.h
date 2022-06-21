
#pragma once
#include <iostream>
#include <vector>

using namespace std;

//O(n)
void Avaro(vector <int> monedasDisponibles,int P,int Q){
    vector <int> solucion;
    int n= monedasDisponibles.size(), cambio = Q-P;

	for (int i = n - 1; i >= 0; i--) {//recorre las monedas disponibles
		while (cambio >= monedasDisponibles[i]){//compara lo que se tiene que dar por las monedas disponibles
			cambio -= monedasDisponibles[i];
			solucion.push_back(monedasDisponibles[i]);
		}
	}
    
    vector <int> tabla;//cuantas veces se tiene que dar la moneda
    int aparece=0;
    for (int i = 0; i < n; i++){
        int ele=monedasDisponibles[i];
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
        cout<<monedasDisponibles[i]<<"                              "<<tabla[i]<<endl;
    }

}


