
P=[0.9 1 1.2];
hold on
for i=1:3
  global Pi
  Pi=P(i);

  function[f]=ttb(x)
    global Pi
    f(1)=x(1)/(2*sqrt(x(1)*x(3)+x(2)))-2*Pi*x(3);
    f(2)=Pi*x(3)**2+0.1-sqrt(x(1)*x(3)+x(2));
    f(3)=sqrt(x(1)+x(2))-1;
  endfunction

  x0=[1 1 1];
  [res]=fsolve('ttb',x0);

  xcoord=linspace(0,1,100);

  function[f]=tobera(x,a,b,l,P)
    if x<l
      f=P*(x*x)+0.1;
    else
      f=sqrt(a*x+b);
    endif
  endfunction



  for j=1:100
    tob(j)=tobera(xcoord(j),res(1),res(2),res(3),P(i));
  end

  plot(xcoord,tob)
end
