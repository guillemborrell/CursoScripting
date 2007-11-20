from pylab import subplot,plot,linspace,savefig
from numpy import sin,cos,sinh,cosh,pi
x=linspace(-pi,pi,100)
subplot(221)
plot(x,sin(x))
subplot(222)
plot(x,cos(x))
subplot(223)
plot(x,sinh(x))
subplot(224)
plot(x,cosh(x))
savefig('figuraejemplo3.pdf',format='pdf')
