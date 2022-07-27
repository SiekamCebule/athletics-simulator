#include "SimulationSettings.h"

double SimulationSettings::getMinResult() const
{
    return minResult;
}

void SimulationSettings::setMinResult(double newMinResult)
{
    minResult = newMinResult;
}

double SimulationSettings::getRandEffect() const
{
    return randEffect;
}

void SimulationSettings::setRandEffect(double newRandEffect)
{
    randEffect = newRandEffect;
}

SimulationSettings::SimulationSettings(double minResult, double randEffect) : minResult(minResult),
    randEffect(randEffect)
{}
