//
// Created by ruslan on 5/18/17.
//

#ifndef LB_3_HOUSEPLANT_ARTIFICIAL_HOUSEPLANT_H
#define LB_3_HOUSEPLANT_ARTIFICIAL_HOUSEPLANT_H

#include "houseplant.h"

class ArtificialHouseplant
        : public Houseplant {
public:
    explicit ArtificialHouseplant(
            const std::string & _name
            ,   int _ageInDays
    );

    virtual void DoWatering() override;
    virtual void DayPassed() override { m_ageInDays++; }
};

#endif //LB_3_HOUSEPLANT_ARTIFICIAL_HOUSEPLANT_H
