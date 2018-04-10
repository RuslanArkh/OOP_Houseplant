//
// Created by ruslan on 5/11/17.
//

#ifndef LB_3_HOUSEPLANT_CONSOLE_LOGGER_H
#define LB_3_HOUSEPLANT_CONSOLE_LOGGER_H

#include "observer.h"

#include <iostream>

#include "houseplant.h"

class FloweringHouseplant;
class FruitingHouseplant;
class FoliarHouseplant;

class ConsoleLogger : public Observer {
public:
    ConsoleLogger(std::ostream & _stream);

    void handle(const Event & event, const FloweringHouseplant * _hp) override;
    void handle(const Event & event, const FruitingHouseplant * _hp) override;
    void handle(const Event & event, const FoliarHouseplant * _hp) override;
    void handle(const Event & event, const ArtificialHouseplant * _hp) override;

private:

    std::ostream & m_stream;

    void flowering_warning(const FloweringHouseplant * _hp);
};

#endif //LB_3_HOUSEPLANT_CONSOLE_LOGGER_H
