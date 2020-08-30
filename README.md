# Trabajo Práctico de Regularización
## Cloná este repositorio

    git clone https://github.com/fgandolfo/ssl-tp-regularizacion
---------
**Objetivo:** Dada una expresión regular, hallar su AFD mínimo y programar en C un robot que descubra dicha expresión dentro de un texto con centinela '#'.

El programa se encuentra dentro de la carpeta ***src***, va a ser necesario compilarlo para poder usarlo.

### Como compilarlo?
Para compilar el programa es necesario, desde la terminal, ubicarse dentro de la carpeta src y copiar este código:

    gcc main.c automata.c automata.h

Con este código ya debería quedar compilado el programa y listo para usar con el nuevo binario ejecutable que se creó.

## Desarrollo de regex a AFD mínimo

**Expresión regular dada:** [01]\\.[0-9]? | [01]*B

**Centinela:** #

Comienzo definiendo cada lenguaje para poder diferenciar las partes de la regex:
- a = { 0 , 1 }  
- b = { . }  
- c = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 }  
- d = { B }

Por lo tanto, habiendo definido los lenguajes, podemos reescribir la regex de la siguiente forma:

    (a.(b+b.c))+(a*.d)

Utilizando el algoritmo de Thompson, llego al AFN completo

![AFN completo](https://github.com/fgandolfo/ssl-tp-regularizacion/blob/master/imgs/AFN_completo.png)

Ya con el AFN completo, podemos realizar la tabla de transiciones y, utilizando el algoritmo enseñado, pasar al AFD asociado.

||a|b|c|d
|--|--|--|--|--|
**{0, 1, 2, 3, 6, 7, 9}**|{2, 3, 4, 5, 6, 7, 11, 12, 14}|{13, 15, 16, 18, 19}|-|{8, 19}|
**{2, 3, 4, 5, 6, 7, 11, 12, 14}**|{2, 3, 4, 5, 6, 7}|-|-|{8, 19}|
**{2, 3, 4, 5, 6, 7}**|{2, 3, 4, 5, 6, 7}|-|-|{8, 19}|
**{13, 15, 16, 18, 19}**|-|-|{18, 19}|-|
**{8, 19}**|-|-|-|-|
**{18, 19}**|-|-|-|-|

Haciendo los cambios necesarios según dicta el algoritmo, nos queda la siguiente tabla final con su AFD asociado:

||a|b|c|d
|--|--|--|--|--|
**0-**|1|-|-|4|
**1**|2|3|-|4|
**2**|2|-|-|4|
**3+**|-|-|5|-|
**4+**|-|-|-|-|
**5+**|-|-|-|-|

![AFD inicial](https://github.com/fgandolfo/ssl-tp-regularizacion/blob/master/imgs/AFD_inicial.png)

Ahora que ya tenemos el AFD inicial, vemos mediante el algoritmo del AFD mínimo, cual es el AFD mínimo para este AFD encontrado.

Partiendo de la tabla anterior, buscamos los estados equivalentes entre sí.  
Encontramos que los estados 4 y 5 son equivalentes por pertenecer a la clase C1 y tener mismo comportamiento.  
Por lo tanto, eliminamos el estado 5 y reemplazamos sus llegadas con el estado 4

||a|b|c|d|Clase
|--|--|--|--|--|--|
**0-**|1|-|-|4|C0
**1**|2|3|-|4|C0
**2**|2|-|-|4|C0
**3+**|-|-|5|-|C1
**4+**|-|-|-|-|C1
**5+**|-|-|-|-|C1

Por lo tanto, eliminamos el estado 5 y reemplazamos sus llegadas con el estado 4

||a|b|c|d|Clase
|--|--|--|--|--|--|
**0-**|1|-|-|4|C0
**1**|2|3|-|4|C0
**2**|2|-|-|4|C0
**3+**|-|-|4|-|C1
**4+**|-|-|-|-|C1

Hacemos la tabla de transición por clases y separamos en nuevas clases por equivalencia

||a|b|c|d|Nueva Clase
|--|--|--|--|--|--|
**0-**|C0|-|-|C1|C2
**1**|C0|C1|-|C1|C0
**2**|C0|-|-|C1|C2
**3+**|-|-|C1|-|C1
**4+**|-|-|-|-|C3

Hacemos la nueva tabla de transición por clases con los nuevos valores

||a|b|c|d|Clase
|--|--|--|--|--|--|
**0-**|C0|-|-|C3|C2
**1**|C2|C1|-|C3|C0
**2**|C2|-|-|C3|C2
**3+**|-|-|C3|-|C1
**4+**|-|-|-|-|C3

Como no hay equivalencias por clase concluímos que el AFD mínimo es

||a|b|c|d|
|--|--|--|--|--|
**0-**|1|-|-|4|
**1**|2|3|-|4|
**2**|2|-|-|4|
**3+**|-|-|4|-|
**4+**|-|-|-|-|

Finalmente, **el AFD mínimo graficado sería el siguiente:**

![AFD minimo](https://github.com/fgandolfo/ssl-tp-regularizacion/blob/master/imgs/AFD_minimo.png)
