//
// Created by Ethan JOAO on 28/03/23.
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include <thread>

#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"
#include "BishopBug.h"

using namespace std;

Board::Board(const Board &source) {
    srand(time(nullptr));
    for (auto p_bug: source.bug_vector) {
        if (p_bug->getType() == 'C') {
            auto *p_crawl = (Crawler *) p_bug;
            bug_vector.push_back(new Crawler(*p_crawl));
        } else if (p_bug->getType() == 'H') {
            auto *p_hop = (Hopper *) p_bug;
            bug_vector.push_back(new Hopper(*p_hop));
        } else if (p_bug->getType() == 'B') {
            auto *p_bish = (BishopBug *) p_bug;
            bug_vector.push_back(new BishopBug(*p_bish));
        }
    }
}

Board::~Board() {
    for (auto p_bug: bug_vector) {
        if (p_bug->getType() == 'C') {
            delete (Crawler *) p_bug;
        } else if (p_bug->getType() == 'H') {
            delete (Hopper *) p_bug;
        } else if (p_bug->getType() == 'B') {
            delete (BishopBug *) p_bug;
        }
    }
}

Board &Board::operator=(const Board &otherBoard) {
    srand(time(nullptr));
    for (auto p_bug: otherBoard.bug_vector) {
        if (p_bug->getType() == 'C') {
            auto *p_crawl = (Crawler *) p_bug;
            bug_vector.push_back(new Crawler(*p_crawl));
        } else if (p_bug->getType() == 'H') {
            auto *p_hop = (Hopper *) p_bug;
            bug_vector.push_back(new Hopper(*p_hop));
        } else if (p_bug->getType() == 'B') {
            auto *p_bish = (BishopBug *) p_bug;
            bug_vector.push_back(new BishopBug(*p_bish));
        }
    }
    return *this;
}

Board::Board() {
    srand(time(nullptr));
    load("../bugs.txt");
};

void Board::load(const string &fname) {
    ifstream fin(fname);
    if (fin) {
        string line;
        while (getline(fin, line)) {
            bug_vector.push_back(parseLine(line));
            updateCell(bug_vector.back());
        }
    }
}

Bug *Board::parseLine(const string &line) {
    stringstream streamline(line);
    string type, id, x, y, direction, size;
    getData(streamline, type);
    getData(streamline, id);
    getData(streamline, x);
    getData(streamline, y);
    getData(streamline, direction);
    getData(streamline, size);
    if (type == "H") {
        string hope;
        getData(streamline, hope);
        return new Hopper(stoi(id), stoi(x), stoi(y), Direction(stoi(direction)), stoi(size), stoi(hope));
    } else if (type == "C") {
        return new Crawler(stoi(id), stoi(x), stoi(y), Direction(stoi(direction)), stoi(size));
    } else if (type == "B") {
        return new BishopBug(stoi(id), stoi(x), stoi(y), Direction(stoi(direction)), stoi(size));
    }
    return nullptr;
}

void Board::getData(stringstream &strm, string &var) {
    getline(strm, var, ';');
}

void Board::displayBugs() const {
    for (auto p_bug: bug_vector) {
        cout << *p_bug << endl;
    }
}

void Board::findBug(int id) {
    auto itBug = find_if(bug_vector.begin(), bug_vector.end(), [id](Bug *p_bug) { return p_bug->getId() == id; });
    if (itBug != bug_vector.end()) {
        cout << *(*itBug) << endl;
    } else {
        cout << "bug " << id << " not found" << endl;
    }
}

void Board::tap() {
    cells.clear();
    for (auto p_bug: bug_vector) {
        if (p_bug->isAlive()) {
            p_bug->move();
            updateCell(p_bug);
        }
    }
    for (auto cell: cells) {
        if (cell.second.size() > 1) {
            auto current = cell.second.front();
            for (auto p_bug: cell.second) {
                if (p_bug == current) {
                    continue;
                }
                if (current->getSize() > p_bug->getSize()) {
                    current->eat(*p_bug);
                } else if (current->getSize() < p_bug->getSize()) {
                    p_bug->eat(*current);
                    current = p_bug;
                } else {
                    if ((rand() % 2 + 1) == 1) {
                        current->eat(*p_bug);
                    } else {
                        p_bug->eat(*current);
                        current = p_bug;
                    }
                }

            }
        }
    }
}

void Board::displayLifeHistories() {
    printLifeHistories(cout);
}

void Board::exit() {
    ofstream file;
    file.open("bugs_life_history_date_time.out");
    printLifeHistories(file);
    file.close();
}

