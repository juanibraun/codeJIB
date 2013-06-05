/* 
 * File:   main.c
 * Author: juanignaciobraun
 *
 * Created on May 28, 2013, 8:51 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"



int main(int argc, char** argv) {

    
    int h;
    int w;
    h = argc;
    size_t nbytes = 5;
    char* Start = (char *) malloc (nbytes + 1);
    char* Finish = (char *) malloc (nbytes + 1);
    int start,finish;
    //LEO ENTRADA
    FILE* inFile = fopen(argv[1],"r" );
    fscanf(inFile,"%d %d\n", &h, &w);
    
    printf("size= %d %d\n",h,w);
    
    int costos[h*w];
    int i;
    int j;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++)
           fscanf(inFile,"%d ",&costos[j+w*i]); 
        fscanf(inFile,"\n");    
    }
    
    /*
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
           printf("%d ",costos[j+w*i]); 
        }
        printf("\n");    
    }
    */

    fclose(inFile);
    
    getline(&Start,&nbytes,stdin);
    getline(&Finish,&nbytes,stdin);
    start = atoi(Start);
    finish = atoi(Finish);
    
    HEAP* t;
    t = (HEAP*)malloc(sizeof(HEAP)); 
    heap_init(t,h);
    ITEM nodos[h];
    
    dijkstra(t, nodos, start, finish, costos);
    heap_delete(t);
    dijkstra2(h, nodos, start, finish, costos);
    
    
}





