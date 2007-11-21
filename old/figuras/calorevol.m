phi=zeros(10,1); phi(10,1)=1;
dt=0.1;
tout=[0.1,1,2,5,10,20,50,100];
hold on
for i=1:500
  phi(2:9)=(1-dt)*phi(2:9)+0.5*dt*phi(1:8)+0.5*dt*phi(3:10);
  phi = (diag([1,(1+dt)*ones(1,8),1],0)+...
	 diag(-[0.5*dt*ones(1,8),0],-1)+...
	 diag(-[0,0.5*dt*ones(1,8)],1))\phi;
  if sum((dt*i)*ones(1,length(tout))==tout)==1
    plot(linspace(0,1,10),phi);
  end
end

hold off
title('Soluciones de la ecuacion del calor unidimensional')
xlabel('Longitud')
ylabel('Temperatura')
print('calorevol.eps','-deps')
