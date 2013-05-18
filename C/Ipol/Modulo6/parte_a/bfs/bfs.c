#include "bfs.h"
#include <stdio.h>


void dfs_rec(tree* t, node* n){
    
    if(n->first_child==NULL){
         printf("%d\n",n->id);
    }else{
        n=n->first_child;
        dfs_rec(t,n);  
        while(n->next_sibling){
              n = n->next_sibling;
              dfs_rec(t,n);             
        }
        n = n->parent;
        printf("%d\n",n->id);
    }    
}

void dfs_it(tree* t, node* n) {
    int i;
    int k;
    int r;
    k = t->n;
    r = k-1;
    node * open[k];
    node * closed[k];
    int openE;
    int closedE;
    open[r] = n;
    openE = 1;
    closedE = 0;
    while(openE>0){
        openE--;
        closed[r-closedE] = open[r-openE];
        closedE++;
      
        if(open[r-openE]->first_child){
            open[r-openE] = open[r-openE]->first_child;
            openE++;
            while(open[r-openE+1]->next_sibling){
                open[r-openE] = open[r-openE+1]->next_sibling;
                openE++;
            }     
        }
                
    }
    for(i=0;i<k;i++)
        printf("%d\n", closed[i]->id);
        
   
}
