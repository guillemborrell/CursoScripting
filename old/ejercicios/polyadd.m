function poly=polyadd(poly1,poly2)
  if (nargin != 2)
    usage('polyadd(poly1,poly2)')
  end
  if (is_vector(poly1) && is_vector(poly2))
    if length(poly1)<length(poly2)
      short=poly1;
      long=poly2;
    else
      short=poly2;
      long=poly1;
    end
    diff=length(long)-length(short);
    if diff>0
      poly=[zeros(1,diff),short]+long;
    else
      poly=long+short;
    end
  else
    error('both arguments must be polynomials')
  end