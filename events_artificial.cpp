//
// Created by ruslan on 5/18/17.
//

#include "events_artificial.h"
#include "artificial_houseplant.h"

using namespace artificial_event;

const ErrorWatering::DescriptorType ErrorWatering::descriptor = "Error watering";
Event::DescriptorType ErrorWatering::EventToString(const Houseplant * _hp) const {
    std::string s {"Error. Artificial houseplant should not be watered."};
    return s;
}

