QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    artificial_houseplant.cpp \
    connection.cpp \
    console_logger.cpp \
    date.cpp \
    dispatcher.cpp \
    events_artificial.cpp \
    events_flowering.cpp \
    events_foliar.cpp \
    events_fruiting.cpp \
    flowering_houseplant.cpp \
    foliar_houseplant.cpp \
    fruiting_houseplant.cpp \
    main.cpp \
    room.cpp \
    room_updater.cpp

HEADERS += \
    artificial_houseplant.h \
    connection.h \
    console_logger.h \
    date.h \
    debug_mode.h \
    dispatcher.h \
    event.h \
    events_artificial.h \
    events_flowering.h \
    events_foliar.h \
    events_fruiting.h \
    flowering_houseplant.h \
    foliar_houseplant.h \
    fruiting_houseplant.h \
    houseplant.h \
    observer.h \
    room.h \
    room_updater.h

DISTFILES +=
