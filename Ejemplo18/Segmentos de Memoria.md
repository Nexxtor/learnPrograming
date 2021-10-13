# Segmentos de memoria

## Introducción

Hasta este momento has creado algunos programas para practicar las estructuras de control condicional, repetición, funciones, uso de variables, operaciones aritmeticas y operaciones logicas. Al mismo tiempo, un idea basica de como se ejecutan estos programas en nuestra computadora. Lo primero que sucede es que el código fuente se transforma en lenguaje de maquina a través de un proceso de compilación, luego haciendo uso de la linea de comando o de la ayuda de VS Code ejecutamos el programa, pero ¿como se ejecuta?en esta lectura responderemos parte de esa pregunta al comprende como funciona la memoria en la computadora.

La memoria es un componente fisico capaz de almacenar o "memorizar" datos durante algun periodo. La memoria aporta a la computación la capacidad de tener conocimiento, es decir, recordar resultados de calculos realizados por el CPU. Existen memorias de diferentes tipos como:

1. Memoria volátil como la memoria RAM
2. Memoria no volátil como los disco duros, usb, CD ...

Ademas, estas memorias puede funcionar de dos formas diferentes

1. Acceso aleatorio: permite acceder a un sector de la memoria con el mismo tiempo que a cualquier otro.
2. Acceso Secuencial: el tiempo de lectura de un sector de memoria depende del tiempo de lectura del sector anterior, ya que es necesario acceder de forma secuencial para poder alcanzar el sector de memoria deseado. Así, como lo pudiste observar en los discos duros mostrados en nuestra primer práctica de laboratorio.

Entender como funcionan todos los tipos de memorias seria interesante, pero en esta ocasion cuando se mencione memoria, se esta haciendo referencia a la memoria RAM de la computadora, ya que nos interesa saber como esta se utiliza para ejecutar nuestros programas.

## Memoria

La memoria se puede representar como una colección de celdas contiguas con la capacidad de almacenar bytes. Cada una de estas celdas posee una **direccion**, que consta de un valor de segmento y otro de offset, pero para nuestros fines, diremos que cada celda la representa un numero en formato hexadecimal como 0x0010.
Si creamos una representación abstracta de la memoria y sus dirección tenemos lo siguiente:

| Dirección | Celda |
| --------- | ----- |
| 0x0070    |       |
| 0x0080    |       |
| 0x0078    |       |
| 0x0088    |       |
| 0x0090    |       |
| 0x0098    |       |
| 0x00A0    |       |
| 0x00A8    |       |
| 0x00B0    |       |
| 0x00B8    |       |

Como podras notar en la representación simplemente es una columna de celda de algun tamaño, que para deferencias una de otras las nombramos con direcciones. Cada vez que tu enciendes tu computadora el sistema operativos se carga en la memoria, para poder ejecutarse y luego este se encarga de como distribuir la memoria para los demas programas.

Cada vez que se ejecuta un programa se reservan segmentos de memoria de un tamaño determinado, estos segmentos sirve para organizar el manejo de memoria y que esta este disponible para la necesidades de usuario.

# Segmentos de memoria

<img src="img/page1-234px-Program_memory_layout.jpg" alt="Distribución de memoria para un programa" style="float: left; margin: 1rem;">

Los segmentos de memoria son bloques de memoria reservados con finalidades especificas para hacer capaz que un programa se ejecute. Cuando un programa se ejecuta se crear los siguientes segmentos de memoria:

CS Code Segment (segmento de código) .text: Un segmento de tamaño fijo y de solo lectura. Donde se almacena el código máquina de nuestro programa. Lo que permite al procesador ejecutar las instrucciones. 

Data Segment (segmento de datos) .data: Se almacenan las variables globales inicializadas, es de tamaño fijo y permite lectura y escritura.

Block Starting Symbol .bss: Se almacenan las variable globales sin inicializar es de tamaño fijo y permite lectura y escritura.

HS Heap Segment (Almacenamiento libre): Segmento de memoria dinamica del programa. El tamaño de este no esta predefinido. Y crece hacia arriba

SS Stack Segment (pila): Aquí se guardan los argumentos pasados al programa, valores de retorno, variables de entorno, entre otros.

Video sobre segmentos de memoria: 