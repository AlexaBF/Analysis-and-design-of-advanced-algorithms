#include<vector>
#include<string>
using namespace std;

void imprimirDatos(vector<string> DATO, vector<int> INDICE){
  int SIZE=INDICE.size();
  for(int i=0;i<SIZE;i++){
    cout<<DATO[INDICE[i]]<<endl;
  }

}