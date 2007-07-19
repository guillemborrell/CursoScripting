from pylab import *
from scipy import *
x=linspace(-pi,pi,100)
subplot(221)
plot(x,sin(x))
subplot(222)
plot(x,cos(x))
subplot(223)
plot(x,sinh(x))
subplot(224)
plot(x,cosh(x))
show()
