//merge sort de iP

//ordenamiento con Merge 
//complejidad log O(n log n) 

#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

int Size(struct Node *HEAD){ //size de la lista ligada
   int SIZE = 0; 
   while (HEAD != NULL) { 
      SIZE++; 
      HEAD = HEAD->next; 
   } 
   return SIZE; 
} 

struct Node* UneI(struct Node *&head1,struct Node *&head2){//une las dos listas
   //crear nuevo nodo
   struct Node* nuevo_head;
   if(head1==NULL){//si esta vacia la lista 1
      return head2;
   } 
   if(head2 ==NULL){//si esta vacia la lista 2
      return head1;
   }

   string IP_1="";
   string IP_2="";
   IP_1+= head1->IP + to_string(head1->PUERTO) + head1->FECHA + head1->HORA + head1->ERROR;
   IP_2+= head2->IP + to_string(head2->PUERTO) + head2->FECHA + head2->HORA + head2->ERROR;

   //comparar valores
   if(IP_1 > IP_2){
      nuevo_head = head1;
      nuevo_head->next = UneI(head1->next,head2);

   }else{
      nuevo_head = head2;
      nuevo_head->next = UneI(head1,head2->next);
   }

   return nuevo_head;
}


void MergeSort(struct Node **head){
   if((*head)->next!=NULL){//verificar que no sea el ultimo nodo
      struct Node* head1;
      struct Node* head2 = *head;
      
      for(int i=0; i< (Size(*head)) /2;i++){//mitad de lista
         head1 = head2;
         head2 = head2->next;
      }
      head1->next = NULL;//borrar primera parte de lista ligada
      head1 = *head;
      MergeSort(&head1);
      MergeSort(&head2);
      
      *head = UneI(head1,head2);//une las dos listas 
      
   }
}
