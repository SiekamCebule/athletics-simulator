#pragma once

#include "Athlete.h"
#include "SimulationSettings/RunningSimulationSettings.h"

class RunningAthlete : public Athlete
{
    int paceSkill, conditionSkill;
    RunningSimulationSettings * settings;


    virtual void randomizeSkill();
    virtual void calculateResult();

public:
    RunningAthlete(QString name = "", QString nationality = "", int paceSkill = 60, int conditionSkill = 60, RunningSimulationSettings * settings = nullptr);

    int getPaceSkill() const;
    void setPaceSkill(int newPaceSkill);
    int getConditionSkill() const;
    void setConditionSkill(int newConditionSkill);
virtual void checkSkillLimits();
    virtual void simulate();
    RunningSimulationSettings *getSettings() const;
    void setSettings(RunningSimulationSettings *newSettings);
};

