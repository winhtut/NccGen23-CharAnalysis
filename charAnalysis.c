#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define ARRSIZE 1000 //symbolic constant
#define CHARSIZE 26
char arr[ARRSIZE];
char chararr[CHARSIZE]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int numArr[CHARSIZE]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int alphaToFile();
void fileReading();
int biggestIndex();
void writingDToFile(int index);
int main(){
    alphaToFile();
    fileReading();

    int biggest = biggestIndex();
    writingDToFile(biggest);

    printf("Hello");
    return 0;
}
int alphaToFile(){
    FILE *fptr0;
    fptr0 = fopen("alphabet.txt","w");
    fclose(fptr0);


    FILE *fptr;
    fptr = fopen("alphabet.txt","a+");
    srand(time(NULL));

    for(int i=0; i<ARRSIZE ; i++){
        char randNumber =rand()%26+97;//
        arr[i] = randNumber;
        if(fptr == NULL){
            printf("File Cannot Open!");

        } else{

            fprintf(fptr,"%c",randNumber);

        }

    }
    fclose(fptr);
}

void fileReading(){

    FILE *fptr;
    fptr = fopen("alphabet.txt","r");
    char c = getc(fptr);

    while (c!=EOF){

        for(int i=0; i<CHARSIZE ; i++){

            if(c ==chararr[i]) {
                numArr[i]++;
                break;
            }

        }
        c = getc(fptr);

    }

}

int biggestIndex(){

    int biggest=0;

    for(int i=0; i < CHARSIZE ; i++){

        if(numArr[i]>biggest){
            biggest = numArr[i];
        }


    }
    return biggest;

}

void writingDToFile(int index){

    FILE *fptr;
    fptr = fopen("alphabet.txt","w");
    fclose(fptr);

    FILE *fptr2;
    fptr2 = fopen("alphabet.txt","a");

    for(int x=0; x<index ; x++){//46
        char mychar =97;


        for(int j=0; j<=CHARSIZE ; j++){//26

            int numArrIndex = numArr[j];

            if(j==26){
                fprintf(fptr2 ,"%c",'\n');
            } else if( numArrIndex <= 0 ){
                fprintf(fptr2 ,"%c",' ');
                for(int k=0; k<4; k++){
                    fprintf(fptr2 ,"%c",' ');
                }
                mychar++;

            }else {
                fprintf(fptr2 ,"%c",mychar);
                for(int k=0; k<4; k++){
                    fprintf(fptr2 ,"%c",' ');
                }
                mychar++;
            }
            numArr[j] = numArr[j]-1;
        }

    }

}


