x=0;

function xdot=func(x,t)
a=10;b=28;c=8/3;
xdot(1,1)=a*(x(2)-x(1));
xdot(2,1)=x(1)*(b-x(3))-x(2);
xdot(3,1)=x(1)*x(2)-c*x(3);
endfunction

x0=[1;1;1];
t=linspace(0,50,5000);
lsode_options('integration method','non-stiff')
tic;x=lsode("func",x0,t);toc

#plot3(x(:,1),x(:,2),x(:,3))
