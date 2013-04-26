function [muestras,numCiclos] = leerSalida(ruta)
f = fopen(ruta,'r');
SIGNAL_LENGTH=fscanf(f,'%u\n',1);
numCiclos = fscanf(f,'Ciclos: %f\n',1);
muestras = fscanf(f,'%f\n',[1,SIGNAL_LENGTH]);