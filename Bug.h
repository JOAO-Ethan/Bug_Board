//
// Created by Ethan JOAO on 14/03/23.
//
#include <utility>
#include <list>
#include <ostream>

#ifndef JOAO_ETHAN_CA3_BUG_H
#define JOAO_ETHAN_CA3_BUG_H
enum Direction : int {
    North = 1, East = 2, South = 3, West = 4
};

std::ostream &operator<<(std::ostream &out, Direction d);

class Bug {
protected:
    int id, size, idKiller;
    std::pair<int, int> position;
    Direction direction;
    bool alive;
    std::list<std::pair<int, int>> path;

    //setters
    void setDirection(Direction dir);

    void setPosition(std::pair<int, int> pos);

    void setX(int x);

    void setSize(int size);

    void setY(int y);

    void kill();

    void addPath(std::pair<int, int> pos);

public:
    //constructors
    Bug(int id, std::pair<int, int> position, Direction direction, int size);

    Bug(int id, int x, int y, Direction direction, int size);

    Bug();

    virtual void move() = 0;

    virtual const char getType() = 0;

    virtual std::ostream &print(std::ostream &out) const = 0;

    //getters
    bool isWayBlocked();

    int getId() const;

    int getSize() const;

    std::pair<int, int> getPosition() const;

    int getX() const;

    int getY() const;

    Direction getDirection() const;

    bool isAlive() const;

    int getIdKiller() const;

    std::list<std::pair<int, int>> getPath() const;

    friend std::ostream &operator<<(std::ostream &out, const Bug &bug);

    static std::string getFullType(char type);

    void eat(Bug &other);
};


#endif //JOAO_ETHAN_CA3_BUG_H
