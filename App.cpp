#include "App.h"
#include "Athletes/RunningAthlete.h"
#include "Competition.h"

#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QTextStream>
#include <Windows.h>

#include <iostream>
#include <conio.h>

QTextStream out(stdout);

App::App()
{


}

void App::start()
{
    using std::cout;

    while(true){
        loadSimulationSettings();
        loadRunningAthletes();

        int ch = 0;
        cout<<"Witaj w symulatorze lekkoatletyki! Co chcesz zrobic?\n";
        cout<<"1. Symuluj zawody\n2. Zawodnicy\n3. Ustawienia\n";
        std::cin >> ch;
        switch(ch)
        {
        case 1:
            simulateCompetitionChoice();
            break;
        case 2:
            break;
        case 3:
            break;
        }

    }
}

void App::loadRunningAthletes()
{
    QFile file("resources/runningAthletes.json");
    file.open(QFile::ReadOnly | QFile::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();
    QJsonValue value = object.value("athletes");
    QJsonArray array = value.toArray();

    for(const auto & v : array)
    {
        RunningAthlete ath;
        ath.setName(v.toObject().value("name").toString());
        ath.setNationality(v.toObject().value("nationality").toString());
        ath.setPaceSkill(v.toObject().value("paceSkill").toInt());
        ath.setConditionSkill(v.toObject().value("conditionSkill").toInt());
        runningAthletes.push_back(ath);

    }
}

void App::loadSimulationSettings()
{
    QFile file("resources/simulationSettings.json");
    file.open(QFile::ReadOnly | QFile::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();

    //running
    QJsonValue value = object.value("running");
    QJsonArray array = value.toArray();
    for(const QJsonValue & v : array)
    {
        RunningSimulationSettings sett;
        sett.setDistance(v.toObject().value("distance").toInt());
        sett.setMaxResult(v.toObject().value("maxResult").toDouble());
        sett.setRandEffect(v.toObject().value("randEffect").toDouble());
        sett.setPaceSkillEffect(v.toObject().value("paceSkillEffect").toDouble());
        sett.setConditionSkillEffect(v.toObject().value("conditionSkillEffect").toDouble());
        runningSettings.push_back(sett);
    }
}

void App::simulateCompetitionChoice()
{
    using std::cout;

    int ch;
    system("cls");
    cout<<"Wybierz dyscypline:\n";
    cout<<"1. Biegi\n";
    std::cin >> ch;

    Competition competition;
    QVector<Athlete *> athletes;

    switch(ch)
    {
    case 1:
        cout<<"\nJaki dystans biegow?\n";
        int i = 1;
        for(const auto & runset : runningSettings)
        {
            cout<<i<<". "<<runset.getDistance() <<"m\n";
            i++;
        }
        std::cin>>ch;
        for(auto & run : runningAthletes){
            run.setSettings(&runningSettings[ch-1]);
            athletes.push_back(&run);
        }
        competition.setCompetitionType(Competition::Running);
        break;
    }
    competition.setAthletes(athletes);

    cout<<"\nZawodnicy:\n";
    int i =1;
    for(const auto & ath : athletes)
    {
        cout<<i<<". "<<ath->getName().toStdString()<<" ("<<ath->getNationality().toStdString()<<")\n";
        i++;
    }
    getch();
    competition.startCompetition();
}
