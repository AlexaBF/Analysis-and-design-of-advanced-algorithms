# Actividad-2.2.-Implementacion-de-Hash-String-
La salida es una cadena de longitud n/4 que es una representación hexadecimal que corresponde al hasheo del archivo de texto de entrada de acuerdo con las siguientes reglas:

El entero n determina el número de columnas que contendrá una tabla donde se irán acomodando los caracteres del archivo de texto (incluyendo saltos de líneas) en los renglones que sean necesarios.
Si el numero de caracteres en el archivo de entrada no es múltiplo de n, el último renglón se "rellena" con el valor de n.
En un arreglo a de longitud n se calcula a[i] = (la suma de los ASCII de cada char en la columna) % 256.
La salida se genera concatenando la representación hexadecimal (mayúsculas) a dos dígitos de cada posición en el arreglo.
La longitud de la cadena de salida será de n/4.
Muestra la tabla generada, el arreglo a, y la cadena de salida.
