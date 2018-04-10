//
// Created by ruslan on 5/12/17.
//

#include "events_fruiting.h"
#include "fruiting_houseplant.h"


using namespace fruiting_event;


const StartFruiting::DescriptorType StartFruiting::descriptor = "Start fruiting";
Event::DescriptorType StartFruiting::EventToString(const Houseplant * _hp) const {
    std::string s {"Congratulations! New fruit - " +
                 (dynamic_cast<const FruitingHouseplant *>(_hp))->FruitName()};
    s += " - started to grow.";
    return s;
}

const FruitIsReady::DescriptorType FruitIsReady::descriptor = "Fruit is ready";
Event::DescriptorType FruitIsReady::EventToString(const Houseplant * _hp) const{
    std::string s = "Congratulations! Your fruit - " + dynamic_cast<const FruitingHouseplant *>(_hp)->FruitName() +
            " - is ready. Take it and eat!";
    return s;
}

const FruitingFailed::DescriptorType FruitingFailed::descriptor = "Fruiting failed";
Event::DescriptorType FruitingFailed::EventToString(const Houseplant * _hp) const {
    return "Fruiting is failed, because of watering plan disparity.";
}
