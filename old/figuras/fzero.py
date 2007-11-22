from pylab import *

x=linspace(0.1,2*pi,100)
l=lambda x: log(x)
s=lambda x: sin(x)
plot(x,l(x),x,s(x))
axis((0.1,6,-1.5,1.5))
savefig('fzero.pdf',format='pdf')
