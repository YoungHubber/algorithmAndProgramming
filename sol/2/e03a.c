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
int searchSubStr(char [], char [], int);

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

  subText (argv[1], fpR, argv[3], fpW);            //传argv用char []

  fclose (fpR);
  fclose (fpW);

  return (SUCCESS);
}

void
subText (
  char from[MAX_WORDSIZE+1],        //字符数组使用时多一位for'/0'
  FILE *fpR,
  char to[MAX_WORDSIZE+1],
  FILE *fpW
  )
{
  char buff[MAX_LINESIZE+1];
  char s[MAX_LINESIZE+1];

  while (fgets (buff, MAX_LINESIZE, fpR) != NULL) {             //读 replace 写文件
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
  int i, idx, from, to, endFlag;

  /* computation and output */
  endFlag = from = idx = 0;
  do {
    to = searchSubStr(s1, s2, from);
    if (to < 0) {
      to = strlen(s1);
      endFlag = 1;
    }
    for (i=from; i<to; i++) {
      s4[idx] = s1[i];
      idx++;
    }
    if (endFlag == 0) {
      for (i=0; i<strlen(s3); i++) {
        s4[idx] = s3[i];
        idx++;
      }
    }
    from = to+strlen(s2);
  } while (endFlag != 1);

  s4[idx] = '\0';
  return;
}

/*
 *  search a sub-string
 */
int searchSubStr(char str1[], char str2[], int from)      //在str1中找str2，从from开始
{
  int i, j, flag;
  
  i = from;
  while (i < strlen(str1)-strlen(str2)) {
    flag = j = 0;
    while (j<strlen(str2) && flag==0) {
      if (str1[i+j] != str2[j]) {
        flag = 1;
      }
      j++;
    }
    if (flag == 0) {
      return i;
    }
    i++;
  } 
  return -1;
}

