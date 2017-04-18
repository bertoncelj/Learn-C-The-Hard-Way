#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void die(const char* message){

    if(errno){
        perror(message);
    }else{
        printf("ERROR: %s \n",message);
    }
    exit(1);
}

int main (int argc,char *argv[]) {


    char *tabela[] = {"Drek", "Yolo", "Swag", "magic"};
    int abcd = 10;
    
    


return 0;
}
