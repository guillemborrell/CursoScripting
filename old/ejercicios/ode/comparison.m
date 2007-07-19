%lsode no stiff
lsode_options('integration method','non-stiff')
disp('tiempo lsode')
tic;y=lsode('vdp1',[2 0],linspace(0,20,1000));toc
disp('tiempo ode45')
tic;[tout,xout]=ode45(@vdp1,[0,20],[2 0],pair=0,ode_fcn_format=1);toc
plot(linspace(0,20,1000),y(:,1))
hold on
plot(tout,xout(:,1),'bo')
%Si intentamos hacer lo mismo con vdp1000 ya no podemos
lsode_options('integration method','stiff')
tic;ystiff=lsode('vdp1000',[2 0],linspace(0,3000,100000));toc
%octave:29> y=lsode('vdp1',[0 1],linspace(0,30,2000));
%octave:30> plot(linspace(0,30,2000),y(:,1),';x=0  x\'=1;')
%octave:31> hold on
%octave:32> y=lsode('vdp1',[0 0.1],linspace(0,30,2000));
%ctave:33> plot(linspace(0,30,2000),y(:,1),';x=0  x\'=0.1;')
%octave:34> y=lsode('vdp1',[0 0.01],linspace(0,30,2000));
%octave:35> plot(linspace(0,30,2000),y(:,1),';x=0  x\'=0.01;')
