//
// Created by Ethan JOAO on 14/03/23.
//

#include "Crawler.h"
#include <iomanip>

#include <cstdlib>

using namespace std;

void Crawler::move() {
    while (isWayBlocked()) {
        setDirection(Direction(rand() % 4 + 1));
    }
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
    addPath(getPosition());

}

Crawler::Crawler(int id, pair<int, int> position, Direction direction, int size) : Bug(id, position, direction, size) {
    //Do nothing
}

Crawler::Crawler() : Bug() {
    // Do nothing
}

Crawler::Crawler(int id, int x, int y, Direction direction, int size) : Bug(id, x, y, direction, size) {
    // Do nothing
}

Crawler::Crawler(const Crawler &crawler) : Bug(crawler.getId(), crawler.getPosition(), crawler.getDirection(),
                                               crawler.getSize()) {

}

const char Crawler::getType() {
    return 'C';
}

ostream &Crawler::print(ostream &out) const {
    stringstream ss;
    ss << '(' << getX() << ',' << getY() << ")";
    out << left << setw(4) << getId()
        << setw(8) << "Crawler"
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
