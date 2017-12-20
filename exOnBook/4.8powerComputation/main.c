#include <stdio.h>
#include <stdlib.h>

int powerI(int ,int );
int powerR(int ,int );

int main()
{
    int x=5;
    int n=3;

    printf("%d power of %d is %d\n",x,n,powerI(x,n));
    printf("%d power of %d is %d\n",x,n,powerR(x,n));
    return 0;
}

int powerI(int x,int n){
    int i;
    int power=1;
    for(i=0;i<n;i++){
        power=power*x;
    }
    return power;
}

int powerR(int x,int n){
    if(n<=0){
        return 1;
    }

    return x*powerR(x,n-1);
}
