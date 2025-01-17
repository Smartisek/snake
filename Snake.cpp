//
// Created by domal on 03/07/2024.
//

#include "Snake.h"
#include "vector"
using namespace std;
Snake::Snake(int x, int y, Direction direction, int size) : position(x,y), direction(direction), size(size), alive(true){}; //constructor

int Snake::getSize() const{
    return size;
}

pair<int, int> Snake::getPosition() const{
    return position;
}

Direction Snake::getDirection() const{
    return direction;
}

string Snake::getStatus() const{
    if(alive == 1){
        return "Alive";
    } else {
        return "Dead";
    }
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

string Snake::positionToString(pair<int, int> position) {
    return "(" + to_string(position.first) + "," + to_string(position.second) + ")";
}

void Snake::drawSnake(Snake &snake,sf::RenderWindow &window){
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(snake.getSize()*50, snake.getSize() *50));
    shape.setPosition(snake.getPosition().first, snake.getPosition().second);

    if(snake.getStatus() == "Alive"){
        window.draw(shape);
    }
}

bool Snake::isWayBlocked() const {
    pair<int, int> currentPosition = getPosition();
    Direction currentDirection = getDirection();

    int windowX = 1200;
    int windowY = 1000;

    if((currentPosition.first == 0 + 25 && (currentDirection == Direction::EAST)) ||
        currentPosition.first == windowX - 25 && (currentDirection == Direction::WEST) ||
        currentPosition.second == 0 + 25 && (currentDirection == Direction::NORTH) ||
        currentPosition.second == windowY - 25 && (currentDirection == Direction::SOUTH) ) {

        return true;
    } else {
        return false;
    }
}

void Snake::move() {
    pair<int, int> newPosition = getPosition();

    if(isWayBlocked()){
        setDirection(Direction::SOUTH);
    }


    switch (getDirection()) {
        case Direction::NORTH:
            newPosition.second -=5;
            break;
        case Direction::SOUTH:
            newPosition.second +=5;
            break;
    }
    setPosition(newPosition);
}
