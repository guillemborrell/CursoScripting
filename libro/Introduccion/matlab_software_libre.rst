Matlab es el lenguaje interpretado para cálculo numérico más
extendido.  Aunque no le falta la competencia ha conseguido hacerse
con el primer puesto en el mercado gracias a una combinación muy
acertada de sencillez y potencia.  Además puede extenderse utilizando
lenguajes compilados como C y Fortran lo que le convierte en un buen
candidato como base para el desarrollo de aplicaciones híbridas.

Sin embargo Matlab no se utilizará en absoluto y no es porque no sea
adecuado.  Matlab es un producto comercial, si se utilizara en algún
ejemplo el lector debería disponer de una instalación correcta de
Matlab con los siguientes inconvenientes:

* Debe pagar una licencia de un coste considerable en el caso
  que no disponga de una gracias a su universidad, empresa...

* Debe contar con un entorno de desarrollo cuya configuración no es
  trivial. No hay que olvidar que con Matlab no basta; se necesitan
  compiladores compatibles en una versión adecuada, algo en lo que
  normalmente no se piensa cuando se instala.

  La gran ventaja del software libre es que en cualquier distribución
  de GNU/Linux se consigue una integración total de las herramientas
  de desarrollo.  Es incluso común que los compiladores disponibles
  sean idénticos a los que se utilizaron para construir las
  bibliotecas.  Muchos de los ejemplos funcionarán con sólo instalar
  todos los paquetes binarios necesarios o despues de compilar su
  código fuente.

* Plantea el siguiente inconveniente ideológico: este libro es
  gratuito... ¿Es razonable exigir una herramienta de pago para seguir
  los ejemplos?  ¿Debe darse publicidad a una compañía que no ha dado
  soporte al libro de ningún tipo?


Sin embargo los conceptos y los ejemplos, sobretodo los códigos
implementados en Octave, son fácilmente extrapolables a Matlab.
Incluso en algunos casos se utilizarán las funciones de las que
dispone Octave para procesar archvos MEX, el modo usual de enlazar
Matlab con C, para que el salto sea aún más fácil.
