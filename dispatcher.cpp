//
// Created by ruslan on 5/11/17.
//

#include "connection.h"
#include "dispatcher.h"


#include <algorithm>


Dispatcher::Dispatcher(std::initializer_list<const Event::DescriptorType > & _l) {
    for (auto & d: _l)
        _observers.insert(std::make_pair(d, std::vector<SlotHandle>{}));
}

void Dispatcher::AddEvents(std::initializer_list<const Event::DescriptorType > && _l) {
    for (auto & d: _l)
        _observers.insert(std::make_pair(d, std::vector<SlotHandle>{}));
}

void Dispatcher::AddEvent(const Event::DescriptorType & _d) {
    _observers.insert(std::make_pair(_d, std::vector<SlotHandle>{}));
}

void Dispatcher::AddObserver(Observer * p_o) {
    for (auto & e_o: _observers)
        subscribe(e_o.first, *p_o);
}

Connection Dispatcher::subscribe( const Event::DescriptorType& descriptor,
                                  Observer & slot )
{
    auto id = _nextID;
    SlotHandle handle = { id, &slot };

    //_observers.insert(std::pair(descriptor, {}));

    _observers[ descriptor ].push_back( handle );
    ++_nextID;

    return Connection( this, id );
}

void Dispatcher::unsubscribe( const Connection& connection )
{
    for( auto&& pair : _observers )
    {
        auto&& handles = pair.second;

        handles.erase( std::remove_if( handles.begin(), handles.end(),
                                       [&] ( SlotHandle & handle )
                                       {
                                           return handle.id == connection.id();
                                       } ),
                       handles.end() );
    }
}

void Dispatcher::postAll(const Event& event, std::function<void(SlotHandle)> && _f) const {
    auto type = event.type();

    if( _observers.find( type ) == _observers.end() )
        return;

    auto & observers = _observers.at( type );

    for( auto & observer : observers )
        _f(observer);
}

void Dispatcher::post( const Event& event, const FloweringHouseplant * _hp ) const {
    postAll(event, [&](SlotHandle _h) { _h.slot->handle(event, _hp); });
}

void Dispatcher::post( const Event& event, const FruitingHouseplant * _hp ) const {
    postAll(event, [&](SlotHandle _h) { _h.slot->handle(event, _hp); });
}

void Dispatcher::post( const Event& event, const FoliarHouseplant * _hp ) const {
    postAll(event, [&](SlotHandle _h) { _h.slot->handle(event, _hp); });
}

void Dispatcher::post( const Event& event, const ArtificialHouseplant * _hp ) const {
    postAll(event, [&](SlotHandle _h) { _h.slot->handle(event, _hp); });
}

