#A ver si lo hacemos funcionar...
from scipy import *
from pylab import *
from scipy.interpolate import interp1d
xf=linspace(0,10,0.05);yf=sin(2*pi*xf/5);
xp=r_[0:10]     ;yp=sin(2*pi*xp/5);
lin=interp1d(xp,yp,kind='linear');
spl=interp1d(xp,yp,kind='spline');
cub=interp1d(xp,yp,kind='cubic');
near=interp1d(xp,yp,kind='nearest');
plot(xf,yf,xf,lin(yf),xf,spl(yf),xf,cub(yf),xf,near(yf))
title('Comparacion de las opciones de interp1')
legend('real','lineal','splines','cubica','discreta')