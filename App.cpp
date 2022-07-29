#include "App.h"
#include "Athletes/RunningAthlete.h"
#include "Competition.h"
#include "Random.h"

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

App::App()
{


}

void App::start()
{
    using std::cout;

    while(true){
        loadSimulationSettings();
        loadRunningAthletes();
        loadLongJumpAthletes();

        int ch = 0;
        ColorText::write(15, "Witaj w symulatorze lekkoatletyki! Co chcesz zrobic?\n");
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

    QJsonParseError error;
    QJsonDocument document = QJsonDocument::fromJson(jsonData, &error);
    if(error.error != QJsonParseError::NoError)
    {
        qDebug()<<"Blad przy wczytywaniu pliku resources/runningAthletes.json: "<<error.errorString()<<"\n";
    }
    else{
        QJsonObject object = document.object();
        QJsonValue value = object.value("athletes");
        QJsonArray array = value.toArray();

        runningAthletes.clear();

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
}
void App::loadLongJumpAthletes()
{
    QFile file("resources/longJumpAthletes.json");
    file.open(QFile::ReadOnly | QFile::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument document = QJsonDocument::fromJson(jsonData, &error);
    if(error.error != QJsonParseError::NoError)
    {
        qDebug()<<"Blad przy wczytywaniu pliku resources/longJumpAthletes.json: "<<error.errorString()<<"\n";
    }
    else{
        QJsonObject object = document.object();
        QJsonValue value = object.value("athletes");
        QJsonArray array = value.toArray();

        longJumpAthletes.clear();

        for(const auto & v : array)
        {
            LongJumpAthlete ath;
            ath.setName(v.toObject().value("name").toString());
            ath.setNationality(v.toObject().value("nationality").toString());
            ath.setAccelarateSkill(v.toObject().value("accelarateSkill").toInt());
            ath.setJumpSkill(v.toObject().value("jumpSkill").toInt());
            longJumpAthletes.push_back(ath);
        }
    }
}

void App::loadSimulationSettings()
{
    QFile file("resources/simulationSettings.json");
    file.open(QFile::ReadOnly | QFile::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument document = QJsonDocument::fromJson(jsonData, &error);
    if(error.error != QJsonParseError::NoError)
    {
        qDebug()<<"Blad przy wczytywaniu pliku resources/simulationSettings.json: "<<error.errorString()<<"\n";
    }
    else{
        QJsonObject object = document.object();

        //Running
        runningSettings.clear();
        QJsonValue value = object.value("Running");
        QJsonArray array = value.toArray();
        for(const QJsonValue & v : array)
        {
            RunningSimulationSettings sett;
            sett.setDistance(v.toObject().value("distance").toInt());
            sett.setMinResult(v.toObject().value("minResult").toDouble());
            sett.setRandEffect(v.toObject().value("randEffect").toDouble());
            sett.setPaceSkillEffect(v.toObject().value("paceSkillEffect").toDouble());
            sett.setConditionSkillEffect(v.toObject().value("conditionSkillEffect").toDouble());
            runningSettings.push_back(sett);
        }

        //LongJump
        value = object.value("LongJump");
        longJumpSimulationSettings.setMinResult(value.toObject().value("minResult").toDouble());
        longJumpSimulationSettings.setRandEffect(value.toObject().value("randEffect").toDouble());
        longJumpSimulationSettings.setAccelarateSkillEffect(value.toObject().value("accelarateSkillEffect").toDouble());
        longJumpSimulationSettings.setJumpSkillEffect(value.toObject().value("jumpSkillEffect").toDouble());
    }
}

void App::simulateCompetitionChoice()
{
    using std::cout;

    int ch;
    system("cls");
    ColorText::write(15, "Wybierz dyscypline\n");
    cout<<"1. Biegi\n"
       <<"2. Skok w dal\n";
    std::cin >> ch;

    Competition competition;
    QVector<Athlete *> athletes;
    athletes.clear();

    switch(ch)
    {
    case 1:{
        ColorText::write(15, "\nJaki dystans biegow:\n");
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
    case 2:{
        for(auto & lon : longJumpAthletes)
        {
            lon.setSettings(&longJumpSimulationSettings);
            athletes.push_back(&lon);
        }
        competition.setCompetitionType(Competition::LongJump);
        break;
    }
    default:
        break;
    }
    competition.setAthletes(athletes);

    ColorText::write(15, "Zawodnicy:\n");
    int i =1;
    for(const auto & ath : athletes)
    {
        cout<<i<<". "<<ath->getName().toStdString()<<" ("<<ath->getNationality().toStdString()<<")\n";
        i++;
    }
    getch();
    competition.startCompetition();
}
