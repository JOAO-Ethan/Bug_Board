//
// Created by Ethan JOAO on 28/03/23.
//

#ifndef JOAO_ETHAN_CA3_BOARD_H
#define JOAO_ETHAN_CA3_BOARD_H


#include <vector>
#include "Bug.h"
using namespace std;
class Board {
private:
    vector<Bug*> bug_vector;
public:

    //Copy constructor
    Board(const Board& source);

    //Destructor
    ~Board();


    //Assignment operator
    Board& operator= (const Board& otherBoard);

};


#endif //JOAO_ETHAN_CA3_BOARD_H
