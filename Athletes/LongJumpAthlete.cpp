#include "LongJumpAthlete.h"
#include "../Random.h"

int LongJumpAthlete::getAccelarateSkill() const
{
    return accelarateSkill;
}

void LongJumpAthlete::setAccelarateSkill(int newAccelarateSkill)
{
    accelarateSkill = newAccelarateSkill;
}

int LongJumpAthlete::getJumpSkill() const
{
    return jumpSkill;
}

void LongJumpAthlete::setJumpSkill(int newJumpSkill)
{
    jumpSkill = newJumpSkill;
}

LongJumpSimulationSettings *LongJumpAthlete::getSettings() const
{
    return settings;
}

void LongJumpAthlete::setSettings(LongJumpSimulationSettings *newSettings)
{
    settings = newSettings;
}

void LongJumpAthlete::checkSkillLimits()
{
    if(accelarateSkill > 120)
        accelarateSkill = 120;
    else if(accelarateSkill < 1)
        accelarateSkill = 1;

    if(jumpSkill > 120)
        jumpSkill = 120;
    else if(jumpSkill < 1)
        jumpSkill = 1;
}

void LongJumpAthlete::randomizeSkill()
{
    accelarateSkill += Random::randomInt(-3, 3);
    jumpSkill += Random::randomInt(-2, 3);
}

void LongJumpAthlete::calculateResult()
{
    result = settings->getMinResult();
    result += (accelarateSkill * settings->getAccelarateSkillEffect());
    result += (jumpSkill * settings->getJumpSkillEffect());
    result += Random::normalRandom(0, settings->getRandEffect());
}
LongJumpAthlete::LongJumpAthlete(const QString &name, const QString &nationality, int accelarateSkill, int jumpSkill, LongJumpSimulationSettings *settings) : Athlete(name, nationality),
    accelarateSkill(accelarateSkill),
    jumpSkill(jumpSkill),
    settings(settings)
{}
