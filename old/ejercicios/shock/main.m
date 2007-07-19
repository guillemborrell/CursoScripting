 
%  Programa para el calculo de ondas de choque y de expansion
%  Diferencias finitas de 2º orden
%  Integración streamwise mediante un Adams-Bashforth (PECE)
%  Para pasar de Octave a Matlab sustituir lsode por ode113
%
%  cuidado: absolutamente todo es una matriz
%
%  Metelo todo en la funcion densidad para aumentar la velocidad

%  Variables primitivas
u=@(F1,rho) F1./rho
v=@(F1,F3) F3./F1
p=@(F1,F2,u) F2.-F1.*u
T=@(p,rho,R) p./(R*rho)

% Variables secundarias
M=@(u,v,gamma,R,T) sqrt((u.^2.+v.^2)./(gamma*R.*T))

global gridfuncs={L,@detadx,@detady,@dhsdx}
global opts.gamma=1.4
opts.R=286
opts.NX=100
opts.NY=100
