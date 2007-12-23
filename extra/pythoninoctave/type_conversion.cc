#include <octave/oct.h>
// #ifdef HAVE_STAT
// #undef HAVE_STAT
// #endif
// #include <Python.h>

void type(octave_value value){
  if ( value.is_defined         ())std::cout <<"defined"<< std::endl;  
  if ( value.is_undefined	())std::cout <<"undefined"<< std::endl;
  if ( value.is_empty		())std::cout <<"empty"<< std::endl;
  if ( value.is_cell		())std::cout <<"cell"<< std::endl;
  if ( value.is_cellstr		())std::cout <<"cellstr"<< std::endl;
  if ( value.is_real_scalar	())std::cout <<"real_scalar"<< std::endl;
  if ( value.is_real_matrix	())std::cout <<"real_matrix"<< std::endl;
  if ( value.is_real_nd_array	())std::cout <<"real_nd_array"<< std::endl;
  if ( value.is_complex_scalar	())std::cout <<"real_scalar"<< std::endl;
  if ( value.is_complex_matrix	())std::cout <<"real_matrix"<< std::endl;
  if ( value.is_bool_scalar	())std::cout <<"bool_scalar"<< std::endl;
  if ( value.is_bool_matrix	())std::cout <<"bool_matrix"<< std::endl;
  if ( value.is_char_matrix	())std::cout <<"char_matrix"<< std::endl;
  if ( value.is_string		())std::cout <<"string"<< std::endl;
  if ( value.is_sq_string	())std::cout <<"sq_string"<< std::endl;
  if ( value.is_dq_string	())std::cout <<"dq_string"<< std::endl;
  if ( value.is_range		())std::cout <<"range"<< std::endl;
  if ( value.is_map 		())std::cout <<"map"<< std::endl;
  if ( value.is_streamoff 	())std::cout <<"streamoff"<< std::endl;
  if ( value.is_cs_list 	())std::cout <<"cs_list"<< std::endl;
  if ( value.is_list 		())std::cout <<"list"<< std::endl;
  if ( value.is_magic_colon	())std::cout <<"magic_colon"<< std::endl;
  if ( value.is_double_type	())std::cout <<"double_type"<< std::endl;
  if ( value.is_single_type	())std::cout <<"single_type"<< std::endl;
  if ( value.is_int8_type 	())std::cout <<"int8_type"<< std::endl;
  if ( value.is_int16_type	())std::cout <<"int16_type"<< std::endl;
  if ( value.is_int32_type	())std::cout <<"int32_type"<< std::endl;
  if ( value.is_int64_type	())std::cout <<"int64_type"<< std::endl;
  if ( value.is_uint8_type	())std::cout <<"uint8_type"<< std::endl;
  if ( value.is_uint16_type	())std::cout <<"unit16_type"<< std::endl;
  if ( value.is_uint32_type	())std::cout <<"uint32_type"<< std::endl;
  if ( value.is_uint64_type	())std::cout <<"uint64_type"<< std::endl;
  if ( value.is_bool_type	())std::cout <<"bool_type"<< std::endl;
  if ( value.is_integer_type	())std::cout <<"integer_type"<< std::endl;
  if ( value.is_real_type	())std::cout <<"real_type"<< std::endl;
  if ( value.is_complex_type	())std::cout <<"complex_type"<< std::endl;
  if ( value.is_scalar_type	())std::cout <<"scalar_type"<< std::endl;
  if ( value.is_matrix_type	())std::cout <<"matrix_type"<< std::endl;
  if ( value.is_numeric_type	())std::cout <<"numeric_type"<< std::endl;
  if ( value.is_sparse_type	())std::cout <<"sparse_type"<< std::endl;
  if ( value.is_true		())std::cout <<"true"<< std::endl;
  if ( value.is_zero_by_zero	())std::cout <<"zero_by_zero"<< std::endl;
  if ( value.is_constant	())std::cout <<"constant"<< std::endl;
  if ( value.is_function_handle	())std::cout <<"function_handle"<< std::endl;
  if ( value.is_inline_function	())std::cout <<"inline_function"<< std::endl;
  if ( value.is_function	())std::cout <<"function"<< std::endl;
  if ( value.is_builtin_function())std::cout <<"builtin_function"<< std::endl;
  if ( value.is_dld_function	())std::cout <<"dld_function"<< std::endl;
  if ( value.is_mex_function    ())std::cout <<"mex_function"<< std::endl; 

}

DEFUN_DLD (type_conversion,args, ,
	   "function to test type conversion between python and octave\n"){
  int i;
  for(i=0;i<args.length();i++){
    type(args(i));
    std::cout << "--------" << std::endl;
  }
//   Py_Initialize();
//   PyRun_SimpleString(s.c_str());
//   Py_Finalize();
  return octave_value(0);
}
