/* 
 * File:   main.c
 * Author: juanignaciobraun
 *
 * Created on April 30, 2013, 8:40 PM
 */

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
    ITEM* datos;
    h = (HEAP*)malloc(sizeof(HEAP));
    printf("arguments: %d\n",argc);
    
    //LEO ENTRADA
    FILE* inFile = fopen("/Users/juanignaciobraun/codeJIB/C/Ipol/Modulo5/entradas/entrada1","r" );
    fscanf(inFile,"%d\n", &size);
    
    printf("size= %d\n",size);
    
    int entrada[size];
    int i;
    for(i=0;i<size;i++){
        fscanf(inFile,"%d\n",&aux);
        entrada[i] = aux;
    }
    
    //IMPRIMO ENTRADA
    printf("Entrada\n");
    for(i=0;i<size;i++)
        printf("%d\n",entrada[i]);
    
    
    //GUARDO ENTRADA EN ARRAY DE ITEMS
    datos = (ITEM*)malloc(size*sizeof(ITEM));
    for(i=0;i<size;i++){
        datos[i].value=entrada[i];
        datos[i].label = i;
    }
    
    sort(datos,size);
   
    printf("Entrada\n");
    for(i=0;i<size;i++)
        printf("%d\n",datos[i].value);
    
    ITEM* min;
    min = find_minimum(datos,size);
    printf("Min = %d\n", min->value);
    
    //INICIALIZO HEAP
    heap_init(h,size);
    
    //CHEQUEO ESTADO HEAP
    estadoHeap = heap_isEmpty(h);
    printf("HEAP VACIO: %d\n", estadoHeap);
    
    //LLENO HEAP
//    build_heap(h,datos,size);
    build_heap_lin(h,datos,size);
    
    
    
    //VUELVO A CHEQUEAR ESTADO HEAP
    estadoHeap = heap_isEmpty(h);
    printf("HEAP VACIO: %d\n", estadoHeap);
    
    estadoHeap = heap_isFull(h);
    printf("HEAP LLENO: %d\n", estadoHeap);
    
    //IMPRIMO HEAP LLENO
    printHeap(h);
    printf("\nIndice: %d\n",(int)h->index);
    while(h->index>=0){
      //SACO DEL HEAP EL ITEM MAS CHICO
      ITEM* a; 
      a = heap_extractMin(h);
    
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
    }
    
}

