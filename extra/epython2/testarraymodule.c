#include "Python.h"
#include "numpy/arrayobject.h"
#include "numpy/ndarrayobject.h"
#include "numpy/noprefix.h"
#include <stdio.h>

static PyObject *testarray_test(PyObject *self, PyObject *args)
{
  int i,j;
  PyArrayObject *array;
  PyArrayObject *cparray;
  double *data_in_array;
  
  if (!PyArg_ParseTuple(args, "O", &array))
    return NULL;

  printf("here\n, %i\n",PyArray_DIMS(array)[0]);

/*   cparray = (PyArrayObject *) PyArray_FromArray(array, */
/* 						array->descr, */
/* 						DEFAULT_FLAGS); */

/*   data_in_array = (double *) array->data; */



/*   for(i=0;i < array->nd;i++) */
/*     { */
/*       for(j=0;j < array->dimensions[i];j++) */
/* 	{ */
/* 	  *data_in_array[i][j]=*data_in_cparray[i][j]/2.; */
/* 	} */
/*     } */
  return Py_BuildValue("O", array);
}

static PyMethodDef TestarrayMethods[] = {
  {"test",  testarray_test, METH_VARARGS,
   "Test the array interface"},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC inittestarray(void)
{
  PyObject *m;
  
  m = Py_InitModule("testarray", TestarrayMethods);

}
