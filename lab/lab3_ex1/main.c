#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILTER_MAX_WORDS 100
#define WORD_LENGTH 20
#define FIRST_FILE_ROW_LENGTH 100

typedef struct _wordCounter{
    char word[WORD_LENGTH];
    int counter;
}wordCounter;

int main()
{

    wordCounter filter[FILTER_MAX_WORDS];

    FILE *firstFile;
    FILE *secondFile;

    int i=0;
    int filterWords=0;


    secondFile = fopen("second file.txt","r");
    if(secondFile==NULL){
        fprintf(stderr,"Can't open second file.\n");
    }

    while(fscanf(secondFile,"%s",filter[filterWords].word)!=EOF){
        filterWords++;
    }

    fclose(secondFile);


    //filter words to upper
    int j=0;
    for(i=0;i<filterWords;i++){
        while(filter[i].word[j]){
            filter[i].word[j]=toupper(filter[i].word[j]);
            j++;
        }
        j=0;
    }

    firstFile = fopen("first file.txt","r");
    if(firstFile==NULL){
        fprintf(stderr,"Can't open first file.\n");
    }

//    char row[FIRST_FILE_ROW_LENGTH];
    char currentWord[WORD_LENGTH];


    //to upper
//    i=0;
//    while(fgets(row,FIRST_FILE_ROW_LENGTH,firstFile)!=NULL){
//        while(sscanf(row,"%s",currentWord)!=EOF){
//            /*while(currentWord[i]){
//            currentWord[i]=toupper(currentWord[i]);
//            i++;
//        }*/
//        i=0;
//        }
//
//
//    }
for(i=0;i<filterWords;i++){
    filter[i].counter=0;
}
i=0;
while(fscanf(firstFile,"%s",currentWord)!=EOF){
    while(currentWord[i]){
        currentWord[i]=toupper(currentWord[i]);
        i++;
    }
    i=0;
    for(j=0;j<filterWords;j++){
        if(strcmp(currentWord,filter[j].word)==0){
            filter[j].counter++;
        }
    }
}
fclose(firstFile);

for(i=0;i<filterWords;i++){
    printf("%s - %d occurrence(s).\n",filter[i].word,filter[i].counter);
}




    return EXIT_SUCCESS;
}

//get one row in first file
//search every words occ in second file,plus counter of words in second file
//print the counter

