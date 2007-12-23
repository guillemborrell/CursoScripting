CC = mkoctfile

all: py_init.oct py_finalize.oct py_eval.oct py_exec.oct

py_init.oct: py_init.cc
	mkoctfile -I/usr/include/python2.4 -lpython2.4 py_init.cc

py_finalize.oct: py_finalize.cc
	mkoctfile -I/usr/include/python2.4 -lpython2.4 py_finalize.cc

py_eval.oct: py_eval.cc
	mkoctfile -I/usr/include/python2.4 -lpython2.4 py_eval.cc

py_exec.oct: py_exec.cc
	mkoctfile -I/usr/include/python2.4 -lpython2.4 py_exec.cc

pyrun_string.oct: pyrun_string.cc
	mkoctfile -I/usr/include/python2.4 -lpython2.4 pyrun_string.cc

clean:
	rm *.oct
