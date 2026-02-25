#include <iostream>

bool solve_maze(char maze[5][6],char checked_maze[5][6], int y, int x){
    if (maze[y][x] == 'X' || checked_maze[y][x] == 'X' ){
        return false;
    }
    else if (maze[y][x] == 'E'){
        return true;
    }

    checked_maze[y][x] = 'X';

    if(solve_maze(maze,checked_maze, y-1, x)){ //Checker et felt opad
        return true;
    }
      if(solve_maze(maze,checked_maze, y, x+1)){ //Checker et felt til højre
        return true;
    }
     if(solve_maze(maze,checked_maze, y+1, x)){ //Checker et felt nedad
        return true;
    }   
    if(solve_maze(maze,checked_maze, y, x-1)){ //Checker et felt til venstre
        return true;
    }
    
    return false;
    }


int main() {
    
   
    char maze[5][6] = {
    {'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', ' ', ' ', ' ', ' ', 'X'},
    {'X', ' ', 'X', 'X', ' ', 'X'},
    {'X', ' ', 'X', 'E', ' ', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X'}
};

char checked_maze[5][6] = {
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '}
};

std::cout << solve_maze(maze,checked_maze,1,1) << std::endl;
   
    return 0;
}