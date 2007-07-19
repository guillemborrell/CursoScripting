gamma=input('¿Circulación?');

f=@(x,y) (x+i*y) + 1./(x+i*y) + (i*gamma)/(2*pi)*log(x+i*y);
[XX,YY]=meshgrid(linspace(-5,5,100),linspace(-5,5,100));

%xc=linspace(1,-1,50);
%yc=sqrt(1-xc.^2);
%xc=[xc,-xc(2:end)];
%yc=[yc,-yc(2:end)];

%plot(xc,yc,':r')
%hold on
vtk_contour(XX,YY,-imag(f(XX,YY)),"NConts",29)

%hold off

