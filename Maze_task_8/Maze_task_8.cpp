#include <iostream>
#include <algorithm>
#include "Maze.h"
int main()
{
    int n = 5;
    int m = 5;
    Maze* ma = new Maze(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
                ma->makeConnection(i, j, i + 1, j + 1);
        }
    }
    ma->printMaze();
}