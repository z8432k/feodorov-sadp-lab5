#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "include/sort.h"

#define ARR_SIZE 150
#define MAX_VAL 50

static void initArr(size_t size, unsigned int *arr) {
  srand((unsigned) time(NULL));
  for (size_t i = 0; i < size; i++) {
    arr[i] = rand() % MAX_VAL;
  }
}

void dispSort(size_t n, unsigned int m, unsigned int *arr) {
  unsigned int *arr2 = (unsigned int *) calloc(m, sizeof(unsigned int));

  for (size_t i = 0; i < n; i++) {
    arr2[arr[i]] = arr2[arr[i]] + 1;
  }

  size_t k = 0;
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < arr2[i]; j++) {
      arr[k] = i;
      k++;
    }
  }

  free(arr2);
}

int main(void) {
  printf("== Distribution Sort implementation. ==\n\n");

  unsigned int arr[ARR_SIZE];

  initArr(ARR_SIZE, arr);

  dispSort(ARR_SIZE, MAX_VAL, arr);

  size_t counter = 0;
  for (size_t i = 0; i < ARR_SIZE; i++) {
    printf("%d\t", arr[i]);

    if (counter++ == 4) {
      printf("\n");
      counter = 0;
    }
  }

  exit(EXIT_SUCCESS);
}
