function ret=cdot(c,M)

%  argumentos:
%    c :: escalar entero
%    M :: escalar entero
%  Calcula el operador c· para un vector de coeficientes
%  de M elementos.

if isscalar(c) && isscalar(M)
  ret=c*eye(M);
else
  disp ('Ambos argumentos deben ser escalares')
end
