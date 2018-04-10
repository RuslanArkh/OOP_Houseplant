//
// Created by ruslan on 5/18/17.
//

#ifndef LB_3_HOUSEPLANT_ROOM_UPDATER_H
#define LB_3_HOUSEPLANT_ROOM_UPDATER_H

#include "room.h"
#include "observer.h"

#include <iostream>


class RoomUpdater : public Observer {
public:

    void handle(const Event & event, const FloweringHouseplant * _hp) override {}
    void handle(const Event & event, const FruitingHouseplant * _hp) override {}
    void handle(const Event & event, const ArtificialHouseplant * _hp) override {}
    void handle(const Event & event, const FoliarHouseplant * _hp) override;

    RoomUpdater(Room & _r);
private:

    Room & _room;
};

#endif //LB_3_HOUSEPLANT_ROOM_UPDATER_H
