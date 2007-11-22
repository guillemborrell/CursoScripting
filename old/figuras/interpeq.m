fit=@(x) 1./(1+16*x.^2);
x=linspace(-1,1,17);
xcont=linspace(-1,1,200);
y=fit(x);
ycont=fit(xcont);
c=vander(x)\y';
yfit=polyval(c',xcont); 
p=plot(x,y,'r.',xcont,ycont,'k',xcont,yfit,'b');
set(p(1),'markersize',2)
set(p(2),'linewidth',2)
set(p(3),'linewidth',3)
axis([-1,1,-0.1,1.1]);
legend('nodos','real','interpolacion')
print('interpeq.eps','-deps')
