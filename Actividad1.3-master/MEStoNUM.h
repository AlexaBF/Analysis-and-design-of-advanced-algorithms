#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> MEStoNUM(vector<string> vec){
  vector<string> mes={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};//meses a comparar
  //variables auxiliares
  string MES; // se guarda el MES como: "Jan","Feb","Mar","Apr",... 
  string MES_NUMERICO;//la (posición +1) donde se encuentra el MES dentro del vector de strings mes={"Jan","Feb”,…}

  for (int i = 0; i < vec.size(); i++){// va linea por linea del doc Bitacora.txt
    MES.clear();//limpiar o vaciar string
    MES=vec[i][0];// de la linea i del documento Bitácora.txt toma el primer carácter 
    MES+=vec[i][1];// de la linea i del documento Bitácora.txt toma el segundo carácter y lo agrega a MES
    MES+=vec[i][2];// de la linea i del documento Bitácora.txt toma el tercer carácter y lo agrega a MES

    string INICIO="0";// es un indicador por si el mes es menor a 10 o a “Oct” 
    for (int j = 0; j < 12; j++){//iterar para comparar con el vectormes
      if (MES==mes[j]){// si MES supongamos MES=“Aug” es igual a mes[j]=“Aug”
        MES_NUMERICO.clear();//limpiar el MES_NUMERICO 
        MES_NUMERICO+=to_string(j+1);//asignar al MES_NUMERICO j+1 en tipo de dato string
        break;
      } 
      
    }
    if(MES_NUMERICO.length()==1){// si el numero MES_NUMERICO se encuentra en el rango de 1 a 9 como para “Aug” MES_NUMERICO =9   
      INICIO+=MES_NUMERICO;// INICIO que es igual a cero en formato de string se le agrega el MES_NUMERICO correspondiente para que te quede “09”
      MES_NUMERICO=INICIO;
    }

    //borrar MES de vec
    vec[i].erase(vec[i].begin() + 0);//borro “A” del principio de la linea
    vec[i].erase(vec[i].begin() + 0);//borro “u” del principio de la linea
    vec[i].erase(vec[i].begin() + 0);//borro “g” del principio de la linea
    
    //una vez que lo borro voy agregar “09” al principio de este para que se pueda ordenar de manera correcta y no alfabeticamente con “AUG”
    MES_NUMERICO+=vec[i];//agregar MES_NUMERICO al vector
    vec[i]=MES_NUMERICO;//vector con MES en NUMERO
  }
  return vec; // regreso el vector con el numero correspondiente de cada mes para cada linea 
}