# Act2.2

reverse	Descripción	
invierte el contenido de la lista ligada
regresa un pointer a la cabeza de la nueva lista ligada
Trabajar con listas simplemente ligadas, NO usar doblemente ligadas. 
La lista debe mutar, es decir, la lista recibida como parámetro debe desaparecer, solo persiste la nuneva lista

Entrada	Apuntador (a apuntador) al inicio de la lista a invertir
Salida	Apuntador al inicio de la nueva lista ligada (reordenada)
Precondición	Una lista ligada válida 
Postcondición	Una lista ligada válida

equals	Descripción	Revisa si dos listas ligadas tienen el mismo contenido.
Entrada	dos apuntadores a listas ligadas válidas
Salida	true / false
Precondición	dos listas ligadas válidas 
Postcondición	dos listas ligadas válidas

concat	Descripción	
Concatena lista1 + lista2

Entrada	dos apuntadores a listas ligadas válidas
Salida	nada
Precondición	las dos listas ligadas son válidas
Postcondición	La primera lista ligada contiene los elementos que contenía originalmente más los elementos de la otra lista ligada

Todas las funcionalidades deberán de estar correctamente alineadas y documentadas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.

input:
m
m daos enteros
n
n datos enteros

output :
reversed list 1
reversed list 2
reversed list 2 + reversed list 1
true / false

Ejemplo de entrada:
5
65
32
45
78
99
4
45
14
256
36

Ejemplo de salida
99
78
45
32
65
36
256
14
45
36
256
14
45
99
78
45
32
65
false
