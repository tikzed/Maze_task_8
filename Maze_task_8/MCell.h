#pragma once
class MCell {
    friend class Maze;
public:
    bool right() const;
    bool down() const;
private:
    MCell();
    bool m_down = false;
    bool m_right = false;
};
