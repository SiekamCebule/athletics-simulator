#pragma once


class SimulationSettings
{
    double minResult, randEffect;
public:
    SimulationSettings(double minResult = 0, double randEffect = 0);

    double getMinResult() const;
    void setMinResult(double newMinResult);
    double getRandEffect() const;
    void setRandEffect(double newRandEffect);
};

