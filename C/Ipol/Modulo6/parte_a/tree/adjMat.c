#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Funcion que genera matrices de adyacencia

se llama como:

./adjMat 7 1 ./entrada0

el primer argumento es el tamano de la matriz
el segundo es una bandera para hacer que la matriz sea simetrica(1 simetrica, 0 no simetrica)
el tercero es el archivo a escribir

*/
int main(int argc, char** argv) {

  int size = atoi(argv[1]);
  int i;
  int j;
    
  printf("arguments: %d\n",argc);
  printf("size = %d\n",size);

  
  FILE* inFile = fopen(argv[3],"w" );
  fprintf(inFile,"%d\n", size);
  
  if(atoi(argv[2]) == 0){
  for(i=0;i<size;i++){
      for(j=0;j<size;j++){
          fprintf(inFile,"%d ",rand()%2); 
      }
      fprintf(inFile,"\n");
  }
  }else if(atoi(argv[2]) == 1){
      int mat[size*size];
      for(i=0;i<size;i++){
	for(j=i;j<size;j++){
          if(i==j){
             mat[j+i*size] = 0;
          }else{
	  mat[j+i*size] = rand()%2;
          mat[i+j*size] =  mat[j+i*size];
          }
        }
      }
    for(i=0;i<size;i++){
      for(j=0;j<size;j++){
          fprintf(inFile,"%d ",mat[j+i*size]); 
      }
      fprintf(inFile,"\n");
    }
  }else{
    fprintf(inFile,"ERROR DE ENTRADA");
  }

  fclose(inFile);
      
}
