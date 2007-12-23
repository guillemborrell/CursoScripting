#include <octave/oct.h>
#ifdef HAVE_STAT
#undef HAVE_STAT
#endif
#include <Python.h>

DEFUN_DLD (py_eval,args, ,
	   "Executes and prints a command in the python interpreter\n"){
  int retval=0;
  std::string s ="print ";
  try{
    s.append(args(0).string_value());
    PyRun_SimpleString(s.c_str());
    retval=1;
  }
  catch(std::bad_alloc&){
    std::cout << "Expression could not be evaluated" << std::endl;
  }
  return octave_value(retval);
}
