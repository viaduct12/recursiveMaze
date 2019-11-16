//
// Created by Lawrence Fiesta on 10/21/2019.
//

#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Maze {

private:
    int width, height, rowExit, columnExit, index;
    //method that splits the text file
    void split(string textInput);

public:

    //static variables
    static int const ROW = 100;
    static int const COLUMN = 100;
    static char const WALL = 'x';
    static char const FREE = ' ';
    static char const VISITED = '+';
    static char const PATH = '*';
    //getters
    int getWidth();

    int getHeight();
    //empty constructor
    Maze();
    //stores the maze file into a 2d array
    explicit Maze(const string &mazeFile);
    //checks to see if the path hasn't been marked
    bool IsClear(int row, int column) const;
    //checks to see if the path is a wall
    bool IsWall(int row, int column) const;
    //checks to see if the path is a path
    bool IsPath(int row, int column) const;
    //checks to see if the path has been visited
    bool IsVisited(int row, int column) const;
    //checks to see if the path is the goal
    bool IsGoal(int row, int column) const;
    //marks the path as a path
    void MarkAsPath(int row, int column);
    //marks the path as visited
    void MarkAsVisited(int row, int column);

    friend ostream &operator<<(ostream &out, const Maze &maze);
    //initializes a maze with a max of 100X100
    char maze[ROW][COLUMN];

};


#endif //MAZE_MAZE_H
