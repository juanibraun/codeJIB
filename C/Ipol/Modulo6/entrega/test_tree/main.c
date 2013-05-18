/* 
 * File:   main.c
 * Author: juanignaciobraun
 *
 * Created on May 13, 2013, 7:28 PM
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * 
 */
int main(char** argv) {

    
    int size;
    int aux;
    //LEO ENTRADA
    FILE* inFile = fopen(argv[1],"r" );
    fscanf(inFile,"%d\n", &size);
    
    printf("size= %d\n",size);
    
    int entrada[size*size];
    int grado[size];
    int hist[size];
    int i;
    int j;
    for(i=0;i<size;i++){
        grado[i]=0;
        for(j=0;j<size;j++){
           fscanf(inFile,"%d ",&entrada[j+size*i]); 
           grado[i] += entrada[j+size*i];
        }
        fscanf(inFile,"\n",&aux);    
    }
    
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
           printf("%d ",entrada[j+size*i]); 
        }
        printf("\n");    
    }
    
    printf("GRADO\n");
    for(i=0;i<size;i++)
        printf("%d ",grado[i]);
    printf("\n");
    
    for(i=0;i<size;i++)
        hist[i] = 0;
    
    for(i=0;i<size;i++)
        hist[grado[i]]++;
    
    printf("HISTOGRAMA\n");
    for(i=0;i<size;i++)
        printf("%d ",hist[i]);
    printf("\n");
    
   
}

