//
// Created by ruslan on 5/11/17.
//

#ifndef EVENTSYSTEM_DISPATCHER_H
#define EVENTSYSTEM_DISPATCHER_H

#include "event.h"
#include "observer.h"

#include <functional>
#include <map>
#include <vector>
#include <initializer_list>

class Houseplant;


class Connection;

class Dispatcher {

public:

    Connection subscribe(   const Event::DescriptorType & descriptor,
                            Observer & slot);

    Dispatcher() {}
    Dispatcher(std::initializer_list<const Event::DescriptorType > & _l);

    void AddEvent(const Event::DescriptorType & descriptor);
    void AddEvents(std::initializer_list<const Event::DescriptorType > && _l);

    void AddObserver(Observer * p_o);

    void unsubscribe(const Connection & connection);

    /*
    Posts an event to all connected observers. This function has no way of
    knowing whether the event has been processed correctly. It will merely
    pass it on to anyone who might listen.
    */

    void post( const Event& event, const FloweringHouseplant * _hp ) const;
    void post( const Event& event, const FruitingHouseplant * _hp ) const;
    void post( const Event& event, const FoliarHouseplant * _hp ) const;
    void post( const Event& event, const ArtificialHouseplant * _hp ) const;


private:

    unsigned int _nextID = 0;

    struct SlotHandle
    {
        unsigned int id;
        Observer * slot;
    };

    std::map< Event::DescriptorType, std::vector<SlotHandle> > _observers;

    void postAll(const Event& event, std::function<void(SlotHandle)> && _f) const;
};

#endif //EVENTSYSTEM_DISPATCHER_H
