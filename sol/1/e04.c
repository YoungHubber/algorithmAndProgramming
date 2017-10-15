#include <stdio.h>

#define MAX 10

int main(void)
{
  float m1[MAX][MAX], m2[MAX][MAX], m3[MAX][MAX];
  int i, j, k, r1, c1, r2, c2, r3, c3;

  /* read matrix size */
  printf("First  matrix size:\n");
  do {
    printf("  Number of rows: ");
    scanf("%d", &r1);
    printf("  Number of columns: ");
    scanf("%d", &c1);
  } while (r1<=0 || r1>MAX || c1<=0 || c1>MAX);
  printf("Second matrix size:\n");
  do {
    printf("  Number of rows: ");
    scanf("%d", &r2);
    printf("  Number of columns: ");
    scanf("%d", &c2);
  } while (r2<=0 || r2>MAX || c2<=0 || c2>MAX);

  /* check-out size */
  if (c1 != r2) {
    printf("Not compatible dimensions!\n");
  } else {
    /* read matrix */
    printf("Input first  matrix:\n");
    for (i=0; i<r1; i++) {
      for (j=0; j<c1; j++) {
        printf("  Element [%d,%d] = ", i+1, j+1);
        scanf("%f", &m1[i][j]);
      }
    }
    printf("Input second matrix:\n");
    for (i=0; i<r2; i++) {
      for (j=0; j<c2; j++) {
        printf("  Element [%d,%d] = ", i+1, j+1);
        scanf("%f", &m2[i][j]);
      }
    }

    /* 
     *  compute the matrix product
     */
    r3 = r1;
    c3 = c2;
    for (i=0; i<r1; i++) {
      for (j=0; j<c2; j++) {
        m3[i][j] = 0;
        for (k=0; k<c1; k++) {
          m3[i][j] += m1[i][k] * m2[k][j];
        }
      }
    }

    /* 
     *  display the product result
     */
    for (i=0; i<r1; i++) {
      for (j=0; j<c1; j++) {
        printf("%7.2f ", m1[i][j]);
      }
      printf("\n");
    }
    printf("*\n");
    for (i=0; i<r2; i++) {
      for (j=0; j<c2; j++) {
        printf("%7.2f ", m2[i][j]);
      }
      printf("\n");
    }
    printf("=\n");
    for (i=0; i<r3; i++) {
      for (j=0; j<c3; j++) {
        printf("%7.2f ", m3[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
