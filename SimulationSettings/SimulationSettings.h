#pragma once


class SimulationSettings
{
    double maxResult, randEffect;
public:
    SimulationSettings(double maxResult = 0, double randEffect = 0);

    double getMaxResult() const;
    void setMaxResult(double newMaxResult);
    double getRandEffect() const;
    void setRandEffect(double newRandEffect);
};

