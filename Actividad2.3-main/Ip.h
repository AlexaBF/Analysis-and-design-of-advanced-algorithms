//obtiene ip

#pragma once
#include <string>

using namespace std;

string cero(string STR){//agrega ceros
 
  if(STR.length()==2){
    STR.insert(0,"0");
  }else if(STR.length()==1){
    STR.insert(0,"00");
  }
  return STR; 
}

string Ip(string ip){
  int pos1,pos2,pos3,pos4;
  //dividir IP
  for (int i = 0; i < 4; i++){//hay cuatro espacios en total
      if(i==0){
          pos1=ip.find(".");//punto 1
          
      }else if (i==1){
          pos2=ip.find(".",pos1+1);//punto 2
          
      }else if (i==2){
          pos3=ip.find(".",pos2+1);//punto 3
      }else{
          pos4=ip.find("\n",pos3+1);//
      }
  }
  string ip1=ip.substr(0,pos1);//cambiar string a int antes del primer punto
  string ip2=ip.substr(pos1+1,(pos2- (pos1+1) ));//despues del primer punto hasta el segundo
  string ip3=ip.substr(pos2+1,(pos3- (pos2+1) ));//despues del segundo punto hasta el tercero
  string ip4=ip.substr(pos3+1,(pos4- (pos3+1) ));//despues del tercer punto hasta los : del puerto
  
  ip1=cero(ip1);
  ip2=cero(ip2);
  ip3=cero(ip3);
  ip4=cero(ip4);

  string Ip=ip1 + "." + ip2 +"." + ip3 +"." + ip4;
  return Ip;
}
