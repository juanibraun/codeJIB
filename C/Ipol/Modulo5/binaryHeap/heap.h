/* 
 * File:   heap.h
 * Author: juanignaciobraun
 *
 * Created on April 30, 2013, 8:42 PM
 */



typedef struct{
  int label;
  int value;  
} ITEM;

typedef struct{
   long size;
   long index;
   ITEM** data;
}  HEAP;


extern int heap_isEmpty(HEAP *h);
extern int heap_isFull(HEAP*h);
extern int heap_init(HEAP* h, long size);
extern void heap_delete(HEAP* h);
extern int heap_addItem(HEAP* h, ITEM* p);
extern void heap_updateItem(HEAP* h, ITEM *p);
extern ITEM* heap_extractMin(HEAP* h);
extern ITEM* heap_queryMin(HEAP* h);

extern ITEM* find_minimum(ITEM* nodes, int n);

static void move_up(HEAP* h, int i);
static void move_down(HEAP* h, int i);
static void swap(HEAP* h, int i, int j);
static int left(int i), right(int i), parent(int i);
