//
// Created by Ethan JOAO on 16/04/23.
//

#include <sstream>
#include <iomanip>
#include "BishopBug.h"

using namespace std;

BishopBug::BishopBug() : Bug() {

}

BishopBug::BishopBug(int id, pair<int, int> position, Direction direction, int size) : Bug(id, position, direction,
                                                                                           size) {

}

BishopBug::BishopBug(int id, int x, int y, Direction direction, int size) : Bug(id, x, y, direction, size) {

}

BishopBug::BishopBug(const BishopBug &bishopBug) : Bug(bishopBug.getId(), bishopBug.getPosition(),
                                                       bishopBug.getDirection(),
                                                       bishopBug.getSize()) {

}

void BishopBug::move() {
    while (isWayBlocked()) {
        setDirection(Direction(rand() % 4 + 1));
    }
    for (int i = 0; i < 2; i++) {
        switch (getDirection()) {
            case East:
                setX(getX() + 1);
                break;
            case West:
                setX(getX() - 1);
                break;
            case North:
                setY(getY() - 1);
                break;
            case South:
                setY(getY() + 1);
                break;
        }
        if (i > 0) { continue; }
        if (getDirection() == East || getDirection() == West) {
            do {
                if ((rand() % 2 + 1) == 1) { setDirection(North); } else { setDirection(South); }
            } while (isWayBlocked());
        } else {
            do {
                if ((rand() % 2 + 1) == 1) { setDirection(East); } else { setDirection(West); }
            } while (isWayBlocked());
        }
    }
    addPath(getPosition());
}

const char BishopBug::getType() {
    return 'B';
}

ostream &BishopBug::print(ostream &out) const {
    stringstream ss;
    ss << '(' << getX() << ',' << getY() << ")";
    out << left << setw(4) << getId()
        << setw(8) << "BishopBug"
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
