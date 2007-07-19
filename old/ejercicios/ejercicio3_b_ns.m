t=linspace(0,50,5000);
lsode_options('integration method','non-stiff');
tic;x=lsode("eqlorentz",[1;1;1],t);toc
plot3(x(:,1),x(:,2),x(:,3))
