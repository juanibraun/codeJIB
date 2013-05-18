/* 
 * File:   main.c
 * Author: juanignaciobraun
 *
 * Created on May 14, 2013, 10:08 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "../tree/tree.h"
#include "../bfs/bfs.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    tree T;
    read_tree(argv[1], &T);
    tree_print(&T);
    tree_print_dot(&T);
    dfs_rec(&T,T.root);
    dfs_it(&T,T.root);
}
