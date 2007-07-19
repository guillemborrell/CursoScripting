phi=zeros(10,1); phi(10,1)=1;
dt=0.1;
for i=1:50 #Activate loop in case of precision leak
  phi(2:9)=(1-dt)*phi(2:9)+0.5*dt*phi(1:8)+0.5*dt*phi(3:10);
  phi=trisolve(-[0.5*dt*ones(8,1);0],[1;(1+dt)*ones(8,1);1],...
  -[0;0.5*dt*ones(8,1)],phi);
end
