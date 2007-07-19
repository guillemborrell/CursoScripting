 function dFdchi=euleredo(F,xi)
% df     -dc/dy   dG
%---- =  -------  ------
% de      de/dx

global gridfuncs
global opts

F1=F(1,:)
F2=F(2,:)
F3=F(3,:)
F4=F(4,:)

gamma=opts.gamma
R=opts.R
NX=opts.NX
NY=opts.NY
eta=linspace(0,1,NY)
gridinfG=-gridfuncs{2}(eta)./gridfuncs{1}
gridinfF=-gridfuncs{3}(eta)./gridfuncs{1}

rho=(-(gamma/(gamma-1).*F1.*F2).*...
sqrt((gamma/(gamma-1).*F1.*F2).^2.-4*...
(F3.^2./(2*F1).-F4).*((gamma-1)/(2*(gamma-1))*F1.^3)))...
./(2*(F3.^2./(2*F1).-F4))

G1=rho.*F3./F1
G2=F3
G3=rho.*(F3./F1).^2+F2-F1.^2./rho
G4=(gamma/(gamma-1)).*(F2.-(1./rho).*F1.^2).*...
F3./F1+0.5*rho.*(F3./F1).*((F1./rho).^2+(F3./F1).^2)

%  Condiciones de contorno

F3(1)=F1(1)^2/rho(1)*gridfuncs{4}(xi)

tempdFdchi1(2:NY-1)=gridinfG(2:NY-1).*1/NY(G1(3:NY)-G1(1:NY-1)).-...
                    gridinfF(2:NY-1).*1/NY(F1(3:NY)-F1(1:NY-1))
tempdFdchi2(2:NY-1)=gridinfG(2:NY-1).*1/NY(G2(3:NY)-G2(1:NY-1)).-...
                    gridinfF(2:NY-1).*1/NY(F2(3:NY)-F2(1:NY-1))
tempdFdchi3(2:NY-1)=gridinfG(2:NY-1).*1/NY(G3(3:NY)-G3(1:NY-1)).-...
                    gridinfF(2:NY-1).*1/NY(F3(3:NY)-F3(1:NY-1))
tempdFdchi4(2:NY-1)=gridinfG(2:NY-1).*1/NY(G4(3:NY)-G4(1:NY-1)).-...
                    gridinfF(2:NY-1).*1/NY(F4(3:NY)-F4(1:NY-1))

tempdFdchi1(1)=gridinfG(1).*1/NY(G1(2)-G1(1)).-...
               gridinfF(1).*1/NY(F1(2)-F1(1))
tempdFdchi2(1)=gridinfG(1).*1/NY(G2(2)-G2(1)).-...
               gridinfF(1).*1/NY(F2(2)-F2(1))
tempdFdchi3(1)=gridinfG(1).*1/NY(G3(2)-G3(1)).-...
               gridinfF(1).*1/NY(F3(2)-F3(1))
tempdFdchi4(1)=gridinfG(1).*1/NY(G4(2)-G4(1)).-...
               gridinfF(1).*1/NY(F4(2)-F4(1))

tempdFdchi1(NY)=gridinfG(1).*1/NY(G1(NY)-G1(NY-1)).-...
                gridinfF(1).*1/NY(F1(NY)-F1(NY-1))
tempdFdchi2(NY)=gridinfG(1).*1/NY(G2(NY)-G2(NY-1)).-...
                gridinfF(1).*1/NY(F2(NY)-F2(NY-1))
tempdFdchi3(NY)=gridinfG(1).*1/NY(G3(NY)-G3(NY-1)).-...
                gridinfF(1).*1/NY(F3(NY)-F3(NY-1))
tempdFdchi4(NY)=gridinfG(1).*1/NY(G4(NY)-G4(NY-1)).-...
                gridinfF(1).*1/NY(F4(NY)-F4(NY-1))

dFdchi(1,:)=tempdFdchi1
dFdchi(2,:)=tempdFdchi2
dFdchi(3,:)=tempdFdchi3
dFdchi(4,:)=tempdFdchi4
