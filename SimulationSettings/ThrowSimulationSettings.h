#pragma once

#include "SimulationSettings.h"

class ThrowSimulationSettings : public SimulationSettings
{
    double strengthSkillEffect, techniqueSkillEffect;
public:
    ThrowSimulationSettings();

    double getStrengthSkillEffect() const;
    void setStrengthSkillEffect(double newStrengthSkillEffect);
    double getTechniqueSkillEffect() const;
    void setTechniqueSkillEffect(double newTechniqueSkillEffect);
};
