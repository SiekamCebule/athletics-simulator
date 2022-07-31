#include "RunningAthlete.h"
#include "../Random.h"

#include <QDebug>

int RunningAthlete::getPaceSkill() const
{
    return paceSkill;
}

void RunningAthlete::setPaceSkill(int newPaceSkill)
{
    paceSkill = newPaceSkill;
}

int RunningAthlete::getConditionSkill() const
{
    return conditionSkill;
}

void RunningAthlete::setConditionSkill(int newConditionSkill)
{
    conditionSkill = newConditionSkill;
}

RunningSimulationSettings *RunningAthlete::getSettings() const
{
    return settings;
}

void RunningAthlete::setSettings(RunningSimulationSettings *newSettings)
{
    settings = newSettings;
}

void RunningAthlete::checkSkillLimits()
{
    if(paceSkill > 120)
    {
        paceSkill = 120;
    }
    else if(paceSkill < 1) paceSkill = 1;

    if(conditionSkill > 120)
    {
        conditionSkill = 120;
    }
    else if(conditionSkill < 1 ) conditionSkill = 1;
}

void RunningAthlete::randomizeSkill()
{
    paceSkill += Random::normalRandom(-2, 3);
    conditionSkill += Random::randomInt(-2, 1);
}

void RunningAthlete::calculateResult()
{
    result = settings->getMinResult();
    result -= (paceSkill * settings->getPaceSkillEffect());
    result -= (conditionSkill * settings->getConditionSkillEffect());
    result -= Random::normalRandom(0, settings->getRandEffect());
}


RunningAthlete::RunningAthlete(QString name, QString nationality, int paceSkill, int conditionSkill,  RunningSimulationSettings * settings) : Athlete(name, nationality),
    paceSkill(paceSkill),
    conditionSkill(conditionSkill),
    settings(settings)
{}
