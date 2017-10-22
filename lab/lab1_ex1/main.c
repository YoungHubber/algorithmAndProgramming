#include <stdio.h>
#include <stdlib.h>

#define DIM 15

int main()
{
    int i,j,t;
    int posMax;
    int length=0;
    int lengthMax=0;

    int array[DIM]= {2,3,4,-1,-10,5,6,8,11,-9,8,-10,9,3,0};

//    int array[DIM];
//
//    printf("Input array:\n");
//    for(i=0;i<DIM;i++){
//        printf("array[%d]= ",i);
//        scanf("%d",&array[i]);
//    }

    for(i=0; i<DIM; i++)
    {
        for(j=i+1; j<DIM; j++)
        {
            if(array[j]>=array[j-1])
            {
                length++;
            }
            else
            {
                break;
            }

        }
        if(length>=lengthMax)
        {
            posMax=i;
            lengthMax=length;
        }
        length=0;
    }

    for(t=posMax; t<=posMax+lengthMax; t++)
    {
        printf("%d ",array[t]);
    }
    return EXIT_SUCCESS;
}
