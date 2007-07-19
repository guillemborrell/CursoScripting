%Primero introducimos los valores numericos
M = .5;
m = 0.2;
b = 0.1;
i = 0.006;
g = 9.8;
l = 0.3;
q = (M+m)*(i+m*l^2)-(m*l)^2;

%Definimos la funcion de transferencia con tf
%la salida de tf es un dato tipo estructura
sys=tf([m*l/q  0],[1  b*(i+m*l^2)/q  -(M+m)*m*g*l/q  -b*m*g*l/q]);
figure(1)
impulse(sys);
axis([0,1,0,60]) %Colocamos mejor los ejes
T=0:0.05:10;
U=0.2*ones(size(T'));
[X,Y]=lsim(sys,U,T);
figure(2)
plot(T,Y)
axis([0,2,0,100])