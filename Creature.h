//
// Created by Lawrence Fiesta on 10/21/2019.
//

#ifndef MAZE_CREATURE_H
#define MAZE_CREATURE_H

#include <iostream>
#include "Maze.h"

using namespace std;

class Creature {

private:

    int startX, startY;
    string tempPath = "";

public:
    //marks the path with the visited symbol
    void markAsVisited(int row, int col, Maze &maze);
    //marks the path with the path symbol
    void markAsPath(int row, int col, Maze &maze);
    //initializes the solving using recursion
    string Solve(Maze &maze);
    //empty constructor
    Creature();
    //initializes a creature with a starting coordinate
    Creature(int startX, int startY);

    friend ostream &operator<<(ostream &out, const Creature &creature);

    //recursive method that will go north first, then west, and finally east
    bool goNorth(int startX, int startY, Maze &maze);
    //recursive method that will go east first, then south, and finally north
    bool goEast(int startX, int startY, Maze &maze);
    //recursive method that will go south first, then east, and finally west
    bool goSouth(int startX, int startY, Maze &maze);
    //recursive method that will go west first, then north, and finally south
    bool goWest(int startX, int startY, Maze &maze);


};


#endif //MAZE_CREATURE_H
