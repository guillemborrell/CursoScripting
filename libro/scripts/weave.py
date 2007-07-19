from numpy import empty,array
from scipy import weave
from scipy.weave import converters
from timeit import Timer

def lorentz(x):
    xdot=empty(3)
    a=10
    b=28
    c=8./3.
    xdot[0] = a*(x[1]-x[0])
    xdot[1] = x[0]*(b-x[2])-x[1]
    xdot[2] = x[0]*x[1]-c*x[2]

    return xdot

def lorentz_weave(x):
    xdot=empty(3)
    code="""
    double a=10;
    double b=28;
    double c=8./3.;
    xdot[0] = a*(x[1]-x[0]);
    xdot[1] = x[0]*(b-x[2])-x[1];
    xdot[2] = x[0]*x[1]-c*x[2];
    return_val=1;
    """

    err = weave.inline(code,
                       ['x','xdot'],
                       type_converters=converters.blitz,
                       compiler='gcc')

    return xdot

print lorentz(array([1,1,1]))
print lorentz_weave(array([1,1,1]))

t1=Timer('lorentz(array([1,1,1]))',"""
from numpy import array
from __main__ import lorentz""")

print t1.timeit(number=10000)

t2=Timer('lorentz_weave(array([1,1,1]))',"""
from numpy import array
from __main__ import lorentz_weave""")

print t2.timeit(number=10000)



      
