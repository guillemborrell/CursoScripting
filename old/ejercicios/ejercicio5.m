x=1:1:100;
xsmooth=1:0.1:100;
rspectra=1:-0.01:0.01;
ispectra=exp(-(rand(size(rspectra))));
spectra=(rspectra+i*ispectra);
phys=abs(fft(spectra));
subplot(2,2,1);plot(x,abs(spectra));title('Espectro');
subplot(2,2,2);plot(x,phys)        ;title('Plano fisico');
coefs_fit1=polyfit(x,phys,1);
coefs_fit2=polyfit(x,phys,2);
coefs_fit5=polyfit(x,phys,5);
subplot(2,2,3);plot(x,polyval(coefs_fit1,x),';polinomio grado 1;');
hold on
subplot(2,2,3);plot(x,polyval(coefs_fit2,x),';polinomio grado 2;');
subplot(2,2,3);plot(x,polyval(coefs_fit5,x),';polinomio grado 5;');
plot(x,phys,';func;')
title('Interpolación polinomica');
hold off
coefs_spline=spline(x,phys);
splinecurve=spline(x,phys,xsmooth);
subplot(2,2,4);plot(xsmooth,splinecurve,';Splines cúbicos;');
hold on
plot(x,phys,';func;')
title('Interpolación por splines');
hold off
