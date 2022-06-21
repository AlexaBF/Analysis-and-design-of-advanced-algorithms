//clase para crear tabla de hash
//A01422793 Alexa Basurto Flores
//28/11/2020

#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Tabla_Hash{
protected:
    string arreglo[32749];//declarar arreglo
    int lleno;//indica cuando la tabla este llena

public:
    Tabla_Hash();
    void ins(string dato);
    void search(string llave);
    ~Tabla_Hash();
};

Tabla_Hash::Tabla_Hash(){
}






//------------------------------------------------------------------------------------------------------------------------------------
//insertar datos a tabla
void Tabla_Hash::ins(string newData){
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
    
    string ip=newData.substr(pos3+1,(pos5-(pos3+1)));//tomar solo la parte de IP
    string puerto=newData.substr(pos5+1,(pos4-(pos5+1)));//tomar solo la parte de Puerto
    

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
    string ip_con_cero = RED + "." + HOST;

    
    string llave = RED;


    int suma = 0;

    //complejidad O(n)
    for (int i = 0; i < llave.size(); i++){
        suma += int(llave[i]);//sumar ASCII de cada char
    }

    int pos_tabla = suma % 32749;//operacion de %32749 para obtener la posicion hash


    string encuentra;
    int inicio,fin,inicio2,fin2,num_dominio,num_host;
    string datos;//linea de ips completas de un dominio

    bool indica = false;

    //verificar que llave no sea duplicada 
    //complejidad O(1)
    for (int i = 0; i < 32749; i++){
        encuentra = "";
        encuentra+= arreglo[i].substr(0, 7);//toma ip _ _ _ . _ _ _
        if(llave == encuentra){//si encuentra la llave dentro de tabla
            indica = true;
            inicio = arreglo[i].find(" ");
            fin = arreglo[i].find(" ",inicio+1);
            //toma las veces de acceso al dominio
            num_dominio = stoi( arreglo[i].substr(inicio +1, (fin-(inicio +1) ) ) );
            num_dominio++;

            inicio2 = fin+1;
            fin2 = arreglo[i].find(" ",fin+1);
            //toma el numero de host unicos del dominio
            num_host = stoi( arreglo[i].substr(inicio2, (fin2 - inicio2  ) ) );

            if(arreglo[i].find(HOST) != -1){//si el host ya se encuentra en la lista
                datos="";
                datos = arreglo[i].substr(fin2 +1, (arreglo[i].length() -(fin2 +1) )  );

                //insertar datos nuevos a tabla
                arreglo[i]= RED +" " + to_string(num_dominio)+" "+to_string(num_host)+" "+ datos;


            }else{//si el host no esta en la lista
                num_host++;
                datos="";
                datos = arreglo[i].substr(fin2 +1, (arreglo[i].length() -(fin2 +1) )  );
                datos += " " + ip_con_cero;
                //insertar datos nuevos a tabla
                arreglo[i]= RED +" " + to_string(num_dominio)+" "+to_string(num_host)+" "+ datos;
            }
            break;
        }
    }
    

    if(lleno == 32749){//cuando la tabla esta llena
        cout<<"Tabla llena, imposible meter más datos"<<endl;
    
    }else if(indica == false){//si todavia no se encuentra la llave dentro de la tabla

        //si la posicion de hash que se obtuvo ya esta ocupada
        if(arreglo[pos_tabla] != ""){

            //complejidad O(n)
            while (arreglo[pos_tabla] != ""){
                pos_tabla ++;
                if (pos_tabla == 32749){
                    pos_tabla=0;
                }
            }
            
            //una vez que se encuentra un espacio meter dato
            
            datos="";
            
            datos += " " + ip_con_cero;
            arreglo[pos_tabla] = RED +" 1"+" 1"+ datos;
            

        }else{//si el espacio esta vacio de primera instancia

            datos="";
            datos += " " + ip_con_cero;
            arreglo[pos_tabla] = RED +" 1"+" 1"+ datos;
        }

        lleno++;//indicar que se inserto un elemento en la tabla
    }


}








