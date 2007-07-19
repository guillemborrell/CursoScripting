#include <Python.h>
#include <numpy/arrayobject.h>
#include <numpy/ndarrayobject.h>
#include <numpy/noprefix.h>

static PyObject *test_transpose(PyObject *self, PyObject *args)
{
  PyObject *input, *output;

  //  Declaration group
  intp *dimsin;
  intp *dimsout;
  intp *SIZE;

  void *output_data;

  int type;
  int i,j;

  //  Allocation group
  dimsin = malloc(2*sizeof(intp));
  dimsout = malloc(2*sizeof(intp));
  SIZE = malloc(sizeof(intp));
  
  if (!PyArg_ParseTuple(args, "O", &input))
    return NULL;

  dimsin=PyArray_DIMS(input);
  type=PyArray_TYPE(input);
  *SIZE=PyArray_SIZE(input);
 
  dimsout[0]=dimsin[1];
  dimsout[1]=dimsin[0];

  printf("%i\n",*dimsout);
  printf("%i\n",*SIZE);
  printf("%i\n",sizeof(long));

  //  output_data = malloc(PyArray_ITEMSIZE(input)*sizeof(PyArray_SIZE(input)));

  //  output = PyArray_SimpleNewFromData(2,sizeout,type,output_data);
  
  //  Just allocates the array
  //  output = PyArray_SimpleNew(2,sizeout,type);
  

  return Py_BuildValue("s","all done");
}

static PyMethodDef TestMethods[] = {
  {"transpose",  test_transpose, METH_VARARGS,"Transpose a numpy array"},
  {NULL, NULL, 0, NULL}   
};

PyMODINIT_FUNC inittest(void)
{
  PyObject *m;
  
  m = Py_InitModule("test", TestMethods);
}
