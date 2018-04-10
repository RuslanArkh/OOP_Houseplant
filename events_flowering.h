//
// Created by ruslan on 5/11/17.
//

#ifndef LB_3_HOUSEPLANT_START_FLOWERING_H
#define LB_3_HOUSEPLANT_START_FLOWERING_H

#include "event.h"

namespace flowering_event {
    class StartFlowering : public Event {
    public:

        StartFlowering() {}

        virtual ~StartFlowering() {}

        static const DescriptorType descriptor;

        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };

    inline Event::DescriptorType StartFlowering::type() const { return descriptor; }

/*-------------------------------------------------------------------------------------------*/

    class FloweringSuccessfulFinish : public Event {
    public:

        FloweringSuccessfulFinish() {}

        virtual ~FloweringSuccessfulFinish() {}

        static const DescriptorType descriptor;

        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };

    inline Event::DescriptorType FloweringSuccessfulFinish::type() const { return descriptor; }

/*-------------------------------------------------------------------------------------------*/

    class WateringHurried : public Event {
    public:

        WateringHurried() {}

        virtual ~WateringHurried() {}

        static const DescriptorType descriptor;

        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };

    inline Event::DescriptorType WateringHurried::type() const { return descriptor; }

/*-------------------------------------------------------------------------------------------*/

    class WateringLate : public Event {
    public:

        WateringLate() {}

        virtual ~WateringLate() {}

        static const DescriptorType descriptor;

        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };

    inline Event::DescriptorType WateringLate::type() const { return descriptor; }

/*------------------------------------------------------------------------------------*/

    class FailedFlowering : public Event {
    public:

        FailedFlowering() {}

        virtual ~FailedFlowering() {}

        static const DescriptorType descriptor;

        DescriptorType EventToString(const Houseplant * _hp) const override;
        virtual DescriptorType type() const;
    };

    inline Event::DescriptorType FailedFlowering::type() const { return descriptor; }
}

#endif //LB_3_HOUSEPLANT_START_FLOWERING_H
