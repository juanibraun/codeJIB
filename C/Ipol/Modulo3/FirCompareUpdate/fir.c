
#include<stdio.h>
#include "fir.h"

//int tiempo;
sample_t buffer[TAP_LENGTH];
sample_t coefsLocales[TAP_LENGTH];


sample_t a[TAP_LENGTH]; // Coeficientes del filtro.
sample_t buff_in[TAP_LENGTH]; //Entrada al filtro, del mismo tamaño que a[].
int p; // Puntero a una muestra, siempre apunta a la ultima muestra 
       // ingresada (circular).

sample_t coefsLocalesNC[TAP_LENGTH];
int tiempo;


void ini_fir (sample_t coefs[]){ 
    int i;
    for(i=0;i<TAP_LENGTH;i++){
        coefsLocales[i] = coefs[i];
        buffer[i] = 0;
    }
    //    tiempo = 0;
    //imprimo coefs
    // printf("\nCOEFS: ");
    //for(i = 0; i<TAP_LENGTH; i++)
    //    printf("%f\t",coefsLocales[i]);
    //printf("\n");
}

sample_t fir(sample_t muestra){
    sample_t out = 0;
    int i;
//    // imprimo coefs
//    printf("\nCOEFS: ");
//    for(i = 0; i<TAP_LENGTH; i++)
//        printf("%f\t",coefsLocales[i]);
//    printf("\n");
    
    // lleno el buffer
    for(i = TAP_LENGTH-1; i>0; i--)
        buffer[i]=buffer[i-1];
    buffer[0]=muestra;
    
//    //imprimo buffer
//    printf("\nBuffer en %d: ",tiempo);
//    for(i = 0; i<TAP_LENGTH; i++)
//        printf("%f\t",buffer[i]);
//    printf("\n");
    
    // aplico filtro
    for(i = 0; i<TAP_LENGTH; i++)
        out+=coefsLocales[i] * buffer[i];
    
//    tiempo++;
    return out;
    
}

void ini_fir_sol(sample_t coefs[]){
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

sample_t fir_sol(sample_t muestra){
    buff_in[p] = muestra;
    int i;
    sample_t muestra_out = 0;
    for(i=0;i<TAP_LENGTH;i++){
        muestra_out = muestra_out + a[i]*buff_in[p];
        update_p(1);
    }
    update_p(1);
    return muestra_out;
}

void ini_fir_NC (sample_t coefs[]){ 
    int i;
    for(i=0;i<TAP_LENGTH;i++){
        coefsLocalesNC[i] = coefs[i];
    }
    tiempo = 0;
}

sample_t fir_NC(sample_t* muestra){
    sample_t out = 0;
    int i;

     // aplico filtro
    for(i = 0; i<TAP_LENGTH; i++){
      if((tiempo-i)<0){
	break;
      }else{ 
	out+=coefsLocalesNC[i] * *(muestra-i);
      	//printf("muestra[%d]: %f\t Dir:%ld\n", i, *(muestra-i),(long int)(muestra-i));
      }
    }
    tiempo++;
    return out;
    
}
