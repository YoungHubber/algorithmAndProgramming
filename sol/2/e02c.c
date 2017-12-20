/*
 *  Store part of the input file in a matrix
 *  Deal with matrix rows as strings
 */

#include <stdio.h>
#include <string.h>

#define C 100+1
#define R     5
#define L  20+1

int checkO (char []);
int checkV (char [][C]);
void copyRow (char [][C], char []);
void clean (char []);

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
    clean (mat[i]);
  }
  
  /* process file */
  no = nv = 0;
  while (fgets (row, C, fp) != NULL) {
    copyRow (mat, row);
    no += checkO (row);
    nv += checkV (mat);
  }

  fclose (fp);

  printf ("%d\n", no);
  printf ("%d\n", nv);
  
  /*system ("pause");*/
  
  return (0);
}

void
copyRow (
  char mat[R][C],
  char row[C]
  )
{
  int i;

  /* up-shift one Row */
  for (i=0; i<R-1; i++) {
    clean (mat[i]);
    strcpy (mat[i], mat[i+1]);
  }

  /* copy new row */
  clean (mat[R-1]);  
  strcpy (mat[R-1], row);

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
  char row[C]
  )
{
  int i, n;

  n = 0;
  for (i=0; i<=strlen(row)-R; i++) {
    if (row[i]=='h' && row[i+1]=='h' && row[i+2]=='h' &&
      row[i+3]=='h' && row[i+4]=='h') {
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
  char row[]
  )
{
  int i;
  
  for (i=1; i<C; i++) {
    row[i] = ' ';
  }
  row[0] = '\0';
  
  return;
}
