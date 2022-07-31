#pragma once

#include "SimulationSettings.h"

class LongJumpSimulationSettings : public SimulationSettings
{
protected:
    double accelarateSkillEffect, jumpSkillEffect;
public:
    LongJumpSimulationSettings();
    double getAccelarateSkillEffect() const;
    void setAccelarateSkillEffect(double newAccelarateSkillEffect);
    double getJumpSkillEffect() const;
    void setJumpSkillEffect(double newJumpSkillEffect);
};

