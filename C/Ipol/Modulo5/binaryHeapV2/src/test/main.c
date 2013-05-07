/* 
 * File:   main.c
 * Author: juanignaciobraun
 *
 * Created on April 30, 2013, 8:40 PM
 */
#define PR
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heap.h"

/*
 * 
 */

int main(int argc, char** argv) {

    int size,aux;
    int estadoHeap;
    HEAP* h;
    h = (HEAP*)malloc(sizeof(HEAP));
    printf("arguments: %d\n",argc);
    
    //LEO ENTRADA
    FILE* inFile = fopen(argv[1],"r" );
    fscanf(inFile,"%d\n", &size);
    
    printf("size= %d\n",size);
    
    int entrada[size];
    int i;
    for(i=0;i<size;i++){
        fscanf(inFile,"%d\n",&aux);
        entrada[i] = aux;
    }
    
    #ifndef PR
    //IMPRIMO ENTRADA
    printf("Entrada\n");
    for(i=0;i<size;i++)
        printf("%d\n",entrada[i]);
    #endif
    
    //GUARDO ENTRADA EN ARRAY DE ITEMS
    ITEM datos[size];
    for(i=0;i<size;i++){
        datos[i].value=entrada[i];
    }
   
    ITEM* min;
    min = find_minimum(datos,size);
    #ifndef PR
    printf("Min = %d\n", min->value);
    #endif

    //INICIALIZO HEAP
    heap_init(h,size);
    
    //CHEQUEO ESTADO HEAP
    estadoHeap = heap_isEmpty(h);
    #ifndef PR
    printf("HEAP VACIO: %d\n", estadoHeap);
    #endif
    
    //LLENO HEAP
    build_heap_lin(h,datos,size);
    //build_heap(h,datos,size);   

    #ifndef PR
    //VUELVO A CHEQUEAR ESTADO HEAP
    estadoHeap = heap_isEmpty(h);
    printf("HEAP VACIO: %d\n", estadoHeap);
    
    estadoHeap = heap_isFull(h);
    printf("HEAP LLENO: %d\n", estadoHeap);
    #endif
    
    //IMPRIMO HEAP LLENO
    #ifndef PR
    printHeap(h);
    printf("\nIndice: %d\n",(int)h->index);
    #endif

    while(h->index>=0){
      //SACO DEL HEAP EL ITEM MAS CHICO
      ITEM* a; 
      a = heap_extractMin(h);
    
      #ifndef PR
      //IMPRIMO EL VALOR DEL ITEM QUE SAQUE
      printf("\nVALOR: %d\n",a->value);
      
      //IMPRIMO HEAP
      printHeap(h);
      printf("\nIndice: %d\n",(int)h->index);
      //VUELVO A CHEQUEAR ESTADO
      estadoHeap = heap_isEmpty(h);
      printf("HEAP VACIO: %d\n", estadoHeap);
    
      estadoHeap = heap_isFull(h);
      printf("HEAP LLENO: %d\n", estadoHeap);
      #endif
    }
    
    heap_delete(h);
    
}

