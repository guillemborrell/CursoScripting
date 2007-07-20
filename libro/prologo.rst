Más que un prólogo, las lineas que siguen son una justificación.  

Mi primer libro *Introducción informal al Matlab y Octave* me provoca
un ligero sentimiento de frustración.  Escribí la mayor parte de las
ciento setenta páginas del texto en sólo dos meses en el inicio de una
etapa bastante complicada de mi vida.  El contexto no era ni mucho
menos el más adecuado para afrontar una monografía de calidad.  Cada
vez que lo hojeo me arrepiento de cómo lo estructuré, de la redacción
de algunas partes, de las numerosas erratas tanto en el fondo como en
la forma. Durante los dos años posteriores a la escritura estuve
buscando tiempo para arreglar los errores más flagrantes pero el
perenne sentimiento de vagancia de aquellos días no me era de gran
ayuda.

Cuando uno tiene la sensación de salir de un pozo muy profundo lo hace
acompañado de buenos propósitos, de buenas intenciones.  Con esfuerzo
puede llegar a convertirlos en buenos actos.  Escribo estas líneas en
el nacimiento de esta nueva monografía, *Lenguajes Interpretados para
Simulación en Ingeniería* despues de tener la sensación de haber
tocado fondo en todos los sentidos.

Algunas personas tienen la necesidad de empezar un diario, otros
escriben un blog, otros prefieren la bebida o las drogas.  Yo soy un
ser humano muy particular y prefiero escribir monografías de
programación. En esta pretendo reflejar mis aficiones: el desarrollo
de aplicaciones mediante el uso de más de un lenguaje de programación,
el diseño de programas de simulación y la integración del trabajo en
equipo.

Siento sinceramente que este libro será mejor que el anterior en todos
lo sentidos.  Escribo mejor, se más y pienso con más claridad.  Esto
no significa que sea un experto en el tema.  Sigo pensando que tengo
mucho por aprender y no tengo ningún miedo a aceptar errores ni
reparos en escuchar sugerencias.  Este sigue siendo un libro abierto a
todos que nace de mi aprendizaje, tanto en la lectura como en la
escritura; invito a quien quiera colaborar que lo haga, se lo
agradeceré sinceramente.


Este es un libro libre.
=======================
  
Lo es por un cálculo que parece no ser tan evidente para muchos
autores.  Cuando después de escribir un libro para un público
minoritario un escritor se dirige a un editorial las condiciones son
casi siempre las mismas: el autor debe abonar la mitad de los costes
de impresión de la primera edición. Esto sitúa al editor en una
situación de victoria o victoria; si el libro fracasa no pierde dinero
y si triunfa tiene los derechos de edición.
  
  
Las consecuencias son que el autor casi siempre termina perdiendo
dinero y que el libro se difunde muchísimo menos de lo que debería.
Abordando el problema desde la voluntad de extender el conocimiento la
decisión más efectiva es publicar el libro electrónicamente (sin
gastos de impresión) y a coste cero (sin limitaciones para su
difusión).  Eliminando el mundo editorial de la cadena ni el autor
pierde dinero ni el lector pierde derechos, goza de los que el autor
le otorgue.

  
restructuredtext
================
  
No tiene ningún sentido liberar el contenido de libro y publicarlo en
un formato exótico o cerrado.  Una parte esencial del movimiento del
conocimiento libre es la utilización de estándares abiertos y
aceptados por organizaciones como ISO o W3C. Siguiendo estas pautas en
la escritura y la generación del documento final nos aseguramos que
podrá leerlo quien lo desee Los formatos escogidos son casi siempre
`pdf` para impresión y `xhtml` para la lectura online.
  
  
Ser tu propio editor no es fácil; cada frase, cada página debe ser
leíble.  Sería una lástima estropear un buen contenido por una mala
presentación o una tipografía deficiente.  La única salida es utilizar
un formato que se encargue él mismo de la presentación final.  Por
este motivo no tiene mucho sentido utilizar un procesador de texto
para escribir un libro.  Los requisitos dicho formato son los
siguientes:
  
      
1. Capacidad para exportar a la mayor cantidad de formatos posibles
   tanto impresos como para su lectura online.
      
2. La fuente del documento debe ser editable en algún formato de
   texto convencional para que puedan utilizarse sistemas de control
   de versiones.
      
3. Debe conseguir una gran calidad tipográfica en todos los aspectos:
   texto, cabeceras, ecuaciones, gráficos...
      
4. Debe ser escalable, es decir, que a medida que el documento crezca
   no se haga más difícil de editar ni que el resultado final pierda
   calidad.
      
El objetivo es entonces crear un *metadocumento* que sea capaz de
convertir el texto en cualquier formato ya sea de impresión o de
lectura online. Los tres candidatos que he considerado son LaTeX,
`XML/docbook` y `restructuredtext` resultando vencedor el último, un
lenguaje de marcas ligero parte de `docutils` que a su vez es un
proyecto asociado a Python, uno de los lenguajes de programación
utilizados en el libro.
  

