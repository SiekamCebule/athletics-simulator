#include "ThrowAthlete.h"

#include "Random.h"

int ThrowAthlete::getStrengthSkill() const
{
    return strengthSkill;
}

void ThrowAthlete::setStrengthSkill(int newStrengthSkill)
{
    strengthSkill = newStrengthSkill;
}

int ThrowAthlete::getTechniqueSkill() const
{
    return techniqueSkill;
}

void ThrowAthlete::setTechniqueSkill(int newTechniqueSkill)
{
    techniqueSkill = newTechniqueSkill;
}

ThrowAthlete::ThrowAthlete()
{

}

ThrowSimulationSettings *ThrowAthlete::getSettings() const
{
    return settings;
}

void ThrowAthlete::setSettings(ThrowSimulationSettings *newSettings)
{
    settings = newSettings;
}

void ThrowAthlete::checkSkillLimits()
{
    if(strengthSkill > 120)
    {
        strengthSkill = 120;
    }
    else if(strengthSkill < 1) strengthSkill = 1;

    if(techniqueSkill > 120)
    {
        techniqueSkill = 120;
    }
    else if(techniqueSkill < 1 ) techniqueSkill = 1;
}

void ThrowAthlete::randomizeSkill()
{
    strengthSkill += Random::normalRandom(-1, 1);
    techniqueSkill += Random::randomInt(-3, 3);
}

void ThrowAthlete::calculateResult()
{
    result = settings->getMinResult();
    result += (strengthSkill * settings->getStrengthSkillEffect());
    result += (techniqueSkill * settings->getTechniqueSkillEffect());
    result += Random::normalRandom(0, settings->getRandEffect());
}
