//
// Created by ruslan on 5/18/17.
//

#include "room.h"

Room::Room(int _height) : height(_height) {}

Room::Room(std::initializer_list<const Houseplant *> _houseplantList, int _height) :height(_height) {
    for (auto & x: _houseplantList)
        m_plants.push_back(x);
}