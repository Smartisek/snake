//
// Created by domal on 03/07/2024.
//

#include "Snake.h"
Snake::Snake(int x, int y, Direction direction, int size) : position(x,y), direction(direction), size(size){}; //constructor

int Snake::getSize() const{
    return size;
}

pair<int, int> Snake::getPosition() const{
    return position;
}

Direction Snake::getDirection() const{
    return direction;
}

void Snake::setSize(int newSize){
    this->size = newSize;
}

void Snake::setPosition(pair<int, int> newPosition){
    this->position = newPosition;
}

void Snake::setDirection(Direction newDirection){
    this->direction = newDirection;
}

void Snake::setStatus(bool newStatus){
    this->alive = newStatus;
}
