# archivo principal, genera las figuras en eps para la solucion
# y para el error

r=R(5);
[s,q]=SRq(r);
solM5=(s*r)\q;

r=R(10);
[s,q]=SRq(r);
solM10=(s*r)\q;

r=R(20);
[s,q]=SRq(r);
solM20=(s*r)\q;

r=R(30);
[s,q]=SRq(r);
solM30=(s*r)\q;

x = linspace(-1,1,100);
figure(1)
hold on
plot(x,exp((x.^4-1)/4));
plot(x,polyval(transsol(solM5),x),'rx');
plot(x,polyval(transsol(solM10),x),'bo');
plot(x,polyval(transsol(solM20),x),'kv');
plot(x,polyval(transsol(solM30),x),'m+');
legend('exacta','orden 5','orden 10','orden 20','orden 30')
title('Solucion completa')
hold off
print('solucion.eps','-deps')


figure(2)
hold on
plot(x,polyval(transsol(solM5),x)-exp((x.^4-1)/4),'rx');
plot(x,polyval(transsol(solM10),x)-exp((x.^4-1)/4),'bo');
plot(x,polyval(transsol(solM20),x)-exp((x.^4-1)/4),'kv');
plot(x,polyval(transsol(solM30),x)-exp((x.^4-1)/4),'m+');
legend('orden 5','orden 10','orden 20','orden 30')
axis([-1,0]);
title('Error de las soluciones')
hold off
print('error.eps','-deps')
