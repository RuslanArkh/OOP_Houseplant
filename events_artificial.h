//
// Created by ruslan on 5/18/17.
//

#ifndef LB_3_HOUSEPLANT_EVENTS_ARTIFICIAL_H
#define LB_3_HOUSEPLANT_EVENTS_ARTIFICIAL_H

#include "event.h"

namespace artificial_event {

    class ErrorWatering : public Event {
    public:

        ErrorWatering() {}

        virtual ~ErrorWatering() {}

        static const DescriptorType descriptor;

        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };

    inline Event::DescriptorType ErrorWatering::type() const { return descriptor; }
}

#endif //LB_3_HOUSEPLANT_EVENTS_ARTIFICIAL_H
