aprsin=@(s) s-s.^3/6;
x = linspace(-pi,pi,100);
y=aprsin(x);
plot(x,y,'k.',x,sin(x),'b');
title('Comparacion sin vs aprsin');
legend('aprsin','sin');
print('figuraejemplo1.eps','-deps')
