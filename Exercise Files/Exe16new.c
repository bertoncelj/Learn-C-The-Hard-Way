#include <stdio.h>
#include <assert.h>


int cal (int a, int b){

    return a*b;
}
struct Lik{
    char* name;
    int size;
    int A;
    int B;
};
struct Lik *creat(char* name, int A, int B,int(*cal)(int,int)){
    struct Lik *make = malloc(sizeof(struct Lik));
    printf("Malloc address is: %d.\n", creat);
    printf("\n");
    /* Init  struct*/
    
    make->name = name;
    make->size = cal(A,B);
    make->A = A;
    make->B = B;

return make;    
}

void PrintLik(struct Lik *make){
    
    printf("Ta lik je %s.\n",make->name);
    printf("\t Size of lik is %d \n",make->size);
    printf("\t\t -A: %d \n",make->A);
    printf("\t\t -B: %d \n",make->B);
}
void deletLik(struct Lik *creat){

    free(creat);

}


int main(int argc, char* argv[]){
    int i,j;
    
    struct Lik *Kvadrat = creat("Kvadrat",12,22,cal);
    
    PrintLik(Kvadrat);
    deletLik(Kvadrat);
}
