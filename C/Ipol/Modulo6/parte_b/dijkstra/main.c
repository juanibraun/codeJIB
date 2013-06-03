/* 
 * File:   main.c
 * Author: juanignaciobraun
 *
 * Created on May 28, 2013, 8:51 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"
#include "dijkstra.h"
#include "tree.h"


int main(int argc, char** argv) {

    
    int h;
    int w;
    h = argc;
    char Start,Finish;
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
    
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
           printf("%d ",costos[j+w*i]); 
        }
        printf("\n");    
    }
   
    fclose(inFile);
    
    Start = getc(stdin);
    Finish = getc(stdin);
    start = Start - 65;
    finish = Finish - 65;
    
    HEAP* t;
    t = (HEAP*)malloc(sizeof(HEAP)); 
    heap_init(t,h);
    ITEM nodos[h];
    
    dijkstra(t, nodos, start, finish, costos);
    heap_delete(t);
    dijkstra2(h, nodos, start, finish, costos);
    
    
}





