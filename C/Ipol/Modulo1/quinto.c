#include <stdio.h>
#include "auxiliares.h"

int main(){
  int a=7;
  int b=8;
  int c=maximo(a,b);
  printf("El maximo entre %d y %d es: %d\n",a,b,c);
  c=minimo(a,b);
  printf("El minimo entre %d y %d es: %d\n",a,b,c);
}

/*int maximo(int a, int b){
  if(a>b){
    return a;
  }else{
    return b;
  }
}*/
