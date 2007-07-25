Esta sección intenta responder satisfactoriamente la siguiente
pregunta... ¿En qué se diferencia el desarrollo de una aplicación de
simulación al de cualquier otro programa?  La respuesta rápida es que
en nada o en muy poco.  Como va en contra del pensamiento generalizado
del sector es necesario extenderse un poco más.

El punto de vista
-----------------

Cabe diferenciar dos casos en este aspecto:

1. Los experimentos numéricos

2. Los códigos comerciales

Dos algoritmos pueden estar implementados de forma completamente
distinta según se utilicen para realizar un experimento numérico o
como parte de un código comercial.  Siendo breves: en el primero el
código no importa y en el segundo sí.

Un investigador ve un experimento numérico como un medio para llegar a
un resultado con lo que lo que más le interesa es que su resultado sea
el correcto.  En cambio un ingeniero trabajando en un código comercial
será consciente que es parte de un organismo y que la productividad es
importante.  Si su código cae en manos de otro ingeniero no puede
perder productividad.

Estas diferencias existen porque se rompe el proceso ideal de
desarrollo de software donde la estructura y la documentación del
código son valores importantes.  La principal causa es la ausencia de
tiempo para cuidar estos detalles aunque sean de suma importancia.

Este libro pretende dar herramientas para que la calidad del código
pueda mantenerse con el mínimo esfuerzo.

Las exigencias computacionales
------------------------------

Resolución de ecuaciones diferenciales tanto ordinarias como en
derivadas parciales, algoritmos genéticos, estudios paramétricos.
Algunos de estos problemas necesitan ordenadores de potencia casi
infinita para ser resueltos.

Existe la creencia que los lenguajes interpretados, objetivo de este
libro, son lentos y no aptos para estas tareas.  Que no son más que
juguetes para que los ingenieros informáticos administren servidores o
creen aplicaciones gráficas.  Esta creencia es verdadera pero sólo
hasta cierto punto.

Los lenguajes interpretados son lentos haciendo una serie determinada
de cosas.  Alguna de ellas, como las iteraciones, son parte
fundamental de cualquier algoritmo numérico.  Existen soluciones para
paliar estas inconveniencias así como para conseguir que el
rendimiento global se acerque a los códigos escritos enteramente en C
o Fortran.  Este libro da pistas de cómo hacerlo.
