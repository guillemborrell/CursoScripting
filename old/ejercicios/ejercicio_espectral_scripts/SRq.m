function [S,q]=SRq(R)

%  calcula la matriz SR en funcion de la matriz residuo R

% Nodos de Gauss Chebyshev
% Tomo M de R
M=size(R)(2); %esto es legal en Octave pero ilegal en Matlab
              %Octave permite una escritura mucho mas compacta
ngc=(cos((2*(1:M)-1)*pi/(2*M))).';
grado=size(R)(1);

%No hay mas remedio que utilizar un bucle.
S=R';
for i=0:grado-1
  S(:,i+1)=ngc.^i;
end

q=ngc.^6+3*ngc.^2;

