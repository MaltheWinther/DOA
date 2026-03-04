#include <iostream>

bool solve_maze(char maze[5][6], int y, int x){
    if (maze[y][x] == 'X'){
        return false;
    }
    else if (maze[y][x] == 'E'){
        return true;
    }

    maze[y][x] = 'X';

    if(solve_maze(maze, y-1, x)){ //Checker et felt opad
        return true;
    }
      if(solve_maze(maze, y, x+1)){ //Checker et felt til højre
        return true;
    }
     if(solve_maze(maze, y+1, x)){ //Checker et felt nedad
        return true;
    }   
    if(solve_maze(maze, y, x-1)){ //Checker et felt til venstre
        return true;
    }
    
    return false;
    }


int main() {
    
   
    char maze[5][6] = {
    {'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', ' ', ' ', ' ', ' ', 'X'},
    {'X', ' ', 'X', 'X', ' ', 'X'},
    {'X', ' ', 'X', ' ', ' ', 'X'},
    {'X', 'E', 'X', 'X', 'X', 'X'}
};



std::cout << solve_maze(maze,1,1) << std::endl;
   
    return 0;
}