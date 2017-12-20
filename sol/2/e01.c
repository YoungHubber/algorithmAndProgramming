/*
 *  Solution with functions
 *  (prototypes, calls, and definitions)
 */

#include <stdio.h>

#define MAX 10

/* function prototypes */
void readDim(int *, int *);
int checkDim(int, int, int, int);
void readMatrix(float [][MAX], int, int);
void computeProduct(float [][MAX], int, int,
                    float [][MAX], int, int,
                    float [][MAX], int *, int *);
void writeMatrix(float [][MAX], int, int,
                 float [][MAX], int, int,
                 float [][MAX], int, int);

/*
 *  main program
 */
int main(void)
{
  float m1[MAX][MAX], m2[MAX][MAX], m3[MAX][MAX];
  int r1, c1, r2, c2, r3, c3;

  /* read matrix size */
  printf("First  matrix size:\n");
  readDim(&r1, &c1);
  printf("Second matrix size:\n");
  readDim(&r2, &c2);

  /* check-out size */
  if (checkDim(r1, c1, r2, c2) == 0) {
    printf("Not compatible dimensions!\n");
  } else {
    /* read matrix */
    printf("Input first  matrix:\n");
    readMatrix(m1, r1, c1);
    printf("Input second matrix:\n");
    readMatrix(m2, r2, c2);
   
    computeProduct(m1, r1, c1, m2, r2, c2, m3, &r3, &c3);
    writeMatrix(m1, r1, c1, m2, r2, c2, m3, r3, c3);
  }
  return 0;
}

/* 
 *  read matrix size
 */
void readDim(int *rp, int *cp)
{
  do {
    printf("  Number of rows: ");
    scanf("%d", rp);
    printf("  Number of columns: ");
    scanf("%d", cp);
  } while (*rp<=0 || *rp>MAX || *cp<=0 || *cp>MAX);
}

/* 
 *  check matrix sizes: return 0 if they are compatible for product
 */
int checkDim(int r1, int c1, int r2, int c2)
{
  if (c1 == r2) {
    return 1;
  } else {
    return 0;
  }
}

/* 
 *  matrix input
 */
void readMatrix(float matrix[MAX][MAX], int r, int c)
{
  int i, j;

  for (i=0; i<r; i++) {
    for (j=0; j<c; j++) {
      printf("  Element [%d,%d] = ", i+1, j+1);
      scanf("%f", &matrix[i][j]);
    }
  }
}

/* 
 *  compute the matrix product
 */
void computeProduct(
  float m1[MAX][MAX], int r1, int c1,
  float m2[MAX][MAX], int r2, int c2,
  float m3[MAX][MAX], int *r3p, int *c3p
)
{
  int i, j, k;

  *r3p = r1;
  *c3p = c2;

  for (i=0; i<r1; i++) {
    for (j=0; j<c2; j++) {
      m3[i][j] = 0;
      for (k=0; k<c1; k++) {
        m3[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}

/* 
 *  display the product result
 */
void writeMatrix(
  float m1[MAX][MAX], int r1, int c1,
  float m2[MAX][MAX], int r2, int c2,
  float m3[MAX][MAX], int r3, int c3
)
{
  int i, j;

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
