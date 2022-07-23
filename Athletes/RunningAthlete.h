#pragma once

#include "Athlete.h"
#include "SimulationSettings/RunningSimulationSettings.h"

class RunningAthlete : public Athlete
{
    int paceSkill, conditionSkill;
    RunningSimulationSettings * settings;
public:
    RunningAthlete(QString name = "", QString nationality = "", int paceSkill = 60, int conditionSkill = 60, RunningSimulationSettings * settings = nullptr);

    int getPaceSkill() const;
    void setPaceSkill(int newPaceSkill);
    int getConditionSkill() const;
    void setConditionSkill(int newConditionSkill);
};

