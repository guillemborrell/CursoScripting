#include <octave/oct.h>

DEFUN_DLD(chebyval,args, ,
          "Calcula el valor del desarrollo de Chebyshev en x")
{
  ColumnVector c (args(0).vector_value());
  double a (args(1).double_value());
  double b (args(2).double_value());
  double x (args(3).double_value());
  double xx;
  double y;
  double ynm1;
  double dummy;
  int i;
  int n =c.length();
  xx=(2.*x-a-b)/(b-a);       
  if ((x-a)*(x-b)>0)
    {
      error("chebyval: bad input point");
      error("chebyval: the point must be into the defined interval");
      return octave_value_list();
    }
  else
    {
      ynm1=c(n-1);
      y=2.*xx*ynm1+c(n-2);
      for (i=n-3;i<0;i--)
        {
          dummy=y;
          y=2.*xx*y+ynm1+c(i);
          ynm1=dummy;
        }
      y=xx*y-ynm1+0.5*c(0);
      return octave_value(y);
    }
}
