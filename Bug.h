//
// Created by Ethan JOAO on 14/03/23.
//
#include <utility>
#include <list>

using namespace std;
#ifndef JOAO_ETHAN_CA3_BUG_H
#define JOAO_ETHAN_CA3_BUG_H
enum Direction : int {North = 1, East = 2, South = 3, West = 4};

class Bug {
private:
    int id,size;
    pair<int,int> position;
    Direction direction;
    bool alive;
    list<pair<int,int>> path;

protected:
    //setters
    void setDirection(Direction dir);
    void setPosition(pair<int, int> pos);
    void setX(int x);
    void setY(int y);
    void kill();
    void addPath(pair<int, int> pos);
public:
    //constructors
    Bug(int id, pair<int,int> position, Direction direction, int size);
    Bug(int id, int x, int y, Direction direction, int size);
    Bug();

    virtual void move() =0;
    virtual const char getType() =0;
    //getters
    bool isWayBlocked();
    int getId() const;
    int getSize() const;
    pair<int, int> getPosition() const;
    int getX() const;
    int getY() const;
    Direction getDirection() const;
    bool isAlive() const;
    list<pair<int, int>> getPath() const;

};


#endif //JOAO_ETHAN_CA3_BUG_H
