# Actividad-3.2b-Implementacion-de-Dijkstra-and-Floyd-
Escribe un programa en C++ que implemente los algoritmos de Dijkstra y Floyd para encontrar la distancia más corta entre parejas de nodos en un grafo dirigido. 

El programa debe leer un número n seguido de n x n valores enteros no negativos que representan una matriz de adyacencias de un grafo dirigido.

El primer número representa el número de nodos, los siguientes valores en la matriz, el valor en la posición i,j representan el peso del arco del nodo i al nodo j. Si no hay un arco entre el nodo i y el nodo j, el valor en la matriz debe ser -1.
La salida del programa es, primero con el algoritmo de Dijkstra la distancia del nodo i al nodo j para todos los nodos, y luego, la matriz resultado del algoritmo de Floyd

 

Ejemplo de entrada:

4 
0 2 -1 3 
-1 0 1 5 
2 3 0 -1 
3 -1 4 0

 

Ejemplo de salida:

Dijkstra: 
node 1 to node 2:  2 
node 1 to node 3:  3 
node 1 to node 4:  3 
node 2 to node 1:  3 
...

node 4 to node 2:  5 
node 4 to node 3:  4 

Floyd: 
0 2 3 3 
3 0 1 5 
2 3 0 5 
3 5 4 0
