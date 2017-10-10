#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows;
    int i,j;
    int length;

    printf("enter the row of half_triangle.\n");
    scanf("%d",&rows);
    for(j=1; j<=rows; j++)
    {
        for(i=1; i<=j; i++)
        {
            printf("%d ",i);

        }
        printf("\n");
    }


    return 0;
}
