//problema del cambio de monedas. 
//A01422793
//Creacion: 22/08/21
//modificacion: 24/08/21

#include <iostream>
#include <algorithm> //sort 
#include <vector>
#include "Avaro.h"
#include "Dinamica.h"


using namespace std;


int main(){
    int N,E,P,Q;
    vector <int> monedasDisponibles;
    /*
    El programa recibe un numero entero N, seguido de N valores enteros (uno en cada línea) que representan las diferentes denominaciones disponibles de las monedas.  
    Seguido de esto, el programa recibe dos números enteros: P y Q, (uno en cada línea) por la entrada estándar, que representan P: el precio de un producto dado y Q: es el billete o moneda con el que se paga dicho producto. */
    cout<<"Cantidad de denominaciones disponibles de las monedas: ";
    cin>>N;
    for(int i=0;i<N;i++){
        cout<<"Moneda "<<i+1<<" : ";
        cin>>E;
        monedasDisponibles.push_back(E);
    }

    sort(monedasDisponibles.begin(),monedasDisponibles.end());
    
    cout<<"Precio del producto : ";
    cin>>P;

    cout<<"Cantidad con la que se pago : ";
    cin>>Q;


    while(P>Q){
        cout<<"No es suficiente dinero"<<endl;
        cout<<"Cantidad con la que se va a pagar : ";
        cin>>Q;
    }

    if(P==Q){
        
        cout<<"Moneda           Cambio"<<endl;
        for(int i=0;i<monedasDisponibles.size();i++){
            cout<<monedasDisponibles[i]<<"                    0"<<endl;
        }
    }else{
        int cambio=Q-P;
        cout<<"\n\t\t\t\tDinamica"<<endl;
        Dinamica(monedasDisponibles,cambio,N);
        cout<<"\n\t\t\t\tAvaro"<<endl;
        Avaro(monedasDisponibles,P,Q);
    }


    /*La salida del programa es una lista de N valores correspondientes al número de monedas de cada denominación, de mayor a menor, una en cada línea, que se tienen que dar para dar el cambio por el producto pagado, primero utilizando programación dinámica, y luego utilizando un algoritmo avaro. Muestra en pantalla la tabla interna generada por tus programas.*/

    return 0;
}



