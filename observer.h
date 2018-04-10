
#ifndef LB_3_HOUSEPLANT_OBSERVER_H
#define LB_3_HOUSEPLANT_OBSERVER_H

#include "event.h"

class FloweringHouseplant;
class FruitingHouseplant;
class FoliarHouseplant;
class ArtificialHouseplant;

class Observer {
public:

    virtual void handle(const Event & event, const FloweringHouseplant * _hp) = 0;
    virtual void handle(const Event & event, const FruitingHouseplant * _hp) = 0;
    virtual void handle(const Event & event, const FoliarHouseplant * _hp) = 0;
    virtual void handle(const Event & event, const ArtificialHouseplant * _hp) = 0;
};

#endif //LB_3_HOUSEPLANT_OBSERVER_H
