Octave es un lenguaje interpretado de alto nivel diseñado para el
cálculo numérico [OCT]_. Proporciona in interfaz por línea de comandos
para resolver varios problemas de carácter numérico con un lenguaje
que es altamente compatible con Matlab.

Es intuitivo, fácil de aprender y dispone de una extensa biblioteca
apropiada para álgebra lineal, resolución de ecuaciones no linales,
integración numérica, integración de ecuaciones diferenciales... El
lenguaje octave puede extenderse mediante módulos escritos en C++, C,
Fortran o otros lenguajes.

Está publicado bajo la última versión de la licencia GPL y es parte
del proyecto GNU. El desarrollador principal es John W. Eaton y aunque
es un proyecto maduro es relativamente pequeño con una comunidad de
usuarios y desarrolladores entusiasta y agradable.

Aunque en un principio fue diseñado como un lenguaje de programación
independiente ha ido convergiendo lentamente con Matlab hasta un nivel
de compatibilidad más que aceptable.  Hoy en día puede considerarse un
sustituto razonablemente capaz para proyectos de pequeña envergadura.
Es fácilmente extensible mediante C++ y también soporta los métodos de
extensión típicos de Matlab, MEX.

Para aprender más, Octave dispone de un wiki [WIO]_ y el mismo autor
publicó en internet un libro introductiorio [LIB]_ con cuantioso
material adicional.

.. [OCT] http://www.gnu.org/software/octave/

.. [WIO] http://wiki.octave.org/

.. [LIB] http://torroja.dmt.upm.es/guillem/blog/

Instalar Octave en GNU/Linux
----------------------------

Octave es un programa común en todas las distribuciones aunque es muy
probable que no esté instalado por defecto.  Es recomendable instalar
la última version aunque sea catalogada como versión de desarrollo.
Los estándares de estabilidad de Octave son altísimos, la ganancia en
nuevas posibilidades compensa con creces los posibles problemas.

.. note::

  Para obtener la última versión de Octave, los usuarios de Gentoo
  tendrán que acceder al overlay gentoo-science donde se encuentra el
  ebuild de la última versión.  El ebuild de la rama principal suele
  ser anticuado.

Tampoco hay que tener miedo a compilar el código de la última versión
de la página oficial porque es muy poco probable que aparezcan
problamas durante el compilado. El proceso es el típico configurar,
make y make install.

Instalar Octave en Windows
--------------------------

A partir de la versión 2.9.0 existe una versión nativa de Octave para
Windows.  En las versiones interiores era necesario acudir al entorno
de emulación Cygwin, quizás demasiado complicado y pesado para un
usuario medio de Windows.

El proceso de instalación es siempre simple, parecido al de cualquier
otro programa.  El wiki de Octave suele tener información actualizada
de cómo instalar octave y dónde econtrar la última versión [WOI]_.

También en Windows es recomendable utilizar la distribución más
reciente posible.

.. [WOI] http://wiki.octave.org/wiki.pl?OctaveForWindows
