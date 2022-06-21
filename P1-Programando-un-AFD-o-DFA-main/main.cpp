//A01422793 
//Alexa Basurto Flores
//18/03/2021
//modificacion 25/03/2021
//version 5.0
#include <iostream>     
#include <string>       
#include <vector>       //crear vectores
#include <fstream>      //abrir archivo
#include <algorithm>    // std::remove  
#include <cctype> //isalpha().   isdigit().   
using namespace std;


//-------------------------------declaracin de funciones-----------------------------------
void Q10(string LINEA,vector<string> &vectorfinal);
void Q9(string LINEA,vector<string> &vectorfinal);
void Q8(string LINEA,int verifica,vector<string> &vectorfinal);
void Q7(string LINEA,int signo,vector<string> &vectorfinal);
void Q6(string LINEA,int dondeinicia,vector<string> &vectorfinal);
void Q5(string LINEA,int punto,vector<string> &vectorfinal);
void Q4(string LINEA,vector<string> &vectorfinal);
void Q3(string LINEA,vector<string> &vectorfinal);
void Q2(string LINEA,vector<string> &vectorfinal);
void Q1(string LINEA,vector<string> &vectorfinal);
void Q0(string LINEA,vector<string> &vectorfinal);



//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q10-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
void Q10(string LINEA,vector<string> &vectorfinal){//linea a verificar, vector respuestas
  //verifica que hay despues de resta 
  if(isalpha(LINEA[1])){//si es letra
    Q3(LINEA, vectorfinal);//ve al estado 3
  }else if(isdigit(LINEA[1])){//si es digito
    vectorfinal.push_back("-                 Resta");
    Q4(LINEA.substr(1), vectorfinal);//ve al estado 4
  }else{//declaracion incorrecta
    cout<<"error en su formación"<<endl;
  }
}



//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q8-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
void Q8(string LINEA,int verifica,vector<string> &vectorfinal){//linea a verificar, donde quiero empezar a verificar, vector respuestas
  string nuevo=LINEA.substr(verifica);
  int indice=0;
  
  //es comentario y es un entero
  if(isdigit(nuevo[0]) && (nuevo[1]=='/') && (nuevo[2]=='/')){
    vectorfinal.push_back(LINEA.substr(0, LINEA.find("//") ) +"               Real");
    vectorfinal.push_back(LINEA.substr(LINEA.find("//") ) +"               Comentario");
  }
  //termina en digito
  else if(isdigit(nuevo[0]) && nuevo.length() == 1){
    
    vectorfinal.push_back(LINEA +"               Real");
  }
  //es operador
  //que operador es
  else if(isdigit(nuevo[0]) && (nuevo[1]=='-')){
    vectorfinal.push_back(LINEA.substr(0, LINEA.find("-")) +"               Real");
    vectorfinal.push_back("-                 Resta");
    indice = LINEA.find("-") + 1;//string despues de operador
    Q9(LINEA.substr(indice),vectorfinal);//ve al estado 9
  }
  else if(isdigit(nuevo[0]) && (nuevo[1]=='+')){
    vectorfinal.push_back(LINEA.substr(0, LINEA.find("+")) +"               Real");
    vectorfinal.push_back("+                 Suma");
    indice = LINEA.find("+") + 1;//string despues de operador
    Q9(LINEA.substr(indice),vectorfinal);//ve al estado 9
  }
  else if(isdigit(nuevo[0]) && (nuevo[1]=='*')){
    vectorfinal.push_back(LINEA.substr(0, LINEA.find("*")  ) +"               Real");
    vectorfinal.push_back("*                 Multiplicación");
    indice = LINEA.find("*") + 1;//string despues de operador
    
    Q9(LINEA.substr(indice),vectorfinal);//ve al estado 9
  }
  else if(isdigit(nuevo[0]) && (nuevo[1]=='/')){
    vectorfinal.push_back(LINEA.substr(0, LINEA.find("/")) +"               Real");
    vectorfinal.push_back("/                 División");
    indice = LINEA.find("/") + 1;//string despues de operador
    Q9(LINEA.substr(indice),vectorfinal);//ve al estado 9
  }
  else if(isdigit(nuevo[0]) && (nuevo[1]=='^')){
    vectorfinal.push_back(LINEA.substr(0, LINEA.find("^") ) +"               Real");
    vectorfinal.push_back("^                 Potencia");
    indice = LINEA.find("^") + 1;//string despues de operador
    Q9(LINEA.substr(indice),vectorfinal);//ve al estado 9
  }
  //declaracion incorrecta
  else{
    cout<<"error en su formación"<<endl;
  }
  
}


