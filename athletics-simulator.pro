QT -= gui
QT += core5compat

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += file_copies
COPIES += copies
copies.files = $$files(resources)
copies.path = $$OUT_PWD


SOURCES += \
        App.cpp \
        Athletes/Athlete.cpp \
        Athletes/LongJumpAthlete.cpp \
        Athletes/RunningAthlete.cpp \
        Athletes/ThrowAthlete.cpp \
        Competition.cpp \
        Random.cpp \
        SimulationSettings/LongJumpSimulationSettings.cpp \
        SimulationSettings/RunningSimulationSettings.cpp \
        SimulationSettings/SimulationSettings.cpp \
        SimulationSettings/ThrowSimulationSettings.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    App.h \
    Athletes/Athlete.h \
    Athletes/LongJumpAthlete.h \
    Athletes/RunningAthlete.h \
    Athletes/ThrowAthlete.h \
    Competition.h \
    Random.h \
    SimulationSettings/LongJumpSimulationSettings.h \
    SimulationSettings/RunningSimulationSettings.h \
    SimulationSettings/SimulationSettings.h \
    SimulationSettings/ThrowSimulationSettings.h

DISTFILES += \
    resources/hammerThrowAthletes.json \
    resources/longJumpAthletes.json \
    resources/runningAthletes.json \
    resources/simulationSettings.json \
    resources/tripleJumpAthletes.json
