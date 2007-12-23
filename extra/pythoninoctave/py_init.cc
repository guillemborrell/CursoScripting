#include <octave/oct.h>
#ifdef HAVE_STAT
#undef HAVE_STAT
#endif
#include <Python.h>

DEFUN_DLD (py_init,args, ,
	   "Starts the python interpreter\n"){
  int retval;
  retval=0;
  try{
    Py_Initialize();
    retval=1;
  }
  catch(std::bad_alloc&){
    std::cout << "Python interpreter could not be started" << std::endl;
  }

  return octave_value(retval);
}
