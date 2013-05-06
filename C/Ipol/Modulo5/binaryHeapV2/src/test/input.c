/* 
 * File:   main.c
 * Author: juanignaciobraun
 *
 * Created on April 30, 2013, 8:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
 * 
 */

int main(int argc, char** argv) {

  int size = atoi(argv[1]);
  int i;
    
  printf("arguments: %d\n",argc);
  printf("size = %d\n",size);

  
  FILE* inFile = fopen(argv[2],"w" );
  fprintf(inFile,"%d\n", size);
  
  for(i=0;i<size;i++)
    fprintf(inFile,"%d\n",rand()%99); 

  fclose(inFile);
      
}

