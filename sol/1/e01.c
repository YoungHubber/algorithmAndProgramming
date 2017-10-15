#include <stdio.h>

#define DIM 15

int main(void)
{
  int i, posMax, lengthMax, length;
  int array[DIM];

  /* array initialization */
  for (i=0; i<DIM; i++) {
    printf("Input v[%d]: ", i);
    scanf("%d", &array[i]);
  }

  posMax = length = 0;
  lengthMax = 1;
  /* max length search */
  for (i=0; i<DIM; i++) {
    if (i<DIM-1 && array[i]<array[i+1]) {
      length++;
    } else {
      if (length > lengthMax) {
        lengthMax = length + 1;
        posMax = i - length;
      }
      length = 0;
    }
  }

  /* output result */
  printf("Longest positive sequence (start at element %d): ", posMax);
  for (i=posMax; i<posMax+lengthMax; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
