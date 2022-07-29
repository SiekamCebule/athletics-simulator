#pragma once

#include "Athletes/Athlete.h"

#include <QVector>


class Competition
{
    QVector<Athlete *> athletes;
    QVector<Athlete *> results;

    void showClassification();
    void competitionSummary();

    int competitionType, resultType;
    void setResultType();
public:
    Competition();
    Competition(const QVector<Athlete *> &athletes, int competitionType, int resultType);

    void startCompetition();

    const QVector<Athlete *> &getAthletes() const;
    void setAthletes(const QVector<Athlete *> &newAthletes);

    enum CompetitionType{
        Running,
        LongJump
    };

    enum ResultType{
        Seconds,
        Meters
    };

    int getCompetitionType() const;
    void setCompetitionType(int newCompetitionType);
    int getResultType() const;
};

