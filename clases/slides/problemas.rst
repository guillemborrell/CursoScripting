====================================
Solución de los problemas planteados
====================================

Primera sesión
==============

1. Extraer la matriz *T* de la matriz *M*

Para ello primero introducimos la matriz M::

  >> M=[11,12,13,14,15;21,22,23,24,25;31,32,33,34,35;...
     41,42,43,44,45;51,52,53,54,55];

  >> T=M(1:5,1:2:5);

Como podemos abreviar en el caso de tomar toda una columna::

  >> T=M(:,1:2:5)

2. Construir la estructura de datos y llamarla

La estructura de datos se construye de la siguiente manera::

  >> str.sin=@sin
  >> str.cos=@cos
  >> str.tan=@tan

Para llamar las funciones podemos llamar cada elemento de la
estructura del siguiente modo::

  >> str.sin(pi/2)

  ans = 1

:Pregunta recurrente: ¿Por qué no puedo llamar todos los elementos de
 la estructura mediante una única llamada si se que los tres elementos
 son function handles?

 La formulación de esta pregunta es razonable si aún no se ha
 entendido la diferencia entre variable y argumento.  Podemos aplicar
 una función a todos los elementos de una misma matriz (al contenido
 de una variable) porque la variable está asociada a un único
 argumento.  Es independiente que dicho argumento esté compuesto
 por elementos.

 La llamada::

   >> str(pi/2)

 No tiene ninguna lógica porque ``str`` no es ninguna variable, sólo
 la raíz de la estructura. Además Las estructuras de datos son
 estructuras de variables y cada variable
 contiene a su vez un argumento. El intérprete no tiene ninguna manera
 de saber qué contiene cada variable.  Si la llamada fuera posible
 sería inconsistente puesto que fallaría en el caso que alguno de los
 elementos de la estructura no fuera un function handle.

3. Cálculo matricial

  Primero introducimos las matrices

::

  >> A=[1,2,3;4,5,6;7,8,9];
  >> b=[1;2;3];
  >> c=[1,2,3];

* |Ab|

::

  >> A*b
  ans =

    14
    32
    50


.. |Ab| raw:: latex

  $A\cdot b$

* |sAb| . En este caso es importante ver que el sumatorio es el de
  columnas de *A* con el vector c, que es un vector fila.  La manera
  óptima de resolver este sumatorio es invirtiendo el orden natural
  del producto.  El resultado será de dimensión 1

::

  >> c*A
  ans =

    30  36  42


.. |sAb| raw:: latex

  $\sum_i A_{ij}c_i$


* |bc| . Esto no es un producto escalar sino un producto tensorial.
  Cuando Matlab multiplica un vector columna por un vector fila
  consigue una matriz

::

  >> b*c
  ans =

    1  2  3
    2  4  6
    3  6  9

.. |bc| raw:: latex

  $b\cdot c$

Aplicar al resultado la función |xseno| no es trivial puesto que todos
los resultados son matrices o vectores. Tendremos que uilizar los
operadores escalares en ambos casos

.. |xseno| raw:: latex

  $x^2\sin x$

::

  >> x.^2.*sin(x);

4. Crear la matriz *L*

::

  >> L=diag(-2*ones(7,1))+diag(ones(6,1),1)+diag(ones(6,1),-1);
  >> L(end,1)=1;
  >> L(1,end)=1;

