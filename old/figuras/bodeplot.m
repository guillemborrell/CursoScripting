sys=tf(conv([10],[1,2]),[1,3,0,10]);
bode(sys)
print('bodeplot.eps','-deps');
