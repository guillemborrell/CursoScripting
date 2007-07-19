#include <octave/oct.h>
#include <octave/f77-fcn.h>
struct mystruct {
  double mydouble;
  int myint;
  };
extern "C" int F77_FUNC (f95sub,f95SUB) ( mystruct&, mystruct&); 
DEFUN_DLD (f95demo, args , , "[w,z] = f95demo2( x , y )\
returns w  = x^y and z = y * y for integer y") {
  octave_value_list retval;
  mystruct dinptr , doutptr;
  dinptr.mydouble = args(0).scalar_value();
  dinptr.myint = int( args(1).scalar_value() );
  F77_FUNC (f95sub,f95SUB) (dinptr,doutptr );
  retval.append( octave_value( doutptr.mydouble ) );
  retval.append( octave_value( double( doutptr.myint  ) ) );
  return retval;
}
