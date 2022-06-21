#include <string>
#include <vector>
using namespace std;

vector<string> NUMtoMES(vector<string> vec){
  vector<string> mes={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};//meses a comparar


  //variables auxiliares
  string MES;// se guarda el MES como: AUG o JUL y asi

  string MES_NUMERICO;//la (posición +1) donde se encuentra el MES dentro del vector de strings mes={"Jan","Feb”,…}

  int MESTONUM;

  for (int i = 0; i < vec.size(); i++){// va linea por linea del doc Bitacora.txt

    MES_NUMERICO.clear();//limpiar o vaciar string
    MES_NUMERICO=vec[i][0]; // de la linea i del documento Bitácora.txt toma el primer carácter 
    MES_NUMERICO+=vec[i][1]; // de la linea i del documento Bitácora.txt toma el segundo carácter y lo agrega a MES
    
    char Evalua=MES_NUMERICO[0];
    int NUMERO = Evalua - '0'; // NUMERO es ahora igual a int de MES_NUMERICO[0]
    if(NUMERO == 0){//evaluar si empieza con un cero
      MES_NUMERICO=MES_NUMERICO[1];
    }
  
    MESTONUM =(atoi(MES_NUMERICO.c_str()))-1;
    //convertir MES a tipo int y restarle 1 para poder evaluar con vector de strings mes={"Jan","Feb”,…}

     

    for (int j = 0; j < 12; j++){//iterar para comparar con el vectormes

      if (MESTONUM==j){ // si MESTONUM supongamos MES=9 es igual a j=9

        MES.clear();//limpiar el MES un string vacío
        MES+=mes[j];//MES = "Aug"    
	      break;
      }    
    }
    

    //borrar MES_numerico de vec
    vec[i].erase(vec[i].begin() + 0);//borro primer digito del principio de la linea
    vec[i].erase(vec[i].begin() + 0);//borro segundo digito del principio de la linea
    
    
    MES+=vec[i];//agregar MES al vector

    vec[i]=MES;//vector con MES_numerico en MES
  }
  return vec;// regreso el vector con el numero correspondiente de cada mes para cada linea 
}
