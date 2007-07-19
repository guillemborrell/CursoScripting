function ret = R(M)

% Dificil de descifrar.  Comentario pendiente
% Fuciona.

dxxb = dxx(M+2)*b(M);% Primer termino
x6b = xn(M+2,6)*b(M);% Segundo termino
x2_3b = 3*xn(M+2,2)*b(M);% Tercer termino
ret = join(dxxb,x6b) - x6b - join(x2_3b,x6b);
