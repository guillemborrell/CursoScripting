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
