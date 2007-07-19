#include <octave/oct.h>
#include "f77-fcn.h"
extern "C"
{
  int F77_FUNC (tnine, TNINE) (const int& IOPT, const double* PARMOD,
                               double& PS,
                               const double& X, const double& Y,
                               const double &Z,
                               double& BX, double& BY, double& BZ );
}
DEFUN_DLD (t96, args, ,
          "- Funcion: [PS, BX, BY, BZ] = t96 (PM, X, Y, Z)\n\
\n\
Asigna la suma de PM a PS y  X, Y, Z a BX, BY, BZ.")
{
  octave_value_list retval;
  const int dummy_integer = 0;
  Matrix pm;
  const double x = args(1).double_value(), y = args(2).double_value(),
  z = args(3).double_value();
  double ps, bx, by, bz;
  pm = args(0).matrix_value ();
  F77_XFCN (tnine, TNINE,
           (dummy_integer, pm.fortran_vec(), ps, x, y, z, bx, by, bz) );
  if (f77_exception_encountered)
    {
      error ("unrecoverable error in t96");
      return retval;
    }
  retval(0) = octave_value (ps);
  retval(1) = octave_value (bx);
  retval(2) = octave_value (by);
  retval(3) = octave_value (bz);
  return retval;
}
