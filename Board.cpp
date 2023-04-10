//
// Created by Ethan JOAO on 28/03/23.
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

Board::Board(const Board &source) {
    for (auto p_bug: source.bug_vector) {
        if (p_bug->getType() == 'C') {
            auto *p_crawl = (Crawler *) p_bug;
            bug_vector.push_back(new Crawler(*p_crawl));
        } else if (p_bug->getType() == 'H') {
            auto *p_hop = (Hopper *) p_bug;
            bug_vector.push_back(new Hopper(*p_hop));
        }
    }
}

Board::~Board() {
    for (auto p_bug: bug_vector) {
        if (p_bug->getType() == 'C') {
            delete (Crawler *) p_bug;
        } else if (p_bug->getType() == 'H') {
            delete (Hopper *) p_bug;
        }
    }
}

Board &Board::operator=(const Board &otherBoard) {
    for (auto p_bug: otherBoard.bug_vector) {
        if (p_bug->getType() == 'C') {
            auto *p_crawl = (Crawler *) p_bug;
            bug_vector.push_back(new Crawler(*p_crawl));
        } else if (p_bug->getType() == 'H') {
            auto *p_hop = (Hopper *) p_bug;
            bug_vector.push_back(new Hopper(*p_hop));
        }
    }
    return *this;
}

Board::Board() {
    load("../bugs.txt");
};

void Board::load(const string& fname) {
    ifstream fin(fname);
    if (fin) {
        string line;
        while (getline(fin, line)) {
            bug_vector.push_back(parseLine(line));
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
    if(type == "H") {
        string hope;
        getData(streamline, hope);
        return new Hopper(stoi(id),stoi(x),stoi(y),Direction(stoi(direction)),stoi(size),stoi(hope));
    } else if (type=="C") {
        return new Crawler(stoi(id), stoi(x), stoi(y), Direction(stoi(direction)), stoi(size));
    }
    return nullptr;
}

void Board::getData(stringstream &strm, string &var) {
    getline(strm, var, ';');
}

void Board::displayBugs() const {
    for(auto p_bug : bug_vector){
        cout << *p_bug << endl;
    }
}

void Board::findBug(int id) {
    auto itBug = find_if(bug_vector.begin(), bug_vector.end(),[id](Bug* p_bug) {return p_bug->getId() == id;});
    if(itBug != bug_vector.end()){
        cout << *(*itBug) << endl;
    }
    else{
        cout << "bug " << id << " not found" << endl;
    }
}



