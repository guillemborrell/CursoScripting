dx=2;
dy=3;
n=50;
m=50;
function place=place(i,j,n)
  place=i+n*(j-1);
end
A=zeros(n*m,n*m);
tic
for i=1:n*m
  A(i,i)=1;
end
for i=2:n-1
  for j=2:m-1
    A(place(i,j,n),place(i,j,n))=-2*(1/(dx*dx)+1/(dy*dy));
    A(place(i,j,n),place(i-1,j,n))=1/(dx*dx);
    A(place(i,j,n),place(i+1,j,n))=1/(dx*dx);
    A(place(i,j,n),place(i,j-1,n))=1/(dy*dy);
    A(place(i,j,n),place(i,j+1,n))=1/(dy*dy);
  end
end
toc;disp('Creacion de la matriz del sistema'),disp(toc);tic;
i=1;
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
toc;disp('Creacion del vector b'),disp(toc);tic;
T=A\b';
%spA=sparse(A);
%clear A;
%T=spA\b';
toc;disp('Resolucion del sistema'),disp(toc);
T=reshape(T,n,m);
%gset output 'figuraejercicio4.ps'
%gset term postscript
%mesh(T)
