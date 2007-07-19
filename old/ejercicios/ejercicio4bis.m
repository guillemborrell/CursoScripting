dx=2;dy=3;global n=50;global m=50;
%resolucion del problema con un solver iterativo
%construccion de los operadores en diferencias

function place=place(i,j,n)
  place=i+n*(j-1);
end

global DX=diag([1,-2/(dx*dx).*ones(1,n-2),1],0).+...
          diag([0,1/(dx*dx).*ones(1,n-2)],1).+...
          diag([1/(dx*dx).*ones(1,n-2),0],-1);
global DY=diag([1,-2/(dy*dy).*ones(1,n-2),1],0).+...
          diag([0,1/(dy*dy).*ones(1,n-2)],1).+...
          diag([1/(dy*dy).*ones(1,n-2),0],-1);

function [AT]=calcstuff(T)
  global n
  global m
  global DX
  global DY
  rT=reshape(T,n,m);
  AT=reshape((DX*rT)+(rT*DY'),n*m,1);
end
i=1;j=1;b=1;
for j=1:m
  b(place(i,j,n))=sin(pi*(j-1)/(m-1));
end
i=n;
for j=1:m
  b(place(i,j,n))=-sin(pi*(j-1)/(m-1));
end
j=1;
for i=1:n
  b(place(i,j,n))=sin(pi*(i-1)/(n-1));
end
j=n;
for i=1:n
  b(place(i,j,n))=0;
end

tic;T=pcg('calcstuff',b',tol=1e-6,maxit=100);
disp('Tiempo de calculo'),disp(toc)
