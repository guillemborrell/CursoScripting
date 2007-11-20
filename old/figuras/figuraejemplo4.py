from pylab import linspace,xlabel,ylabel,title,plot,savefig
from numpy import exp,sin
x = linspace(0, 500, 10000)
plot(x,exp(-x/100)*sin(x))
title('Una funcion cualquiera')
xlabel('Tiempo')
ylabel('Amplitud')
savefig('figuraejemplo4.pdf',format='pdf')