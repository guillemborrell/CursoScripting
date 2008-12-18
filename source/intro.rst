Prólogo
=======

Este libro ha tenido más de un comienzo por muchos motivos: falta de
tiempo, pánico a la página en blanco, cambio de objetivos. Pero el que
más seriamente me ha frenado ha sido la sensación que no disponía de
suficiente material como para escribir una buena monografía. Mi primer
libro, *Introducción Informal a Matlab y Octave* me enseñó que sin
algo que contar y toneladas de buen material el resultado es mediocre.

Introducción
============

Objetivos de este libro
-----------------------

El mundo del desarrollo de software está en constante
cambio. Los paradigmas, lengajes, herramientas, son considerados
obsoletos cada vez con más rapidez.  Incluso los conceptos sobre cómo
debe afrontarse un proyecto de software han cambiado radicalmente
durante la última década. Es además un cambio acelerado, cada vez es
más difícil mantenerse al día y no sería de extrañar que la simple
elección de herramientas se convierta en una profesión o en motivo de
consulta a un experto.

Sin embargo la ciencia se mantiene ajena a este cambio con la
confianza que merece la pena seguir utilizando lo que ya se probó como
efectivo hace una década. Esta decisión es criticada con asiduidad. Un
ingeniero informático que programe aplicaciones web con un framework
MVC difícilmente aceptará que algunos códigos de simulación reutilicen
rutinas que fueron escritas hace más de veinte años. La decisión de no
actualizarse es puramente pragmática, hacer funcionar ciertos códigos
con una pesada artillería matemática no es una tarea ni mucho menos
trivial.

La mayoría de ingenieros y científicos reciben una formación poco
estricta en computación y lenguajes de programación.  Su misión no es
entenderlo todo, sólo saber utilizarlo.  En algunos casos se puede
argumentar que la carga teórica recibida es insuficiente. No existe
una asignatura de diseño y planificación de proyectos de software en
ninguna asignatura científica o técnica -a excepción de ingeniería
informática-.  Muchos científicos e ingenieros terminan diseñando
software pero manifiestan ciertas carencias muy características
difíciles de resolver:

* Tienen un menor sentido crítico al juzgar si una herramienta será
  realmente útil para su proyecto.

* Son menos propensos a probar algo nuevo a pesar que se les demuestre
  que se reduciría el coste de desarrollo.

* Suelen utilizar lo que ya han aprendido aunque no sea lo más
  adecuado para completar la tarea.

Esta filosofía adquirida se manifiesta en aberraciones como el uso
indiscriminado de las hojas de cálculo, el abuso de plataformas como
Simulink o la nula introducción de las ayudas a la gestión de código.

Este libro pretende resolver sólo uno de estos problemas: proponer
ciertas técnicas de desarrollo de software para aumentar la
productividad de un inteniero o un científico con poca sabiduría pero
con ganas de aprender.

Que nadie busque aquí la respuesta definitiva al desarrollo de
aplicaciones científicas, cómo gestionarlas y cómo mantenerlas. Sería
absurdo porque ni siquiera llegaríamos un acuerdo en el lenguaje de
programación a usar.


Lenguajes interpretados
-----------------------

Quizás lo que primero llame la atención es la elección de los
lenguajes de programación de los ejemplos propuestos en este
libro. Python para el desarrollo de aplicaciones y Fortran y C para la
escritura de rutinas optimizadas.  El uso de más de un lenguaje de
programación no es gratuita, permitirá mantener la versatilidad y
productividad de un lenguaje interpretado e interactivo buscando una
mínima penalización en el rendimiento.  Cómo conseguirlo es parte
esencial de esta monografía.

¿Por qué seguir la moda con Python? Utilizar un lenguaje de
programación relativamente joven puede ser un gran error a largo
plazo.  Siempre aparecerá un lenguaje más elegante, más productivo,
más inteligente que barrerá del mercado todos los anteriores. Parecía
que lisp llegaba para quedarse pero cada vez quedan menos
programadores que lo conozcan.  Lo mismo puede suceder con Python.

Todo se basa en la intuición que Python sí cuenta con una
característica que lo hace único: ha sido diseñado para ser
consistente. Los lenguajes de programación se planean siguiendo una
filosofía más o menos estricta.  Se diseñan buscando la máxima
productividad, intentando resolver una tarea específica o como un
experimento de investigación. Python encuentra una filosofía que
encaja muy bien en un entorno científico: la consistencia.  Nada es
arbitrario en Python, casi cualquier estructura puede deducirse
conociendo una similar. 
