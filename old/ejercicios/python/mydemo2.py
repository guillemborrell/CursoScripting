from pylab import *
from scipy import *
x = linspace(0, 500, 10000)
plot(x,exp(-x/100)*sin(x))
title('Una funcion cualquiera')
xlabel('Tiempo')
ylabel('Amplitud')
show()