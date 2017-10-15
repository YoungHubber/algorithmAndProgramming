#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int main(void)
{
  int n1, n2, i, j, n;
  float v1[DIM], v2[DIM];

  /* array initialization */
  printf("N1: ");
  scanf("%d", &n1);
  printf("N2: ");
  scanf("%d", &n2);
  if (n1<0 || n2<0 || n1>DIM || n2>DIM) {
    printf("Wrong values.\n");
    exit (1);
  }
  for (i=0; i<n1; i++) {
    printf("v1[%d]: ", i);
    scanf("%f", &v1[i]);
  }

  /* max length search */
  for (i=0; i<n1; i++) {
    v2[i] = 0;
    n = 0;
    for (j=-n2; j<=n2; j++) {
      if ((i+j)>=0 && (i+j)<n1) {
        v2[i] = v2[i] + v1[i+j];
        n++;
      }
    }
    v2[i] = v2[i] / n;
  }

  /* output result */
  printf("v2: ");
  for (i=0; i<n1; i++) {
    printf("%.2f ", v2[i]);
  }
  printf("\n");

  return 0;
}
