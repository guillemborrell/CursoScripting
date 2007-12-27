=============================
Notas sobre la API de python.
=============================

Se puede probar código escrito en C sin tener que escribir un módulo
entero, de hecho el código puede ser completamente standalone gracias
a que el intérprete se puede embeber.  Por ejemplo, este programa es
completamente funcional::

  #include <Python.h>
  
  int main(int argc, char *argv[]){
    PyObject *testint;
    long ival=1;
    Py_Initialize();
    testint = PyInt_FromLong(ival);
    printf("%d\n",PyInt_AsLong(testint));
    Py_Finalize();
    return 0;
  }

Lo que hace este programa es iniciar el intérprete y crear un objeto
Python número entero que contiene un long de valor unidad.  Luego lo
vuelve a pasar a long para imprimirlo en pantalla.

Es importante tener en cuenta que si el intérprete no está funcionando
el programa va a dar un fallo de segmentación.  Si se declara algún
PyObject se necesita el object space de Python, en caso contrario no
tiene ni idea de dónde cojones alocatear todo.

Otra cosa intersante es que no he conseguido declarar un array numpy
de esta misma manera.  En teoría debería funcionar pero siempre he
recibido un error de segmentación de memoria.  Ignoro el por qué y
tengo que preguntarlo en la lista de correo.  De todos modos el modo
más eficiente para pasar memoria de C a python-numpy es mediante un
buffer ya que no es más que una manera tonta de pasar memoria entre C
y el intérprete de Python.  Numpy dispone de la función frombuffer que
es capaz de crear un array numpy fácilmente desde un buffer.  De este
modo puedo escribir el conversor de tipos directamente en python y
escribir menos código en C.

Otra cosa interesante es que en python, sobretodo a partir de la
versión 3.0, no tiene sentido declarar enteros como tipo propio de
Python menores que long.  Cualquier otro entero sólo tendrá sentido
como un elemento de un array numpy.
