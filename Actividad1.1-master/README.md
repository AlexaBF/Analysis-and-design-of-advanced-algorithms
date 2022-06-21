# Actividad1.1
Realiza una aplicación en C++ en forma individual,  que calculé la sumatora de 1 hasta n y llame a tres funciones:

sumaIterativa	Descripción	
Calcule la sumatoria de 1 hasta n con un metodo iterativo.

Entrada	Un entero positivo (n)
Salida	La sumatoria de 1 hasta n
Precondición	n es un entero positivo
Postcondición	Nada

sumaRecursiva	Descripción	
Calcule la sumatoria de 1 hasta n con un metodo recursivo.

Entrada	Un entero positivo (n)
Salida	La sumatoria de 1 hasta n
Precondición	n es un entero positivo
Postcondición	Nada

sumaDirecta	Descripción	
Calcule la sumatoria de 1 hasta n con un metodo matemático directo.

Entrada	Un entero positivo (n)
Salida	La sumatoria de 1 hasta n
Precondición	n es un entero positivo
Postcondición	Nada

Todas las funcionalidades deberán de estar correctamente alineadas y documentadas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.

La aplicación leerá un número k, que es la cantidad de enteros positivos de los cuales se calculará las sumatoria por los tres métodos y posteriormente vendrán los k números enteros positivos, y por cada número se desplegará la sumatoria con el siguiente formato:

suma_Iterativa<espacio>suma_Recursiva<espacio>suma_Directa<salto_de_renglón>

Ejemplo de Entrada:

3
4
1
5

Ejemplo de Salida:

10 10 10
1 1 1
15 15 15

Donde:

1 <= k <= 10^4

1 <= n <= 105
