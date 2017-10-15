/*
 *  Solution with functions
 *  (prototypes, calls, and definitions)
 */

#include <stdio.h>

#define R 3
#define C 5

int fact (int);
int power (int);

int main(void)
{
  int m1[R][C], m2[R][C];
  int i, j;

  for (i=0; i<R; i++) {
    for (j=0; j<C; j++) {
      printf("  m1[%d,%d] = ", i+1, j+1);
      scanf("%d", &m1[i][j]);
    }
  }

  for (i=0; i<R; i++) {
    for (j=0; j<C; j++) {
      if (m1[i][j]==0) {
        m2[i][j] = 0;
      } else {
        if (m1[i][j]>0) {
          m2[i][j] = power (m1[i][j]);
        } else {
          m2[i][j] = fact (-m1[i][j]);
        }
      }
    }
  }

  printf("  m2:\n");
  for (i=0; i<R; i++) {
    for (j=0; j<C; j++) {
      printf("%d ", m2[i][j]);
    }
    printf("\n");
  }

  return (0);
}

int fact (
  int n
  )
{
  int i, f;

  f = 1;
  for (i=n; i>0; i--) {
    f = f * i;
  }

  return (f);
}

int power (
  int n
  )
{
  int p;

  p = 1;
  while (p<n) {
    p = p * 10;
  }

  return (p);
}
