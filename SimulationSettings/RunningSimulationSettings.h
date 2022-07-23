#pragma once

#include "SimulationSettings.h"

class RunningSimulationSettings : public SimulationSettings
{
    int distance;
    double paceSkillEffect, conditionSkillEffect;
public:
    RunningSimulationSettings(int distance = 0, double paceSkillEffect = 0, double conditionSkillEffect = 0);

    double getPaceSkillEffect() const;
    void setPaceSkillEffect(double newPaceSkillEffect);
    double getConditionSkillEffect() const;
    void setConditionSkillEffect(double newConditionSkillEffect);
    int getDistance() const;
    void setDistance(int newDistance);
};

