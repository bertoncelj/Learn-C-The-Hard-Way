#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* GNEZDENJE DEFINA */
#define YOLO SWAG
#define SWAG ST
#define ST 10 


    
#define max(A, B)   ((A) < (B) ? (A) : (B))
#define BUFFER_SIZE 1024
#define NUMBERS 1,\
                2,\
                3
                

int main (int argc, char *argv[]){
    
    int a,b;
    printf("Prva stevilka: \n");
    scanf("%d", &a);
    
    printf("Druga stevilka: \n");
    scanf("%d", &b);
   
    

    int x[3] = {NUMBERS};
    char *foo;
    foo = (char *) malloc(BUFFER_SIZE);
    
    printf("Stevila %d\n", x[1]);
    printf("%d \n",YOLO);

return 0;
}


/*
#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",__FILE__,__LINE__,##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : sterror(errno))
*/
