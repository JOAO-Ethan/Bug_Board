//
// Created by Ethan JOAO on 18/04/23.
//

#include "SuperBug.h"
#include <sstream>
#include <iomanip>

using namespace std;

SuperBug::SuperBug() : Bug() {}

SuperBug::SuperBug(int id, std::pair<int, int> position, Direction direction, int size) : Bug(id, position, direction,
                                                                                              size) {}

SuperBug::SuperBug(int id, int x, int y, Direction direction, int size) : Bug(id, x, y, direction, size) {}

SuperBug::SuperBug(const SuperBug &bug) : Bug(bug.getId(), bug.getPosition(), bug.getDirection(), bug.getSize()) {}

void SuperBug::move() {
    switch (getDirection()) {
        case East:
            if (!isWayBlocked()) setX(getX() + 1);
            break;
        case West:
            if (!isWayBlocked()) setX(getX() - 1);
            break;
        case North:
            if (!isWayBlocked()) setY(getY() - 1);
            break;
        case South:
            if (!isWayBlocked()) setY(getY() + 1);
            break;
    }
    addPath(getPosition());
}

const char SuperBug::getType() {
    return 'S';
}

std::ostream &SuperBug::print(std::ostream &out) const {
    stringstream ss;
    ss << '(' << getX() << ',' << getY() << ")";
    out << left << setw(4) << getId()
        << setw(8) << "SuperBug"
        << setw(6) << ss.str()
        << setw(4) << getSize()
        << setw(6) << getDirection()
        << setw(5);
    if (isAlive()) {
        out << "Alive";
    } else {
        out << "Eaten by " << getIdKiller();
    }
    return out;
}

void SuperBug::move(Direction direction) {
    setDirection(direction);
    move();
}



