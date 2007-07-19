function retval = avg (v)
% retval = avg(v)
% v :: vector
%
% Calcula la media de los elementos de un vector

  retval = 0;
  if (nargin != 1)
    usage ("avg (vector)");
  endif
  if (isvector(v))
    retval = sum(v) / length(v);
  else
    error ("avg: expecting vector argument");
  endif
endfunction
