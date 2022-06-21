# Actividad2.1
Escribe un programa en C++ que trabaje con listas (simplemente) ligadas de manera individual.
Un nodo contiene simplemente un entero y el apuntadora al siguiente nodo
La lista puede contener elementos duplicados

El programa debe funcionar de acuerdo a un menu ciclado que representa las siguientes opciones:

1. Inserta al inicio
2. Inserta al final
3. Elimina al inicio
4. Elimina al final
5. Imprime
0. Salir

IMPORTANTE: el menú NO se imprime, solo espera por la entrada del usuario, NO cambiar opciones.



Todas las funcionalidades deberán de estar correctamente alineadas y documentadas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.

 
 Inserta_al_inicio
Descripción	Insertar un elemento al inicio de la lista ligada
Entrada	Estructura de datos (doble pointer) y elemento a insertar
Salida	Estructura de datos válida mostrando la inserción del elemento 
Precondición	Estructura de datos válida
Postcondición	Estructura modificada

Inserta_al_final	Descripción	Insertar un elemento al final de la lista ligada
Entrada	Estructura de datos (doble pointer) y elemento a insertar
Salida	Estructura de datos válida mostrando la inserción del elemento 
Precondición	Estructura de datos válida
Postcondición	Estructura modificada

Elimina_al_inicio	Descripción	Eliminar al elemento que se encuentra al inicio de la lista ligada. Si la lista esta vacia, se escribe la palabra ERROR
Entrada	Estructura de datos (doble pointer) válida
Salida	Estructura de datos válida
Precondición	Estructura de datos válida
Postcondición	Estructura de datos válida

Elimina_al_final	Descripción	
Eliminar al elemento que se encuentra al final de la lista ligada. Si la lista esta vacia, se escribe la palabra ERROR

Entrada	Estructura de datos (doble pointer) válida
Salida	Estructura de datos válida
Precondición	Estructura de datos válida
Postcondición	Estructura de datos válida

Imprime	Descripción	
imprimne los elementos de una lista ligada, uno por línea

Entrada	Estructura de datos (pointer) válida
Salida	Una estructura de datos válida
Precondición	Una estructura de datos válida
Postcondición	Una estructura de datos válida
 
 
 

ejemplo de entrada

3
2
88
1
23
3
2
56
2
48
4
1
56
1
89
4
3
1
29
2
73
5
0

ejemplo de salida

ERROR
29
56
88
73
