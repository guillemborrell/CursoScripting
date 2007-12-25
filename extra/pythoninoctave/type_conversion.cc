#include <octave/oct.h>
/*#ifdef HAVE_STAT
#undef HAVE_STAT
#endif
#include <Python.h>
#include <arrayobject.h>
*/
octave_value octave_type(octave_value *value){
  octave_value retval;
  /*
    Note that pvalue is not copied to prevent copying large chunks
    of memory in case pvalue is large. Value is a dummy variable to
    avoid filling the subroutine of asterisks.

    Calling this function with &args(i) will make a warning to come
    out, but it is deliberately triggered.
    */
  retval=octave_value('0');
  
  if (value->is_double_type() && value->is_real_type()){
    retval=octave_value('d');
  }
  if (value->is_double_type() && value->is_complex_type()){
    retval=octave_value('z');
  }
  if (value->is_int8_type()){
    retval=octave_value('1');
  }
  if (value->is_int16_type()){
    retval=octave_value('2');
  }
  if (value->is_int32_type()){
    retval=octave_value('3');
  }
  if (value->is_int64_type()){
    retval=octave_value('4');
  }  
  if (value->is_string()){
    retval=octave_value('s');
  }
  if (value->is_cell()){
    retval=octave_value('c');
  }
  return retval;
}

DEFUN_DLD (type_conversion,args, ,
	   "function to test type conversion between python and octave\n"){
  int i;
  octave_value_list retlist;
  for(i=0;i<args.length();i++){
    retlist.append(octave_type(&args(i)));
  }
//   Py_Initialize();
//   PyRun_SimpleString(s.c_str());
//   Py_Finalize();
  return retlist;
}
