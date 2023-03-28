//
// Created by ubuntu on 14/03/23.
//

#include "Bug.h"

Bug::Bug(int id, pair<int,int> position, Direction direction, int size){
    this->id = id;
    this->position = position;
    this->direction = direction;
    alive = true;
    this->size = size;
}
Bug::Bug(int id, int x, int y, Direction direction, int size){
    this->id = id;
    position = {x,y};
    this->direction = direction;
    alive = true;
    this->size = size;
}
Bug::Bug(){
    id = 0;
    position = {0,0};
    direction = South;
    alive = true;
    size = 1;
}

bool Bug::isWayBlocked() {
    switch (direction) {
        case North:
            return position.second == 0;
        case East:
            return position.first == 9;
        case West:
            return position.first == 0;
        default:
            return position.second == 9;
    }
}

void Bug::setDirection(Direction dir) {
    direction = dir;
}

void Bug::setPosition(pair<int, int> pos) {
    position = pos;
}

void Bug::setX(int x) {
    position.first = x;
}

void Bug::setY(int y) {
    position.second = y;
}

void Bug::kill() {
    alive = false;
}

void Bug::addPath(pair<int, int> pos) {
    path.push_back(pos);
}

int Bug::getId() const {
    return id;
}

int Bug::getSize() const {
    return size;
}

pair<int, int> Bug::getPosition() const {
    return position;
}

int Bug::getX() const {
    return position.first;
}

int Bug::getY() const {
    return position.second;
}

Direction Bug::getDirection() const {
    return direction;
}

bool Bug::isAlive() const {
    return alive;
}

list<pair<int, int>> Bug::getPath() const {
    return path;
}
