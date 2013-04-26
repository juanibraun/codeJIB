#include "fir.h"
#include <stdio.h>
 
sample_t a[TAP_LENGTH]; // Coeficientes del filtro.
sample_t buff_in[TAP_LENGTH]; //Entrada al filtro, del mismo tamaño que a[].
int p; // Puntero a una muestra, siempre apunta a la ultima muestra 
       // ingresada (circular).



void ini_fir(sample_t coefs[]){
    register int index;
    for (index=0;index<TAP_LENGTH;index++){
        a[index] = coefs[index];
        buff_in[index] = 0;
    }
    p = 0;
}


sample_t fir(sample_t muestra){
    buff_in[p] = muestra;
    register int i;
    register sample_t muestra_out = 0;
    for(i=0;i<TAP_LENGTH;i++){
      //printf("Paso: %d\nMuestra: %f\n\n",p,buff_in[p]);
        muestra_out = muestra_out + a[i]*buff_in[p];
        update_p(p);
	
    }
    update_p(p);
    return muestra_out;
}
