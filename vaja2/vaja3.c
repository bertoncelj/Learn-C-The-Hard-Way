#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "vaja3.h"

#define MAX_ARRAY 300
#define MIN_ARRAY 20

#define MAX_BOOKS 30
#define MAX_ROWS 100

/* Struct in H */


Knjiga *CreateKnj(int id, char *naslov, char *bes, int size) {
    
    Knjiga *knjiga = malloc(sizeof(Knjiga));
    if(!knjiga) die("Failed to load besedilo to malloc\n"); //if point is 0
    
    //Vpis strukture
    knjiga->id = id;
    knjiga->bes = strdup(bes);
    knjiga->naslov = strdup(naslov);
    knjiga->size = size;
    
    return knjiga; 
}

void knjigaDestroy (Knjiga *knjiga) {
    
    printf("DESTROY: %s", knjiga->naslov);
    if(!knjiga) die("Can't get destroy");
    
    free(knjiga->naslov);
    free(knjiga->bes);
    free(knjiga);
}

void knjigaPrintAll(Knjiga *knjiga) {
    
    printf("\n-----------------------\n");
    printf("Id: %d \n", knjiga->id);
    printf("Naslov: %s \n", knjiga->naslov);
    printf("Besedilo: %s \n", knjiga->bes);
    printf("Dolzina: %d \n", knjiga->size);
    printf("-------------------------\n");
}

Knjiga *KnjigaDodajanje() {
   
    char scanVpisNaslov[256];
    char scanVpisBesedilo[256];
    
    printf("/t--- Create new input ---\n");
    printf("Naslov strukture: \n");
    scanf("%s",&scanVpisNaslov);
    
    printf("Besedilo strukture : \n");
    scanf("%s",&scanVpisBesedilo);
    
    int id = 0;
    
    Knjiga *InputKnjiga = CreateKnj(id, scanVpisNaslov, scanVpisBesedilo, sizeof(Knjiga));
    if(!InputKnjiga) die("Can't create new knjiga input, error in knjigaDodajanje()!");
    
    //Print
    knjigaPrintAll(InputKnjiga);
    
    //Save in knjiznica
    DodajKnjigoVKnjiznico(InputKnjiga);
    
    return InputKnjiga; //naslov 
}

Knjiznica *CreateKnjiznica(Knjiga *knjiga, int idKnj){

    Knjiznica *knjiznica = malloc(sizeof(Knjiznica));
    if(!knjiznica) die("Failed to load knjiznica in Create Knjizinica \n"); 
    
    knjiznica->stKnjige = idKnj;
    knjiznica->knjiga = knjiga;

}

void DodajKnjigoVKnjiznico(Knjiga *knjiga) {  
    
    Knjiznica *knjiznica = CreateKnjiznica(knjiga, (knjiznica->stKnjige)); 
    
    int index = knjiznica->stKnjige;
   // knjiznica.knjiga[index] = knjiga; 
   // knjiznica.stKnjige++;
    
}

void Vpis() {
    
    int ch = getchar();
    getchar(); // eat ENTER
    
    switch(ch){
        case 'v':
            KnjigaDodajanje();
        break;
        
        case 'd':
            //delete
        break;
        
        case 'x':
            printf("Deleting all Heap !");
           // knjigaDestroy(knjiga);
        break;
        
    }
}

int main(int argc, char *argv[]){
    
    printf("Start Main \n");
    
    while(1) {
        Vpis();
    }
    

return 0;
}
