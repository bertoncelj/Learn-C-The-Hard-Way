#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ReadFile(char *filename)
{
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "r");

   if (handler)
   {
       // Seek the last byte of the file
       fseek(handler, 0, SEEK_END);
       // Offset from the first to the last byte, or in other words, filesize
       string_size = ftell(handler);
       // go back to the start of the file
       rewind(handler);

       // Allocate a string that can hold it all
       buffer = (char*) malloc(sizeof(char) * (string_size + 1) );

       // Read it all in one operation
       read_size = fread(buffer, sizeof(char), string_size, handler);

       // fread doesn't set it so put a \0 in the last position
       // and buffer is now officially a string
       buffer[string_size] = '\0';

       if (string_size != read_size)
       {
           // Something went wrong, throw away the memory and set
           // the buffer to NULL
           free(buffer);
           buffer = NULL;
       }

       // Always remember to close the file.
       fclose(handler);
    }

    return buffer;
}
/*
int add_rows(const char* stringArray){
    
    int add = 2;
    char string = stringArray[0];
    
    for(i = 0;(i/3) < max_add; i=i+3) {
        printf("%c%c\n",stringArray[i],stringArray[i+1]);
    }
    printf("\n");
    


return add;
}
*/
int concatenate(int x, int y) {
    int pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

int main() {
    
    int i;
    int max_add = 20;
    char *stringArray = ReadFile("dope.txt");
    char string = stringArray[1];
    
   int x = stringArray[3]-'0';
   int y = stringArray[4]-'0';
   
    int rez = concatenate(1,1);
    printf("%d \n",rez);
    rez = concatenate(1,1);
    printf("TOTO :\t %d + %d = %d \n",x,y, rez);
    
    for(i = 0;(i/3) < max_add; i=i+3) {
        printf("%c%c\n",stringArray[i],stringArray[i+1]);
    }
    printf("\n");
    if (string)
    {
        puts(stringArray);
        free(stringArray);
    }

    return 0;
}
