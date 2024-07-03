//
// Created by domal on 03/07/2024.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include <vector>
using namespace std;

enum class Direction{
    NORTH = 1,
    SOUTH= 2,
    WEST = 3,
    EAST = 4
};

class Snake {
private:
    pair<int, int> position;
    int size;
    bool alive;
    Direction direction;
public:
    Snake(int x, int y, Direction direction, int size);
    int getSize() const;
    pair<int, int> getPosition() const;
    Direction getDirection() const;

    void setSize(int newSize);
    void setPosition(pair<int, int> newPosition);
    void setDirection(Direction newDirection);
    void setStatus(bool newStatus);
};


#endif //SNAKE_SNAKE_H
