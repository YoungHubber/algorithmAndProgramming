/*
 *  Store part of the input file in a matrix
 */

#include <stdio.h>
#include <string.h>

#define C 100+1
#define R     5
#define L  20+1

int readRow (char [], FILE *);
int checkO (char [][C]);
int checkV (char [][C]);
void copyRow (char [][C], char []);
void clean (char [][C], int i);           //clean row i

int
main (
  int argc,
  char *argv[]
  )
{
  FILE *fp;
  char row[C], mat[R][C];
  int i, no, nv;

  if (argc!=2) {
    fprintf (stderr, "Wrong number of parameter.\n");
    return (1);
  }

  /* open files */
  fp = fopen (argv[1], "r");
  if (fp == NULL) {
    printf("Error while opening the files\n");
    return (1);
  }

  /* clean matrix */
  for (i=0; i<R; i++) {
    clean (mat, i);
  }

  /* process file */
  no = nv = 0;
  while (readRow (row, fp) == 1) {      //读一行
    copyRow (mat, row);                 //把此行copy进，5行100列的矩阵最后一行
    no += checkO (mat);                 //mat 5行  check mat 最后一行（新来的一行）
    nv += checkV (mat);                   //check 当前矩阵（5行）
  }

  fclose (fp);

  printf ("%d\n", no);
  printf ("%d\n", nv);

  //system ("pause");

  return (0);
}

int
readRow (
  char row[C],
  FILE *fp
  )
{
  int i;

  if (fgets (row, C, fp) == NULL) {
    return (0);
  }

  for (i=strlen (row); i<C; i++) {
    row[i] = ' ';
  }

  return (1);
}

void
copyRow (
  char mat[R][C],
  char row[C]
  )
{
  int i, j;

  /* up-shift one Row */                 //uuuuuuussssssss
  for (i=0; i<R-1; i++) {                    //把i行清掉，下一行复制上来
    clean (mat, i);          //清i行
    for (j=0; j<C; j++) {         //i下面的行向上移动
      mat[i][j] = mat[i+1][j];
    }
  }

  /* copy new row */
  clean (mat, R-1);              //最后一行是R-1
  for (j=0; j<C; j++) {
    mat[i][j] = mat[i+1][j];
  }

#if 0
  printf ("\n");
  for (i=0; i<R; i++) {
    printf ("%s", mat[i]);
  }
#endif

  return;
}

int
checkO (
  char mat[R][C]
  )
{
  int i, n;

  n = 0;
  for (i=0; i<=C-R; i++) {                  //R==5
    if (mat[R-1][i]=='h' && mat[R-1][i+1]=='h' && mat[R-1][i+2]=='h' &&     //R-1 对最后一行处理
      mat[R-1][i+3]=='h' && mat[R-1][i+4]=='h') {
      n++;
    }
  }

  /*printf ("o = %d\n", n);*/

  return (n);
}

int
checkV (
  char mat[R][C]
  )
{
  int i, n;

  n = 0;
  for (i=0; i<C; i++) {
    if (mat[0][i]=='v' && mat[1][i]=='v' && mat[2][i]=='v' &&
      mat[3][i]=='v' && mat[4][i]=='v') {
      n++;
    }
  }

  /*printf ("v = %d\n", n);*/

  return (n);
}

void
clean (
  char mat[R][C],
  int i
  )
{
  int j;

  for (j=0; j<C; j++) {
    mat[i][j] = ' ';
  }

  return;
}
