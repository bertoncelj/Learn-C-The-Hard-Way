#include <stdio.h>
#include <stdlib.h>


struct Room{
    float ce, fe;
} A;








int main(int argc, char *argv[]){
    
    srand(time(NULL));
    
    Map *game = NEW(Map, "The Hall of the Minotaur.");
    
    printf("you enter the ");
    game->location->_(describe)(game->location);
    
    
    A = 0;
    
    while(process_input(game)){
    
    }
    return 0;
}
