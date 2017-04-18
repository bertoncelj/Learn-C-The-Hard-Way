#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


void die (const char* message){

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
    int t, height, save;
        
    
    /*Piramide stucture, height */
    i = 0;   
    while( 0 < size - ExpMath(2,i)){
        if(i > 10) die("V while zanki i ne gre več");
        ++i;
    }
    
    ostk_num = size - ExpMath(2,i);    
    ostk_num = abs(ostk_num) - 1 ;

    
    /* Presledki */
    height = i;
    i = 0;
    for(j = 0;j < height; j++){
        space(height-j-1);
        t = j;
        save = i;
        
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

int main(int argc, char* arhv[]){
    
    int A[] = {4,5,1,5,1,4,7,9,7,3,1,6,4,5,2,1,1,1,
    1,1,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,
    1,1,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,
    8,9,1,2,3,4,5,6,7,8,9,8,9,0,0,3,8,7,7,7,9,1,6,5, 
    3,4,5,6,7};
    int size = sizeof(A) / sizeof(int);
    
    
    piramida(A, size);


return 0;
}
