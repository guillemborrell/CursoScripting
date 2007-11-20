xf=0:0.05:10;yf=sin(2*pi*xf/5);
xp=0:10     ;yp=sin(2*pi*xp/5);
lin=interp1(xp,yp,xf);
spl=interp1(xp,yp,xf,'spline');
cub=interp1(xp,yp,xf,'cubic');
near=interp1(xp,yp,xf,'nearest');
title('Comparacion de las opciones de interp1')
plot(xf,yf,";real;",xf,lin,";lineal;",xf,spl,";splines;",...
xf,cub,";cubica;",xf,near,";discreta;")
legend('real','lineal','splines','cubica','discreta')
print('figuraejemplo2.eps','-deps')
