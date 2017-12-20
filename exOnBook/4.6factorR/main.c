#include <stdio.h>
#include <stdlib.h>

int factorR(int );

int main()
{
    int n=19;
    int resultR;
    int resultI;
    resultR=factorR(n);
    printf("the resultR is %d \n",resultR);
    resultI=factorI(n);
    printf("the resultI is %d \n",resultI);
    return 0;
}

int factorR(int n){
    if(n==0){
        return 1;
    }
    return(n*factorR(n-1));
}

int factorI(int n){
    int fact=1;
    int i;
    for(i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;

}
