#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 5

int main()
{
    int mat1[R][C]= { {9,23, 155,   -1, 33},
        {0, -2,   -4,   8,  -6},
        {20, -1,   0,   0, 499}
    };
    int mat2[R][C];
    int i,j,k;

//    for (i=0; i<R; i++)
//    {
//        for (j=0; j<C; j++)
//        {
//            printf("  m1[%d,%d] = ", i+1, j+1);
//            scanf("%d", &mat1[i][j]);
//        }
//    }

    for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
        {
            if(mat1[i][j]==0)
            {
                mat2[i][j]=0;
            }
            else if(mat1[i][j]<0)
            {
                mat2[i][j]=1;
                for(k=-mat1[i][j]; k>=1; k--)
                {
                    mat2[i][j]=mat2[i][j]*k;
                }
            }
            else if(mat1[i][j]>0)
            {
                mat2[i][j] = 1;
                while (mat2[i][j]<mat1[i][j])
                {
                    mat2[i][j] = mat2[i][j] * 10;
                }
            }
        }
    }



    printf("  m2:\n");
    for (i=0; i<R; i++)
    {
        for (j=0; j<C; j++)
        {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
