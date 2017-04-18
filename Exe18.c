#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>


/* Defein a function */
typedef int (*compare)(int a, int b);
typedef int *(*sortingSystem)(int *numbers, int count, int last,  compare cmp);

/*Function declart before*/
void print(int *numbers, int size, int low, int hig, int pivot);
int revers_order(int a, int b);
int sorted_order(int a, int b);
void sorting(int *numbers, int size, sortingSystem sortType, compare cmp);
void printEnd(int *numbers, int size);
void downheap (int *numbers, int size, int i);

/* Function to delete char */
void die(const char* message){

    if(errno){
        perror(message);
    }else{
        printf("ERROR: %s \n",message);
    }
    
    exit(1);
}
int ExpMath(int number, int exp){
    
    int i, rez;
    rez = number;
   if(exp == 0){
        return 0;
   }else{
        for(i = 1; i < exp; i++){
            rez = number * rez;
        }
    }
return rez;   
}
/***   HEAP DRAW  ***/
void space(int level){

    int i;
    int max = ExpMath(2,level) - 1;
    for(i = 0;i < max; i++){
        printf(" ");
    }
}
int abs(int a){
    
    if(a > 0){
        return a;
    }else return -a;
}

int piramida (int *numbers, int size){
   
    int i, j, a, ostk_num;
    int t, height, save = 0;
        
    printf("size: %d",size);
    /*Piramide stucture, height */
    i = 0;   
    while( 0 < size - ExpMath(2,i)){
        if(i > 10) die("V while zanki i ne gre več");
        ++i;
    }
    
    ostk_num = size - ExpMath(2,(i - 1));    
    ostk_num = abs(ostk_num);

    
    /* Presledki */
    height = i;
    printf("\n Height:%d\tostk_num:%d\n", height, ostk_num);
    i = 0;
    for(j = 0;j < height; j++){
        space(height-j-1);
        t = j;
        save = i + save;
        
        /* DRAWING */
        if(save == 0){
            printf("%d",numbers[0]);
            i++;
            printf("\n");
        } else {
            if(height-j == 1){
                for(i = 0; i <= (ostk_num);i++){
                     printf("%d",numbers[i + save]);
                     space(height-j);
                }
            }else{
                for(i = 0; i < (ExpMath(2,t));i++){               
                    printf("%d",numbers[i + save]);
                    space(height-j);
                }
            }
            printf("\n");
        }
    }
}

