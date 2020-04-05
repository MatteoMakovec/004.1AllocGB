#include <stdio.h>
#include <stdlib.h>

#define ONE_GIGABYTE (1024 * 1024 * 1024L)  // definendo un valore come long estendo la definizione
                                            // di long a tutta la costante

int main(void) {
  unsigned long alloc_test[] = {ONE_GIGABYTE, ONE_GIGABYTE * 10, ONE_GIGABYTE * 100, ONE_GIGABYTE * 1000, -1};
  unsigned long *ptr = alloc_test;   // equivalente a scrivere *ptr = &alloc_test[0]
  
  printf("\nalloc_test[4] = %lu \t(valore di -1 in unsigned long)\n\n", alloc_test[4]);

  while(*ptr != -1){
    printf("provo ad allocare %lu GB...", *ptr / ONE_GIGABYTE);
    char *test = malloc(*ptr);

    if(test == NULL){
      printf("richiesta malloc: fallita!\n");
    }
    else{
      printf("richiesta malloc: OK\n");
    }
    free(test);
    ptr++;        // avanzamento di puntatore, ovvero vado a puntare la cella di memoria successiva
  }

  return 0;
}