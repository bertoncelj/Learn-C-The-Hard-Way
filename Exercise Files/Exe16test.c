#include <assert.h>
#include <stdio.h>

struct House;
struct Room;
void printHouse;



int Add(int a, int b){
    int c = a*b;
return c;    
}


typedef struct Person{
   const char *name;
   const char *sex;
   int weight;
   double height;
   int mass;
}Person;

void getPerson (Person One){


    printf("My name is %s \n",One.name);
    printf("My sex is %s \n",One.sex);
    printf("My weight is %d \n",One.weight);
    printf("My height is %f \n",One.height);
    printf("My mass is %d that musco. \n", One.mass);

}



struct Room{
    char* name;
    int size;
    int width;
    int lenght;
    
};

struct House{
    char *address;
    struct Room *rooms[10];
};


void printHouse(struct House house){
    printf("%s\n",house.address);
    printf("\n\r\n\r");
    int i;
    for(i = 0;i < 10;i++){
        if(house.rooms[i] != NULL){
            struct Room r = *house.rooms[i];
            printf("Room #%d: %s",i,r.name);
        }
    } 
}
int main()
{
   int a  = 12;
   char str[50];
   Person Janez = {"Jamez","Man",80,190,100};
   getPerson (Janez);
   printf("Hello add nubreS now %d \n", Add(4,4));
   assert(a >= Add(3,3));
    
    
    struct House h;
    h.address = "Oretnekova pot 5";
    printf("%d",*(h.address));
    for (a = 0; a < 10; a++){
        h.rooms[a] = NULL;
        }
    struct Room hall;
    hall.width = 10;
    hall.lenght = 12;
    hall.size = 10;
    hall.name = "Hall";
    
    h.rooms[0] = &hall;
    printHouse(h);
    
    system("PAUSE");
   return(0);
}
