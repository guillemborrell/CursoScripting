function ret=join(A,B)

%  argumentos:
%  A :: Matriz, real
%  B :: Matriz, real
%  Devuelve una copia de la matriz A compatible
%  con la matriz B en el caso que sean transformaciones
%  de un vector

sizA = size(A);
sizB = size(B);

if sizA(2) == sizB(2) && sizA(1) < sizB(1)
  ret=[A;zeros(sizB(1)-sizA(1),sizA(2))];
else
  disp('Las matrices no son compatibles')
  ret=0;
end
