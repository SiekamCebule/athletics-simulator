#include "Athlete.h"

const QString &Athlete::getName() const
{
    return name;
}

void Athlete::setName(const QString &newName)
{
    name = newName;
}

const QString &Athlete::getNationality() const
{
    return nationality;
}

void Athlete::setNationality(const QString &newNationality)
{
    nationality = newNationality;
}

double Athlete::getResult() const
{
    return result;
}

void Athlete::setResult(double newResult)
{
    result = newResult;
}

void Athlete::simulate()
{
    checkSkillLimits();
    randomizeSkill();
    calculateResult();
}

Athlete::Athlete(const QString &name, const QString &nationality) : name(name),
    nationality(nationality)
{}
