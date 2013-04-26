/* 
 * File:   testFir.c
 * Author: juanignaciobraun
 *
 * Created on April 6, 2013, 11:08 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "fir.h"
#include <time.h>
//#define OPTIM
#define ESC TRUE
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
    sample_t escalonIn[SIGNAL_LENGTH];
    sample_t deltaIn[SIGNAL_LENGTH];
    sample_t salida[SIGNAL_LENGTH];
    clock_t comienzo;
    clock_t final;

    sample_t coeficientes[TAP_LENGTH];
    for(i=0;i<TAP_LENGTH;i++)
      coeficientes[i] = 1/(sample_t)TAP_LENGTH;
    
    
    //printf("\n======================INICIO======================\n");    


    
    escalon(escalonIn, 1.0, 500);
    
    #ifndef OPTIM
    // imprimo entrada en archivo
    FILE* escalon_txt;
    escalon_txt = fopen("escalon.txt","w"); 
    fprintf(escalon_txt,"%d\n",SIGNAL_LENGTH);     
    for(i=0;i<SIGNAL_LENGTH;i++)
      fprintf(escalon_txt,"%f\n",escalonIn[i]);
    fclose(escalon_txt); 
    #endif

    delta(deltaIn, 100.0, 300);
    
    #ifndef OPTIM
    // imprimo entrada en archivo
    FILE* delta_txt;
    delta_txt = fopen("delta.txt","w"); 
    fprintf(delta_txt,"%d\n",SIGNAL_LENGTH);     
    for(i=0;i<SIGNAL_LENGTH;i++)
      fprintf(delta_txt,"%f\n",deltaIn[i]);
    fclose(delta_txt); 
    #endif

    
    //printf("\n======================FIR 1======================\n");

    #if ESC

      //printf("\n======================CASO ESCALON======================\n");
    
      ini_fir(coeficientes);
    
      for(i = 0; i<SIGNAL_LENGTH; i++)
          salida[i]=fir(escalonIn[i]);
    
      #ifndef OPTIM
      // imprimo salida en archivo
      FILE* salida1;
      salida1 = fopen("salida1.txt","w"); 
      fprintf(salida1,"%d\n",SIGNAL_LENGTH);  
      fprintf(salida1,"Ciclos: %f\n",(float)(final - comienzo)); 
      for(i=0;i<SIGNAL_LENGTH;i++)
        fprintf(salida1,"%f\n",salida[i]);
      fclose(salida1);
      #endif

    #else    
      //printf("\n======================CASO DELTA======================\n");
    
    
      ini_fir(coeficientes);

      for(i = 0; i<SIGNAL_LENGTH; i++)
          salida[i]=fir(deltaIn[i]);
   
      #ifndef OPTIM 
      // imprimo salida en archivo
      FILE* salida2;
      salida2 = fopen("salida2.txt","w"); 
      fprintf(salida2,"%d\n",SIGNAL_LENGTH);
      fprintf(salida2,"Ciclos: %f\n",(float)(final - comienzo));     
      for(i=0;i<SIGNAL_LENGTH;i++)
        fprintf(salida2,"%f\n",salida[i]);
      fclose(salida2);
      #endif

    #endif
    //printf("\n======================FIR 2======================\n");

    #if ESC
      //printf("\n======================CASO ESCALON======================\n");
        
      ini_fir_sol(coeficientes);
    
      for(i = 0; i<SIGNAL_LENGTH; i++)
        salida[i]=fir_sol(escalonIn[i]);
   
      #ifndef OPTIM
      // imprimo salida en archivo
      FILE* salida_sol1;
      salida_sol1 = fopen("salida_sol1.txt","w"); 
      fprintf(salida_sol1,"%d\n",SIGNAL_LENGTH);
      fprintf(salida_sol1,"Ciclos: %f\n",(float)(final - comienzo));     
      for(i=0;i<SIGNAL_LENGTH;i++)
        fprintf(salida_sol1,"%f\n",salida[i]);
      fclose(salida_sol1);
      #endif
    
    #else
      //printf("\n======================CASO DELTA======================\n");

      ini_fir_sol(coeficientes);
    
      for(i = 0; i<SIGNAL_LENGTH; i++)
        salida[i]=fir_sol(deltaIn[i]);
    
      #ifndef OPTIM
      FILE* salida_sol2;
      salida_sol2 = fopen("salida_sol2.txt","w"); 
      fprintf(salida_sol2,"%d\n",SIGNAL_LENGTH);
      fprintf(salida_sol2,"Ciclos: %f\n",(float)(final - comienzo));     
      for(i=0;i<SIGNAL_LENGTH;i++)
        fprintf(salida_sol2,"%f\n",salida[i]);
      fclose(salida_sol2);
      #endif

    #endif
    //printf("\n======================FIR 3======================\n");

    #if ESC
      //printf("\n======================CASO ESCALON======================\n");
    
      ini_fir_NC(coeficientes);
   
      for(i = 0; i<SIGNAL_LENGTH; i++)
          salida[i]=fir_NC(&escalonIn[i]);
    
      #ifndef OPTIM
      // imprimo salida en archivo
      FILE* salida1_NC;
      salida1_NC = fopen("salida1_NC.txt","w"); 
      fprintf(salida1_NC,"%d\n",SIGNAL_LENGTH);  
      fprintf(salida1_NC,"Ciclos: %f\n",(float)(final - comienzo)); 
      for(i=0;i<SIGNAL_LENGTH;i++)
        fprintf(salida1_NC,"%f\n",salida[i]);
      fclose(salida1_NC);
      #endif

    #else
      //printf("\n======================CASO DELTA======================\n");
    
      ini_fir_NC(coeficientes);

      for(i = 0; i<SIGNAL_LENGTH; i++)
          salida[i]=fir_NC(&deltaIn[i]);

      #ifndef OPTIM
      // imprimo salida en archivo
      FILE* salida2_NC;
      salida2_NC = fopen("salida2_NC.txt","w"); 
      fprintf(salida2_NC,"%d\n",SIGNAL_LENGTH);
      fprintf(salida2_NC,"Ciclos: %f\n",(float)(final - comienzo));     
      for(i=0;i<SIGNAL_LENGTH;i++)
        fprintf(salida2_NC,"%f\n",salida[i]);
      fclose(salida2_NC);
      #endif
    #endif
}
