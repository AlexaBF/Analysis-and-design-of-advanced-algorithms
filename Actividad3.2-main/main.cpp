#include "priority_queue.h"

int main(){
   int entrada;
   priority_queue ARBOL;
   cin>>entrada;
   while (entrada != 0){
      while (entrada < 1 || entrada > 6){
         cin>>entrada;  
      }

      switch (entrada){
      case 1:
         int elemento;
         cin>>elemento;
         ARBOL.push(elemento);
         break;
      
      case 2:
         ARBOL.pop();
         break;

      case 3:
         ARBOL.print();
         break;

      case 4:
         ARBOL.top();
         break;

      case 5:
         
         if (ARBOL.empty() == false){
            cout<<"false"<<endl;
         }else{
            cout<<"true"<<endl;
         }
         
         break;

      case 6:
         ARBOL.size();
         break;
      }
      cin>>entrada;
   }
   
}