function ret=xn(M,n)

%  argumentos:
%    M :: escalar entero
%    n :: escalar entero
%  Retorna la matriz correspondiente al operador
%  x^n con n cualquier exponente entero para un
%  vector de coeficientes de M elementos

if isscalar(M) && isscalar(n)
  ret=[zeros(n,M);eye(M)];
else
  disp ('Ambos argumentos deben ser escalares')
end
