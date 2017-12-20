#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINESIZE 100
#define MAX_WORDSIZE 20
#define SUCCESS  0
#define FAILURE -1
#define FALSE 0
#define TRUE  1

void subText (char [], FILE *, char [], FILE *);
void subStringReplace (char [], char [], char [], char []); 

int
main (
  int argc,
  char *argv[]
  )
{
  FILE *fpR, *fpW;

  if (argc!=5) {
    fprintf (stderr, "Wrong number of parameter.\n");
    return (1);
  }

  fpR = fopen(argv[2], "r");
  fpW = fopen(argv[4], "w");
  if (fpR==NULL || fpW==NULL) {
    printf("One or both of the files does not exist\n");
    return FAILURE;
  }

  subText (argv[1], fpR, argv[3], fpW);

  fclose (fpR);
  fclose (fpW);

  return (SUCCESS);
}

void
subText (
  char from[MAX_WORDSIZE+1],
  FILE *fpR,
  char to[MAX_WORDSIZE+1],
  FILE *fpW
  )
{
  char buff[MAX_LINESIZE+1];
  char s[MAX_LINESIZE+1];

  while (fgets (buff, MAX_LINESIZE, fpR) != NULL) {
    subStringReplace (buff, from, to, s);
    fprintf (fpW, "%s", s);
  }

  return;
}

void
subStringReplace (
  char s1[],
  char s2[], 
  char s3[],
  char s4[] 
  )
{
  char *start, *end;

  s4[0] = '\0';
  start = s1;
  do {
    end = strstr (start, s2);
    if (end == NULL) {
      strcat (s4, start);
    } else {
      *end = '\0';
      strcat (s4, start);
      strcat (s4, s3);
      start = end + strlen (s2);
    }
  } while (end != NULL);

  return;
}
