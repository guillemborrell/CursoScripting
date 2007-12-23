#include <octave/oct.h>
#ifdef HAVE_STAT
#undef HAVE_STAT
#endif
#include <Python.h>

DEFUN_DLD (pyrun_string,args, ,
	   "Executes and prints a command in the python interpreter"){
  std::string s = "print ";
  s.append(args(0).string_value());
  Py_Initialize();
  PyRun_SimpleString(s.c_str());
  Py_Finalize();
  return octave_value(0);
}
