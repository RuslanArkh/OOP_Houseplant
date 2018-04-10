//
// Created by ruslan on 5/11/17.
//

#include "connection.h"
#include "dispatcher.h"

Connection::Connection()
{
}

unsigned int Connection::id() const
{
    return _id;
}

void Connection::disconnect()
{
    if( _dispatcher )
        _dispatcher->unsubscribe( *this );
}

Connection::Connection( Dispatcher* dispatcher, unsigned int id )
        : _dispatcher( dispatcher )
        , _id( id )
{
}