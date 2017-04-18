#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef struct  {
    char *name;
    int age;
}Person;

Person *Person_create(Person *who, char *name, int age, int height, int weight)
{
    who = malloc(sizeof(Person));
    printf("Memory allocated: %d bytes\n",(int)malloc_usable_size(who));

    (*who).name = strdup(name);
    who->age = age;
    
    return who;
}

void Person_destroy(Person *who)
{
    free(who->name);
    free(who);
}

void Person_print(Person *who)
{ 
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
}

int main(int argc, char *argv[])
{
    // make two people structures
    Person *joe;
    
    joe = Person_create(joe, "Joe Alex", 32, 64, 140);

    printf("\t\tMemory allocated FUNCTION: %d bytes\n",(int)malloc_usable_size(joe));
   
    Person_destroy(joe);
    return 0;
}

