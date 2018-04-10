//
// Created by ruslan on 5/11/17.
//

#include "events_flowering.h"

#include "flowering_houseplant.h"


using namespace flowering_event;

std::string flowering_warning(const Houseplant * _hp) {
    std::string s{""};
    const FloweringHouseplant * fh = dynamic_cast<const FloweringHouseplant * >(_hp);
    if (fh->GetCurrentWaterings() > 0)
        s += "Amount of true waterings is decreased by 1.\n" +
                std::string("Current amount of true waterings is: ") + std::to_string(fh->GetCurrentWaterings());
    else
        s += "Amount of true watering is 0.\n"
                "Please, follow watering plan, or the plant will die.";
    return s;
}

const StartFlowering::DescriptorType StartFlowering::descriptor = "Start flowering";
Event::DescriptorType StartFlowering::EventToString(const Houseplant * _hp) const {
    return "Plant started flowering.";
}

const FloweringSuccessfulFinish::DescriptorType FloweringSuccessfulFinish::descriptor = "Stop flowering";
Event::DescriptorType FloweringSuccessfulFinish::EventToString(const Houseplant * _hp) const {
    std::string s{"Congratulations! Flowering period is passed.\n "
                  "Now plant is stronger and its watering interval increased for 2 days: "};
    s += std::to_string(_hp->WateringInterval());
    return s.c_str();
}

const WateringHurried::DescriptorType WateringHurried::descriptor = "Watering hurry";
Event::DescriptorType WateringHurried::EventToString(const Houseplant * _hp) const {
    std::string s {"Warning! Watering is hurried.\n"};
    s += flowering_warning(_hp);
    return s;
}

const WateringLate::DescriptorType WateringLate::descriptor = "Watering delay";
Event::DescriptorType WateringLate::EventToString(const Houseplant * _hp) const {
    std::string s {"Warning! Too many days without watering. "};
    s += flowering_warning(_hp);
    return s;
}

const FailedFlowering::DescriptorType FailedFlowering::descriptor = "Failed flowering";
Event::DescriptorType FailedFlowering::EventToString(const Houseplant * _hp) const {
    return "Flowering is failed, because of watering plan disparity.";
}