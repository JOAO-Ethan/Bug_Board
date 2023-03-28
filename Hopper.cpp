//
// Created by ubuntu on 22/03/23.
//

#include "Hopper.h"
#include <cstdlib>

void Hopper::move() {
    while (isWayBlocked()) {
        setDirection(Direction(rand() % 4 + 1));
    }
    int newX = getX();
    int newY = getY();
    switch (getDirection()) {
        case East:
            newX += hopLength;
            if (newX >= 10) newX = 9;
            break;
        case West:
            newX -= hopLength;
            if (newX < 0) newX = 0;
            break;
        case North:
            newY -= hopLength;
            if (newY < 0) newY = 0;
            break;
        case South:
            newY += hopLength;
            if (newY >= 10) newY = 9;
            break;
    }
    setPosition({newX, newY});
    addPath(getPosition());
}

Hopper::Hopper() : Bug() {
    hopLength = 1;
}

void Hopper::sethopLength(int length) {
    hopLength = length;
}

int Hopper::gethopLength() {
    return hopLength;
}

Hopper::Hopper(int id, pair<int, int> position, Direction direction, int size, int hopLength) : Bug(id,position,direction, size){
    this->hopLength = hopLength;
}

Hopper::Hopper(int id, int x, int y, Direction direction, int size, int hopLength) : Bug(id,x,y,direction, size) {
    this->hopLength = hopLength;

}

Hopper::Hopper(const Hopper &hopper) : Bug(hopper.getId(), hopper.getPosition(), hopper.getDirection(), hopper.getSize()) {
    this->hopLength = hopper.hopLength;
}

const char Hopper::getType() {
    return 'H';
}