//---------------------------quitar ceros de ip  ------------------------------------------------
string sin_cero(string STR){//quita ceros de ip
    for (int i = 0; i < (STR.length() ) ; i++){//recorre ip
        if( (STR[0]) == '0'){//si empieza con 0 quita cero del inicio
            STR.erase(STR.begin());
        }else{//sale de ciclo si no empieza con 0
            break;
        }
    }
    return STR; 
}


string Ip_sin_cero(string ip){//quitar cero agregado de ip
    string Ip;

    if( (ip.length())  != 7){//si quiero quitar ceros de una ip como: _ _ _._ _ _._ _ _._ _ _

        int pos1,pos2,pos3,pos4;
        //dividir IP
        for (int i = 0; i < 3; i++){//hay cuatro espacios en total
            if(i==0){
                pos1=ip.find(".");//punto 1
                
            }else if (i==1){
                pos2=ip.find(".",pos1+1);//punto 2
                
            }else{
                pos3=ip.find(".",pos2+1);//punto 3
            } 
            
        }
        string ip1=ip.substr(0,pos1);//cambiar string a int antes del primer punto
        string ip2=ip.substr(pos1+1,(pos2- (pos1+1) ));//despues del primer punto hasta el segundo
        string ip3=ip.substr(pos2+1,(pos3- (pos2+1) ));//despues del segundo punto hasta el tercero
        string ip4=ip.substr(pos3+1,(  (ip.length())  - (pos3+1) ));//despues del tercer punto hasta fin
        
    
        ip1=sin_cero(ip1);
        ip2=sin_cero(ip2);
        ip3=sin_cero(ip3);
        ip4=sin_cero(ip4);
        

        Ip=ip1 + "." + ip2 + "." + ip3 + "." + ip4;


    }else{//si quiero quitar ceros de una ip como: _ _ _._ _ _

    
        int pos1=ip.find(".");//punto 1
                
        //dividir IP
        string ip1=ip.substr(0,pos1);//cambiar string a int antes del primer punto
        string ip2=ip.substr(pos1+1,(  (ip.length())  - (pos1+1)) );//despues del primer punto hasta el espacio
        
    
        ip1=sin_cero(ip1);
        ip2=sin_cero(ip2);
        

        Ip=ip1 + "." + ip2;
    }



    return Ip;

}
//--------------------------------------------------------------------------------------------


//--------------------------------------buscar datos e imprimirlos------------------------------------------------
void Tabla_Hash::search(string llave){
    
    string HOST;
    
    vector<string> IPS;

    int inicio,fin,inicio2,fin2;
    string dominio,datos,num_dominio,num_host,ip;


    //complejidad O(1)
    for (int i = 0; i < 32749; i++){

        HOST = "";
        HOST = arreglo[i].substr(0, arreglo[i].find(" ") );
        HOST = Ip_sin_cero(HOST);//host a comparar con llave


        if(llave == HOST){//si la llave que se busca esta en la tabla
            cout<<HOST<<endl;
            inicio = arreglo[i].find(" ");
            fin = arreglo[i].find(" ",inicio+1);
            num_dominio =  arreglo[i].substr(inicio +1, (fin-(inicio +1) ) );
            cout<<num_dominio<<endl;//imprimir veces de acceso de dominio

            inicio2 = fin+1;
            fin2 = arreglo[i].find(" ",fin+1);
            num_host = arreglo[i].substr(inicio2, (fin2 - inicio2  ) );
            //imprimir cantidad de host unicos
            cout<<num_host<<endl;

            
            datos="";
            datos = arreglo[i].substr(fin2 +1, (arreglo[i].length() -(fin2 +1) )  );

            //complejidad O(n) 
            for (int i = 0; i < (datos.length()) ; i++){
                
                if(datos[i] == ' ' || i == (datos.length()) -1 ){
                    ip+= datos[i];
                    
                    //imprimir datos ips unicas
                    IPS.push_back(ip);
                    ip = "";

                }else{
                    ip+= datos[i];
                }
            }
            
            break;
        }
    }

    sort(IPS.begin(), IPS.end());
    string IP;
    for (int i = 0; i < IPS.size(); i++){
        IP = Ip_sin_cero(IPS[i]);
        cout<<IP<<endl;
    }
    

}


Tabla_Hash::~Tabla_Hash(){
}
