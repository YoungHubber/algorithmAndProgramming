#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 100

int main()
{
    float m1[MAX_DIM][MAX_DIM],m2[MAX_DIM][MAX_DIM],m3[MAX_DIM][MAX_DIM];
    int r1,c1,r2,c2,r3,c3,i,j,k;

    printf("Input logical size r1 c1\n");
    scanf("%d %d",&r1,&c1);
    if(r1<=0||r1>MAX_DIM||c1<=0||c1>MAX_DIM){
        printf("Invalid dim\n");
    }

    printf("Input logical size r2 c2\n");
    scanf("%d %d",&r2,&c2);
    if(r2<=0||r2>MAX_DIM||c2<=0||c2>MAX_DIM){
        printf("Invalid dim\n");
    }
    if(c1!=r2){
        printf("Unable to compute the product\n");
    }

    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            printf("Input element [%d][%d]\n",i+1,j+1);
            scanf("%f",&m1[i][j]);
        }
    }

    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            printf("Input element [%d][%d]\n",i+1,j+1);
            scanf("%f",&m2[i][j]);
        }
    }

    r3 = r1;
    c3 = c2;
    for (i=0; i<r1; i++) {
      for (j=0; j<c2; j++) {
        m3[i][j] = 0;
        for (k=0; k<c1; k++) {
          m3[i][j] += m1[i][k] * m2[k][j];
        }
      }
    }

        for (i=0; i<r3; i++) {
      for (j=0; j<c3; j++) {
        printf("%7.2f ", m3[i][j]);
      }
      printf("\n");
    }

    return 0;
}
