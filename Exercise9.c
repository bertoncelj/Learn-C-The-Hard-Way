#include <stdio.h>

void graphSwitchNumbers(int *A,int size, int mark){
    int i;
    for(i = 0; i < size;i++){
        if(A[i] == mark || A[i+1] == mark ){
            printf("(%d) ",A[i]);
        }else{
            printf("%d ",A[i]);
        }
    }printf("\n");
}
int compare (int A, int B){
    if(A > B) return 1;
    else return -1;
}



void BubleSort(int *A,int size, int (*compare)(int,int)){
    int i,temp,check = 1,d=1;
    printf("Hi!\n");
    printf("Size: %d",size);
    while (check == 1){
        printf("N: %d\n",d++);
        check = 0;
        for(i = 0; i < size - 1 ;i++){
            if(compare(A[i],A[i+1]) > 0) {       //function as argumant;
                //graphSwitchNumbers(A,size,i);
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                check = 1;
            }
        
        }
    }
    printf("End of function!\n");
}



int main(int argc, char* argv[]) {
    int A[] = {12,41,51,63,2,56,21,5,251,5,3,21,1,45,25,61,6,7,2,21,57,3,578,34,79,43};
    int i;
    int size = sizeof(A) / sizeof(A[0]);
    BubleSort(A,size,compare);
    //izpis:
    for(i = 0;i < size-1;i++){
        printf("%d, ",A[i]);
    }
    printf("%d",A[i+1]);
    

return 0;
}

