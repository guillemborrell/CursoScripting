[t,x]=ode45(@rikitake,[0 300],[1 2 3],pair=0,ode_fcn_format=1);
plot(t,x(:,1),';x_1;',t,x(:,2),';x_2;',t,x(:,3),';x_3;')