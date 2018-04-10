//
// Created by ruslan on 5/11/17.
//

#ifndef LB_3_HOUSEPLANT_EVENT_H
#define LB_3_HOUSEPLANT_EVENT_H

#include "debug_mode.h"

#include <string>
class Houseplant;

class Event {
public:

    virtual ~Event() = default;

    using DescriptorType = std::string;

    virtual DescriptorType EventToString(const Houseplant * _hp) const = 0;
    virtual DescriptorType type() const = 0;
};

#endif //LB_3_HOUSEPLANT_EVENT_H
