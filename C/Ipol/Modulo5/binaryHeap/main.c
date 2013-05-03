/* 
 * File:   main.c
 * Author: juanignaciobraun
 *
 * Created on April 30, 2013, 8:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/*
 * 
 */

void printHeap(HEAP* h){
    int i;
    printf("\n============HEAP============\n");
    for(i=0;i<=h->index;i++){
        printf("value: %d\tlabel: %d\n",h->data[i]->value,h->data[i]->label);
    }
}
int main(int argc, char** argv) {

    int size,aux;
    HEAP h;
    
    
    FILE* inFile = fopen("/Users/juanignaciobraun/codeJIB/C/Ipol/Modulo5/binaryHeap/entrada","r" );
    fscanf(inFile,"%d\n", &size);
    
    printf("size= %d\n",size);
    
    int entrada[size];
    int i;
    for(i=0;i<size;i++){
        fscanf(inFile,"%d\n",&aux);
        entrada[i] = aux;
    }
    
    printf("Entrada\n");
    for(i=0;i<size;i++)
        printf("%d\n",entrada[i]);
    
    
    ITEM datos[size];
    for(i=0;i<size;i++){
        datos[i].value=entrada[i];
    }
    heap_init(&h,size);
    
    int estadoHeap;
    estadoHeap = heap_isEmpty(&h);
    printf("HEAP VACIO: %d\n", estadoHeap);
    
    heap_addItem(&h,&datos[3]);
    heap_addItem(&h,&datos[2]);
    heap_addItem(&h,&datos[1]);
    heap_addItem(&h,&datos[6]);
    heap_addItem(&h,&datos[9]);
    heap_addItem(&h,&datos[7]);
    heap_addItem(&h,&datos[4]);
    heap_addItem(&h,&datos[8]);
    heap_addItem(&h,&datos[10]);
    heap_addItem(&h,&datos[15]);
    heap_addItem(&h,&datos[0]);
    heap_addItem(&h,&datos[14]);
    heap_addItem(&h,&datos[11]);
    heap_addItem(&h,&datos[13]);
    heap_addItem(&h,&datos[12]);
    heap_addItem(&h,&datos[5]);
    
    estadoHeap = heap_isEmpty(&h);
    printf("HEAP VACIO: %d\n", estadoHeap);
    
    estadoHeap = heap_isFull(&h);
    printf("HEAP LLENO: %d\n", estadoHeap);
    printHeap(&h);
    
    ITEM* a;
    
    a = heap_extractMin(&h);
    
    printf("\nVALOR: %d\n",a->value);
    
    printHeap(&h);
    
    estadoHeap = heap_isEmpty(&h);
    printf("HEAP VACIO: %d\n", estadoHeap);
    
    estadoHeap = heap_isFull(&h);
    printf("HEAP LLENO: %d\n", estadoHeap);
    
    datos[4].value=20;
    
    heap_updateItem(&h,&datos[4]);
    
    printHeap(&h);
    
    estadoHeap = heap_isEmpty(&h);
    printf("HEAP VACIO: %d\n", estadoHeap);
    
    estadoHeap = heap_isFull(&h);
    printf("HEAP LLENO: %d\n", estadoHeap);
    
    
}

