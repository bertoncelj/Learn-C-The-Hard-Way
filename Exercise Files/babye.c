#include <stdio.h>
void printHello(){
    printf("HARO,\n");
}
int Add(void (*pa)()){
    pa();

}

int main(){
   void (*p)() = printHello;
   Add(p);

}
