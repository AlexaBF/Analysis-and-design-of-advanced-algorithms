//clase para declarar el nodo de la lista

#pragma once
#include <iostream>
using namespace std;

struct Node{
    int data;// dato del nodo
    struct Node *next;// apuntador al siguiente nodo
};
