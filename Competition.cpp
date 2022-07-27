#include "Competition.h"

#include <iostream>
#include <conio.h>

#include <Windows.h>
#include <QTime>
#include <QDateTime>

#include "Athletes/RunningAthlete.h"

const QVector<Athlete *> &Competition::getAthletes() const
{
    return athletes;
}

void Competition::setAthletes(const QVector<Athlete *> &newAthletes)
{
    athletes = newAthletes;
}

int Competition::getCompetitionType() const
{
    return competitionType;
}

void Competition::setCompetitionType(int newCompetitionType)
{
    competitionType = newCompetitionType;
    setResultType();
}

int Competition::getResultType() const
{
    return resultType;
}

void Competition::setResultType()
{
    switch(competitionType)
    {
    case Running:
        resultType = Seconds;
        break;
    }
}

Competition::Competition()
{

}

Competition::Competition(const QVector<Athlete *> &athletes, int competitionType, int resultType) : athletes(athletes),
    competitionType(competitionType),
    resultType(resultType)
{}

void Competition::startCompetition()
{
    using std::cout;
    system("cls");
    for(const auto & ath : athletes)
    {
        switch(competitionType)
        {
        case Running:
            dynamic_cast<RunningAthlete*>(ath)->simulate();
            break;
        }

        QTime t = QTime(0,0,0).addMSecs(ath->getResult() * 1000);
        cout<<ath->getName().toStdString()<<" ("<<ath->getNationality().toStdString()<<") ---> ";
        switch(resultType)
        {
        case Seconds:
            if(t.hour() > 0)
                cout<<t.hour()<<"godz ";
            if(t.minute() > 0)
                cout<<t.minute()<<"min ";
            if(t.second() > 0|| t.msec() > 0)
                cout<<static_cast<double>(t.second() + ((double)t.msec() / 1000))<<"sek";
            cout<<"\n";
            break;
        case Meters:
            cout<<ath->getResult()<<" metrów\n";
            break;
        }
        getch();
        system("cls");
    }
}
