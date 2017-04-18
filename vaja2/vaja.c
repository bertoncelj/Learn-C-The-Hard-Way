#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 20

void die (const char *message){

    if(errno){
        perror(message);
    } else {
        printf("ERROR: %s \n", message);
    }
    exit(1);
}

void printAll(int *num, int size){
    
    int i;
    printf("\nVse vnesena stevila:\n");
    
    for(i = 0; i < size; i++){
        printf("%d ", num[i]);
    }    
    printf("\n");
}

int *scanNum(int *num, int size){
    
    int i , number;
  
    printf("Vnesite stevila (do %d): \n", size);
   
    for (i = 0 ; i < size; i++ ) {
        scanf("%d", &number );
        num[ i ] = number;
    }
    
    printAll(num, size);

    return num;
}

int *sort_bubble(int *num, int size) {

    int i, j;
    int temp,check  = 1;
    
    int *target = malloc(size* sizeof(int));
    
    do {
        check = 0;
        for(i = 0; i < size; i++){
            if(target[i+1] < target[i]){
                temp = target[i+1];
                target[i+1] = target[i];
                target[i]  = temp;
                check = 1;
            }
        }
    }while(check == 1);
    
return target;
}
int sizeNum() {

    int size;
    printf("Koliko stevil zelite vnesti ? \n");
    scanf("%d",&size);
    
    if(!size) die("You must entered one or more numbers");
    if(size == MAX_SIZE) die("You must entered to much numbers, max is 20!");
    
    return size;
}
void do_something(int *numbers){
    
    printf("do_something 1: %d\n",&numbers);
    int size = sizeNum();
    /* Main malloc */
    numbers = scanNum(numbers, size);
    
    if(!numbers) die("ERROR: Fail to insert numbers!");
     
    int *sorted = sort_bubble(numbers, size);
    
    printf("Presortiran string: \n");
    printAll(sorted, size);
    
    free(sorted);
}

int main (int argc, char *argv[]) {
   
    int *numbers = malloc(MAX_SIZE * sizeof(int));
    printf("main 1: %d\n",&numbers);
    do_something(numbers);
    
    free(numbers);

return 0;
}
