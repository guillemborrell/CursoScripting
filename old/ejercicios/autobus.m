#Octave + octave-forge
#10-08-2005
#Guillem Borrell
#
#Constantes del sistema simulado
m1=2500;
m2=320;
k1=80000;
k2=500000;
b1 = 350;
b2 = 15020;
#apartado1
#Funcion de transferencia de la fuerza aplicada
nump=[(m1+m2),b2,k2];
denp=[(m1*m2),(m1*(b1+b2))+(m2*b1),(m1*(k1+k2))+...
(m2*k1)+(b1*b2),(b1*k2)+(b2*k1),k1*k2];
g1=tf(nump,denp);
#Funcion de transferencia de la distancia a la referencia
num1=[-(m1*b2),-(m1*k2),0,0];
den1=[(m1*m2),(m1*(b1+b2))+(m2*b1),(m1*(k1+k2))+...
(m2*k1)+(b1*b2),(b1*k2)+(b2*k1),k1*k2];
g2=tf(num1,den1);
#-------------------------------------
#apartado2
#Graficas de la respuesta de lazo abierto
#figure(1)
#gset output 'figuraejercicio6_1.png'
#gset term png
#step(g1)
#title('Respuesta de lazo abierto a la fuerza aplicada')
#figure(2)
#gset output 'figuraejercicio6_2.png'
#gset term png
#step(g2)
#title('Respuesta de lazo abierto con el sensor')
#figure(3)
#bode(g1);
#figure(4)
#bode(g2)
#apartado3
#constantes del controlador PID
KD=208025;
KP=832100;
KI=624075;
g3=tf(conv(g2.num,[1,0]),polyadd(conv([1,0],g1.den),conv([KD,KP,KI],g1.num)));
step(g2)