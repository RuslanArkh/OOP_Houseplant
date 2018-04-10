//
// Created by ruslan on 5/12/17.
//

#ifndef LB_3_HOUSEPLANT_EVENTS_FRUITING_H
#define LB_3_HOUSEPLANT_EVENTS_FRUITING_H

#include "event.h"

namespace fruiting_event {

    class StartFruiting : public Event {
    public:

        StartFruiting() {}

        virtual ~StartFruiting() {}

        static const DescriptorType descriptor;

        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };

    inline StartFruiting::DescriptorType StartFruiting::type() const { return StartFruiting::descriptor; }

    class FruitIsReady : public Event {
    public:

        FruitIsReady() {}

        virtual ~FruitIsReady() {}

        static const DescriptorType descriptor;

        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };

    inline FruitIsReady::DescriptorType FruitIsReady::type() const { return FruitIsReady::descriptor; }


    class FruitingFailed : public Event {
    public:

        FruitingFailed() {}

        virtual ~FruitingFailed() {}

        static const DescriptorType descriptor;

        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };

    inline FruitingFailed::DescriptorType FruitingFailed::type() const { return FruitingFailed::descriptor; }


}



#endif //LB_3_HOUSEPLANT_EVENTS_FRUITING_H
