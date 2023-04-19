//
// Created by ubuntu on 18/04/23.
//

#ifndef JOAO_ETHAN_CA3_SUPERBUG_H
#define JOAO_ETHAN_CA3_SUPERBUG_H


#include "Bug.h"

class SuperBug : public Bug {
public:
    SuperBug();

    SuperBug(int id, std::pair<int, int> position, Direction direction, int size);

    SuperBug(int id, int x, int y, Direction direction, int size);

    SuperBug(const SuperBug &bug);

    void move() override;

    const char getType() override;

    std::ostream &print(std::ostream &out) const override;

    void move(Direction direction);
};


#endif //JOAO_ETHAN_CA3_SUPERBUG_H
