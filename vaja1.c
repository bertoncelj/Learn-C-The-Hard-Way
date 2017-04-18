#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void f1(){
    int a = 10;
    printf("f1: %d \n", a);
}

void f2(){
    int b = 3;
    
}


int main(int argc, char *argv[]){

int i;

char x[] = "neki";
for (i=0; x[i];i++) x[i]='q';
printf(x);

return 0;
}
