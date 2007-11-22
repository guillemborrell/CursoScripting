x=0:0.1:1;
y=[2,2.1850,2.2011,2.5762,2.5780,2.9711,2.7816,3.0766,2.8277,3.673,3.6933];
p=plot(x,polyval(polyfit(x,y,1),x),x,y,'r.')
set(p(1),'linewidth',2)
set(p(2),'markersize',2)
print('fitting.eps','-deps')
