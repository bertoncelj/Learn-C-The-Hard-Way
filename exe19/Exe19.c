#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

struct Sorted{
	
	
};

void die(const char *message) {

	if(errno){
		perror(message);
	} else {
		printf("ERROR: %s",message);
	}
	exit(1);
}

void sorting(char *numbers, int count){

	int i;
	int *sorted = malloc(count * sizeof(int));
	

}

int Save_input (char* argv[], int argc){
	if(argc < 2) die("USAGE: ./Exe19 1 4 5 2 9 3 4 6 7");
	printf("Input Argc:\t %d \n",argc);
	
	int i;
	int count = argc - 1;
	char **input_numbers = argv + 1;
	int *numbers = malloc(count * sizeof(int));
	if(!numbers) die("Memory error, can't save numbers in malloc!");
	
	printf("Number saved: ");
	for(i = 0; i < count; i++){
		numbers[i] = atoi(input_numbers[i]);
		printf("%d, ",numbers[i]);
	}
	printf("\n");
	return numbers;

}
int main(int argc, char *argv[]){

	int count = argc - 1;
	int *numbers = Save_input(argv, argc);


	sorting(numbers,count);
	
	free(numbers);
	
	return 0;
}















































#ifndef _object_h
#define _object_h

typedef enum {
    NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct {
    char *description;
    int (*init)(void *self);
    void (*describe)(void *self);
    void (*destroy)(void *self);
    void *(*move)(void *self, Direction direction);
    int (*attack)(void *self, int damage);
} Object;

int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);


#endif


































