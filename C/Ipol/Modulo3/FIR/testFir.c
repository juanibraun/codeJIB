/* 
 * File:   testFir.c
 * Author: juanignaciobraun
 *
 * Created on April 6, 2013, 11:08 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "fir.h"

/*
 * Simple C Test Suite
 */

void escalon(sample_t entrada[], sample_t altura, int comienzo) {
    int i;
    for(i = 0; i<SIGNAL_LENGTH; i++){
        if(i<comienzo){
            entrada[i]=0;
        }else{
            entrada[i]=altura;
        }
                
    }
}


void delta(sample_t entrada[], sample_t altura, int comienzo) {
    int i;
    for(i = 0; i<SIGNAL_LENGTH; i++){
        if(i!=comienzo){
            entrada[i]=0;
        }else{
            entrada[i]=altura;
        }
                
    }
}

int main() {
    
    int i;
    sample_t entrada[SIGNAL_LENGTH];
    sample_t salida[SIGNAL_LENGTH];
    
    printf("\n======================CASO ESCALON======================\n");
    escalon(entrada, 1.0, 5);
    
    printf("\nENTRADA: ");
    for(i = 0; i<SIGNAL_LENGTH; i++){
        printf("%f\t",entrada[i]);
    }
    printf("\n");
    
    sample_t coeficientes[TAP_LENGTH] = {1/(sample_t)TAP_LENGTH,1/(sample_t)TAP_LENGTH,1/(sample_t)TAP_LENGTH,1/(sample_t)TAP_LENGTH};
    
    ini_fir(coeficientes);
    
    
    for(i = 0; i<SIGNAL_LENGTH; i++)
        salida[i]=fir(entrada[i]);
   
    printf("\nSALIDA: ");
    for(i = 0; i<SIGNAL_LENGTH; i++){
        printf("%f\t",salida[i]);
    }
    printf("\n");
    
    printf("\n======================CASO DELTA======================\n");
    delta(entrada, 2.0, 3);
    
    printf("\nENTRADA: ");
    for(i = 0; i<SIGNAL_LENGTH; i++){
        printf("%f\t",entrada[i]);
    }
    printf("\n");
    
    ini_fir(coeficientes);
    
    
    for(i = 0; i<SIGNAL_LENGTH; i++)
        salida[i]=fir(entrada[i]);
   
    printf("\nSALIDA: ");
    for(i = 0; i<SIGNAL_LENGTH; i++){
        printf("%f\t",salida[i]);
    }
    printf("\n");

}
