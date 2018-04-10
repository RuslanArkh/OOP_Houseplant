
#ifndef LB_3_HOUSEPLANT_HOUSEPLANT_H_H
#define LB_3_HOUSEPLANT_HOUSEPLANT_H_H

#include "debug_mode.h"

#include "observer.h"

#include "dispatcher.h"

#include <string>
#include <vector>
#include <memory>

#include "dispatcher.h"


class Houseplant {

protected:

    //  [2.1] Title of the plant
    const std::string name;
    //  [2.2] Age in days
    int m_ageInDays = 0;
    //  [2.3] The period of watering
    int n_WateringInterval;
    //  [2.4] Date of last watering - better count days from last watering
    //  TODO: make a real date.
    int DaysFromLastWatering;

    bool isWatered() const;

    std::unique_ptr< Dispatcher> dispatcher;

public:

    //  [2.5] Pure virtual method which "does" watering
    virtual void DoWatering() = 0;
    //  [2.6] Pure virtual method which notifies a plant that a day is passed
    virtual void DayPassed() = 0;

    //  Constructor
    Houseplant(
            std::string const & _name
            ,   int _ageInDays
            ,   int _wateringInterval
            ,   int _lastWatering
    );

    //  Getter methods:
    int GetDaysFromLastWatering() const;

    std::string Title() const;

    int AgeInDays() const;

    int WateringInterval() const;

    void Attach(Observer & _obs) {
        dispatcher->AddObserver(&_obs);
    }

    Dispatcher & GetDispatcher() const {
        return *dispatcher.get();
    }
};

inline int Houseplant::GetDaysFromLastWatering() const { return DaysFromLastWatering; }

inline bool Houseplant::isWatered() const { return DaysFromLastWatering == 0; }

inline std::string Houseplant::Title() const { return name; }

inline int Houseplant::AgeInDays() const { return m_ageInDays; }

inline int Houseplant::WateringInterval() const { return n_WateringInterval; }


inline Houseplant::Houseplant(std::string const &_name, int _ageInDays, int _wateringInterval, int _lastWatering)
        :   name(_name)
        ,   m_ageInDays(_ageInDays)
        ,   n_WateringInterval(_wateringInterval)
        ,   DaysFromLastWatering(_lastWatering)
{
    dispatcher = std::unique_ptr<Dispatcher>{new Dispatcher()};
}

#endif //LB_3_HOUSEPLANT_HOUSEPLANT_H_H
