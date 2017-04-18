#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define NAVODIILA "Za n je trepa rpisniti bpagha ga gag af w fv"
const char abc[25] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','z'};

 typedef enum Smer{
    down, up
} Smer;

void die(const char *message){

    if(errno){
        perror(message);
    }else{
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

void izpisHex(int i, Smer smer) {
    
    if(smer){
        int num =(int) abc[i];
        printf("Crka %c -> %x\n", abc[i], num);
    }else {
         int num =(int) abc[i-1];
         printf("Crka %c -> %x\n", abc[i-1], num);
    }
}



int readInput(int i){
    
    if(i > 20){
        i = 0;
    }
    char ch = getchar(); 
    scanf("%c",&ch);
    
    switch(ch){
        case -1:
            printf("SURRENDER? \n");
            return 0;
            break;
            
        case 'n':
            printf("Go to start \n");
            break;
            
        case 'w':
            izpisHex(i,up);
            i++;
            break;
            
        case 'q':
            izpisHex(i,down);
            i--;
            break;
            
        case 'x':
            printf("END\n");
            exit(1);
            break;
        /*    
        default:
            printf("\nWhat? Your entry %d is invalid! \n", ch);
            printf("%s\n",NAVODIILA);
            break;
            đ*/
    }
    return i;
}

int main(int argc, int *argv[]){
    
    
    int i = 0;
    int a = (int)('b');
    printf("%x",a);
    
    
    while(1){
       i = readInput(i);
    }

return 0;
}
