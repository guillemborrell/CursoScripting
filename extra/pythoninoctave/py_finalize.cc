#include <octave/oct.h>
#ifdef HAVE_STAT
#undef HAVE_STAT
#endif
#include <Python.h>

DEFUN_DLD (py_finalize,args, ,
	   "Closes the python interpreter\n"){
  int retval;
  retval=0;
  try{
    Py_Finalize();
    retval=1;
  }
  catch(std::bad_alloc&){
    std::cout << "Python interpreter could not be closed" << std::endl;
  }

  return octave_value(retval);
}
