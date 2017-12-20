#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibonacciR(int );
int fibonacciI(int );

int main()
{
    int n=50;
    int i;
    for(i=0;i<n;i++){
        //printf("the %dth fibonacciR is %d\n",i,fibonacciR(i));
        //printf("the %dth fibonacciI is %d\n",i,fibonacciI(i));
    }
    printf("1.618 power of %d %f ",n,pow(1.618,n));
    return EXIT_SUCCESS;
}

int fibonacciR(int n){
    if(n==0||n==1){
        return n;
    }
    return (fibonacciR(n-1)+fibonacciR(n-2));

}

int fibonacciI(int n){                //return n1 and do the last 2 calculate
    int n1,n2,n3,i;
    n1=0;
    n2=1;
    for(i=0;i<=n;i++){
        n3=n1+n2;
        n1=n2;
        n2=n3;
    }
    return n1;

}
