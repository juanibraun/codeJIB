#include "dijkstra.h"

#define INF 2147483647

void init_source(ITEM* g, int s, int size){
    int i;
    for(i=0;i<size;i++){
        g[i].label= i;
        g[i].id= i;
        g[i].value = INF ;
//        g[i].label = i;
//        g[i].value = INF;
//        g[i].nodo = &G->nodes[i];
    }
    
    g[s].value= 0;
    
}

void relax(HEAP* G, ITEM* u, ITEM* v, int cost){
    if(v->value > u->value + cost){
      v->value = u->value + cost; 
      move_up(G,v->label);
     
    }
}

void dijkstra(HEAP* G, ITEM* g, int start, int finish, int* costs){
    
 int size = G->size;
    ITEM S[size];
    ITEM pred[size];
    ITEM path[size];
    ITEM* u;
    ITEM *v;
    int i = 0;
    int j,w;
    int k = 1;
    
    
    init_source(g,start,size);

    
    build_heap_lin(G,g,size);
    
    while(heap_isEmpty(G)!=1){
        u = heap_extractMin(G);
        S[i] = *u;
//        printf("id: %c\t cost: %d\n\n",u->id,u->value);

        
        i++;
        for(j=0;j<G->size;j++){
            w = costs[size*(u->id)+j];
            if(w<INF || w==0){
                 if(g[j].value > u->value + w){
                         g[j].value = u->value + w; 
                         move_up(G,g[j].label);
                         pred[j] = *u;
                 }
      
//            printf("DEST id: %c cost: %d\n",g[j].id,g[j].value);
//            printf("PREV id: %c cost: %d\n",pred[j].id,pred[j].value);
                   
            }       
        }    
    }
   printf("\nCostos\n");
   for(j=0;j<size;j++)
        printf("id: %c\t cost: %d\n",S[j].id+65,S[j].value);
   
   printf("\nPrevios\n");
   for(j=0;j<size;j++)
        printf("id: %c\t cost: %d\n",pred[j].id+65,pred[j].value);
   
   path[0] = g[finish];
   i = finish;
   while(g[i].id!=start){
       i = pred[i].id;
       path[k] = g[i];
       k++;
   }
   printf("CAMINO\n");
   for(j=k-1;j>=0;j--)
        printf("id: %c\t cost: %d\n",path[j].id+65,path[j].value);
}

void dijkstra2(int size, ITEM* g, int start, int finish, int* costs){
    
    
    ITEM S[size];
    ITEM pred[size];
    ITEM path[size];
    ITEM* u;
    ITEM *v;
    int i = 0;
    int j,w;
    int k = 1;
    int label;
    
    
    init_source(g,start,size);

    
//    build_heap_lin(G,g,size);
//    
//       for(j=0;j<size;j++)
//        printf("id: %c\t cost: %d\n",g[j].id+65,g[j].value);

    while(i<size){
        sort(g,size);
//        for(j=0;j<size;j++)
//                printf("id: %c\t cost: %d\n",g[j].id+65,g[j].value);
        u = &g[i];
        S[i] = *u;
        
//        printf("id: %c\t cost: %d\n\n",u->id+65,u->value);

        
        i++;
        for(j=0;j<size;j++){
            label = g[j].id;
            S[label] = g[j];
            w = costs[size*(u->id)+label];
            if(w<INF){
                 if(g[j].value > u->value + w){
                         v = &g[j];
                         v->value = u->value + w; 
                         pred[label] = *u;
                         S[label] = *v;
                         
                 }
      
//            printf("DEST id: %c cost: %d\n",g[j].id+65,g[j].value);
//            printf("PREV id: %c cost: %d\n",pred[label].id+65,pred[label].value);
                   
            }       
        }    
    }
//   printf("\nCostos\n");
//   for(j=0;j<size;j++)
//        printf("id: %c\t cost: %d\n",S[j].id+65,S[j].value);
//   
//   printf("\nPrevios\n");
//   for(j=0;j<size;j++)
//        printf("id: %c\t cost: %d\n",pred[j].id+65,pred[j].value);
   
   
   
   path[0] = S[finish];
   i = finish;
   while(S[i].id!=start){
       i = pred[i].id;
       path[k] = S[i];
       k++;
   }
   printf("CAMINO\n");
   for(j=k-1;j>=0;j--)
        printf("id: %d\t cost: %d\n",path[j].id+65,path[j].value);
}
