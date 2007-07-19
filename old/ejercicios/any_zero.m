function out = any_zero(v)
% out = any_zero (v)
% v :: vector
%
% devuelve un mensaje si algun elemento de v es 0
out = 0;
for i = 1:length(v)
  if (v (i) == 0)
    out = 1;
    return
  endif
endfor
printf ("No se ha encontrado ningun cero\n")
endfunction