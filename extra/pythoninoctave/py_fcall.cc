
#include <octave/oct.h>
#ifdef HAVE_STAT
#undef HAVE_STAT
#endif
#include <Python.h>

DEFUN_DLD (py_fcall,args, ,
	   "Executes a function f in a module m\n with arguments args\n\n")
{
  PyObject *pModule, *pDict, *pFunc;
  PyObject *pArgs, *pValue;
  int i;
  int retval=0;
  std::string module_name,function_name;
  int nargs = args.length();

  module_name = args(0).string_value();
  function_name = args(1).string_value();
  /* Error checking of pName left out */

  pModule = PyImport_Import(PyString_FromString(module_name.c_str()));

  if (pModule != NULL) {
    pFunc = PyObject_GetAttrString(pModule, function_name.c_str());
    /* pFunc is a new reference */

    if (pFunc && PyCallable_Check(pFunc)) {
      pArgs = PyTuple_New(nargs - 2);
      for (i = 0; i < nargs - 2; ++i) {
	pValue = PyInt_FromLong(atoi(argv[i + 3]));
	if (!pValue) {
	  Py_DECREF(pArgs);
	  Py_DECREF(pModule);
	  fprintf(stderr, "Cannot convert argument\n");
	  return 1;
	}
	/* pValue reference stolen here: */
	PyTuple_SetItem(pArgs, i, pValue);
      }
      pValue = PyObject_CallObject(pFunc, pArgs);
      Py_DECREF(pArgs);
      if (pValue != NULL) {
	printf("Result of call: %ld\n", PyInt_AsLong(pValue));
	Py_DECREF(pValue);
      }
      else {
	Py_DECREF(pFunc);
	Py_DECREF(pModule);
	PyErr_Print();
	fprintf(stderr,"Call failed\n");
	return 1;
      }
    }
    else {
      if (PyErr_Occurred())
	PyErr_Print();
      fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
    }
    Py_XDECREF(pFunc);
    Py_DECREF(pModule);
  }
  else {
    PyErr_Print();
    fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
    return 1;
  }
  //    Py_Finalize();
  return 0;
}
