
#include <iostream>
#include "connection.h"
#include "flowering_houseplant.h"
#include "fruiting_houseplant.h"
#include "foliar_houseplant.h"
#include "artificial_houseplant.h"
#include "events_foliar.h"
#include "console_logger.h"
#include "room_updater.h"
#include "room.h"

int main() {

    Room r{32};

    FloweringHouseplant fp = FloweringHouseplant("Plant1", 0, 3, 6, 3, 0);

    ConsoleLogger cl{std::cout};

    fp.Attach(cl);

    r.Add(fp);

    // 1)
    fp.DayPassed();
    fp.DayPassed();
    fp.DayPassed();
    fp.DoWatering();
    fp.DoWatering();
    // 2)
    fp.DayPassed();
    fp.DayPassed();
    fp.DayPassed();
    fp.DoWatering();
    // 3)
    fp.DayPassed();
    fp.DayPassed();
    fp.DayPassed();
    fp.DoWatering();
    // Must be flowering
    fp.DayPassed();
    fp.DayPassed();
    fp.DoWatering();

    fp.DayPassed();
    fp.DayPassed();
    fp.DayPassed();
    fp.DayPassed();
    fp.DoWatering();
    fp.DayPassed();
    fp.DayPassed();
    fp.DoWatering();
    fp.DayPassed();


    std::cout << "\n\n***********************************************************************";

    std::unique_ptr<FruitingHouseplant> fruit{ new FruitingHouseplant("Plant",  0, 3, 2, 3, "Apple", 5, 0)};

    fruit->Attach(cl);

    r.Add(*fruit.get());

    // 1)
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DoWatering();

    // 2)
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DoWatering();

    // 3)
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DoWatering();


    fruit->DayPassed();
    //  Now - Must be flowering

    fruit->DayPassed();
    fruit->DoWatering();

    fruit->DayPassed();
    fruit->DayPassed();
    //  Here (after day passed) plant becomes Fruiting.
    fruit->DayPassed();

    fruit->DayPassed();
    fruit->DoWatering();

    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DoWatering();

    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DoWatering();

    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DayPassed();
    fruit->DoWatering();
    //  Must stop fruiting.

    std::cout << "\n\n***********************************************************************";
    std::cout << "\n***********************************************************************";

    FoliarHouseplant fh {"Rose", 0, 2, 0, 30, r.Height()};

    fh.Attach(cl);

    r.Add(fh);

    RoomUpdater r_upd{r};
    fh.GetDispatcher().subscribe(foliar_event::TooLarge::descriptor, r_upd);

    fh.DayPassed();
    fh.DayPassed();
    fh.DoWatering();
    fh.DayPassed();
    fh.DayPassed();
    fh.DoWatering();
    fh.DayPassed();
    fh.DayPassed();
    fh.DoWatering();
    fh.DayPassed();
    fh.DayPassed();
    fh.DoWatering();

    ArtificialHouseplant ahp{"Plastic Rose", 0};
    ahp.Attach(cl);
    r.Add(ahp);
    ahp.DoWatering();

    std::cout << "\n\n";
    for (auto & x: r.getPlants())
        std::cout << x->Title() << "\n";
    std::cout << "\n";


}