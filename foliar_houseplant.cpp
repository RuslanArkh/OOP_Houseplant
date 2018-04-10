

#include "foliar_houseplant.h"

#include "events_foliar.h"

using namespace foliar_event;

FoliarHouseplant::FoliarHouseplant(
		std::string const & _name
		,   int _ageInDays
		,   int _wateringInterval
		,   int _lastWatering
		,	int _height
		,	int _max_height
)
	: Houseplant(_name, _ageInDays, _wateringInterval, _lastWatering),
	  m_height(_height),
	  MAX_HEIGHT(_max_height)
{
    dispatcher->AddEvents({GrowEvent::descriptor, TooLarge::descriptor, ReplantEvent::descriptor });
}

FoliarHouseplant::FoliarHouseplant(const FoliarHouseplant & _fp)
: Houseplant(_fp.name, _fp.m_ageInDays, _fp.n_WateringInterval, _fp.DaysFromLastWatering)
,	MAX_HEIGHT(_fp.Height()){
	m_height = _fp.Height();
	isWateredByPlan = _fp.isWateredByPlan;
}

void FoliarHouseplant::DoWatering() {
	// Check if it is already watered at current day
	if (isWatered()) return;
	isWateredByPlan = std::abs(DaysFromLastWatering - n_WateringInterval) <= 1 && m_height < MAX_HEIGHT;
	DaysFromLastWatering = 0;
}

void FoliarHouseplant::DayPassed() {

	DaysFromLastWatering++;

	if (m_height >= MAX_HEIGHT) {
		//	TODO: Make a message that the plant is too large
		//	TODO: add a new plant to the room
		DEBUG("The plant is too large. Please replant!");
        dispatcher->post(TooLarge(), this);
	} else {
		//	[5.2.1] If the plant is watered by plan
		if (isWateredByPlan) {
			//	...than it must grow
			//	Event: grow for 1 cm.
			Grow();
            dispatcher->post(GrowEvent(), this);
		}
	}
    isWateredByPlan = false;
}

void FoliarHouseplant::Grow() {
	++m_height;
}

FoliarHouseplant * FoliarHouseplant::reproduce() const {
	m_height /= 2;
    dispatcher->post(ReplantEvent(), this);
	return new FoliarHouseplant(*this);
}

