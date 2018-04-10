//
// Created by ruslan on 5/11/17.
//

#ifndef EVENTSYSTEM_CONNECTION_H
#define EVENTSYSTEM_CONNECTION_H

class Dispatcher;

class Connection {
public:

    Connection();

    unsigned int id() const;

    void disconnect();

private:

    /**
      Sets up a valid connection that belongs to a dispatcher and is identified
      by some ID.
    */

    Connection( Dispatcher* dispatcher, unsigned int id );

    /** Dispatcher that created this connection */
    Dispatcher* _dispatcher = nullptr;

    /** Identifier for this connection */
    unsigned int _id = 0;

    /**
      Since the constructor that yields a valid connection is private, this
      ensures that the dispatcher is the only class that is capable of creating
      a valid connection object.
    */

    friend class Dispatcher;
};

#endif //EVENTSYSTEM_CONNECTION_H
