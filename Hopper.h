//
// Created by Ethan JOAO on 22/03/23.
//

#ifndef JOAO_ETHAN_CA3_HOPPER_H
#define JOAO_ETHAN_CA3_HOPPER_H


#include <ostream>
#include "Bug.h"

class Hopper : public Bug{
private:
    int hopLength;

    //setters
    void sethopLength(int length);
public:
    Hopper();
    Hopper(int id, std::pair<int,int> position, Direction direction, int size, int hopLength);
    Hopper(int id, int x, int y, Direction direction, int size, int hopLength);
    Hopper(const Hopper &hopper);

    void move() override;
    const char getType() override;
    std::ostream& print(std::ostream&out) const override;
    //getters
    int gethopLength();


};


#endif //JOAO_ETHAN_CA3_HOPPER_H
