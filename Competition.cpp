#include "Competition.h"

#include <iostream>
#include <conio.h>
#include <algorithm>

#include <Windows.h>
#include <QTime>
#include <QDateTime>

#include "Athletes/RunningAthlete.h"
#include "Athletes/LongJumpAthlete.h"
#include "Random.h"

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

void Competition::showClassification()
{
    using std::cout;
    if(competitionType != Running)
        std::sort(results.begin(), results.end(), [](Athlete * left, Athlete * right){return left->getResult() > right->getResult();});
    else
        std::sort(results.begin(), results.end(), [](Athlete * left, Athlete * right){return left->getResult() < right->getResult();});

    int i = 1;
    ColorText::write(8, "Klasyfikacja:\n");
    for(auto res : results)
    {
        ColorText::write(6, i);
        cout<<". ";
        ColorText::write(15, res->getName().toStdString()+" ("+res->getNationality().toStdString()+")");
        cout<<" ---> ";

        QTime t = QTime(0,0,0).addMSecs(res->getResult() * 1000);
        switch(resultType)
        {
        case Seconds:
            if (t.hour() > 0){
                ColorText::write(11, QString::number(t.hour()).toStdString());
                ColorText::write(6, " godz ");
            }
            if(t.minute() > 0){
                ColorText::write(11, QString::number(t.minute()).toStdString());
                ColorText::write(6, " min ");
            }
            if(t.second() > 0|| t.msec() > 0){
                ColorText::write(11, QString::number(static_cast<double>((double)t.second() + ((double)t.msec() / 1000))).toStdString());
                ColorText::write(6, " sek");
            }
            cout<<"\n";
            break;
        case Meters:
            ColorText::write(11, QString::number(res->getResult()).toStdString());
            ColorText::write(6, " metrow\n");
            break;
        }
        i++;
    }
}

void Competition::competitionSummary()
{

}

void Competition::setResultType()
{
    switch(competitionType)
    {
    case Running:
        resultType = Seconds;
        break;
    case LongJump:
    case TripleJump:
        resultType = Meters;
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
            static_cast<RunningAthlete*>(ath)->simulate();
            break;
        case LongJump:
        case TripleJump:
            static_cast<LongJumpAthlete*>(ath)->simulate();
            break;
        }

        QTime t = QTime(0,0,0).addMSecs(ath->getResult() * 1000);
        ColorText::write(15, ath->getName().toStdString()+" ("+ath->getNationality().toStdString()+")");
        cout<<" ---> ";
        switch(resultType)
        {
        case Seconds:
            if(t.hour() > 0){
                ColorText::write(11, QString::number(t.hour()).toStdString());
                ColorText::write(6, " godz ");
            }
            if(t.minute() > 0){
                ColorText::write(11, QString::number(t.minute()).toStdString());
                ColorText::write(6, " min ");
            }
            if(t.second() > 0|| t.msec() > 0){
                ColorText::write(11, QString::number(static_cast<double>((double)t.second() + ((double)t.msec() / 1000))).toStdString());
                ColorText::write(6, " sek");
            }
            cout<<"\n";
            break;
        case Meters:
            ColorText::write(11, QString::number(ath->getResult()).toStdString());
            ColorText::write(6, " metrow\n");
            break;
        }
        results.push_back(ath);

        cout<<"\n\n";
        showClassification();
        getch();
        system("cls");
    }
}