//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q7-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------

void Q7(string LINEA,int signo,vector<string> &vectorfinal){//linea a verificar, donde se encuentra - o resta, vector respuestas
  if(isdigit(LINEA[signo+1]) ){//hay digito despues de menos -> E-3
    int verifica=signo+1;
    Q8(LINEA,verifica, vectorfinal);//ve al estado 8
  }else{//declaracion incorrecta
    cout<<"error en su formación"<<endl;
  }
}


//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q6-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
void Q6(string LINEA,int dondeinicia,vector<string> &vectorfinal){//linea a verificar, posicion donde hay E,e
  int identifica=dondeinicia+1;
  if(LINEA[identifica] == '-'){//E-
    Q7(LINEA,identifica, vectorfinal);//ve al estado 7
  }
  else if(isdigit(LINEA[identifica])){// es digito E3
    Q8(LINEA,identifica, vectorfinal);//ve al estado 8
  }else{//declaracion incorrecta
    cout<<"error en su formación"<<endl;
  }
}



//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q5-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
void Q5(string LINEA,int punto,vector<string> &vectorfinal){//linea a verificar, vector respuestas
  string Nuevalinea;
  bool flag=false,COME=false,Ee=false;//banderas
  int indica=0,muestra=0;//indicadores
  Nuevalinea=LINEA.substr(punto+1);//linea despues del punto
  //recorre lo que esta despues del punto
  for(int i=0;i<Nuevalinea.length();i++){
    if(Nuevalinea[i] == 'E' |Nuevalinea[i] == 'e'){
      Ee=true;
      muestra=i;
      break;
    }
    else if(Nuevalinea[i] == '-'){
      flag = true;
      muestra=i;
      break;
    }
    else if(Nuevalinea[i] == '+'){
      flag = true;
      muestra=i;
      break;
    }
    else if(Nuevalinea[i] == '*'){
      flag = true;
      muestra=i;
      break;
    }
    else if(Nuevalinea[i] == '/' && Nuevalinea[i+1]!= '/'){
      flag = true;
      muestra=i;
      break;
    }
    else if(Nuevalinea[i] == '^'){
      flag = true;
      muestra=i;
      break;
    }
    else if(Nuevalinea[i] == '/' && Nuevalinea[i+1]== '/'){//comentario
      COME = true;
      muestra=i;
      break;
    }
    else{
      flag=false;
    }
  }


  if(Ee==true){//si encontro e | E
    //verifica que lo que esta entre el punto y E sea digito
    string verifica = Nuevalinea.substr(0,muestra-1);
    for(int i=0;i<verifica.length();i++){
      if(isdigit(verifica[i])){
        indica++;
      }
    }
    if(indica==verifica.length()){//si esta bien declarado
      Q6(LINEA, LINEA.find(Nuevalinea[muestra]), vectorfinal);//ve al estado 6
    }
    else{//declaracion incorrecta
      cout<<"error en su formación"<<endl;
    }
  }

  else if(COME==true){//tiene comentario
    //verifica que sea digito
    string verifica = Nuevalinea.substr(0,muestra-1);
    for(int i=0;i<verifica.length();i++){
      if(isdigit(verifica[i])){
        indica++;
      }
    }
    if(indica==verifica.length()){//declaracion correcta
      vectorfinal.push_back(LINEA.substr(0,LINEA.find(Nuevalinea[muestra])) + "               Real");
      vectorfinal.push_back(LINEA.substr(muestra) + "               Comentario");
    }else{//declaracion incorrecta
      cout<<"error en su formación"<<endl;
    }
  }


  else if(flag== true){//si tiene operador
    //verifica que lo que esta entre el punto y operador sea digito
    string verifica = Nuevalinea.substr(0,muestra-1);
    for(int i=0;i<verifica.length();i++){
      if(isdigit(verifica[i])){
        indica++;
      }
    }
    if(indica==verifica.length()){//si esta bien declarado
      vectorfinal.push_back(LINEA.substr(0,LINEA.find(Nuevalinea[muestra]))+"                      Real");//guarda la parte del numero real
      //que operador contiene
      if(LINEA[ LINEA.find(Nuevalinea[muestra]) ]=='-'){
        vectorfinal.push_back("-                 Resta");
      } else if(LINEA[ LINEA.find(Nuevalinea[muestra]) ]=='+'){
        vectorfinal.push_back("+                 Suma");
      }else if(LINEA[ LINEA.find(Nuevalinea[muestra]) ]=='*'){
        vectorfinal.push_back("*                 Multiplicación");
      }else if(LINEA[ LINEA.find(Nuevalinea[muestra]) ]=='/'){
        vectorfinal.push_back("/                 División");
      }else{
        vectorfinal.push_back("^                 Potencia");
      }
      verifica= LINEA.substr(LINEA.find(Nuevalinea[muestra]) +1);//despues del signo
      Q9(verifica, vectorfinal);//ve al estado 9
    }
    else{//declaracion incorrecta
      cout<<"error en su formación"<<endl;
    }
  }

  else if(Nuevalinea.length()<1){//se acaba en punto
    vectorfinal.push_back(LINEA + "               Real");
  }
  else if(isdigit(Nuevalinea[0])){//hay numeros despues del punto
    for(int i=0;i<Nuevalinea.length();i++){
      if(isdigit(Nuevalinea[i]) ){
        indica++;
      }
    }
    if(indica==Nuevalinea.length()){
      vectorfinal.push_back(LINEA + "               Real");
    }
  }
  else{//declaracion incorrecta 
    
    cout<<"error en su formación"<<endl;
  }



}


