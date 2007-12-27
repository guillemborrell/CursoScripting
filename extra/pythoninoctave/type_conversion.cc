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

PyObject *oct_double2numpy(octave_value *octave_double){
  int i;
  PyObject *numpy_array;
  int ndims = octave_double->ndims();
  npy_intp c_dims[ndims];
  dim_vector dims = octave_double->dims();
  /*
    Silly copy because octave_double.dims() returns a custom type
    called dim_vector that must be copied to a int array.
   */
  for (i=0; i<ndims; i++){
    c_dims[i]=dims(i);
  }
  std::cout << c_dims[0] << c_dims[1] << std::endl;

  numpy_array = PyArray_SimpleNew(ndims,c_dims,PyArray_DOUBLE);

  std::cout << "not more than here" << std::endl;
  return numpy_array;
}

DEFUN_DLD (type_conversion,args, ,
	   "function to test type conversion between python and octave\n"){
  int i;
  octave_value_list retlist;
  octave_value typechar;
  std::string typechar_string;
  PyObject *test;
  for(i=0;i<args.length();i++){//for every argument...
    /*
      ... get the type and load it into the octave_value typechar.
      This value cannot be compared to a C char so typechar_string is
      created to make such comparison.
     */
    typechar = octave_type(&args(i));
    retlist.append(typechar);
    typechar_string = typechar.string_value();
    std::cout << typechar_string.c_str() << std::endl;
    if ((typechar_string.c_str())[0] == 'd'){
      test = oct_double2numpy(&args(i));
      std::cout << "made the conversion" << std::endl;
    }
  }
//   Py_Initialize();
//   PyRun_SimpleString(s.c_str());
//   Py_Finalize();
  return retlist;
}
