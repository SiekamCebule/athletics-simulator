#pragma once

#include "Athletes/RunningAthlete.h"
#include "Athletes/LongJumpAthlete.h"


#include <QVector>


class App
{
    //athletes
    QVector<RunningAthlete> runningAthletes;
    QVector<LongJumpAthlete> longJumpAthletes;
    //settings
    QVector<RunningSimulationSettings> runningSettings;
    LongJumpSimulationSettings longJumpSimulationSettings;

    void loadRunningAthletes();
    void loadLongJumpAthletes();
    void loadSimulationSettings();

    void simulateCompetitionChoice();
public:
    App();
    void start();
};

