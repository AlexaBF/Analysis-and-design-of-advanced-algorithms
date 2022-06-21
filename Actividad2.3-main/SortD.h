//sort por mes descendente

#include <string>
#include "Node.h"
#include <iostream>
#include "Mes.h"
using namespace std;

//divide lista en dos 
struct Node *splitL(struct Node *head){  
    struct Node *fast = head,*slow = head;  
    while (fast->next && fast->next->next){  
        fast = fast->next->next;  
        slow = slow->next;  
    }  
    struct Node *temp = slow->next;  
    slow->next = NULL;  
    return temp;  
}
  
//une las listas
struct Node *Une(struct Node *lista1, struct Node *lista2){   
    if (!lista1) {//si la lista 1 esta vacia
        return lista2; 
    }
    if (!lista2){//si la lista 1 esta vacia
        return lista1;  
    } 

    string Mes1=lista1->MES;
    string Mes2=lista2->MES;
    int MES1,MES2;
    MES1=Mes(Mes1);
    MES2=Mes(Mes2);

    //elige valor mayor 
    if (MES1 > MES2){  
        lista1->next = Une(lista1->next,lista2);  
        lista1->next->previo = lista1;  
        lista1->previo = NULL; 
        
        return lista1;  
    }  
    else{  
        lista2->next = Une(lista1,lista2->next);  
        lista2->next->previo = lista2;  
        lista2->previo = NULL;  
        
        return lista2;  
    }  
}  
  
// Function to do merge sort  
struct Node *SortD(struct Node *head){  
    if (!head || !head->next){  
        return head;  
    }
    struct Node *lista2 = splitL(head);  
  
    // Recur for left and right halves  
    head = SortD(head);  
    lista2 = SortD(lista2);  
  
    // Merge the two sorted halves  
    return Une(head,lista2);  
}  

