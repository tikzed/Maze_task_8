#include<iostream>
#include<algorithm>
#include "Maze.h"

Maze::Maze(int n, int m) {
    i = n;
    j = m;
    m_field = new MCell[n * m];
}

Maze :: ~Maze() {
    delete[] m_field;
}
const MCell& Maze::cell(int n, int m) const
{
    return m_field[i * n + m];
}
bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
    bool b = m_field[1].m_right;
    if (i1 - i2 == 0 || i2 - i1 == 0)
    {
        m_field[i1 * i + std::min(j1, j2)].m_right = true;
        return true;
    }
    else
    {
        m_field[i1 * i + std::min(j1, j2)].m_right = true;
        m_field[std::min(i1, i2) * i + std::min(j1, j2) + 1].m_down = true;
    }
    bool a = m_field[1].m_right;
    return true;
}
bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
    if (std::max(i1, i2) < i || std::max(i1, i2) < j)
        return false;
    if (i1 - i2 == 0 || i2 - i1 == 0)
    {
        m_field[i1 * i + std::min(j1, j2)].m_right = false;
        return true;
    }
    else
        m_field[std::min(i1, i2) * i + std::min(j1, j2) + 1].m_down = false;

    return true;
}
void  Maze::printMaze()
{
    for (int n = 0; n < i;n++)
    {
        for (int m = 0; m < j; m++)
        {
            if (m_field[n * i + m].m_right) {
                if (m == 0 && n == 0) {
                    m++;
                    std::cout << '0';
                }
                if (n - 1 >= 0 && m - 1 >= 0 && m_field[(n - 1) * i + m].m_down) {
                    std::cout << (char)192;
                    if (i - 1 == n && m == j - 1)
                        continue;
                    m++;
                }
                std::cout << (char)191;
            }
            else
                std::cout << '0';
        }
        std::cout << '\n';
    }
}