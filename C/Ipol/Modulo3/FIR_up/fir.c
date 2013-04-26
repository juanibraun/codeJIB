#include "fir.h"
#include <stdio.h>
 
sample_t a[TAP_LENGTH]; // Coeficientes del filtro.
sample_t buff_in[TAP_LENGTH]; //Entrada al filtro, del mismo tamaño que a[].
int p; // Puntero a una muestra, siempre apunta a la ultima muestra 
       // ingresada (circular).



void ini_fir(sample_t coefs[]){
    int index;
    for (index=0;index<TAP_LENGTH;index++){
        a[index] = coefs[index];
        buff_in[index] = 0;
    }
    p = 0;
}

void update_p(){
  
    if (p+1<0){
        p = TAP_LENGTH + p + 1;
    } else if (p+1>TAP_LENGTH-1){
        p = p + 1 - TAP_LENGTH;
    } else {
        p = p + 1;
    }
}

sample_t fir(sample_t muestra){
    buff_in[p] = muestra;
    int i;
    sample_t muestra_out = 0;
    for(i=0;i<TAP_LENGTH;i++){
      //printf("Paso: %d\nMuestra: %f\n\n",p,buff_in[p]);
        muestra_out = muestra_out + a[i]*buff_in[p];
        update_p(1);
	
    }
    update_p(1);
    return muestra_out;
}
