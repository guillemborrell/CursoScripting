x=0;t=0;
tic;[t,x]=ode45('lorentz',[0,50],[1,1,1]);toc
#plot3(x(:,1),x(:,2),x(:,3))
