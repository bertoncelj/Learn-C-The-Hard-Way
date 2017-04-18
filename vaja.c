#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_DATA 20
#define MIN_DATA 2

#define MAX_ROWS 100

typedef enum color{ 
    blue, red, green, orange
};

struct Car{

    int id;
    char car_name[MAX_DATA];
    char registration[MAX_DATA];
    int color;
};
struct Database{
    struct Car rows[MAX_ROWS];
};


struct Connection {
    FILE *file;
    struct Database *db;
};

void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

void Datacreate_create(struct Connection *conn){

    int i = 0;
    printf("Address how many rows do you what: ");
    
    for(i = 0; i < MAX_ROWS; i++){
        struct Address addr = {
            .id = i, 
            .set = 0 };
        conn->db->rows[i] = addr;
    }
}

void Database_write(struct Connection *conn){

    rewind(conn->file);
    
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to write database!");
    
    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.");
    

}

void Database_set(struct Connection *conn, int id, const char *name, const char *email){

    


int main(int argc, char *argv[]){
    if(argc < 3) die("USAGE: vaja <dbfile> <action> [action Parametrs]");
    
    char *filename[] = argv[1];
    char action = argv[2][0];
    
    int max_rows = (int) sizeof(argc[1]);
    int max_data = (int) sizeof(argv[2][0]);
    
    struct Database *base = Database_open(filename, action); 
    int id = 0;
    
    Database_create(base);
    




return 0;
}
