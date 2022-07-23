#include "RunningSimulationSettings.h"

double RunningSimulationSettings::getPaceSkillEffect() const
{
    return paceSkillEffect;
}

void RunningSimulationSettings::setPaceSkillEffect(double newPaceSkillEffect)
{
    paceSkillEffect = newPaceSkillEffect;
}

double RunningSimulationSettings::getConditionSkillEffect() const
{
    return conditionSkillEffect;
}

void RunningSimulationSettings::setConditionSkillEffect(double newConditionSkillEffect)
{
    conditionSkillEffect = newConditionSkillEffect;
}

int RunningSimulationSettings::getDistance() const
{
    return distance;
}

void RunningSimulationSettings::setDistance(int newDistance)
{
    distance = newDistance;
}

RunningSimulationSettings::RunningSimulationSettings(int distance, double paceSkillEffect, double conditionSkillEffect) : distance(distance),
    paceSkillEffect(paceSkillEffect),
    conditionSkillEffect(conditionSkillEffect)
{}
