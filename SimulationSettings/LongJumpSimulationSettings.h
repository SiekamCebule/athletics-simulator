#pragma once

#include "SimulationSettings.h"

class LongJumpSimulationSettings : public SimulationSettings
{
    double accelarateSkillEffect, jumpSkillEffect;
public:
    LongJumpSimulationSettings();
    double getAccelarateSkillEffect() const;
    void setAccelarateSkillEffect(double newAccelarateSkillEffect);
    double getJumpSkillEffect() const;
    void setJumpSkillEffect(double newJumpSkillEffect);
};

