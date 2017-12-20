#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 10

void arrayVisitR_v1(int [],int * ,int * ,int start);
void arrayVisitR_v2(int * ,int * ,int *,int );

int main()
{
    int v[N]={1,3,5,7,9,11,8,6,4,2};
    int min,max;

    min=INT_MAX;
    max=INT_MIN;

    printf("Array : \n");
    arrayVisitR_v1(v,&min,&max,0);
    printf("\n");
    printf("min = %d\n",min);
    printf("max = %d\n",max);

    min=INT_MAX;
    max=INT_MIN;

    printf("Array : \n");
    arrayVisitR_v2(&v[0],&min,&max,0);
    printf("\n");
    printf("min = %d\n",min);
    printf("max = %d",max);

    return EXIT_SUCCESS;
}

void arrayVisitR_v1(int v[],int *min,int *max,int token){
    if(token>=N){
        return;
    }

    printf("%d ",v[token]);

    if(v[token]<*min){
        *min=v[token];
    }

    if(v[token]>*max){
        *max=v[token];
    }

    arrayVisitR_v1(v,min,max,token+1);         //min max is var of address

    return;

}


void arrayVisitR_v2(int *v,int *min,int *max,int token){
    if(token>=N){
        return;
    }

    printf("%d ",*v);

    if((*v)< *min){
        *min=*v;
    }

    if((*v)> *max){
        *max=*v;
    }

    arrayVisitR_v2(v+1,min,max,token+1);         //min max is var of address

    return;

}

