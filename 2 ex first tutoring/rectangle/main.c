#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    int n;
    int r,c;
    int v[SIZE];

    printf("Enter the rectangle size \n");
    scanf("%d",&n);

    for(r=0;r<n;r++){
        if(r%2==1){
            for(c=0;c<n;c++){
                printf("%d ",c+1);
            }
            printf("\n");
        }else{
            for(c=0;c<n;c++){
                v[c]=c+1;
            }
            for(c=n;c>0;c--){
                 printf("%d ",v[c]);
            }


        }
    }
    return 0;
}
