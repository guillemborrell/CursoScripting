A continuación se listan algunas de las convenciones tipográficas con
significado:

* Cada vez que se exponga código literal que puede ser cortado y
  pegado se utilizará una fuente equiespaciada.  Esto es un ejemplo::

    #include <stdout.h>

    int main(){
      printf("Hello, world!);
    }

* Durante los ejemplos es posible que haya que comunicarse con el
  sistema mediante la consola.  Las sesiones de consola en UNIX se
  expresarán del siguiente modo::

    U> cat /proc/version
    Linux version 2.6.20-gentoo-r8 (root@peret)
    (gcc version 4.1.2 (Gentoo 4.1.2)) #1 SMP 
    Fri May 25 11:27:27 CEST 2007
    U>

  Y las sesiones en consola windows como sigue::

    W> cd c:\
    W> dir
      El volumen de la unidad C no tiene etiqueta.
      El número de serie del volumen es: 5C58-8AD2

      Directorio de C:\

    20/07/2007  12:06    <DIR>          Archivos de programa
    21/12/2006  01:11                 0 AUTOEXEC.BAT
    21/12/2006  01:11                 0 CONFIG.SYS
    08/01/2007  20:17    <DIR>          cygwin
    19/07/2007  14:01    <DIR>          Documents and Settings
    19/07/2007  13:35    <DIR>          MinGW
    21/12/2006  01:36    <DIR>          MyWorks
    29/12/2006  13:40    <DIR>          Program Files
    19/07/2007  13:08    <DIR>          Python25
    26/03/2007  15:30         3.117.086 tec
    19/07/2007  13:13    <DIR>          WINDOWS
               3 archivos      3.117.086 bytes
               8 dirs  142.115.049.472 bytes libres

* Además de la consola del sistema operativo, los intérpretes
  utilizados también siguen una notación.  Python puede distinguirse
  gracias a sus tres signos `>`::

    >>> print 'Hello, world!'
    Hello, world!
    >>> for i in range(2):print i
    ...
    0
    1


  Y para octave se utilizará la expresión de consola típica de
  Matlab::

    >> a=[1,2,3];
    >> a'
    ans =

       1
       2
       3

