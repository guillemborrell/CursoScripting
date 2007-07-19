function ret=dxx(M)

%  argumentos:
%    M :: escalar entero
%  Retorna el operador derivada segunda para
%  un vector de coeficientes de tamano M

if isscalar(M)
  ret=[zeros(M-2,1),zeros(M-2,1),diag(2:M-1).*diag(1:M-2)];
else
  disp('M debe ser un escalar')
end