//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q9-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------

void Q9(string LINEA,vector<string> &vectorfinal){//linea a verificar,vector respuestas
  //si inicia con letra
  if(isalpha(LINEA[0])){
    Q3(LINEA, vectorfinal);//ve al estado 3
  }
  //si inicia con digito
  else if(isdigit(LINEA[0]) ){
    Q4(LINEA,vectorfinal);//ve al estado 4
  }
  //si inicia con parentesis
  else if(LINEA[0] == '(' | LINEA[0] == ')'){
    if(LINEA[0]=='('){
      vectorfinal.push_back("(                Parentesis que abre"); 
      Q2(LINEA.substr(1),vectorfinal);//ve al estado 2
    }else{
      vectorfinal.push_back(")                Parentesis que cierra"); 
      Q2(LINEA.substr(1),vectorfinal);//ve al estado 2
    }
  }
  //inicia con algun operador
  else if(LINEA[0] == '-' ){
    vectorfinal.push_back("-                 Resta");//ve al estado 2
    Q2(LINEA.substr(1),vectorfinal);//ve al estado 2
  }
  else if(LINEA[0] == '+' ){
    vectorfinal.push_back("+                 Suma");  
    Q2(LINEA.substr(1),vectorfinal);//ve al estado 2
  }
  else if(LINEA[0] == '*' ){
    vectorfinal.push_back("*                 Multiplicación");  
    Q2(LINEA.substr(1),vectorfinal);//ve al estado 2
  }
  else if(LINEA[0] == '/' ){
    vectorfinal.push_back("/                 División");  
    Q2(LINEA.substr(1),vectorfinal);//ve al estado 2
  }
  else if(LINEA[0] == '^' ){
    vectorfinal.push_back("^                 Potencia");  
    Q2(LINEA.substr(1),vectorfinal);//ve al estado 2
  }
  else{//declaracion incorrecta
    cout<<"error en su formación"<<endl;
  }
}


