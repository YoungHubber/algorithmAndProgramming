/*
 *  Store the input file in an array one line at a time
 */

#include <stdio.h>
#include <string.h>

#define C 100+1
#define L  20+1

int readRow (char [], FILE *);
int checkO (char []);
int checkV (char [], int []);

int
main (
  int argc,
  char *argv[]
  )
{
  FILE *fp;
  char row[C];
  int count[C];    //counter array for vertical checking
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

  /* reset counters */
  for (i=0; i<C; i++) {
    count[i] = 0;
  }

  /* process file */
  no = nv = 0;
  while (readRow (row, fp) == 1) {          //fgets读行的函数用法
    no += checkO (row);
    nv += checkV (row, count);
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
    return (0);                        //读到空行，末尾行
  }

  for (i=strlen (row); i<C; i++) {
    row[i] = ' ';
  }

  return (1);                          //读一行，并把后面的元素至空格
}

int
checkO (
  char row[C]
  )
{
  int i, n;

  n = 0;
  for (i=0; i<=C-5; i++) {                 //i from 0 to c-5
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
  char row[C],
  int count[C]
  )
{
  int i, n;

  n = 0;
  for (i=0; i<C; i++) {
    if (row[i]!='v') {
      count[i] = 0;
      } else {
      count[i]++;
      if (count[i]>=5) {
        n++;
      }
    }
  }

  /*printf ("v = %d\n", n);*/

  return (n);
}
