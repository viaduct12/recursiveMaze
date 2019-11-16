//
// Created by Lawrence Fiesta on 10/21/2019.
//

#include "Creature.h"

Creature::Creature() {
    this->startX = 0;
    this->startY = 0;
}

Creature::Creature(int startX, int startY) {
    this->startX = startX;
    this->startY = startY;
}

string Creature::Solve(Maze &maze) {

    if (maze.IsWall(startX, startY) || startX > maze.getHeight() || startY > maze.getWidth()) {
        return "Bad starting position!";
    } else if (maze.IsGoal(startX, startY)) {
        markAsPath(startX, startY, maze);
        return "Starting position was at the exit!";
    } else {
        markAsPath(startX, startY, maze);
        goNorth(this->startX, startY, maze);
        goWest(this->startX, startY, maze);
        goSouth(this->startX, startY, maze);
        goEast(this->startX, startY, maze);
    }

    if (tempPath.empty()) {
        tempPath = "No path available!";
    }

    return tempPath;
}

void Creature::markAsVisited(int row, int col, Maze &maze) {
    maze.maze[row][col] = '+';
}

void Creature::markAsPath(int row, int col, Maze &maze) {
    maze.maze[row][col] = '*';
}

bool Creature::goNorth(int startX, int startY, Maze &maze) {
    bool success = false;
    if (maze.IsClear(startX - 1, startY) && startX - 1 != -1 && !maze.IsVisited(startX - 1, startY)) {
        startX = startX - 1;
        maze.MarkAsPath(startX, startY);
        tempPath += "N";
        if (maze.IsGoal(startX, startY)) {
            success = true;
            this->startX = startX;
            this->startY = startY;
        } else {
            success = goNorth(startX, startY, maze);
            if (!success) {
                success = goWest(startX, startY, maze);
                if (!success) {
                    success = goEast(startX, startY, maze);
                    if (!success) {
                        markAsVisited(startX, startY, maze);
                        tempPath.pop_back();
                    }
                }
            }
        }
    } else {
        success = false;
    }
    return success;

}

bool Creature::goEast(int startX, int startY, Maze &maze) {
    bool success = false;
    if (maze.IsClear(startX, startY + 1) && startY + 1 <= maze.getWidth() && !maze.IsVisited(startX, startY + 1)) {
        startY = startY + 1;
        maze.MarkAsPath(startX, startY);
        tempPath += "E";
        if (maze.IsGoal(startX, startY)) {
            success = true;
            this->startX = startX;
            this->startY = startY;
        } else {
            success = goEast(startX, startY, maze);
            if (!success) {
                success = goSouth(startX, startY, maze);
                if (!success) {
                    success = goNorth(startX, startY, maze);
                    if (!success) {
                        markAsVisited(startX, startY, maze);
                        tempPath.pop_back();
                    }
                }
            }
        }
    } else {
        success = false;
    }
    return success;
}

bool Creature::goSouth(int startX, int startY, Maze &maze) {
    bool success = false;
    if (maze.IsClear(startX + 1, startY) && startX + 1 <= maze.getHeight() && !maze.IsVisited(startX + 1, startY)) {
        startX = startX + 1;
        maze.MarkAsPath(startX, startY);
        tempPath += "S";
        if (maze.IsGoal(startX, startY)) {
            success = true;
            this->startX = startX;
            this->startY = startY;
        } else {
            success = goSouth(startX, startY, maze);
            if (!success) {
                success = goWest(startX, startY, maze);
                if (!success) {
                    success = goEast(startX, startY, maze);
                    if (!success) {
                        markAsVisited(startX, startY, maze);
                        tempPath.pop_back();
                    }
                }
            }
        }
    } else {
        success = false;
    }
    return success;

}

bool Creature::goWest(int startX, int startY, Maze &maze) {
    bool success = false;
    if (maze.IsClear(startX, startY - 1) && startY - 1 != -1 && !maze.IsVisited(startX, startY - 1)) {
        startY = startY - 1;
        maze.MarkAsPath(startX, startY);
        tempPath += "W";
        if (maze.IsGoal(startX, startY)) {
            success = true;
            this->startX = startX;
            this->startY = startY;
        } else {
            success = goWest(startX, startY, maze);
            if (!success) {
                success = goSouth(startX, startY, maze);
                if (!success) {
                    success = goNorth(startX, startY, maze);
                    if (!success) {
                        markAsVisited(startX, startY, maze);
                        tempPath.pop_back();
                    }
                }
            }
        }
    } else {
        success = false;
    }
    return success;

}

ostream &operator<<(ostream &out, const Creature &creature) {
    out << "C(" << creature.startX << "," << creature.startY << ")";

    return out;
}
