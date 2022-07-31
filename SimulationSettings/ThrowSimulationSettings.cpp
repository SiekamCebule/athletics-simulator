#include "ThrowSimulationSettings.h"

double ThrowSimulationSettings::getStrengthSkillEffect() const
{
    return strengthSkillEffect;
}

void ThrowSimulationSettings::setStrengthSkillEffect(double newStrengthSkillEffect)
{
    strengthSkillEffect = newStrengthSkillEffect;
}

double ThrowSimulationSettings::getTechniqueSkillEffect() const
{
    return techniqueSkillEffect;
}

void ThrowSimulationSettings::setTechniqueSkillEffect(double newTechniqueSkillEffect)
{
    techniqueSkillEffect = newTechniqueSkillEffect;
}

ThrowSimulationSettings::ThrowSimulationSettings()
{

}
