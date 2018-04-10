
#ifndef FOLIAR_HOUSEPLANT_H
#define FOLIAR_HOUSEPLANT_H

#include "houseplant.h"

#include <string>

class FoliarHouseplant
	: public Houseplant {

	//	[5.1] Height of plant (sm)
	mutable int m_height;

	//
	const int MAX_HEIGHT;

	bool isWateredByPlan = false;


public:

	FoliarHouseplant(const FoliarHouseplant & _fp);

	void DayPassed() override;
	void DoWatering() override;

	void Grow();

	explicit FoliarHouseplant(
			std::string const & _name
			,   int _ageInDays
			,   int _wateringInterval
			,   int _lastWatering
			,	int _height
			,	int _max_height
	);

	FoliarHouseplant * reproduce() const;

    //  [Getters]
    int Height() const;
    int MaxHeight() const;
    int IsWateredByPlan() const;


};

inline int FoliarHouseplant::Height() const { return m_height; }
inline int FoliarHouseplant::MaxHeight() const { return MAX_HEIGHT; }
inline int FoliarHouseplant::IsWateredByPlan() const { return isWateredByPlan; }

#endif