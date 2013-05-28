#include "dijkstra.h"

#define INF 2147483647

void init_source(tree* G, node* s){
    int i;
    for(i=0;i<G->n;i++){
        G->nodes[i].id = INF;
        G->nodes[i].parent = NULL ;
    }
    
    s->id = 0;
    
}

void relax(node* u, node* v, int cost){
    if(v->id > u->id + cost){
      v->id = u->id + cost; 
      v->parent = u;
    }
}

void dijkstra(tree* t, node* s, int* costs){
    init_source(t,s);
    
}
