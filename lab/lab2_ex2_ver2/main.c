#include <stdio.h>
#include <stdlib.h>

#define C 100+1
#define R 5
#define L 20+1

int readRow(char [],FILE *);
int checkO (char [][C]);
int checkV (char [][C]);
void copyRow(char [][C], char []);
void clean (char [][C], int);



int main(int argc,char *argv[])
{
    FILE *fp;
    char row[C], mat[R][C];
    int i, no, nv;

    if(argc!=2){
        fprintf(stderr,"Wrong number of parameter.\n");
        return (1);
    }

    //open files
    fp=fopen(argv[1],"r");
    if(fp==NULL){
        printf("Error while opening the files\n");
        return 1;
    }

    //clean matrix
    for (i=0; i<R; i++){
        clean(mat, i);
    }

    //process file
    no = nv = 0;
    while(readRow(row, fp)==1){
        copyRow(mat,row);
        no+=checkO(mat);
        nv+=checkV(mat);
    }

    fclose(fp);

    printf("%d\n",no);
    printf("%d\n",nv);

    return 0;
}

int readRow(char row[C],FILE *fp){
    int i;

    if(fgets(row, C, fp) == NULL){
        return 0;
    }

    for (i=strlen(row);i<C;i++){
        row[i] = ' ';
    }

    return 1;
}

void copyRow(char mat[R][C],char row[C]){
    int i,j;

    //up shift
    for (i=0; i<R-1; i++){
        for (j=0; j<C; j++){
        clean(mat, i);
            mat[i][j] = mat[i+1][j];
        }
    }

    //copy new row
    clean (mat, R-1);
    for (j=0; j<C; j++){
        mat[i][j] = mat[i+1][j];
    }

    return;
}

int checkO(char mat[R][C]){
    int i, n;

    n = 0;
    for(i=0; i<=C-R; i++){
        if( mat[R-1][i]=='h' && mat[R-1][i+1]=='h' && mat[R-1][i+2] && mat[R-1][i+3]=='h'&&mat[R-1][i+4]=='h'){
            n++;
        }
    }
    return n;
}

int checkV(char mat[R][C]){
    int i,n;

    n=0;
    for(i=0;i<C;i++){
        if(mat[0][i]=='v'&&mat[1][i]=='v'&&mat[2][i]=='v'&&mat[3][i]=='v'&&mat[4][i]=='v'){
            n++;
        }
    }
    return n;
}

void clean (char mat[R][C], int i){
    int j;
    for(j=0;j<C;j++){
        mat[i][j]=' ';
    }
    return;
}
