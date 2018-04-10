//
// Created by ruslan on 8/13/16.
//

#ifndef LB_3_HOUSEPLANT_FLOWERINGHOUSEPLANT_H
#define LB_3_HOUSEPLANT_FLOWERINGHOUSEPLANT_H

#include "houseplant.h"
#include <string>


class FloweringHouseplant
        : public Houseplant {

    /*------------------------------------------------*/
    //  [According to the task]

    //  [3.1] Amount of days for flowering:
    const int FloweringDuration;

    //  [3.2.1] Amount of watering needed for flowering
    const int n_NecessaryWateringsForFlowering;

protected:

    //  [3.2.2] Current amount of proper waterings
    int m_nCurrentProperWaterings;

protected:

    /*------------------------------------------------*/
    //  [Own ideas]
    //  Current amount of days of flowering
    int m_CurrentFloweringDays = 0;

    //  [Own ideas]
    //  Variable, which is created for 2 purposes:
    //  1) It tells that the flower is watered (today),
    //  e.g., if (DaysFromLastWatering == 0) -> It is already watered today.
    //  2) It is also a counter for days passed from last watering -> useful for checking watering strategy.
    //  3) TODO: it can substitute the m_lastWatering, just telling how many days ago the plant was flowered
    //  int DaysFromLastWatering;

protected:
    //  [Own ideas]
    //  Shows the state of a plant (default = false).
    bool IS_FLOWERING = false;

public:

    explicit FloweringHouseplant(
            const std::string & _name
            ,   int _ageInDays
            ,   int _wateringInterval
            ,   int _floweringDuration
            ,   int _necessaryWaterings
            ,   int _daysFromLastWatering
            ,   int _currentWaterings = 0
    );

    virtual void DoWatering() override;
    virtual void DayPassed() override;


    int GetCurrentWaterings() const;

    bool isFlowering() const;

    int GetFloweringDays() const;


private:

    void ChangeState(bool _isFlowering);
};

inline int FloweringHouseplant::GetCurrentWaterings() const {
    return m_nCurrentProperWaterings;
}

inline bool FloweringHouseplant::isFlowering() const { return IS_FLOWERING; }

inline int FloweringHouseplant::GetFloweringDays() const { return m_CurrentFloweringDays; }


#endif //LB_3_HOUSEPLANT_FLOWERINGHOUSEPLANT_H
