#include "object.h"

void object_new(struct object *this, int x, int y, char* s){

	this->x = x;
	this->y = y;
	this->s = s;
}

int object_get_x(struct object this){
	return this.x;
}
