//
// Created by Ethan JOAO on 28/03/23.
//

#ifndef JOAO_ETHAN_CA3_BOARD_H
#define JOAO_ETHAN_CA3_BOARD_H


#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <SFML/Graphics.hpp>
#include "Bug.h"
#include "SuperBug.h"

class Board {
private:
    std::vector<Bug *> bug_vector;
    std::map<std::pair<int, int>, std::vector<Bug *>> cells;

    Bug *parseLine(const std::string &line);

    static void getData(std::stringstream &strm, std::string &var);

    std::ostream &printLifeHistories(std::ostream &out) const;

    void updateCell(Bug *bug);

    void drawBugs(sf::RenderWindow &window, sf::Font &font, int windowSize, int nbCells);

    void createGrid(std::vector<sf::RectangleShape> &board, int windowSize, int nbCells);

    void movePlayer(Direction direction, SuperBug* player);

    void fight(const std::pair<int, int> &position);
public:
    Board();

    //Copy constructor
    Board(const Board &source);

    //Destructor
    ~Board();


    //Assignment operator
    Board &operator=(const Board &otherBoard);

    void load(const std::string &fname);

    void displayBugs() const;

    void findBug(int id);

    void tap();

    void displayLifeHistories();

    void exit();

    bool gameOver();

    void displayAllCells();

    void run();
};


#endif //JOAO_ETHAN_CA3_BOARD_H
