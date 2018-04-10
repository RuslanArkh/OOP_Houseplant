//
// Created by ruslan on 5/11/17.
//

#include "console_logger.h"

#include "flowering_houseplant.h"
#include "fruiting_houseplant.h"
#include "foliar_houseplant.h"
#include "artificial_houseplant.h"

#include "events_flowering.h"
#include "events_fruiting.h"
#include "events_foliar.h"
#include "events_artificial.h"

ConsoleLogger::ConsoleLogger(std::ostream & _stream) : m_stream(_stream) {}

void ConsoleLogger::flowering_warning(const FloweringHouseplant * _hp) {

    if (_hp->GetCurrentWaterings() > 0)
        m_stream << "Amount of true waterings is decreased by 1.\n"
                 << "Current amount of true waterings is: "
                 << _hp->GetCurrentWaterings() << "\n";
    else
        m_stream << "Amount of true watering is 0.\n"
                 << "Please, follow watering plan, or the plant will die.\n";
}

void ConsoleLogger::handle(const Event & event, const FloweringHouseplant * _hp) {

    m_stream << "\n\n*****************"
             << (dynamic_cast<const FruitingHouseplant *>(_hp) ? "Fruiting (now flowering)" : "Flowering")
             <<  " Houseplant event [" << event.type() << "]*****************\n";
    m_stream << event.EventToString(_hp);
    /*
    if (event.type() == StartFlowering::descriptor) {
        m_stream << "Plant started flowering.\n";
    } else if (event.type() == FloweringSuccessfulFinish::descriptor) {
        m_stream << "Congratulations! Flowering period is passed.\n"
                 << "Now plant is stronger and its watering interval increased for 2 days: "
                 << _hp->WateringInterval() << "\n";
    } else if (event.type() == WateringHurried::descriptor) {
        m_stream << "Warning! Watering is hurried.\n";
        flowering_warning(_hp);
    } else if (event.type() == WateringLate::descriptor) {
        m_stream << "Warning! Too many days without watering. ";
        flowering_warning(_hp);
    } else if (event.type() == FailedFlowering::descriptor) {
        m_stream << "Flowering is failed, because of watering plan disparity.\n";
    }
*/
}

void ConsoleLogger::handle(const Event & event, const FruitingHouseplant * _hp) {
    m_stream << "\n\n*****************Fruiting Houseplant event [" << event.type() << "]*****************\n";
    /*
    if (event.type() == StartFruiting::descriptor) {
        m_stream << "Congratulations! New fruit -" << _hp->FruitName() << " - started to grow.\n";
    } else if (event.type() == FruitIsReady::descriptor) {
        m_stream << "Congratulations! Your fruit - " << _hp->FruitName() << " - is ready. Take it and eat!\n";
    } else if (event.type() == FruitingFailed::descriptor) {
        m_stream << "Fruiting is failed, because of watering plan disparity.\n";
    }
    */
    m_stream << event.EventToString(_hp);

}

void ConsoleLogger::handle(const Event & event, const FoliarHouseplant * _hp) {
    m_stream << "\n\n*****************Foliar Houseplant event [" << event.type() << "]*****************\n";
    m_stream << event.EventToString(_hp);
}

void ConsoleLogger::handle(const Event & event, const ArtificialHouseplant * _hp) {
    m_stream << "\n\n*****************Artificial Houseplant event [" << event.type() << "]*****************\n";
    m_stream << event.EventToString(_hp);
}