#include <octave/oct.h>
DEFUN_DLD (eqlorentz,args, ,
    "Ecuacion de Lorentz en C++")
    {
    ColumnVector xdot (3);
    ColumnVector x (args(0).vector_value());
    int a=10;
    int b=28;
    double c=8./3;
    xdot(0) = a*(x(1)-x(0));
    xdot(1) = x(0)*(b-x(2))-x(1);
    xdot(2) = x(0)*x(1)-c*x(2);
    
    return octave_value (xdot);
    }
