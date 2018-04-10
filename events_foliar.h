//
// Created by ruslan on 5/15/17.
//

#ifndef LB_3_HOUSEPLANT_EVENTS_FOLIAR_H
#define LB_3_HOUSEPLANT_EVENTS_FOLIAR_H

#include "event.h"

namespace foliar_event {

    class TooLarge : public Event {
    public:
        TooLarge() {}
        virtual ~TooLarge() {}
        static const DescriptorType descriptor;
        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };
    inline TooLarge::DescriptorType TooLarge::type() const { return descriptor; }

    class GrowEvent : public Event {
    public:
        GrowEvent() {}
        virtual ~GrowEvent() {}
        static const DescriptorType descriptor;
        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };
    inline GrowEvent::DescriptorType GrowEvent::type() const { return descriptor; }

    class ReplantEvent : public Event {
    public:
        ReplantEvent() {}
        virtual ~ReplantEvent() {}
        static const DescriptorType descriptor;
        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };
    inline ReplantEvent::DescriptorType ReplantEvent::type() const { return descriptor; }
}

#endif //LB_3_HOUSEPLANT_EVENTS_FOLIAR_H
