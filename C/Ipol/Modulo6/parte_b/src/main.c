/* 
 * File:   main.c
 * Author: juanignaciobraun
 *
 * Created on May 13, 2013, 7:28 PM
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
   
    node nodos[h];
    tree t;
    t.n = h;
    t.nodes = nodos;
    
    
    
}

