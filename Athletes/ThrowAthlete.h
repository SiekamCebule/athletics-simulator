#pragma once

#include "Athlete.h"
#include "../SimulationSettings/ThrowSimulationSettings.h"

class ThrowAthlete : public Athlete
{
    int strengthSkill, techniqueSkill;
    ThrowSimulationSettings * settings;

    virtual void checkSkillLimits();
    virtual void randomizeSkill();
    virtual void calculateResult();

public:
    ThrowAthlete();

    int getStrengthSkill() const;
    void setStrengthSkill(int newStrengthSkill);
    int getTechniqueSkill() const;
    void setTechniqueSkill(int newTechniqueSkill);
    ThrowSimulationSettings *getSettings() const;
    void setSettings(ThrowSimulationSettings *newSettings);
};

