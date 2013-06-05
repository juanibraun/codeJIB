#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

void init_source(ITEM* G, int s, int size);

void relax(HEAP* G, ITEM* u, ITEM* v, int cost);

void dijkstra(HEAP* G, ITEM* g, int start, int finish, int* costs);

void dijkstra2(int size, ITEM* g, int start, int finish, int* costs);
