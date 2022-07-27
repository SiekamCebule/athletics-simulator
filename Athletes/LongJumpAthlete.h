#pragma once

#include "Athlete.h"
#include "../SimulationSettings/LongJumpSimulationSettings.h"

class LongJumpAthlete : public Athlete
{
    int accelarateSkill, jumpSkill;
    LongJumpSimulationSettings * settings;

    virtual void checkSkillLimits();
    virtual void randomizeSkill();
    virtual void calculateResult();

public:
    LongJumpAthlete(const QString &name = "", const QString &nationality = "", int accelarateSkill = 0, int jumpSkill = 0, LongJumpSimulationSettings *settings = 0);
    int getAccelarateSkill() const;
    void setAccelarateSkill(int newAccelarateSkill);
    int getJumpSkill() const;
    void setJumpSkill(int newJumpSkill);
    LongJumpSimulationSettings *getSettings() const;
    void setSettings(LongJumpSimulationSettings *newSettings);
};

