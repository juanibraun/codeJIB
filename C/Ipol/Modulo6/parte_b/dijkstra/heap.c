
#include "heap.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

extern int heap_isEmpty(HEAP *h){
    if (h->index<0){
        return 1;
    }else{ 
        return 0;
    }
}

extern int heap_isFull(HEAP*h){
    if(h->index +1 == h->size){
        return 1;
    }else{
        return 0;
    }
}

extern int heap_init(HEAP* h, long size){
    if (h==NULL){
      return 2;
    }else{
    h->size = size;
    h->index = -1;
    h->data=(ITEM**)malloc(size*sizeof(ITEM*));
    if (h->data==NULL){
      return 3;
    }else{
      return 1;
    }
    }
}

extern void heap_delete(HEAP* h){
    free(h->data);
    free(h);
}

extern int heap_addItem(HEAP* h, ITEM* p){
    if(h->index +1 >= h->size){
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

extern ITEM* find_minimum(ITEM* nodes, int n){
    int i;
    ITEM* aux;
    ITEM* min = nodes;
    for (i = 0; i < n; i++) {
        aux = nodes + i;
        if (aux->value < min->value) {
            min = aux;

        }
    }
  return min;
}

void sort(ITEM* nodes, int n) {
    int j;
    ITEM* min;
    ITEM temp;
    for (j = 0; j < n; j++) {
        min = find_minimum(nodes + j, n - j);
        temp = nodes[j];
        nodes[j].value = min->value;
        nodes[j].id = min->id;
        nodes[min->label].id = temp.id;
        nodes[min->label].value = temp.value;
//        printf("min: %d\t label: %d\n",nodes[j].value,nodes[j].label);
    }

}

extern void build_heap_lin(HEAP* h, ITEM* nodes,int n){
    int i;
    h->size = n;
    h->index = n-1;
    
    for(i=0;i<n;i++){
        h->data[i]= nodes+i;
    }
    for(i = floor((n-1)/2); i>=0; i--){
        move_down(h,i);
    } 
        
}

extern void build_heap(HEAP* h, ITEM* nodes,int n){
    int i;
    h->size = n;
    for(i=0;i<n;i++)
        heap_addItem(h, nodes + i);
}

void move_up(HEAP* h, int i){
    int p = parent(i);
    
    if((p>=0) && (h->data[p]->value > h->data[i]->value)){
       swap(h, i, p);
       move_up(h,p);
    }       
}

void move_down(HEAP* h, int i){
    int l = left(i);
    int r = right(i);
    int min;
    
    if((l<=h->index) && (h->data[l]->value < h->data[i]->value)){
           min = l;
    }else{
        min =i;
    }
    if((r<=h->index)&&(h->data[r]->value < h->data[min]->value)){
             min = r;
    }
    if (min != i){
        swap(h, i, min);
        move_down(h,min);    
    }
}
void swap(HEAP* h, int i, int j){
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

void printHeap(HEAP* h){
  int i,j,k;
  k=0;
    printf("\n============HEAP============\n");
    for(i=0;i<=log2(h->size);i++){
      for(j=0;j<pow(2,i);j++){
          if(k>h->index){
                printf("%s ","X");    
          }else{
                printf("%d ",h->data[k]->value);
	  }
          k++;
      }
      printf("\n");
    }
   /*
   printf("\n============LISTA============\n");
   for(i=0;i<=h->index;i++){
       printf("value: %d\t label: %d\n",h->data[i]->value,h->data[i]->label);
   }
   */
}
