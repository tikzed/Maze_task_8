
#pragma once
#include "MCell.h"
class Maze {
public:
    Maze(int n, int m);
    ~Maze();
    const MCell& cell(int n, int m) const;
    bool makeConnection(int i1, int j1, int i2, int j2);
    bool removeConnection(int i1, int j1, int i2, int j2);
    void printMaze();
private:
    MCell* m_field;
    int i;
    int j;
};