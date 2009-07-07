#include <octave/oct.h>

/*
  Doing this to avoid previous definition warnings. I have not dived
  too much into the headers to know what kind of errors this may couse
 */

#ifdef HAVE_STAT
#undef HAVE_STAT
#endif
#ifdef HAVE_ISNAN
#undef HAVE_ISNAN
#endif
#ifdef HAVE_ISINF
#undef HAVE_ISINF
#endif

#include <Python.h>
#include <arrayobject.h>


/* TODO.  Cells will be turned into lists.  More difficult
octave_value_list cell_items(octave_value *value){
  octave_value
}
*/

octave_value octave_type(octave_value *value){
  int i;
  octave_value retval;
  /*
    Note that pvalue is not copied to prevent copying large chunks
    of memory in case pvalue is large. Value is a dummy variable to
    avoid filling the subroutine of asterisks.

    This function will cause a warning in compile time but it is
    deliberately triggered.
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
  /* TODO
  if (value->is_cell()){
    octave_value_list cell_items;
    cell_items.append(octave_value('c'));
    for 
    cell_items.append(cell_items(value));
  }
  */
  return retval;
}

PyObject *oct2buffer(octave_value *oct){
  /*
    Transforms an octave_value to a python tuple that contains:

    * A list with the array size.
    * An integer with the element size.
    * A buffer with the data.

    By now only numeric arrays and non unicode strings are supported.
    Cell arrays are a TODO
   */
  PyObject *buffer;
  PyObject *dims_list;
  PyObject *ituple;
  dim_vector dims=oct->dims();
  int ndims=oct->ndims();
  int i;

  dims_list = PyList_New(ndims);
  ituple = PyTuple_New(3);

  for(i=0;i<ndims;i++){
    PyList_Append(dims_list,PyInt_FromLong(dims.elem(i)));
  }

  if (oct->is_numeric_type()){
    buffer = PyBuffer_FromReadWriteMemory(oct->mex_get_data(),
					  oct->numel()*oct->byte_size());
  }

  if (oct->is_string()){
    buffer = PyBuffer_FromReadWriteMemory(oct->mex_get_data(),
					  oct->numel()*sizeof(char));
  } 

  PyTuple_SET_ITEM(ituple,0,dims_list);
  PyTuple_SET_ITEM(ituple,1,PyInt_FromLong(oct->byte_size()));
  PyTuple_SET_ITEM(ituple,2,buffer);

  return ituple;
}

DEFUN_DLD (py_fcall,args, ,
	   "calls a python function from octave.\n"){

  /*
    First argument is the module name
    Second argument is the function name
    The next arguments are te function's arguments

    Lots of possible memory leaks, this is just a quick
    and dirty version. Lots of calls to Py_DECREF and error
    handling need to be done.
   */
  int i;
  std::string module_name_dummy;
  std::string function_name_dummy;
  char *module_name;
  char *function_name;
  PyObject *test;
  PyObject *Module, *Func;
  PyObject *p_args;
  PyObject *p_ret;

  if (!Py_IsInitialized()){ 
    std::cout << "You must initialize the Python interface" << std::endl;
    std::cout << "with py_init" << std::endl;
  }

  /*
    Trick to go from a std::string to a char*.  It cannot be casted
    because std::string.c_str() gives a const char* and I need a char*
    to create python strings.
   */
  module_name_dummy = args(0).string_value();
  module_name = (char *)malloc(sizeof(module_name_dummy.c_str()));
  memcpy(module_name,module_name_dummy.c_str(),
	 sizeof(module_name_dummy.c_str()));
  std::cout << module_name << std::endl;

  function_name_dummy = args(1).string_value();
  function_name = (char *)malloc(sizeof(function_name_dummy.c_str()));
  memcpy(function_name,function_name_dummy.c_str(),
	 sizeof(function_name_dummy.c_str()));

  p_args = PyTuple_New(args.length()-2);

  for(i=2;i<args.length();i++){//build a tuple with the arguments
    PyTuple_SET_ITEM(p_args,i-2,oct2buffer(&args(i)));
  }

  Module = PyImport_Import(PyString_FromString(module_name));

  if (Module != NULL){
    Func = PyObject_GetAttrString(Module, function_name);
    p_ret = PyObject_CallObject(Func, p_args);
  }
  std::cout <<  "here" << std::endl;
  std::cout << PyString_AsString(p_ret) << std::endl;

  return octave_value(0);

}
