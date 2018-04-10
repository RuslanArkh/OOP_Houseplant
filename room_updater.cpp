//
// Created by ruslan on 5/18/17.
//

#include "room_updater.h"

#include "foliar_houseplant.h"

RoomUpdater::RoomUpdater(Room &_r) : _room(_r) {}

void RoomUpdater::handle(const Event & event, const FoliarHouseplant * _hp) {
    std::cout << "\nWould you like to replant it? (y/N) ";
    std::string s;
    std::cin >> s;
    if (s == "y")
        _room.Add(*_hp->reproduce());
}