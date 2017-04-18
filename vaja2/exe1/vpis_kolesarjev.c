#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 30
#define MAX_ROWS 100

struct Riders {
    int id;
    int set;
    int startNum;
    char name[MAX_DATA];
    char surrname[MAX_DATA];
};

struct Database {
    struct Riders rows[MAX_ROWS];
};

struct Connection {
    FILE *file;
    struct Database *db;
};


void die (char *message){
    
    if(errno){
        perror(message);
    } else {
        printf("ERROR: %s \n", message);
    }
    
    Database_close();
    exit(1);
}

void RiderPrint(struct Riders *rider) {

    printf("Rider: %d, %d, %s, %s \n", 1,  
    rider->startNum, rider->name, rider->surrname);
}

void Database_load(struct Connection *conn) {

    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1)die("Fail to load database!");
}

struct Connection *Database_open(const char *filename, char mode) {

    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Failed to load conn to malloc");
    
    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Fail to load memory error in malloc conn->db");
    
    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");
        if(conn->file) {
            Database_load(conn);
        }
    }
    
    if(!conn->file) die("Fail to open the file");
   
   return conn;
}
void Database_close(struct Connection *conn) {

    if(conn){
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
    }
}

void Database_write(struct Connection *conn) {

    rewind(conn->file);
    
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to write database");
    
    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.");   
}

void Database_create(struct Connection *conn) {

    int i;
    
    for(i = 0; i < MAX_ROWS; i++){
        struct Riders rid = {.id = i, .set = 0};
        
        conn->db->rows[i] = rid;
    }
}

void Database_set(struct Connection *conn, int id, char *startNum, const char *name, const char *surrname){

    struct Riders *ridd = &conn->db->rows[id];
    if(ridd->set) die("Already set, delet if first!");
    
    ridd->set = 1;
    
    char *res = strncpy(ridd->name, name, MAX_DATA);
    if(!res) die("Name copy fail !");
    
    res = strncpy(ridd->surrname, surrname, MAX_DATA);
    if(!res) die("Surrname copy fail !");
}

void Database_get(struct Connection *conn, int id){

    struct Riders *ridd = &conn->db->rows[id];
    
    if(ridd->set){
        RiderPrint(ridd);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id) {
    
    struct Riders ridd = {.id = id, .set = 0};
    conn->db->rows[id] = ridd;
}

void Database_list(struct Connection *conn){
    
    int i = 0;
    struct Database *db = conn->db;
    
    for(i = 0; i < MAX_ROWS; i++){
        struct Riders * cur = &db->rows[i];
        
        if(cur->set){
            RiderPrint(cur);
        }
    }
}


int main(int argc, char *argv[]){
    
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if(argc > 3) id = atoi(argv[3]);
    if(id >= MAX_ROWS) die("There's not that many records.");
    
    switch(action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if(argc != 4) die("Need an id to get");

            Database_get(conn, id);
            break;

        case 's':
            if(argc != 7) die("Need id, start position, name, surrname,");

            Database_set(conn, id, argv[4], argv[5], argv[6]);
            Database_write(conn);
            break;

        case 'd':
            if(argc != 4) die("Need id to delete");

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
        
        case 'h':
            printf("Program creates list of riders and stor their startNum, names and surrnames.\
                 Valid actions are c = create, g = get, s = set, d = del, l = list \n");
                 exit(1);   
            break;
                
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
    }
    
    
    Database_close(conn);
    

return 0;
}
