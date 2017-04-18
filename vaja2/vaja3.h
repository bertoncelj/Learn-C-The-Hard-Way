#ifndef vaja3_h
#define vaja3_h

#define MAX_ARRAY 300
#define MIN_ARRAY 20

#define MAX_BOOKS 30
#define MAX_ROWS 100

typedef struct {
    int id;
    char *naslov;
    char *bes;
    int size;
}Knjiga;

typedef struct {
    int stKnjige;
    Knjiga *knjiga[MAX_BOOKS];
} Knjiznica; 

void die(char *message){

    if(errno){
        perror(message);
    }else{
        printf("ERROR: %s", message);
    }
    exit(1);
}

/* Decalearid Funkcije */

void die(char *message);
Knjiga *Create(int id, char *naslov, char *bes, int size);
void knjigaDestroy (Knjiga *knjiga);
void knjigaPrintAll(Knjiga *knjiga);
Knjiga *KnjigaDodajanje();
void DodajKnjigoVKnjiznico(Knjiga *knjiga);
void Vpis();

#endif
