#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct element_s{
    int key;
    struct element_s *next;
}element_t;

listVisitVerIte(element_t *);

int main()
{
    int i;
    int v[N]={1,3,5,7,9,11,8,6,4,2};
    element_t *p,*head;

    //list creation
    head=NULL;

    for(i=0;i<N;i++){
        p=malloc(sizeof(element_t));

        if(p=NULL){
            fprintf(stderr,"Memory allocation error!\n");
            exit(EXIT_FAILURE);
        }

        p->key=v[i];
        p->next=head;
        head=p;

    }

    printf("List: \n");
    listVisitVerIte(head);


    return 0;
}

listVisitVerIte(element_t *head){
    element_t *p;
    p=head;
    while(p!=NULL){
        printf("%d ",p->key);
        p=p->next;
    }

}
