#include <stdio.h>
#include <stdlib.h>

#define DIM 100

int main()
{
    int N1=10;
    int N2=2;
    int i,j,n;
    int v1[DIM]= {0,2,3, 4, -1, -10, 5, 1, 8, 3 };
    float v2[DIM];


//    printf("Input N1:\n");
//    scanf("%d",&N1);
//    if(N1>DIM)
//    {
//        printf("Input N1<=%d",DIM);
//    }
//
//    printf("Input N2:\n");
//    scanf("%d",&N2);
//    if(N2>DIM)
//    {
//        printf("Input N2<=%d",DIM);
//    }

//    for(i=0;i<N1;i++){
//        printf("v1[%d]= ",i);
//        scanf("%d",&v1[i]);
//    }

    for (i=0; i<N1; i++)
    {
        v2[i] = 0;
        n = 0;
        for (j=-N2; j<=N2; j++)
        {
            if ((i+j)>=0 && (i+j)<N1)                //bound checking
            {
                v2[i] = v2[i] + v1[i+j];
                n++;
            }
        }
        v2[i] = v2[i] / n;
    }

    printf("v2: ");
    for (i=0; i<N1; i++)
    {
        printf("%.2f ", v2[i]);
    }
    printf("\n");




    return 0;
}
