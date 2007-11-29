function ret=b(M)

%  argumentos:
%  M :: escalar entero

x2 = xn(M,2);
ret = join(eye(M),x2)-x2;
