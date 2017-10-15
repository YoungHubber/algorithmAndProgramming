#include <stdio.h>
#include <stdlib.h>

#define DIM 5

int main()
{
    int i,j;
    int counter=0;
    int max_accend=0;
    int index=0;

//    int array[DIM]={2,3,4,-1,-10,5,6,8,11,-9,8,-10,9,3,0};
    int array[DIM];

    printf("Input array:\n");
    for(i=0;i<DIM;i++){
        printf("array[%d]= ",i);
        scanf("%d",&array[i]);
    }

    for(i=0;i<DIM;i++){
        for(j=i+1;array[j]>array[i]&&j<DIM;j++){
            counter++;
        }
    if(counter>max_accend){
        max_accend=counter;
        index=i;
    }

    }

    for(i=index;i<i+max_accend;i++){
        printf("%d ",array[i]);
    }



    return 0;
}
