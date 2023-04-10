//
// Created by Ethan JOAO on 28/03/23.
//

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
        }    else if (p_bug->getType() == 'H') {
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

