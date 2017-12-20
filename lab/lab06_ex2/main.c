#include <stdio.h>
#include <stdlib.h>

typedef struct record{
    char *name;
    char id[17];
    char data[11];
    int salary;
    struct record *left;
    struct record *right;
}record_t


record_t *readFile(record_t *,char[] );


int main(int argc,char *argv[])
{
    FILE *fp;
    fp=fopen(argv[1],"r");
    if(fp==NULL){
        fprintf(stderr,"Error opening the file.\n");
    }



    return 0;
}

record_t *readFile(record_t *head,char *fileIn){
    FILE *input;
    char line[MAX_R];name[MAX];



}

