#include <stdio.h>
#include <stdlib.h>

typedef struct list_s{
    int key;
    struct List_s *next;
}list_t;                                 //define struct list (sst)

list_t *newELement();
listVisit();

int main()
{
    list_t *p;
    p=newELement();                       //call for new list node

    return 0;
}

list_t *newELement(){                      //new
    list_t *ePtr;

    ePtr = (list_t *)malloc(sizeof(list_t));

    if(ePtr=NULL){
        fprintf(stderr,"memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    return (ePtr);
}

listVisit(){
    list_t *p;
    #p=head;
    while(p!=NULL){
        p = p->next;
    }                            //waiting to enhance list bulid?
}



