#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINESIZE 100
#define MAX_WORDSIZE 20
#define SUCCESS 0
#define FAILURE -1
#define FALSE 0
#define TRUE 1

void subText (char [], FILE *,char [],FILE *);
void subStringReplace (char [],char [],char [],char []);
int searchSubStr(char [],char [],int );

int main(int argc,char *argv[])
{
    FILE *fpR, *fpW;

    if(argc!=5){
        printf("Error parameters.\n");
        return 1;
    }

    fpR = fopen(argv[2],"r");
    fpW = fopen(argv[4],"w");

    if (fpR == NULL || fpW ==NULL){
        printf("One or both of the file does not exit \n");
        return FAILURE;
    }

    subText(atgv[1],fpR,argv[3],fpW);

    fclose(fpR);
    fclose(fpW);

    return SUCCESS;
}

void subText(char from[MAX_WORDSIZE+1],FILE *fpR,char to[MAX_WORDSIZE+1],FILE *fpW){
    char buff[MAX_LINESIZE+1];
    char s[MAX_LINESIZE+1];

    while (fgets(buff, MAX_LINESIZE, fpR)!=NULL){
        subStringReplace(buff, from, to, s);
        fprintf(fpW, "%s", s);
    }

    return;
}

void subStringReplace(char s1[],char s2[],char s3[],char s4[]){

}

int searchSubStr(char s1[],char s2[],int from){
    int i,j;
    int flag=0;
    j=0;
    for(i=0;i<strlen(s1)-strlen(s2);i++){
        for(j=0;j<strlen(s2);j++){
            if(s1[i+j]!=s2[i+j]){
                flag=1;
            }
        }

    }
}
