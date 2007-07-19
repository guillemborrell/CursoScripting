# include <octave/oct.h>

DEFUN_DLD(testfh,args, ,
          "testing how C++ can call an octave function")
{
  octave_value_list tmp;
  octave_value_list inval;
  octave_function *input_fcn=0;
    if (args(0).is_function_handle() || args(0).is_inline_function())
      input_fcn = args(0).function_value();
    else
      {
        error("this is not a function handle nor an inline function");
        return octave_value(-1);
      }
  double x = args(1).double_value();
  inval.append(octave_value(x));
  tmp = input_fcn->do_multi_index_op(1,inval);
  return tmp;
}
