from pylab import *
x=linspace(-pi,pi,100)
plot(x,sin(x),'m:',x,cos(x),'k^',x,tan(x),'bx')
axis([-pi,pi,-2,2])
grid('on')
legend(('linea de puntos magentas','triangulos negros','cruces azules'))
savefig('figuraejemplo7.pdf',format='pdf')