//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q4-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
void Q4(string LINEA,vector<string> &vectorfinal){//linea a revisar, vector de respuestas
  
  string lea,SEND;
  bool flag=false,COME=false,punto=false;//indicadores
  int indica=0,muestra=0;//inidica->es digito,muestra->donde hay comentario,operador o punto
  if(LINEA[0]=='-'){//si la lnea comienza con menos
    for(int i=1;i<LINEA.length();i++){//recorre caracteres de la linea
      if(LINEA[i]=='-'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='.'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del punto
        punto=true;
        muestra=i;
        break;
      }
      
      else if(LINEA[i]=='+'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='*'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='^'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='/' && LINEA[i+1]!='/'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='/' && LINEA[i+1]=='/' ){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        COME=true;
        muestra=i;
        break;
      }
      else{//no hay operadores
        flag=true; 
      }
    }


    if(punto==true){//contiene punto
      for(int j=0;j<lea.length();j++){
        if(isdigit(lea[j])){//comienza con digito
          indica++;
        }
      }
      if(indica==lea.length()){//es num
        Q5(LINEA,muestra,vectorfinal);//pasa donde se encuentra el punto
      }else{
        cout<<"error en su formación"<<endl;
      }
    }
    else if(COME==true){//tiene comentario
      for(int j=0;j<lea.length();j++){
        if(isdigit(lea[j]) ){//comienza num
          indica++;
        }
      }
      if(indica==lea.length()){//es entero
        vectorfinal.push_back(lea+"                 Entero");
        vectorfinal.push_back(LINEA.substr(muestra) + "                 Comentario");
      }else{
        cout<<"error en su formación"<<endl;
      }
    }
    else if(flag!=true){//si hay operadores
      //verifica que es digito
      for(int j=0;j<lea.length();j++){
        if(isdigit(lea[j])){//comienza con digito
          indica++;
        }
      }
      if(indica==lea.length()){//es num
        vectorfinal.push_back(lea+"                 Entero");
        if(LINEA[muestra]=='-'){
          vectorfinal.push_back("-                Resta");
          SEND=LINEA.substr(muestra+1);//despues del operador
          Q9(SEND,vectorfinal);
        }
        
        else if(LINEA[muestra]=='+'){
          vectorfinal.push_back("+                Suma");
          SEND=LINEA.substr(muestra+1);//despues del operador
          Q9(SEND,vectorfinal);
        }
        else if(LINEA[muestra]=='*'){
          vectorfinal.push_back("*                Multiplicación");
          SEND=LINEA.substr(muestra+1);//despues del operador
          Q9(SEND,vectorfinal);
        }
        else if(LINEA[muestra]=='^'){
          vectorfinal.push_back("^                Potencia");
          SEND=LINEA.substr(muestra+1);//despues del operador
          Q9(SEND,vectorfinal);
        }
        else if(LINEA[muestra]=='/'){
          vectorfinal.push_back("/                División");
          SEND=LINEA.substr(muestra+1);//despues del operador
          Q9(SEND,vectorfinal);
        }
        
      }
      else{
        cout<<"error en su formación"<<endl;
      }
    }

    else{//no hay operadores
      //verifica que es entero
      for(int j=0;j<lea.length();j++){
        if(isdigit(lea[j])){//comienza digito
          indica++;
        }
      }
      if(indica==lea.length()){//es entero
        vectorfinal.push_back(LINEA+"                 Entero");
      }else{
        cout<<"error en su formación"<<endl;
      }
    }
  }
  
  
  
  
  
  else{//no comienza con menos
    //recorre los caracteres en la linea
    for(int i=0;i<LINEA.length();i++){
      if(LINEA[i]=='-'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i] == '(' | LINEA[i] == ')'){
        lea= LINEA.substr(0,i);
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='.'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del punto
        punto=true;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='+'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='*'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='^'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='/' && LINEA[i+1]!='/'){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        flag=false;
        muestra=i;
        break;
      }
      else if(LINEA[i]=='/' && LINEA[i+1]=='/' ){
        lea= LINEA.substr(0,i);//todo lo que esta antes del operador
        COME=true;
        muestra=i;
        break;
      }
      else{//no hay operadores
        flag=true; 
      }
    }


    if(punto==true){//contiene punto
      //verifica que se a digito todo antes del punto
      for(int j=0;j<lea.length();j++){
        if(isdigit(lea[j])){//comienza con digito
          indica++;
        }
      }
      if(indica==lea.length()){//es num
        Q5(LINEA,muestra,vectorfinal);//pasa donde se encuentra el punto estado 5
      }else{
        cout<<"error en su formación"<<endl;
      }
    }
    else if(COME==true){//tiene comentario
      //verificar que sea entero
      for(int j=0;j<lea.length();j++){
        if(isdigit(lea[j]) ){//comienza num
          indica++;
        }
      }
      if(indica==lea.length()){//es entero
        vectorfinal.push_back(lea+"                 Entero");
        vectorfinal.push_back(LINEA.substr(muestra) + "                 Comentario");
      }else{
        cout<<"error en su formación"<<endl;
      }
    }
    else if(flag!=true){//si hay operadores
      for(int j=0;j<lea.length();j++){
        if(isdigit(lea[j])){//comienza con digito
          indica++;
        }
      }
      if(indica==lea.length()){//es num
        vectorfinal.push_back(lea+"                 Entero");//agregar a los resultados
        if(LINEA[muestra]=='-'){
          vectorfinal.push_back("-                Resta");//agregar a los resultados
          SEND=LINEA.substr(muestra+1);//despues del operador
          Q9(SEND,vectorfinal);//va al estado 9
        }
        else if(LINEA[muestra] == '(' | LINEA[muestra] == ')'){
          if(LINEA[muestra]=='('){
            vectorfinal.push_back("(                Parentesis que abre"); 
            SEND=LINEA.substr(muestra+1);//despues del operador
            Q9(SEND,vectorfinal);
          }else{
            vectorfinal.push_back(")                Parentesis que cierra"); 
            SEND=LINEA.substr(muestra+1);//despues del operador
            if(SEND.length()!=0){
              Q9(SEND,vectorfinal);
            }
            
          }
        }
        else if(LINEA[muestra]=='+'){
          vectorfinal.push_back("+                Suma");//agregar a los resultados
          SEND=LINEA.substr(muestra+1);//despues del operador
          Q9(SEND,vectorfinal);//va al estado 9
        }
        else if(LINEA[muestra]=='*'){
          vectorfinal.push_back("*                Multiplicación");//agregar a los resultados
          SEND=LINEA.substr(muestra+1);//despues del operador
          Q9(SEND,vectorfinal);//va al estado 9
        }
        else if(LINEA[muestra]=='^'){
          vectorfinal.push_back("^                Potencia");//agregar a los resultados
          SEND=LINEA.substr(muestra+1);//despues del operador
          Q9(SEND,vectorfinal);//va al estado 9
        }
        else if(LINEA[muestra]=='/'){
          vectorfinal.push_back("/                División");//agregar a los resultados
          SEND=LINEA.substr(muestra+1);//despues del operador
          Q9(SEND,vectorfinal);//va al estado 9
        }
        
      }
      else{//declaracion incorrecta
        cout<<"error en su formación"<<endl;
      }
    }
    else{//no hay operadores
      //verificar que sea digito/entero
      for(int j=0;j<lea.length();j++){
        if(isdigit(lea[j])){//comienza con digito
          indica++;
        }
      }
      if(indica==lea.length()){//es variable
        vectorfinal.push_back(LINEA+"                 Entero");//agregar a los resultados
      }else{//declaracion incorrecta
        cout<<"error en su formación"<<endl;
      }
    }
  } 
}



