close all

[salida1,ciclo1] = leerSalida('salida1.txt');
[salida2,ciclo2] = leerSalida('salida2.txt');
[salida_sol1,ciclo_sol1] = leerSalida('salida_sol1.txt');
[salida_sol2,ciclo_sol2] = leerSalida('salida_sol2.txt');
[salida1_NC,ciclo1_NC] = leerSalida('salida1_NC.txt');
[salida2_NC,ciclo2_NC] = leerSalida('salida2_NC.txt');

figure
plot(1:1024,salida1,'r',1:1024,salida_sol1,'b',1:1024,salida1_NC,'g');
figure
plot(1:1024,salida2,'r',1:1024,salida_sol2,'b',1:1024,salida2_NC,'g');

