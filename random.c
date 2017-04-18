#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Books{
    char title[50];
    char author[30];
    char subject[20];
    int id;
};

void StructSwitch(struct Books book);
void printBook(struct Books book);

void Increment(int *a){
    *a = *a + 1;
    printf("In function:address: %ld \t value:%d \n",(int) a , *a);
    
}

void StructSwitch(struct *Books book){

    book->title = "hodor";
    book->author = "JJ";
    book->subject = 
}

void printBook(struct Books book){

    printf("Title: %s\n",book.title);
    printf("Author: %s\n",book.author);
    printf("Subject: %s \n",book.subject);
    printf("ID: %d \n",book.id);

}

void printArray(int *A, int size){

    int i;
    for (i = 1; i < size; i++){
        printf("Address: %d \n", (A + i));
        printf("Address: %d \n", &A[i]);
        printf("Vlaue: %d \n", A[i]);
        printf("Value: %d \n", *(A+i));
    }
}

/* MAIN */
int main(int argc, char* argv[]){
   
   struct Books Book1;
   int A[] = {1,2,3,4,5,6,7,8,9,0};
   int i; 
   int num = 10;
   Increment(&num);
   printf("main function: %d \t address: %d \n",num, &num);
   
   struct Books book2;
   StructSwitch(&book2);
   
   Book1.id = 10;
   printf("Struct st %d\n",Book1.id);
    
    int size = sizeof(A) / sizeof(int);
    printf("Array size: %d \t Size:%d \n",sizeof(A), sizeof(int));
    /* TODO  */
    
    printArray(&A,size);
    
    
return 0;
}
