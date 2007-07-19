from pylab import *
from scipy import *

def aprsin(x):
    return x-x**3/6

x=linspace(-pi,pi,100)
plot(x,aprsin(x),'--',x,sin(x))
title('Comparacion sin vs aprsin')
legend(('aprsin','sin'))
show()