ostream &Board::printLifeHistories(ostream &out) const {
    for (auto p_bug: bug_vector) {
        out << p_bug->getId() << ' ';
        out << Bug::getFullType(p_bug->getType());
        out << ' ' << "Path:" << ' ';
        list<pair<int, int>> path = p_bug->getPath();
        for (auto &position: path) {
            out << '(' << position.first << ',' << position.second << ')';
            if (&position != &path.back()) {
                out << ',';
            }
            if (&position == &path.back()) {
            }
        }
        out << ' ';
        if (p_bug->isAlive()) {
            out << "Alive";
        } else {
            out << "Eaten by " << p_bug->getIdKiller();
        }
        out << endl;
    }
    return out;
}

void Board::updateCell(Bug *p_bug) {
    if (auto pos = cells.find(p_bug->getPosition()); pos != cells.end()) {
        pos->second.push_back(p_bug);
    } else {
        cells[p_bug->getPosition()] = {p_bug};
    }
}

void Board::displayAllCells() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << '(' << i << ',' << j << "): ";
            if (auto cell = cells.find({i, j}); cell != cells.end()) {
                for (auto p_bug: cell->second) {
                    cout << Bug::getFullType(p_bug->getType());
                    cout << " " << p_bug->getId();
                    if (p_bug != cell->second.back()) {
                        cout << " ,";
                    }
                }
            } else {
                cout << "empty";
            }
            cout << endl;
        }
    }
}

bool Board::gameOver() {
    return count_if(bug_vector.begin(), bug_vector.end(), [](Bug *p_bug) {
        return p_bug->isAlive();
    }) == 1;
}

void Board::run() {
    int windowSize = 500;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "SFML works!");
    int nbCells = 10;
    sf::Font font;
    if (!font.loadFromFile("../Ubuntu-R.ttf")){{cout << "ui" << endl;}};
    vector<sf::RectangleShape> board;
    createGrid(board,windowSize, nbCells);
    while (!gameOver() && window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        displayBugs();
        cout << endl;
        tap();
        std::this_thread::sleep_for(1s);
        window.clear();
        for (auto rect: board) {
            window.draw(rect);
        }
        drawBugs(window,windowSize, nbCells);
        window.display();
    }
    displayBugs();
    stringstream sstrm;
    auto winner = find_if(bug_vector.begin(), bug_vector.end(), [](Bug *p_bug){ return p_bug->isAlive();
    });
    sstrm << (*winner)->getId() << " Won !";
    sf::Text win;
    win.setString(sstrm.str());
    win.setFont(font);
    win.setCharacterSize(24);
    win.setPosition(windowSize/3, windowSize/2);
    win.setStyle(sf::Text::Bold);
    win.setFillColor(sf::Color::Black);
    window.draw(win);
    window.display();
    std::this_thread::sleep_for(2s);
    exit();
    window.close();

}

void Board::drawBugs(sf::RenderWindow &window, int windowSize, int nbCells) {
    for (auto p_bug: bug_vector) {
        if (p_bug->isAlive()) {
            sf::CircleShape bugSprite;
            if (p_bug->getSize() < (windowSize / nbCells) - 1) {
                bugSprite.setRadius(p_bug->getSize());
            } else {
                bugSprite.setRadius((windowSize / nbCells) - 1);
            }
            bugSprite.setPosition(p_bug->getX() * (windowSize / nbCells) - 1,
                                  p_bug->getY() * (windowSize / nbCells) - 1);
            switch (p_bug->getType()) {
                case ('C'):
                    bugSprite.setFillColor(sf::Color::Cyan);
                    break;
                case ('H'):
                    bugSprite.setFillColor(sf::Color::Green);
                    break;
                case ('B'):
                    bugSprite.setFillColor(sf::Color::Magenta);
                    break;
                default:
                    bugSprite.setFillColor(sf::Color::Yellow);
            }
            window.draw(bugSprite);
        }
    }
}

void Board::createGrid(vector<sf::RectangleShape> &board, int windowSize, int nbCells) {
    for (int x = 0; x < nbCells; x++) {
        for (int y = 0; y < nbCells; y++) {
            sf::RectangleShape rect(sf::Vector2f(windowSize / nbCells, windowSize / nbCells));
            rect.setPosition(x * (windowSize / nbCells), y * (windowSize / nbCells));
            rect.setFillColor(sf::Color::White);
            rect.setOutlineThickness(1.f);
            rect.setOutlineColor(sf::Color::Black);
            board.push_back(rect);

        }
    }

}




