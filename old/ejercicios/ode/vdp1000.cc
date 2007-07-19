#include <octave/oct.h>
DEFUN_DLD (vdp1000,args, ,
	   "Ecuacion de Van der Pol para mu=1000")
{
  ColumnVector xdot (2);
  ColumnVector x (args(0).vector_value());
  float mu=1000;
  xdot(0) = x(1);  
  xdot(1) = mu*x(1)*(1-x(0)*x(0))-x(0);

  return octave_value (xdot);
}
