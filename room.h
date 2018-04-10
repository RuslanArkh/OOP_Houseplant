
#ifndef LB_3_HOUSEPLANT_ROOM_H
#define LB_3_HOUSEPLANT_ROOM_H

#include <memory>
#include <vector>
#include <initializer_list>

#include "houseplant.h"



class Room {

    //  TODO: Iterator
    //class Iterator;

    const int height;

    std::vector< const Houseplant * > m_plants;

    friend class Iterator;

public:

    Room(int _height = 300);

    Room(
            std::initializer_list< const Houseplant * > _houseplantList,
            int _height = 300
    );

    void Add(const Houseplant & _plant);

    const std::vector<const Houseplant *> & getPlants() const { return m_plants; }

    int Height() const;

    class Iterator {
        std::vector<const Houseplant *>::iterator _it;
    public:

        Iterator(const Houseplant * _hp) : _it{std::vector<const Houseplant *>::iterator()} {}
    };

    Iterator begin() const { return Iterator(m_plants.at(0)); }
};
inline void Room::Add(const Houseplant & _plant) {
    m_plants.push_back(&_plant);
}

inline int Room::Height() const { return height; }

#endif //LB_3_HOUSEPLANT_ROOM_H
