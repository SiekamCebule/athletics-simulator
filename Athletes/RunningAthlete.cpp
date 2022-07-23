#include "RunningAthlete.h"

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

RunningAthlete::RunningAthlete(QString name, QString nationality, int paceSkill, int conditionSkill,  RunningSimulationSettings * settings) : Athlete(name, nationality),
    paceSkill(paceSkill),
    conditionSkill(conditionSkill),
    settings(settings)
{}
