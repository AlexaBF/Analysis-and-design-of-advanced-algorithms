# Actividad3.2
Escribe una clase en C++ llamada "priority_queue" que tenga las siguientes operaciones utilizando un heap y simulando una fila priorizada de enteros con prioridad de valor mayor.

 

push	Descripción	
Agregue un dato a la fila priorizada

Entrada	
Un entero, el cual se desea agregar a la fila priorizada

Salida	Nada
Precondición	n es un entero
Postcondición	La fila priorizada contiene un nuevo dato.
 

pop	Descripción	
Saca de la fila priorizada el dato que tiene mayor prioridad

Entrada	Nada
Salida	El entero con mayor prioridad
Precondición	Que la fila priorizada contenga al menos 1 dato.
Postcondición	La fila priorizada queda sin el dato con mayor prioridad
 

print	Descripción	
Imprime la fila priorizada, terminando con un salto de línea, primero el dato que tiene mayor prioridad. Los datos NO estan nesesariamente ordenados. Si no hay datos, se imprime sólo un salto de linea. Imprime los datos uno por uno, despues de cada dato va un espacio en blanco, incluso después del último dato.

Entrada	Nada
Salida	Nada
Precondición	ninguna. 
Postcondición	ninguna
 

top	Descripción	
Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.

Entrada	Nada
Salida	El dato que tiene mayor prioridad dentro de la Fila priorizada
Precondición	Que la fila priorizada contenga al menos 1 dato. Si la fila priorizada esta vacía, se regresa un -1
Postcondición	Nada

empty	Descripción	
Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.

Entrada	Nada
Salida	Un valor boleano que diga si la fila priorizada esta vacía o tiene datos.
Precondición	Nada.
Postcondición	Nada

size	Descripción	
Regresa la cantidad de datos que tiene la fila priorizada

Entrada	Nada
Salida	Un valor entero que represena la cantidad de datos de la fila priorizada
Precondición	Nada.
Postcondición	Nada
entrada:
interacción de acuerdo al siguiente menu. (el menu NO se imprime)

1. push
2. pop
3. print
4. top
5. is_empty
6. size
0. exit

salida:
el resultado de la interacción

ejemplo de ejecución:

input:

5
1
51
1
37
5
1
64
1
32
1
16
4
1
96
2
2
3
0

output:

true
false
64
96
64
51 37 16 32

 

(salida con detalles)

true<no hay espacio aqui><salto de linea>
false<no hay espacio aqui><salto de linea>
64<no hay espacio aqui><salto de linea>
96<no hay espacio aqui><salto de linea>
64<no hay espacio aqui><salto de linea>
51<espacio>37<espacio>16<espacio>32<espacio><salto de linea>
