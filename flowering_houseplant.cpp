
#include "flowering_houseplant.h"
#include "events_flowering.h"
#include "console_logger.h"
#include <cstdlib>
#include <initializer_list>
#include <map>

using namespace flowering_event;

FloweringHouseplant::FloweringHouseplant(
        const std::string & _name
        ,   int _ageInDays
        ,   int _wateringInterval
        ,   int _floweringDuration
        ,   int _necessaryWaterings
        ,   int _daysFromLastWatering
        ,   int _currentWaterings
)
        : Houseplant(_name, _ageInDays, _wateringInterval, _daysFromLastWatering)
        ,   FloweringDuration(_floweringDuration)
        ,   n_NecessaryWateringsForFlowering(_necessaryWaterings)
        ,   m_nCurrentProperWaterings(_currentWaterings)
{
    dispatcher->AddEvents({flowering_event::StartFlowering::descriptor,
                           flowering_event::FloweringSuccessfulFinish::descriptor,
                           flowering_event::WateringHurried::descriptor,
                           flowering_event::WateringLate::descriptor,
                           flowering_event::FailedFlowering::descriptor});

    //for (auto des: dispatcher)
}

//void FloweringHouseplant::Attach(Observer & _obs) {
//    dispatcher->AddObserver(&_obs);
//}

void FloweringHouseplant::DoWatering() {
    // TODO - Redo. Use date instead of usual counter.

    // Check if it is already watered at current day
    if (DaysFromLastWatering == 0) {
        DEBUG("Plant is already watered today." << std::endl);
        return;
    }

    //  [3.3.1] If watering is made according strictly to the watering plan
    if ( DaysFromLastWatering == n_WateringInterval) {
        ++m_nCurrentProperWaterings;
        DEBUG("True watering.\nAmount of true waterings: " << m_nCurrentProperWaterings << "\n");
    }
    //  [3.3.3] If watering is hurried or late for MORE than one day
    else if (std::abs(DaysFromLastWatering - n_WateringInterval) > 1) {
        DEBUG("Not true watering.\n");
        if (!IS_FLOWERING) {
            DEBUG("Decreasing m_CurrentTrueWaterings (" << m_nCurrentProperWaterings << ").\n");
            //  [3.3.3] ...and is NOT flowering
            //  decrease the amount of proper waterings
            if (m_nCurrentProperWaterings > 0) {
                --m_nCurrentProperWaterings;
            }

            dispatcher->post(WateringHurried(), this);

        } else {
            //  [3.4.3] If plant is flowering and watering is made not by schedule:
            ChangeState(false);
            dispatcher->post(FailedFlowering(), this);
        }
    }
    //  [3.3.2] Last case - if watering is hurried or late for one day
    else {
        DEBUG("Do nothing\n");
    }
    DaysFromLastWatering = 0;
}

void FloweringHouseplant::DayPassed() {

    ++m_ageInDays;
    ++DaysFromLastWatering;

    //  If the plant is not flowering...
    if (!IS_FLOWERING) {
        //  [3.4] ...and was watered with necessary amount of true waterings
        if (m_nCurrentProperWaterings == n_NecessaryWateringsForFlowering) {
            //  Than reset its counters` and flowering state to 'true'
            ChangeState(true);
            dispatcher->post(StartFlowering(), this);
        }
    }
    //  The plant is flowering (3.4):
    else {
        //  [3.4.3] Too many days without water - the plant must stop flowering
        if (DaysFromLastWatering > (n_WateringInterval + 1)) {
            ChangeState(false);
            dispatcher->post(FailedFlowering(), this);
            return;
        }
        //  [3.4.4] If flowering is finished successfully
        if (m_CurrentFloweringDays++ == FloweringDuration) {
            //  Flowering is passed, so stop it:
            ChangeState(false);
            //  [3.4.4] The plant "becomes stronger" - watering interval increases:
            n_WateringInterval += 2;
            //  [3.4.4] Print congrats on a screen
            //  TODO: use some OBSERVER pattern (or smth. else) for console printing
            DEBUG("Congratulation! Successful flowering period passed!\n");
            dispatcher->post(FloweringSuccessfulFinish(), this);
        }

    }
}


/*----------------------------------------------------------------------------*/

//  Additional functions

void FloweringHouseplant::ChangeState(bool _isFlowering) {
    IS_FLOWERING = _isFlowering;
    // Reseting counters
    m_CurrentFloweringDays = 0;
    m_nCurrentProperWaterings = 0;
}
