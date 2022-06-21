//clase para crear grafo/lista
//Alexa Basurto Flores A01422793
//23/11/2020
#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Grafo{
protected:
    vector<string> LISTA;
    vector<string> red;
    vector<string> red_aparece;
    vector<string> host;
    vector<string> host_aparece;
public:
    Grafo();
    void INGRESA(string);
    void ACOMODA();
    void IMPRIME();
    void APARECE_RED(vector<string>);
    void APARECE_HOST(vector<string>);
    ~Grafo();
};

Grafo::Grafo(){
}

//ingrsa linea de archivo a lista
void Grafo::INGRESA(string newData){

    int pos1,pos2,pos3,pos4,pos5;//posicion de espacios en la linea de entrada

    for (int i = 0; i < 4; i++){//hay cuatro espacios en total
        if(i==0){
            pos1=newData.find(" ");//espacio antes de fecha
            
        }else if (i==1){
            pos2=newData.find(" ",pos1+1);//espacio antes de hora
            
        }else if (i==2){
            pos3=newData.find(" ",pos2+1);//espacio antes de ip
        }else{
            pos4=newData.find(" ",pos3+1);//espacio antes de Error
            pos5=newData.find(":",pos3+1);//inicio de puerto
        }
    }

    string mes=newData.substr(0, pos1);//tomar solo la parte de mes del string original
    string fecha=newData.substr(pos1+1,(pos2-(pos1+1)));//tomar solo la parte de fecha
    string hora=newData.substr(pos2+1,(pos3-(pos2+1)));//tomar solo la parte de Hora
    string ip=newData.substr(pos3+1,(pos5-(pos3+1)));//tomar solo la parte de IP
    string puerto=newData.substr(pos5+1,(pos4-(pos5+1)));//tomar solo la parte de Puerto
    string error=newData.substr(pos4+1,(( (newData.length())) )-(pos4+1));//tomar solo la parte de error

    string i_p = ip + ":"+ puerto;//ip completa   

    int posA,posB,posC,posD;
    //dividir IP
    for (int i = 0; i < 4; i++){//hay cuatro espacios en total
        if(i==0){
            posA=i_p.find(".");//punto 1
            
        }else if (i==1){
            posB=i_p.find(".",posA+1);//punto 2
            
        }else if (i==2){
            posC=i_p.find(".",posB+1);//punto 3
        }else{
            posD=i_p.find(":",posC+1);//inicio puerto 
        }
    }
    string ip1=i_p.substr(0,posA);//primeros numeros de ip
    string ip2=i_p.substr(posA+1,(posB- (posA+1) ));//despues del primer punto hasta el segundo
    string ip3=i_p.substr(posB+1,(posC- (posB+1) ));//despues del segundo punto hasta el tercero
    string ip4=i_p.substr(posC+1,(posD- (posC+1) ));//despues del tercer punto hasta los : del puerto
    string ip5=i_p.substr(posD+1,(  (ip.length())  - (posD+1) ));//despues del tercer punto hasta los : del puerto
    
    string RED = ip1+"."+ip2;
    string HOST = ip3+"."+ip4;

    string DATOS= ip5 + " " + error + " " + mes + " " + fecha + " " + hora;
    string linea_final= RED +" "+ HOST+" "+DATOS;


    red.push_back(RED);
    host.push_back(RED +"."+ HOST);
    LISTA.push_back(linea_final);
}

//cuantas veces aparece una red 
void Grafo::APARECE_RED(vector<string> lista){
    string dato;
    int tamanio=lista.size();

    int revisado[lista.size()];
    for(int i = 0; i < tamanio; i++){
        revisado[i] = 0;
    }

    for(int i = 0; i < tamanio; i++) {
        if(revisado[i] == 0) {
            int count = 0;
            for(int j = i; j < tamanio; j++){
                if(lista[j] == lista[i]) {
                    count += 1;
                    revisado[j] = 1;
                }
            }
            dato="";
            dato=lista[i]+" "+to_string(count);
            red_aparece.push_back(dato);
        }
    }
}


//cuantas veces aparece host
void Grafo::APARECE_HOST(vector<string> lista){
    int pos;
    string dato;
    vector<string> hosts;
    for (int i = 0; i < lista.size(); i++){
        pos=lista[i].find(" ");
        dato=lista[i].substr(8, (pos  - 8));
        hosts.push_back(dato);
    }
    
    int tamanio=hosts.size();

    int revisado[hosts.size()];
    for(int i = 0; i < tamanio; i++){
        revisado[i] = 0;
    }

    for(int i = 0; i < tamanio; i++) {
        if(revisado[i] == 0) {
            int count = 0;
            for(int j = i; j < tamanio; j++){
                if(hosts[j] == hosts[i]) {
                    count += 1;
                    revisado[j] = 1;
                }
            }
            dato="";
            dato=lista[i].substr(0, 8);
            dato+=hosts[i]+" "+to_string(count);
            host_aparece.push_back(dato);
        }
    }
}


//acomoda datos
void Grafo::ACOMODA(){
    sort(LISTA.begin(),LISTA.end());
    sort(red.begin(),red.end());
    APARECE_RED(red);
    sort(host.begin(),host.end());
    APARECE_HOST(host);
}


//imprimir la red mayor visita
void mayor_red(vector<string> lista_completa){
    vector<string> redes;
    int pos;
    string dato;
    for (int i = 0; i < lista_completa.size(); i++){

        pos=lista_completa[i].find(" ");
        dato=lista_completa[i].substr(pos +1, (lista_completa[i].length()  -(pos+1) ));
        redes.push_back(dato);
    }

    string maximo=*max_element(redes.begin(), redes.end());
    vector<int> indices;
    for (int i = 0; i < redes.size(); i++){
        if(maximo==redes[i]){
            indices.push_back(i);
        }
    }
    
    vector<string> resultado;
    for (int i = 0; i < indices.size(); i++){
        pos=lista_completa[indices[i]].find(" ");
        dato=lista_completa[indices[i]].substr(0, (pos));
        resultado.push_back(dato);
    }


    for (int i = 0; i < resultado.size(); i++){
        cout<<resultado[i]<<endl;
    }
    
    
}


//host con mayor visita
void mayor_host(vector<string> lista_completa){
    vector<string> hosts;
    int pos;
    string dato;
    for (int i = 0; i < lista_completa.size(); i++){
        pos=lista_completa[i].find(" ");
        dato=lista_completa[i].substr(pos +1, (lista_completa[i].length()  -(pos+1) ));
        hosts.push_back(dato);
    }

    string maximo=*max_element(hosts.begin(), hosts.end());
    vector<int> indices;
    for (int i = 0; i < hosts.size(); i++){
        if(maximo==hosts[i]){
            indices.push_back(i);
        }
    }
    
    vector<string> resultado;
    for (int i = 0; i < indices.size(); i++){
        pos=lista_completa[indices[i]].find(" ");
        dato=lista_completa[indices[i]].substr(0, (pos));
        resultado.push_back(dato);
    }


    for (int i = 0; i < resultado.size(); i++){
        cout<<resultado[i]<<endl;
    }
}



void Grafo::IMPRIME(){
    mayor_red(red_aparece);
    cout<<endl;
    mayor_host(host_aparece);
    
}



Grafo::~Grafo(){
}
