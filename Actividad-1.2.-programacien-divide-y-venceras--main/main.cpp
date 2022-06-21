//programa recibe un numero entero N, seguido de N valores reales (double, uno en cada línea) por la entrada estándar.
//La salida del programa es una lista de los N valores ordenados de Mayor a menor.
//Alexa Basurto Flores A01422793
//Creado: 16/AGO/21
//Modificado: 17/AGO/21
#include<iostream>
#include <vector>

using namespace std;

//Une los dos subarrays del arreglo original
void uneArreglos(vector<double>& VECTOR, int INICIO, int MITAD, int FIN){//arreglo,inicio del arreglo,mitad del arreglo,fin del arreglo
    int SIZE_1 = MITAD-INICIO+1;
    int SIZE_2 = FIN-MITAD;
    //crear dos subvectores de izquierda y derecha
    vector<double> SUB_VEC_IZQ(SIZE_1);//subvectores izquierda
    vector<double> SUB_VEC_DER(SIZE_2);//subvectores derecha

    for(int i = 0; i < SIZE_1; i++){//llenar sub vector de la izquierda
        SUB_VEC_IZQ[i] = VECTOR[INICIO+i];
    }
    for(int j = 0; j < SIZE_2; j++){//llenar sub vector de la derecha
        SUB_VEC_DER[j]=VECTOR[MITAD+j+1];
    }

    int i=0,j=0;
    int k;
    for(k = INICIO; k <= FIN && i < SIZE_1 && j < SIZE_2; k++){//Unir los dos subarrays en el original
        if(SUB_VEC_IZQ[i] <= SUB_VEC_DER[j]){
            VECTOR[k] = SUB_VEC_IZQ[i];
            i++;
        }
        else{
            VECTOR[k] = SUB_VEC_DER[j];
            j++;
        }
    }
    for(i = i; i < SIZE_1; ++i){
        VECTOR[k] = SUB_VEC_IZQ[i];
        k++;
    }

    for(j = j; j < SIZE_2; j++){
        VECTOR[k] = SUB_VEC_DER[j];
        k++;
    }
}


void MERGESORT(vector<double>& VECTOR, int INICIO, int FIN){//ingresar vector,inicio=0, fin del vector = size-1
    int MITAD;
    if(INICIO < FIN){
        MITAD = (INICIO+FIN)/2;
        MERGESORT(VECTOR, INICIO, MITAD);
        MERGESORT(VECTOR, MITAD+1, FIN);
        uneArreglos(VECTOR, INICIO, MITAD, FIN);
    }
}


int main(){

    vector<double> VECTOR;//vector para guardar datos
    int N;// numeros que seran introducidos
    double n;//elementos
    cout<<"Cantidad de elementos: ";
    cin>>N;//cuantos datos son
    for(int i=0;i<N;i++){//elementos en el vector
        cout<<"Elemento "<<i+1<<" : ";
        cin>>n;
        VECTOR.push_back(n);
    }

    MERGESORT(VECTOR, 0, N-1);

    cout<<"\n----------Elementos ordenados de mayor a menor--------- \n"<<endl;
    for(int i=N-1;i>=0;i--){//elementos de mayor a menor
        cout<<VECTOR.at(i)<<endl;
    }


    return 0;
}
