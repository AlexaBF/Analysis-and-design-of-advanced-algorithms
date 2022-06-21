#include <vector>
#include <string>
using namespace std;

vector<int> busqSecuencial(vector<string> VECTOR, string STRING_BUSCAR){
  vector<int> INDEX;
  int SIZE=VECTOR.size();
  string FECHA;
  for(int i=0;i<SIZE;i++){
    FECHA.clear();
    for(int j=0;j<5;j++){
      FECHA+=VECTOR[i][j];
    }
    if(FECHA==STRING_BUSCAR){
      INDEX.push_back(i);
    }
  }






  return INDEX;
}