function polyout=polyadd(poly1,poly2)
  if (nargin != 2)
    usage('polyadd(poly1,poly2)')
  end
  if (is_vector(poly1) && is_vector(poly2))
    lp1 = length(poly1);
    lp2 = length(poly2);
    lpo = max([lp1,lp2]);
    polyout = zeros(1,lpo);
    polyout(lpo-lp1+1:end) = polyout(lpo-lp1+1:end) + poly1;
    polyout(lpo-lp2+1:end) = polyout(lpo-lp2+1:end) + poly2;
  else
    error('both arguments must be polynomials')
  end