int *heap_swap(int *numbers, int i, int a){
    
    printf("swap:%d\t%d\t i=%d  a=%d\n",numbers[i],numbers[i*2+a], i, a);
    int temp;
    temp = numbers[i];
    numbers[i] = numbers[i*2 + a];
    numbers[i*2 + a] = temp;
 
return numbers;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int *heap_sort (int *target, int count, int first, compare cmp){

    int i, j, a, temp, end;
    /*
    if(count < 3) die("Too short lenght!\n More numbers!"); 
    
    int *numbers = malloc(sizeof(int) * (count+1));
    
    Check is memory is okidoky
    if(!numbers) die("Memory error!");
    
    memcpy(numbers, target, (count + 1)*sizeof(int));
    
    int size;
    int stev[] = {9,4};
    size = sizeof(stev) / sizeof(int);
    piramida(stev, size);
    size = size;
    for(i = 0; i < 10;i++){
        a = 1;
        while(a <= 2){
            if(stev[i*2 + a] < stev[i]){
                heap_swap(stev, i, a);
            }
        ++a;
        }
    }
    
    piramida(stev, size);
    //Build a heap
    printf("STARTEN! \n");
    printf("Size: %d \n", count);
    
    
    
    //sort arry


return numbers;
}
*/

int *heap_sort (int *numbers, int size, int first, compare cmp){
   
    int i;
    piramida(numbers, size);
    for (i = (size - 2) / 2; i >= 0; i--) {
        downheap(numbers, size, i);
    }
    for (i = 0; i < size; i++) {
        int temp = numbers[size - i - 1];
        numbers[size - i - 1] = numbers[0];
        numbers[0] = temp;
        downheap(numbers, size- i - 1, 0);
    }
    printf("\t\t----FINALE----\n\n");
    piramida(numbers, size);
return numbers;
}

void downheap (int *numbers, int size, int i) {

    while(1){
        int j = heap_max(numbers, size, i, 2 * i + 1, 2 * i + 2);
        if(j == i){
            break;
        }
       int temp = numbers[i];
       numbers[i] = numbers[j];
       numbers[j] = temp;
       i = j;
    }
}

int heap_max(int *numbers, int size, int i, int prva, int druga){

    int m = i;
    if(prva < size && numbers[prva] > numbers[m]){
        m = prva;
    }
    if(druga < size && numbers[druga] > numbers[m]){
        m = druga;
    }
    return m;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int *quick_sort (int *NumArray, int count, int first, compare cmp){
    
    int i, j, a, temp;
    int pivot;
    /* Goint ot save another array too manipulate */
    int *numbers = malloc(sizeof(int) * (count+1));
    
    /*Chehck if everythink is okdoky !*/
    if(!numbers) die("Memory error!");
    
    memcpy(numbers, NumArray, (count+1) * sizeof(int));
    
      printf("STARTEN! \n");
      printf("Size: %d \n", count);
    if(first < count){
        pivot = first;
        i = first;
        j = count - 1;
          printf("\n ---------------------------------------------- \n");
          printf("Pivot: %d ", numbers[pivot]);
        while(i < j){    
            while(numbers[i] <= numbers[pivot] && i < count)
                i++;
            while(numbers[j]  > numbers[pivot])
                j--;
            if(i < j){
                  printf("  IF(%d < %d) ",numbers[i], numbers[j]);
                  print(numbers, count, i, j, pivot);
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
                  printEnd(numbers, count);
            }   
        }
    
      printf("Before Store Ends\n");
      printf("i:%d j:%d \n", i, j);
    temp = numbers[pivot];
      printf("%d \n",temp);
    numbers[pivot] = numbers[j];
      printf("%d \n",numbers[pivot]);
    numbers[j] = temp;
      printf("%d \n",numbers[i]);
      printEnd(numbers, count);
    
    /* Calling back quick_sort */
    
    quick_sort(numbers, j-1, first, cmp);
    quick_sort(numbers, count, j+1, cmp);
   
    }
    return numbers;
}

int *bubble_sort (int *numbers, int count, int last, compare cmp){
    
    int sorted = 0;   
    int i, j, temp;
    int *target = malloc(count * sizeof(int));   
        
    /*Chehck is everythink is okdoky !*/
    if(!target) die("Memory error!");
    
    memcpy(target, numbers, count * sizeof(int));
    printf("Going in! \n");
    while(sorted == 0){
        sorted = 1;
        for(i = 0;i < count-1;i++){
            printf("In for loop! \n");
           // print(target,count);
            if(cmp(target[i], target[i+1]) > 0){
                printf("Start switch\t first: %d \t second: %d   i=%d \n",target[i],target[i+1],i);
                temp = target[i+1];
                target[i+1] = target[i];
                target[i] = temp;
                printf("End switch:\t first: %d \t second: %d \n",target[i],target[i+1]);  
                printf("\n");  
                sorted = 0;
            }
        }
    }
    printf("The size of array target: %ld \t Count is: %d",(sizeof(target)/sizeof(int)),count);
    return target;
}

void sorting(int *numbers, int size, sortingSystem sortType, compare cmp){

    int i, last = 0;
    int *sorted = sortType(numbers, size, last, cmp);
    
    if(!sorted) die("Failed to sort as requested!");
    
    /* Prints all possible outcomes */
    printf("\n\t\t\t ------THE ENDE------ \n");
    printf("Final:\n");
    for(i = 0; i < size; i++){
        printf("%d", sorted[i]);
    }
    printf("\n");
    
    free(sorted);
}

void printEnd(int *numbers, int size){
    int i;
    for(i = 0;i < size; i++){
        printf("%d ",numbers[i]);
    }
    printf("\n");
}
void print(int *numbers, int size, int low, int hig, int pivot){
    
    int i;
    printf("\n ----- \n");
    printf("'%d'", numbers[pivot]);
    for(i = 1; i < size; i++){
        if(numbers[i] == numbers[low] || numbers[i] == numbers[hig]){
            printf("(%d) ",numbers[i]);
        }else{
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");
}

int sorted_order(int a, int b){
    return a - b;
}

int revers_order(int a, int b){
    return b - a;
}

int oddEven_order(int a, int b){
    
    if(0 == b%2 && a%2 == 0){
        return a-b;
    }
    else if ( b%2 == 0 && a%2 != 0) {
        return 0;
    }
    else if (b%2 != 0 && a%2 == 0 ){
        return 1;
    }
    else return a-b;

}
void displayNumbers(char *argv[]){
 
    printf("Added numbers: %s \n\n", argv[1]);

}

int main(int argc, char *argv[]){
    
    displayNumbers(argv);
    if(argc < 2) die("USAGE: Exe18 2 1 9 2 4 6");
    
    int size = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(size * sizeof(int));
    if(!numbers) die("Memory error.");
    
    for(i = 0;i < size; i++){
        numbers[i] = atoi(inputs[i]);
    }
      sorting(numbers, size, heap_sort, sorted_order);
     //sorting(numbers, size, quick_sort, sorted_order);
    //sorting(numbers, size, sorted_order);
    //sorting(numbers, size, revers_order);
    //sorting(numbers, size,bubble_sort,  oddEven_order);
    
    
    free(numbers);
    
    return 0;
}
