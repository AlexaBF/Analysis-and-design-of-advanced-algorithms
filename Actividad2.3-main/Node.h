//clase para declarar el nodo de la lista doblemente ligada

#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node{
    string IP;
    int PUERTO;
    string FECHA;
    string HORA;
    string ERROR;
    string MES;// dato del nodo
    struct Node *next;// apuntador al siguiente nodo
    struct Node *previo;//apunta al nodo anterior
};
