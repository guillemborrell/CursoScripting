#include <Python.h>

static PyObject *spam_system(PyObject *self, PyObject *args)

{
  const char *command;//const means intent(in)
  int sts;
  
  if (!PyArg_ParseTuple(args, "s", &command))
    return NULL;
  sts = system(command);
  return Py_BuildValue("i", sts);
}

static PyMethodDef SpamMethods[] = {
  {"system",  spam_system, METH_VARARGS,
   "Execute a shell command."},
  {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC initspam(void)
{
  PyObject *m;
  
  m = Py_InitModule("spam", SpamMethods);

/*   SpamError = PyErr_NewException("spam.error", NULL, NULL); */
/*   Py_INCREF(SpamError); */
/*   PyModule_AddObject(m, "error", SpamError); */
}
