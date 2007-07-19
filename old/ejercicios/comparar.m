x=linspace(-pi,+pi,100);
for i=1:100
    y(i)=aprsin(x(i));
end
title('comparacion sin vs aprsin')
plot(x,[y;sin(x)])