//
// Created by ruslan on 5/18/17.
//

#include "events_foliar.h"
#include "foliar_houseplant.h"

using namespace foliar_event;

const TooLarge::DescriptorType TooLarge::descriptor = "Too large";
Event::DescriptorType TooLarge::EventToString(const Houseplant * _hp) const {
    std::string s{"The plant " + dynamic_cast<const FoliarHouseplant *>(_hp)->Title() + " is too large!\n"};
    s +="Its height is: " +  std::to_string(dynamic_cast<const FoliarHouseplant *>(_hp)->Height());
    s += "\nIt must be replanted.";
    return s;
}

const GrowEvent::DescriptorType GrowEvent::descriptor = "Grow";
Event::DescriptorType GrowEvent::EventToString(const Houseplant * _hp) const {
    std::string s{"The plant "};
    s += dynamic_cast<const FoliarHouseplant *>(_hp)->Title();
    s += " is higher for 1 cm\n";
    s += "Its height is: " +  std::to_string(dynamic_cast<const FoliarHouseplant *>(_hp)->Height());
    return s;
}

const ReplantEvent::DescriptorType ReplantEvent::descriptor = "Replant";
Event::DescriptorType ReplantEvent::EventToString(const Houseplant * _hp) const {
    std::string s{"The plant is reproduced and pushed back to the room.\n"};
    s += "The height of old plant is: " + std::to_string(dynamic_cast<const FoliarHouseplant *>(_hp)->Height());
    s += " cm.";
    return s;
}