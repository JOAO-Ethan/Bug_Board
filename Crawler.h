//
// Created by ubuntu on 14/03/23.
//

#ifndef JOAO_ETHAN_CA3_CRAWLER_H
#define JOAO_ETHAN_CA3_CRAWLER_H


#include "Bug.h"

class Crawler : public Bug {
public:
    Crawler();
    Crawler(int id, pair<int,int> position, Direction direction, int size);
    Crawler(int id, int x, int y, Direction direction, int size);

    Crawler(const Crawler &crawler);
    void move() override;
    const char getType() override;
};


#endif //JOAO_ETHAN_CA3_CRAWLER_H
