function ret=transsol(sol)

%  argumentos
%    sol :: vector real
%           vector de coeficientes solucion del problema

sol=rot90(rot90(sol));
sol=conv([-1,0,1],sol);
sol(length(sol))++; % Operador sólo válido en Octave
ret=sol;                    % proviene de C
