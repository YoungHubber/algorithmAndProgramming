#include <stdio.h>

#define R 3
#define C 5

int main(void)
{
  int m1[R][C], m2[R][C];
  int i, j, k;

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
          m2[i][j] = 1;
          while (m2[i][j]<m1[i][j]) {
            m2[i][j] = m2[i][j] * 10;
          }
        } else {
          m2[i][j] = 1;
          for (k=(-m1[i][j]); k>0; k--) {
            m2[i][j] = m2[i][j] * k;
          }
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

