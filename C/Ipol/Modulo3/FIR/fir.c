
#include<stdio.h>
#include "fir.h"

//int tiempo;
sample_t buffer[TAP_LENGTH];
sample_t coefsLocales[TAP_LENGTH];



void ini_fir (sample_t coefs[]){ 
    int i;
    for(i=0;i<TAP_LENGTH;i++){
        coefsLocales[i] = coefs[i];
        buffer[i] = 0;
    }
//    tiempo = 0;
//    //imprimo coefs
//    printf("\nCOEFS: ");
//    for(i = 0; i<TAP_LENGTH; i++)
//        printf("%f\t",coefsLocales[i]);
//    printf("\n");
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
