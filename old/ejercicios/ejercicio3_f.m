t=linspace(0,50,5000);
tic;x=lsode("eqlorentzf",[1;1;1],t);toc