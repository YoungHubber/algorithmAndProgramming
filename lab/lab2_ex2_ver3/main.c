#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 100+1
#define R 3
#define L 20+1

int checkO (char []);
int checkV (char [][C]);
void copyRow (char [][C], char []);
void clean ( char []);

int main(int argc ,char *argv[])
{
    FILE *fp;
    char row[C], mat[R][C];
    int i, no, nv;

    if(argc!=2){
        fprintf(stderr,"Wrong number of parameter.\n");
        return 1;
    }

    //open files
    fp = fopen(argv[1], "r");
    if (fp==NULL){
        printf("Error while opening the files\n");
        return 1;
    }

    //clean matrix
    for (i=0; i<R; i++){
        clean(mat[i]);
    }

    //process file
    no = nv = 0;
    while(fgets (row, C, fp)!= NULL){
        copyRow(mat,row);
    }



    return 0;
}

void copyRow(char mat[R][C],char row[C]){
    int i;

    //up shift
    for(i=0;i<R-1;i++){
        clean(mat[i]);
        strcpy(mat[i],mat[i+1]);
    }

    //copy new row
    clean(mat[R-1]);
    strcpy(mat[R-1],row);
}

int checkO(char row[C]){
    int i, n;

    n=0;
    for(i=0;i<strlen(row)-R;i++){
        if(row[i]=='h'&&row[i+1])
    }
}





void clean( char row[]){
    int i;

    for(i=1;i<C;i++){
        row[i] = ' ';
    }

    row[0]='\0';

    return;
}
