Este libro no es una guía de cómo escribir aplicaciones de
simulación.  Trata más sobre el conocimiento de las herramientas
que sobre cómo utilizarlas.  Sin embargo no está vacío de
arte.

El diseño es sin duda la parte más interesante y a la vez la más
difícil de cualquier proyecto.  Un diseño preliminar erróneo
puede significar malgastar centenares o miles de valiosas
horas. Si diseñar es tán difícil no debería ser beneficioso
imponer la *dictadura de las herramientas*.

Una práctica tan habitual como nociva es la *elección del
lenguaje de programación*.  Se analizan los requisitos de un
determinado proyecto y se postula qué lenguaje puede ser más
adecuado para llevarlo a cabo.  Esta decisión lleva implícitas
muchas imposiciones: una estructura de código, una metodología de
implementación, un paradigma de programación...  Al final la
impresión es la de tener que valorar delicadamente pros y contras
para llegar a una herramienta *menos mala*.

La visión es que este punto de vista es completamente equivocado.
Hay que buscar la herramienta correcta para cada tarea.  El dicho
que mejor expresa la dictadura de las herramientas es que *cuando
sólo tienes un martillo todo te parece un clavo*.  Es muy triste
tomar sólo un martillo cuando se dispone de todo un set de
bricolaje.

Esta monografía presenta una manera diametralmente opuesta de
hacer las cosas: sólo conociendo un abanico completo de
herramientas y métodos puede obtenerse un diseño sano porque cada
condición de diseño puede exigir capacidades específicas.

Todo parece muy razonable pero genera un problema adicional.  Si antes
existía la dificultad de tener que adaptar el diseño a una herramienta
ahora es necesario tener unos conocimientos de programación y diseño
de aplicaciones mucho más amplios.  Es imposible evaluar decenas de
lenguajes de programación cada vez que se proyecta una subrutina,
además no sería eficiente.

La tesis de esta monografía es que el mínimo común denominador de
todas estas posibles técnicas es la unión de un lenguaje interpretado
con uno compilado.  De todas las posibles parejas se tratarán sólo:

* Python y C

* Octave y C++

Además, para adaptar código ya escrito y probado se les unirá Fortran
al ser un lenguaje de uso común en el Cálculo Numérico y la simulación.


El paradigma de la optimización prematura
-----------------------------------------

.. epigraph::

  La optimización prematura es el orígen de todos los males.

  -- Donald E. Knuth

Los algoritmos asociados al análisis numérico requieren tiempos de
computación elevados, tanto que algunos problemas necesitarían una
potencia de cálculo infinita para ser resueltos satisfactoriamente.

Existen **unos pocos** casos patológicos el los que desde la primera linea
de código debe buscarse la optimización por delante de todo.  En ellas
se evita cualquier bucle que recorra posiciones de memoria no
contiguas o cualquier escritura innecesaria en disco a toda costa. Un
ejemplo son los códigos de simulación directa de las ecuaciones de
Navier Stokes. Son tan pocos que puede generalizarse en su contra.

Partiendo del siguiente código de prioridades:

1. Que el programa funcione.

2. Que el programa funcione bien y en todos los casos.

3. Que el programa sea rápido.

Es importante llegar a una solución lo antes posible aunque su
rendimiento sea inaceptable.

El paradigma de la optimización prematura falla en la mayoría de los
casos por muchos motivos, por ejemplo que se tiende a las estructuras
monolíticas donde la adición de una nueva funcionalidad es difícil y
en algunos casos incluso imposible.  Esto genera código de usar y
tirar, algo que va en contra de la razón.  Otro motivo es que este
paradigma es prohibitivo para un programador no experimentado que
tiende a creer que será capaz de solucionar cualquier inconveniente
debido a un diseño no correcto.

El paradigma de optimización de las técnicas propuestas es la
*optimización obvia*.  Se trata de optimizar de un modo mínimo sólo
para paliar problemas de rendimiento flagrantes.  En muchos casos la
experiencia hará que el diseño evite estos cuellos de botella.

Metodologías de programación
----------------------------

.. epigraph::

  Ley de Corbató. La cantidad de lineas de código que un programador
  es capaz de escribir en un tiempo dado es independiente del lenguaje
  de programación.

  -- Fernando J. Corbató

Cuando un investigador necesita simular la naturaleza ve, y es
completamente comprensible, el código escrito como una herramienta
cuya razón de ser es llegar a un resultado.  Esto difiere de un
proyecto de desarrollo de software destinado a crear una librería o
una aplicación.  En el primer caso el código en sí no importa, en el
fondo quedará escondido en un ejecutable y en algunos casos dicho
investigador lo olvidará en algún rincón del disco duro.

Generar o no código de calidad debe ser una decisión pragmática pero
no poco reflexionada.  El autor piensa que generar código de calidad
tiene un valor intrínseco real y que no existe una excusa (ni siquiera
minimizar el tiempo de desarrollo) para no hacerlo.  Esto no tiene más
valor que el de una opinión pero es una opinión fundada.

Son principalmente científicos, o ingenieros haciendo ciencia, quienes
desarrollan aplicaciones de simulación. No necesiariamente han
recibido formación específica para el desarrollo de aplicaciones y
probablemente no han adquirido las técnicas necesarias para arontar un
proceso de desarrollo complejo.

El finalizar o no con éxito un proyecto suele depender más de la
brillantez y la determinación que de las capacidades técnicas que
influyen más sobre la calidad del producto final y el tiempo de
desarrollo.  La ley de Corbató parte del hecho que un programador
tiene una capacidad dada, esto hace que su productividad dependa
de las herramientas. 
