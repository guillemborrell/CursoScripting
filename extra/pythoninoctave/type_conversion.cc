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
    std::cout << i << dims.elem(i) << std::endl;//debug
  }
  
  buffer = PyBuffer_FromReadWriteMemory(oct->mex_get_data(),
					oct->numel()*oct->byte_size());

  PyTuple_SET_ITEM(ituple,0,dims_list);
  PyTuple_SET_ITEM(ituple,1,PyInt_FromLong(oct->byte_size()));
  PyTuple_SET_ITEM(ituple,2,buffer);

  std::cout << ndims << std::endl;//debug
  std::cout << oct->numel() << std::endl;//debug
  std::cout << oct->byte_size() << std::endl;//debug


  return ituple;
}

DEFUN_DLD (type_conversion,args, ,
	   "function to test type conversion between python and octave\n"){
  int i;
  octave_value_list retlist;
  octave_value typechar;
  std::string typechar_string;
  PyObject *test;

  Py_Initialize();

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
    test = oct2buffer(&args(i));
    std::cout << "made the conversion" << std::endl;
  }
  
  
  return retlist;
  Py_Finalize();
}
