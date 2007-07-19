function xdot=rikitake(x,t)
%
%   Ecuacion de la dinamo de Rikitake
%
xdot(1,1)=-x(1)+x(3)*x(2);
xdot(2,1)=-x(2)+x(1)*(x(3)-3.75);
xdot(3,1)=1-x(1)*x(2);