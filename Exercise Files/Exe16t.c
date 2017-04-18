#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/* Struct incilization */
struct Room{
    char* name;
    int lenght;
    int width;
    int size;
};

struct House{
    char* address;
    int numRooms;
    int size;
    char *Location;
    char *name;
    //struct Room *rooms[10];
};

struct House *insertHouse(char* address, int numRooms, int size, char* location, char *name){
    struct House *insertHouse = malloc(sizeof(struct House));
    printf("Function malloc :%p \n",insertHouse);
    printf("\n");
    assert(insertHouse != NULL);     
    insertHouse->name = strdup(name);
    insertHouse->address = strdup(address);
    insertHouse->numRooms = numRooms;
    insertHouse->size = size;
    insertHouse->Location = strdup(location);
    
return insertHouse;
}
void Destroy(struct House *insertHouse)
{   
    assert(insertHouse != NULL);

    free(insertHouse->address);
    free(insertHouse->Location);
    free(insertHouse);
    
}

void printHouse(struct House *insertHouse){


    printf("This is house named %s. \n",insertHouse->name);
    printf("\tAddress of this house %s. \n", insertHouse->address);
    printf("\tNumbers of room in house %d. \n",insertHouse->numRooms);
    printf("\t Size of house %d.\n",insertHouse->size);
    printf("\tLocation of house is %s.\n",insertHouse->Location);
   
}

int main (int argc, char *argv[]){

     int i,j,a,g;
     struct House *PrBert = insertHouse("Oretnekova", 11, 700 , "Kranj" , "PrBert");
     printf("Address of pointer *PrBert %p \n",PrBert);   
    struct House *Brunarca = insertHouse("Cesta", 13 , 900 , "Kranj" , "Brunarca");
    printf("Address of pointer *Brunarca %p\n",Brunarca);
    printHouse(PrBert);
    printHouse(Brunarca);
    
    Destroy(Brunarca);
    Destroy(PrBert);
    PrBert->address = "Yolo";  

return 0;
}
