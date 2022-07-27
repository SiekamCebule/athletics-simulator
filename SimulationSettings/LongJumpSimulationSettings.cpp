#include "LongJumpSimulationSettings.h"

double LongJumpSimulationSettings::getAccelarateSkillEffect() const
{
    return accelarateSkillEffect;
}

void LongJumpSimulationSettings::setAccelarateSkillEffect(double newAccelarateSkillEffect)
{
    accelarateSkillEffect = newAccelarateSkillEffect;
}

double LongJumpSimulationSettings::getJumpSkillEffect() const
{
    return jumpSkillEffect;
}

void LongJumpSimulationSettings::setJumpSkillEffect(double newJumpSkillEffect)
{
    jumpSkillEffect = newJumpSkillEffect;
}

LongJumpSimulationSettings::LongJumpSimulationSettings()
{

}
