//
// Created by ruslan on 8/28/16.
//

#ifndef LB_3_HOUSEPLANT_FRUITING_HOUSEPLANT_H
#define LB_3_HOUSEPLANT_FRUITING_HOUSEPLANT_H

#include "flowering_houseplant.h"

class FruitingHouseplant
        : public FloweringHouseplant {

private:

	/*------------------------------------------------*/
	//  [According to the task]
    //  [4.1] Title of the fruit
    const std::string s_FruitName;
    //  [4.2] Duration of the fruiting
    const int n_FruitingDuration;

	/*------------------------------------------------*/

	//	[Own ideas]
	//	Identifies the state of plant
	bool IS_FRUITING = false;
    //  Track state changing from "flowering" to "fruiting"
	bool is_flowering_old = false;

	int m_nCurrentFruitingDays = 0;

public:

    void DayPassed() override;
    void DoWatering() override;

	explicit FruitingHouseplant(
			const std::string & _name
			,   int _ageInDays
			,   int _wateringInterval
			,   int _floweringDuration
			,   int _necessaryWaterings
			,	const std::string & _fruitName
			,	int _fruitingDuration
			,   int _lastWatering
			,   int _currentWaterings = 0
	);

	std::string FruitName() const;
	int FruitingDuration() const;
	bool IsFruiting() const;
	int CurrentFruitingDays() const;


	//void Attach(Observer & _obs) {}

};

inline	std::string FruitingHouseplant::FruitName() const { return s_FruitName; }
inline	int FruitingHouseplant::FruitingDuration() const { return n_FruitingDuration; }
inline	bool FruitingHouseplant::IsFruiting() const { return IS_FRUITING; }
inline	int FruitingHouseplant::CurrentFruitingDays() const { return m_nCurrentFruitingDays; }

#endif //LB_3_HOUSEPLANT_FRUITING_HOUSEPLANT_H

