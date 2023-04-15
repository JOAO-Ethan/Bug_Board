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
    path.push_back(position);
}
Bug::Bug(int id, int x, int y, Direction direction, int size){
    this->id = id;
    position = {x,y};
    this->direction = direction;
    alive = true;
    this->size = size;
    path.push_back(position);

}
Bug::Bug(){
    id = 0;
    position = {0,0};
    direction = South;
    alive = true;
    size = 1;
    path.push_back(position);

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

ostream &operator<<(ostream &out, const Bug &bug) {
    return bug.print(out);
}

string Bug::getFullType(char type) {
    switch (type) {
        case 'C':
            return "Crawler";
        case 'H':
            return "Hopper";
        default:
            return "Not a bug";
    }
}

void Bug::eat(Bug &other) {
    this->size += other.getSize();
    other.kill();
    other.idKiller = id;
}

int Bug::getIdKiller() const {
    return idKiller;
}

ostream &operator << ( ostream& out, Direction d){
    switch (d) {
        case North:
            out << "North";
            break;
        case South:
            out << "South";
            break;
        case West:
            out << "West";
            break;
        case East:
            out << "East";
            break;
    }
    return out;
}



