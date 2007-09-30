x0=[1;1;1];
t=linspace(0,50,5000);
tic;x=lsode(@eqlorentz,x0,t);toc
