
#include "heap.h"
#include <math.h>
#include <stdlib.h>

extern int heap_isEmpty(HEAP *h){
    if (h->index<0){
        return 1;
    }else{ 
        return 0;
    }
}

extern int heap_isFull(HEAP*h){
    if(h->index == h->size + 1){
        return 1;
    }else{
        return 0;
    }
}

extern int heap_init(HEAP* h, long size){
    h->size = size;
    h->index = -1;
    h->data=(ITEM**)malloc(size*sizeof(ITEM*));
}

extern void heap_delete(HEAP* h){
    int i;
    for (i=0; i<h->size; i++)
        free(h->data[i]);
    free(h->data);
}

extern int heap_addItem(HEAP* h, ITEM* p){
    
    if(h->index +1 == h->size){
        return 1;
    }else{
        h->index+=1;
        h->data[h->index] = p;
        p->label = h->index;
        move_up(h, h->index);
        return 0;
    }
}

extern void heap_updateItem(HEAP* h, ITEM *p){
    
    move_up(h,p->label);
    move_down(h,p->label);
    
}

extern ITEM* heap_extractMin(HEAP* h){

    ITEM* aux;
    aux = heap_queryMin(h);
    swap(h, 0, h->index);
    h->index -= 1;
    move_down(h, 0);
    return aux;
}

extern ITEM* heap_queryMin(HEAP* h){
    return h->data[0];
}

extern ITEM* find_minimum(ITEM* nodes, int n);

static void move_up(HEAP* h, int i){
    int p = parent(i);
    
    if((p>=0) && (h->data[p]->value > h->data[i]->value)){
       swap(h, i, p);
       move_up(h,p);
    }       
}

static void move_down(HEAP* h, int i){
    int l = left(i);
    int r = right(i);
    int min;
    
    if((l<=h->size) && (h->data[l]->value < h->data[i]->value)){
        min = l;
    }else{
        min = i;
    }
    if((l<=h->size) && (h->data[r]->value < h->data[min]->value)){
        min = r;
    }
    if (min != i){
        swap(h, i, min);
        move_down(h,min);
        
    }
}
static void swap(HEAP* h, int i, int j){
    ITEM* aux;
    int auxLabel;
    
    aux = h->data[i];
    h->data[i] = h->data[j];
    h->data[j] = aux;

    auxLabel = h->data[i]->label;
    h->data[i]->label = h->data[j]->label;
    h->data[j]->label = auxLabel;
    
    
}

int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
int parent(int i){
    return floor((i-1)/2);
}