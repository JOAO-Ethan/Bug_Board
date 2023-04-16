//
// Created by Ethan JOAO on 16/04/23.
//

#ifndef JOAO_ETHAN_CA3_BISHOPBUG_H
#define JOAO_ETHAN_CA3_BISHOPBUG_H


#include "Bug.h"

class BishopBug : public Bug {
public:
    BishopBug();

    BishopBug(int id, pair<int, int> position, Direction direction, int size);

    BishopBug(int id, int x, int y, Direction direction, int size);

    BishopBug(const BishopBug &bishopBug);

    void move() override;

    const char getType() override;

    ostream &print(ostream &out) const override;

};


#endif //JOAO_ETHAN_CA3_BISHOPBUG_H
