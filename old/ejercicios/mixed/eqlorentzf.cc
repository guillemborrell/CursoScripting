#include <octave/oct.h>
#include "f77-fcn.h"
extern "C" int F77_FUNC (eqlorentzfsub,EQLORENTZFSUB)(double*,double*);

DEFUN_DLD(eqlorentzf,args, ,"xdot=eqlorentz(x)")
{
  octave_value_list retval;
  ColumnVector wargin(args(0).vector_value());
  ColumnVector wargout(3);
  F77_FUNC(eqlorentzfsub,EQLORENTZFSUB)(wargin.fortran_vec(),
                                        wargout.fortran_vec());
  retval.append(wargout);
  return retval;
}
