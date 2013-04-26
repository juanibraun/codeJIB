
#include<stdio.h>
#include "fir.h"

int tiempo;
sample_t coefsLocales[TAP_LENGTH];



void ini_fir (sample_t coefs[]){ 
    int i;
    for(i=0;i<TAP_LENGTH;i++){
        coefsLocales[i] = coefs[i];
    }
    tiempo = 0;
}

sample_t fir(sample_t* muestra){
    sample_t out = 0;
    int i;

     // aplico filtro
    for(i = 0; i<TAP_LENGTH; i++){
      if((tiempo-i)<0){
	break;
      }else{ 
	out+=coefsLocales[i] * *(muestra-i);
      	//printf("muestra[%d]: %f\t Dir:%ld\n", i, *(muestra-i),(long int)(muestra-i));
      }
    }
    tiempo++;
    return out;
    
}