//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q3-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
void Q3(string LINEA,vector<string> &vectorfinal){//linea a revisar, vector de resultados
  string lea,SEND;
  bool flag=false,COME=false,PARE=false;//indicadores
  int indica=0,muestra=0;//indica ->verificar que es variable,muestra->guarda donde se encuentra un operador, parentesis o comentario
  //recorre cada caracter de la linea 
  for(int i=0;i<LINEA.length();i++){
    if(LINEA[i] == '(' | LINEA[i] == ')'){
      lea= LINEA.substr(0,i);//todo lo que esta antes del operador
      PARE=true;
      muestra=i;
      break;
    }
    else if(LINEA[i]=='-'){
      lea= LINEA.substr(0,i);//todo lo que esta antes del operador
      flag=false;
      muestra=i;
      break;
    }
    else if(LINEA[i]=='+'){
      lea= LINEA.substr(0,i);//todo lo que esta antes del operador
      flag=false;
      muestra=i;
      break;
    }
    else if(LINEA[i]=='*'){
      lea= LINEA.substr(0,i);//todo lo que esta antes del operador
      flag=false;
      muestra=i;
      break;
    }
    else if(LINEA[i]=='^'){
      lea= LINEA.substr(0,i);//todo lo que esta antes del operador
      flag=false;
      muestra=i;
      break;
    }
    else if(LINEA[i]=='/' && LINEA[i+1]!='/'){
      lea= LINEA.substr(0,i);//todo lo que esta antes del operador
      flag=false;
      muestra=i;
      break;
    }
    else if(LINEA[i]=='/' && LINEA[i+1]=='/' ){
      lea= LINEA.substr(0,i);//todo lo que esta antes del operador
      COME=true;
      muestra=i;
      break;
    }
    else{//no hay operadores
      flag=true; 
    }
  }


  if(COME==true){//tiene comentario
    //verifica que sea variable
    for(int j=0;j<lea.length();j++){
      if(isdigit(lea[j]) | isalpha(lea[j]) | lea[j]=='_'){//comienza con letra,digito o '_'
        indica++;
      }
    }
    if(indica==lea.length()){//es variable
      vectorfinal.push_back(lea+"                 Variable");
      vectorfinal.push_back(LINEA.substr(muestra) + "                 Comentario"); 
    }else{//declaracion incorrecta
      cout<<"error en su formación"<<endl;
    }
  }

  else if(PARE==true){//tiene parentesis
    //verifica que sea variable
    for(int j=0;j<lea.length();j++){
      if(isdigit(lea[j]) | isalpha(lea[j]) | lea[j]=='_'){//comienza con letra,digito o '_'
        indica++;
      }
    }
    if(indica==lea.length()){//es variable
      //que tipo de parentesis es
      if(LINEA[muestra]=='('){
        vectorfinal.push_back(lea+"                 Variable");
        vectorfinal.push_back("(                 Parentesis que abre");
        SEND=LINEA.substr(muestra+1);//despues del operador
        Q9(SEND,vectorfinal);//pasa al estado 9
      }else if(LINEA[muestra]==')'){
        vectorfinal.push_back(lea+"                 Variable");
        vectorfinal.push_back(")                 Parentesis que cierra");
        SEND=LINEA.substr(muestra+1);//despues del operador
        Q9(SEND,vectorfinal);//pasa al estado 9
      }
    }else{//declaracion incorrecta
      cout<<"error en su formación"<<endl;
    }
  }

  else if(flag!=true){//si hay operadores
    //verifica que sea variable
    for(int j=0;j<lea.length();j++){
      if(isdigit(lea[j]) | isalpha(lea[j]) | lea[j]=='_'){//comienza con letra,digito o '_'
        indica++;
      }
    }
    if(indica==lea.length()){//es variable
      vectorfinal.push_back(lea+"                 Variable");
      //es Resta
      if(LINEA[muestra]=='-'){
        vectorfinal.push_back("-                Resta");
        SEND=LINEA.substr(muestra+1);//despues del operador
        Q9(SEND,vectorfinal);
      }
      //es suma
      else if(LINEA[muestra]=='+'){
        vectorfinal.push_back("+                Suma");
        SEND=LINEA.substr(muestra+1);//despues del operador
        Q9(SEND,vectorfinal);//pasa al estado 9
      }
      //es Multiplicación
      else if(LINEA[muestra]=='*'){
        vectorfinal.push_back("*                Multiplicación");
        SEND=LINEA.substr(muestra+1);//despues del operador
        Q9(SEND,vectorfinal);//pasa al estado 9
      }
      //es potencia
      else if(LINEA[muestra]=='^'){
        vectorfinal.push_back("^                Potencia");
        SEND=LINEA.substr(muestra+1);//despues del operador
        Q9(SEND,vectorfinal);//pasa al estado 9
      }
      //es division
      else if(LINEA[muestra]=='/'){
        vectorfinal.push_back("/                División");
        SEND=LINEA.substr(muestra+1);//despues del operador
        Q9(SEND,vectorfinal);//pasa al estado 9
      }
    }
    else{//declaración incorrecta
      cout<<"error en su formación"<<endl;
    }
  }
  else{//no hay operadores
    for(int j=0;j<lea.length();j++){//verifica que sea variable
      if(isdigit(lea[j]) | isalpha(lea[j]) | lea[j]=='_'){//comienza con letra,digito o '_'
        indica++;
      }
    }
    if(indica==lea.length()){//es variable
      vectorfinal.push_back(lea+"                 Variable");
      
    }else{//declaracion incorrecta
      cout<<"error en su formación"<<endl;
    }
  }
}



