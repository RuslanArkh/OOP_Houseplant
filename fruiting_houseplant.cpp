
#include "fruiting_houseplant.h"

#include <cstdlib>

#include "events_fruiting.h"

using namespace fruiting_event;

FruitingHouseplant::FruitingHouseplant(
		//	Delegate constructor parameters:
		const std::string & _name
		,   int _ageInDays
		,   int _wateringInterval
		,   int _floweringDuration
		,   int _necessaryWaterings

		//	Derived class parameters:
		,	const std::string & _fruitName
		,	int _fruitingDuration
		// 	Default values
		,   int _lastWatering
		,   int _currentWaterings
)
		: FloweringHouseplant(_name, _ageInDays, _wateringInterval, _floweringDuration, _necessaryWaterings, _lastWatering)
		, s_FruitName(_fruitName)
		, n_FruitingDuration(_fruitingDuration)
{
    dispatcher->AddEvents({StartFruiting::descriptor,
                           FruitIsReady::descriptor,
                           FruitingFailed::descriptor});
}

void FruitingHouseplant::DoWatering() {
    //  [4.4] Check if watering made accroding to the plan while fruiting
	if (IS_FRUITING)
		if (std::abs(DaysFromLastWatering - n_WateringInterval) > 1) {
			IS_FRUITING = false;
			//	[Event] - fruiting failed.
            dispatcher->post(FruitingFailed(), this);
		}


	FloweringHouseplant::DoWatering();
}

void FruitingHouseplant::DayPassed() {
	if (!IS_FRUITING) {
		is_flowering_old = IS_FLOWERING;

		FloweringHouseplant::DayPassed();
        //  [4.3] Fruiting starts right after the flowering:
        //  One day ago the plant was flowering (is_flowering_old == true)
        //  and TODAY it is not flowering (IS_FLOWERING == false)
        //  and the watering was proper (DaysFromLastWatering < (WateringInterval + 1)
        //  and also it is NOT fruiting right now (see above: !IS_FRUITING)
        //  !SO! the plant MUST start fruiting
		if (is_flowering_old && !IS_FLOWERING && DaysFromLastWatering < (n_WateringInterval + 1)) {
			IS_FRUITING = true;
			DEBUG("Hey, I have fruit right now!");
			//	[Event] - start fruiting!
            dispatcher->post(StartFruiting(), this);
		}
	} else {
        //  [4.4] During the period of fruiting the plant also must be properly watered

		++m_ageInDays;
		++DaysFromLastWatering;

		if (m_nCurrentFruitingDays++ == n_FruitingDuration) {
			m_nCurrentFruitingDays = 0;
			IS_FRUITING = false;
			//  TODO: use some OBSERVER pattern (or smthg. else) for console printing
			DEBUG("Successful fruiting period passed! Take some: " << s_FruitName << "(s)!\n");
			//	[Event] - fruit is ready!
            dispatcher->post(FruitIsReady(), this);
		}
		//  Too many days without water - the plant must stop flowering
		if (DaysFromLastWatering > (n_WateringInterval + 1)) {
			DEBUG("Watering period violated! Plant is stopping fruiting!\n");
			IS_FRUITING = false;
			m_nCurrentFruitingDays = 0;
			m_nCurrentProperWaterings = 0;
			//	[Event] Failed fruiting
            dispatcher->post(FruitingFailed(), this);
		}
	}
}