//
// Created by Lawrence Fiesta on 10/21/2019.
//

#include <sstream>
#include "Maze.h"
//#include "Creature.h"

Maze::Maze() {
    this->width = 0;
    this->height = 0;
    this->columnExit = 0;
    this->rowExit = 0;
    this->index = 0;

}

Maze::Maze(const string &mazeFile) {
    this->width = 0;
    this->height = 0;
    this->columnExit = 0;
    this->rowExit = 0;
    this->index = 0;

    string line;
    ifstream myFile;
    myFile.open(mazeFile);

    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            split(line);
        }
    }

}

bool Maze::IsClear(int row, int column) const {
    return (maze[row][column] == FREE);
}

bool Maze::IsWall(int row, int column) const {
    return (maze[row][column] == WALL);
}

bool Maze::IsPath(int row, int column) const {
    return (maze[row][column] == PATH);
}

bool Maze::IsVisited(int row, int column) const {
    return (maze[row][column] == VISITED);
}

void Maze::split(string textInputs) {
    string num1;
    string num2;


    if (textInputs[0] == 'x' || textInputs[0] == '#') {
        int tempSize = textInputs.size();
        int iterator = 0;
        if (textInputs[0] == 'x') {
            while (iterator < tempSize) {
                this->maze[this->index][iterator] = textInputs[iterator];
                iterator += 1;
            }
            index += 1;
        } else {
            while (iterator < tempSize) {
                if (textInputs[iterator] == '#') {
                    this->maze[this->index][iterator] = 'x';
                } else {
                    this->maze[this->index][iterator] = textInputs[iterator];
                }
                iterator += 1;
            }
            index += 1;
        }

    } else {
        istringstream streams(textInputs);
        streams >> skipws >> num1 >> num2;
        stringstream ssToInt1(num1);
        stringstream ssToInt2(num2);

        if (this->width == 0 && this->height == 0) {
            ssToInt1 >> this->width;
            ssToInt2 >> this->height;
        } else if (this->width != 0 && this->height != 0) {
            ssToInt1 >> this->rowExit;
            ssToInt2 >> this->columnExit;
        }
    }
}

void Maze::MarkAsPath(int row, int column) {
    maze[row][column] = PATH;
}

void Maze::MarkAsVisited(int row, int column) {
    maze[row][column] = VISITED;

}

int Maze::getHeight() {
    return this->height;
}

int Maze::getWidth() {
    return this->width;
}

bool Maze::IsGoal(int row, int column) const {
    return (row == this->rowExit && column == this->columnExit);
}

ostream &operator<<(ostream &out, const Maze &maze) {
    string mazeOut;
    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.width; ++j) {
            mazeOut += maze.maze[i][j];
        }
        mazeOut += "\n";
    }
    out << mazeOut;
    return out;
}

