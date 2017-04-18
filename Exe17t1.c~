#include <stdio.h>

int main(){

    char string[] = "Hahaha";
    FILE *file;
    int a;
    
    
    file = fopen("swag.txt","w");
    fwrite(string, 1, sizeof(string), file);
    fclose(file);
    
    file = fopen("swag.txt" , "r");
    while(1){
       a = fgetc(file);
       if(feof(file)){
            break;
       } 
       printf("%c",a);
    }
    /* REWIND */
    rewind(file);
    printf("\n");
    
     while(1){
       a = fgetc(file);
       if(feof(file)){
            break;
       } 
       printf("%c",a);
    }
    fclose(file);

return 0;
}
