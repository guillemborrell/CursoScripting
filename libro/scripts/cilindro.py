from numpy import *
from pylab import *

gamma=10

f=lambda x,y: (x+y*1j) + 1/(x+y*1j) +\
       (1j*gamma)/(2*pi)*log(x+y*1j)

[XX,YY]=mgrid[-5:5:100j,-5:5:100j]
contour(XX,YY,-imag(f(XX,YY)),29,colors='black')
axis('scaled')
show()
