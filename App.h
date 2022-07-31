#pragma once

#include "Athletes/RunningAthlete.h"
#include "Athletes/LongJumpAthlete.h"
#include "Athletes/ThrowAthlete.h"


#include <QVector>


class App
{
    //athletes
    QVector<RunningAthlete> runningAthletes;
    QVector<LongJumpAthlete> longJumpAthletes;
    QVector<LongJumpAthlete> tripleJumpAthletes;
    QVector<ThrowAthlete> hammerThrowAthletes;
    //settings
    QVector<RunningSimulationSettings> runningSettings;
    LongJumpSimulationSettings longJumpSimulationSettings;
    LongJumpSimulationSettings tripleJumpSimulationSettings;
    ThrowSimulationSettings hammerThrowSimulationSettings;

    void loadRunningAthletes();
    void loadLongJumpAthletes();
    void loadTripleJumpAthletes();
    void loadHammerThrowAthletes();
    void loadSimulationSettings();

    void simulateCompetitionChoice();
public:
    App();
    void start();
};

