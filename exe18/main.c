#include <stdio.h>
#include <stdlib.h>

#include "object.h"



int main(int argc, char **argv){

	struct object o;
	object_new(&o, 10, 11, "Hello");
	printf("Hello: %d \n",object_get_x(o));
	return 0;
}
