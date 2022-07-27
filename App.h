#pragma once

#include "SimulationSettings/RunningSimulationSettings.h"
#include "Athletes/RunningAthlete.h"

#include <QVector>


class App
{
    //athletes
    QVector<RunningAthlete> runningAthletes;
    //settings
    QVector<RunningSimulationSettings> runningSettings;

    void loadRunningAthletes();
    void loadSimulationSettings();

    void simulateCompetitionChoice();
public:
    App();
    void start();
};

