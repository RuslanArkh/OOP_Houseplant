//
// Created by ruslan on 5/18/17.
//

#include "artificial_houseplant.h"
#include "events_artificial.h"

using namespace artificial_event;

ArtificialHouseplant::ArtificialHouseplant(
        const std::string & _name
        ,   int _ageInDays) : Houseplant(_name, _ageInDays, 0, 0) {
    dispatcher->AddEvent(ErrorWatering::descriptor);
}

void ArtificialHouseplant::DoWatering() {
    dispatcher->post(ErrorWatering(), this);
}
