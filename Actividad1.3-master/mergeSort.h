/*
ordenamiento con Merge
//complejidad del algoritmo
//peor caso O(n log n)
//caso promedio O(n log n)

*/

#include <vector>
using namespace std;


//Une los dos subarrays del arreglo original

void Une(vector<string>& VECTOR, int INICIO, int MITAD, int FIN){//arreglo,inicio del arreglo,mitad del arreglo,fin del arreglo
    int SIZE_1 = MITAD-INICIO+1;
    int SIZE_2 = FIN-MITAD;
    //crear dos subvectores de izquierda y derecha
    vector<string> SUB_VEC_IZQ(SIZE_1);//subvectores izquierda
    vector<string> SUB_VEC_DER(SIZE_2);//subvectores derecha

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


void MERGESORT(vector<string>& VECTOR, int INICIO, int FIN){//ingresar vector,inicio=0, fin del vector = size-1
  int MITAD;
  if(INICIO < FIN){
    MITAD = (INICIO+FIN)/2;
    MERGESORT(VECTOR, INICIO, MITAD);
    MERGESORT(VECTOR, MITAD+1, FIN);
    Une(VECTOR, INICIO, MITAD, FIN);
  }
}

