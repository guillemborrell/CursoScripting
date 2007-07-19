#include <octave/oct.h>
#include <math.h>

static double PI=4.*atan(1.);

DEFUN_DLD(chebyexpand,args, ,
"-*- texinfo -*-\n\
@deftypefn {Loadable Function} {[@var{c}]=} chebyexpand (@var{f},@var{a},@var{b},@var{n})\n\
\n\
Chebyshev fit:\n\
\n\
Given a function @var{f} and the interval @var{a},@var{b} computes\n\
the @var{n} coefficients of the Chebyshev polynomial expansion.\n\
\n\
@example\n\
>> chebyexpand(@@(x) 2*x^2-1,-1,1,5)\n\
ans =\n\
   -2.6645e-16\n\
    1.1948e-17\n\
    1.0000e+00\n\
    7.9786e-17\n\
   -1.0426e-16\n\
@end example\n\
\n\
Note that @var{f} must be a function handle or an anonymous function\n\
\n\
@end deftypefn")
{
  int j,k;

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
  
  double a=args(1).double_value();
  double b=args(2).double_value();
  int n=args(3).int_value();

  ColumnVector f=ColumnVector(n);
  ColumnVector c=ColumnVector(n);

  for (k=0;k<n;k++)
    {
      inval(0)=octave_value(cos(PI*(k+0.5)/n)*\
                            0.5*(b-a)+0.5*(b+a));
      tmp=input_fcn->do_multi_index_op(1,inval);
      f(k)=tmp(0).double_value();
    }
  for (j=0;j<n;j++)
    {
      double sum=0.;
      for (k=0;k<n;k++)
        {
          sum += f(k)*cos(PI*j*(k+0.5)/n);
        }
      c(j)=sum*2./n;
    }

  return octave_value(c);
}
