t=linspace(0,50,5000);
lsode_options('integration method','non-stiff');
tic;x=lsode("eqlorentzf",[1;1;1],t);toc
