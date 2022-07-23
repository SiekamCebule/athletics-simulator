#include "SimulationSettings.h"

double SimulationSettings::getMaxResult() const
{
    return maxResult;
}

void SimulationSettings::setMaxResult(double newMaxResult)
{
    maxResult = newMaxResult;
}

double SimulationSettings::getRandEffect() const
{
    return randEffect;
}

void SimulationSettings::setRandEffect(double newRandEffect)
{
    randEffect = newRandEffect;
}

SimulationSettings::SimulationSettings(double maxResult, double randEffect) : maxResult(maxResult),
    randEffect(randEffect)
{}
