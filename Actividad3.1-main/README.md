# Actividad3.1
Implementa y agrega las funcionalidades avanzadas al ADT del BST realizado con las funcionalidades fundamentales:

traversal	Descripción	
Desplegará cada uno de los datos almacenados en el BST dependiendo del parámetro en entrada:

Preorder
Inorder
Postorder
Level by level
Entrada	Un entero (1-4)
Salida	Nada
Precondición	Un BST válido
Postcondición	Nada

height	Descripción	Regresará la altura del BST
Entrada	Nada
Salida	Un entero con el cual indicará la altura del BST
Precondición	Un BST válido
Postcondición	Nada

ancestors	Descripción	
Desplegará los ancestros de un dato

Entrada	El dato del cual se desea conocer los ancestros
Salida	Nada
Precondición	Un BST válido
Postcondición	Nada

whatlevelamI	Descripción	
Regresará un entero que indica el nivel en que se encuentra un dato, o -1 en caso de que no se encuentre en el BST

Entrada	Un dato a buscar su altura
Salida	Entero indicando el nivel del dato en el BST, o -1 si no se encuentra
Precondición	Un BST válido
Postcondición	Nada
entrada:

n // número de nodos a insertar
n valores enteros
m // número de nodos a eliminar
m valores enteros
q // número de valores a desplegar sus ancestros
q valores enteros
r // número de valores a desplegar en que nivel se encuentran
r valores enteros

salida:

recorrido en preorden, valores separados por exactamente un espacio, el ultimo valor tambien lleva espacio
recorrido en inorden, valores separados por exactamente un espacio, el ultimo valor tambien lleva espacio
recorrido en postorden, valores separados por exactamente un espacio, el ultimo valor tambien lleva espacio
recorrido nivel por nivel, valores separados por exactamente un espacio, el ultimo valor tambien lleva espacio
valor de la altura total del arbol sin espacios al final
lista de ancestros de los q valores, separados por exactamente un espacio, el ultimo valor tambien lleva espacio
lista de enteros representando el nivel de cada uno de los r valores leidos, uno en cada línea, sin espacios al final


ejemplo de entrada
10
45
98
32
85
96
36
25
74
98
95
3
98
85
36
2
74
25
3
96
45
75


ejemplo de salida

45 32 25 95 74 96
25 32 45 74 95 96
25 32 74 96 95 45
45 32 95 25 74 96
3
45 95
45 32
2
0
-1
