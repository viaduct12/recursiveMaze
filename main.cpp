#include "Maze.h"
#include "Creature.h"
#include <cassert>

void test() {
    Maze gameboard = Maze("mazeSimple.txt");
    Creature bacon = Creature(1, 6);
    cout << bacon << " before \n";
    string thingy = bacon.Solve(gameboard);
    assert (thingy == "SSSSWWWWS");
    cout << thingy << endl;
    cout << gameboard << bacon << " after\n";

    bacon = Creature(2, 14);
    Maze gameboard1 = Maze("maze.txt");
    cout << endl << bacon << " before\n";
    thingy = bacon.Solve(gameboard1);
    assert (thingy == "ESSSEEENNNNN");
    cout << thingy << endl;
    cout << gameboard1 << bacon << " after\n";

    bacon = Creature(2, 7);
    Maze gameboard2 = Maze("maze0.txt");
    cout << endl << bacon << " before\n";
    thingy = bacon.Solve(gameboard2);
    assert (thingy == "ENN");
    cout << thingy << endl;
    cout << gameboard2 << bacon << " after\n";

}

void test1() {
    Creature bacon = Creature(6, 2);
    Maze gameboard = Maze("mazeSimple.txt");
    cout << endl << bacon << " before \n";
    string thingy = bacon.Solve(gameboard);
    assert (thingy == "Starting position was at the exit!");
    cout << thingy << endl;
    cout << gameboard << bacon << " after\n";

    bacon = Creature(2, 7);
    Maze gameboard1 = Maze("maze.txt");
    cout << endl << bacon << " before\n";
    thingy = bacon.Solve(gameboard1);
    assert (thingy == "No path available!");
    cout << thingy << endl;
    cout << gameboard1 << bacon << " after\n";

    bacon = Creature(2, 20);
    Maze gameboard2 = Maze("maze0.txt");
    cout << endl << bacon << " before\n";
    thingy = bacon.Solve(gameboard2);
    assert (thingy == "Bad starting position!");
    cout << thingy << endl;
    cout << gameboard2 << bacon << " after\n";

}

void testAll() {
    test();
    test1();
}


int main() {
    testAll();
    cout << "\nDone." << std::endl;
    return 0;
}