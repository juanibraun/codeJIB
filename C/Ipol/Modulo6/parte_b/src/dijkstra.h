#include "tree.h"
#include "heap.h"
#include <stdlib.h>

void init_source(tree* G, node* s);

void relax(node* u, node* v, int cost);

void dijkstra(tree* t, node* n, int* costs);
