#pragma once

#include "SimulationSettings/RunningSimulationSettings.h"

#include <QVector>


class App
{
    QVector<RunningSimulationSettings> runningSettings;

    void loadSimulationSettings();
public:
    App();
    void start();
};

