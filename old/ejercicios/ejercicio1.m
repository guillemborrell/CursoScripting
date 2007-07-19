a=[5 4 7];
b=[7 2 8];
c=[9 1 6];

ada=a/norm(a);
adb=b/norm(b);
adc=c/norm(c);

A=ada;
A(2,:)=adb;
A(3,:)=adc;
A
det(A)

function [b]=cambio(A,a)
  b=A*a;
endfunction

vec=[3;2;1]
ivec=cambio(A,vec)

A'-inv(A)

function [b]=cambioinv(A,a)
  b=inv(A)*a;
endfunction

iivec=cambioinv(A,ivec)

bb=[1;1;2];
result=inv(A)*bb