//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q2-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
void Q2(string LINEA,vector<string> &vectorfinal){//linea para analizar, vector de resultados
  char inicia = LINEA[0];//que hay despues de =
  //es alpha/letra
  if(isalpha(inicia)){
    Q3(LINEA,vectorfinal);//pasa al estado 3
  }
  //es digito
  else if(isdigit(inicia)){
    Q4(LINEA,vectorfinal);//pasa al estado 4
  }
  //es signo de menos
  else if(inicia=='-'){
    Q10(LINEA,vectorfinal);//pasa al estado 10 
  }else{//declaracion incorrecta
    cout<<"error en su formación"<<endl;
  }
}


//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q1-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
void Q1(string LINEA,vector<string> &vectorfinal){//linea con datos,vector donde se almacenan resultados
  string SEND,lea;
  int indica=0;
  lea= LINEA.substr(0,LINEA.find("="));//todo lo que esta antes del igual
  for(int j=0;j<lea.length();j++){//recorre cada caracter antes del =
    //verifica que sea. variable
    if(isdigit(LINEA[j]) | isalpha(LINEA[j]) | LINEA[j]=='_'){//comienza con letra,digito o '_'
      indica++;
    }
  }
  if(indica==lea.length()){//es variable
    vectorfinal.push_back(lea+"                 Variable");
    vectorfinal.push_back("=                      Asignación");
    SEND = LINEA.substr(LINEA.find("=")+1);//toma todo lo que esta despues del igual
    Q2(SEND, vectorfinal);//manda al siguiente estado
  }else{//declaracion incorrecta
    cout<<"error en su formación"<<endl;
  }
}


