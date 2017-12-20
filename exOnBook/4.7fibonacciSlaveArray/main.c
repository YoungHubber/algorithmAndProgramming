#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n,int *known);

int main(void)
{
    int *known,i,n;
    n=50;
    known = (int *)malloc((n+1)*sizeof(int));

    if(known==NULL){
        printf("MA error.\n");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<=n;i++){
        known[i]=-1;
    }

    fibonacci(n,known);
    for(i=0;i<=n;i++){
        printf("the %dth fibonacci num is %d\n",i,known[i]);
    }


    free(known);

    return EXIT_SUCCESS;
}

int fibonacci(int n,int *known){
    if(known[n]<0){
        if(n==0||n==1){
            known[n]=n;
        }else{
            known[n]=fibonacci(n-1,known)+fibonacci(n-2,known);
        }
    }
    return known[n];
}
