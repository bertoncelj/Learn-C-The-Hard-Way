#ifndef H_OBJECT
#define H_OBJECT

struct object {

	int x;
	int y;
	char* s;
};

void object_new(struct object *o, int x, int y, char* s);

int object_get_x(struct object o);




#endif
