//
// Created by Ethan JOAO on 28/03/23.
//

#ifndef JOAO_ETHAN_CA3_BOARD_H
#define JOAO_ETHAN_CA3_BOARD_H


#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "Bug.h"
using namespace std;
class Board {
private:
    vector<Bug*> bug_vector;
    map<pair<int,int>,vector<Bug*>> cells;

    Bug* parseLine(const string &line);

    static void getData(stringstream &strm, string &var);

    ostream& printLifeHistories(ostream&out) const;

    void updateCell(Bug* bug);
public:
    Board();

    //Copy constructor
    Board(const Board& source);

    //Destructor
    ~Board();


    //Assignment operator
    Board& operator= (const Board& otherBoard);

    void load(const string& fname);

    void displayBugs() const;

    void findBug(int id);

    void tap();

    void displayLifeHistories();

    void exit();

    bool gameOver();

    void displayAllCells();
};


#endif //JOAO_ETHAN_CA3_BOARD_H