//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//---------------------------------------------------Q0-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
void Q0(vector<string> ENTRADA,vector<string> &vectorfinal){//vector con datos acomodados, donde se guardan los resultados
  
  //recorre cada linea en el archivo que se ingreso
  for(int i=0;i<ENTRADA.size();i++){
    if(isalpha(ENTRADA[i][0])){//comienza con letra
      Q1(ENTRADA[i],vectorfinal);//pasa al siguiente estado
    }else if(ENTRADA[i].find("//")==0){//comienza con comentario
      vectorfinal.push_back(ENTRADA[i]+"            Comentario");
      
    }else{//declaración incorrecta
      cout<<"error en su formación"<<endl;
      
    }
  }
}

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//------------------------------------FUNCION PRINCIPAL-----------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
void lexerAritmetico(string archivo,vector<string> &vectorfinal){//toma el archivo que se lee y el vector donde se van a guardar los resultados
  vector<string> LISTA;
  string line;//linea que a sacar del doc txt
  fstream myfile;

  myfile.open (archivo); //abrir doc y leerlo
  while(getline(myfile, line)){ //leer linea de archivo
    if(line != ""){

      LISTA.push_back(line);//agregar linea a lista
    }
  }
  myfile.close(); //cerrar archivo

  //ENCUENTRA COMENTARIO Y JUNTA LOS DATOS SI ES QUE TIENEN ESPACIOS
  int found;
  string DATOS,COME,todo,verifica;
  vector<string> CADENA;
  //revisa cada linea para organizarla 
  for (int i = 0; i < LISTA.size(); i++) {
    found=LISTA[i].find("//");
    if (found!= -1){//si encuentra un comentario no quitar espacios
      DATOS=LISTA[i].substr (0,found);//datos antes del comentario
      DATOS.erase(remove(DATOS.begin(), DATOS.end(), ' '), DATOS.end());//quitar espacios
      COME= LISTA[i].substr (found);//comentario completo
      todo = DATOS + COME;//une los datos y el comentario
      CADENA.push_back(todo);//a= b * 3 // hola a todos --> a=b*3// hola a todos
    }else{
      //quitar espacios
      LISTA[i].erase(remove(LISTA[i].begin(), LISTA[i].end(), ' '), LISTA[i].end());
      CADENA.push_back(LISTA[i]);//agrega a la lista 
    }
  }

  Q0(CADENA,vectorfinal);//manda las lineas al primer estado
}
int main(){
  vector<string> SALIDA;
  string in,ARCHIVO;
  cin>>in;//input del nombre del archivo como --> entrada.txt
  ARCHIVO=""+ in +"";//agrega "" al input para poder leer el archivo --> "entrada.txt"
  SALIDA.push_back("Token                  Tipo");
  lexerAritmetico(ARCHIVO,SALIDA);//lee el contenido y lo mando al primer estado
  for (int i = 0; i < SALIDA.size(); i++) {//imprime los datos obtenidos
    cout<<SALIDA[i]<<endl;
  }

  return 0;
}
