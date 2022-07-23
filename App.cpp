#include "App.h"
#include "Random.h"

#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QTextStream>
#include <iostream>

QTextStream out(stdout);

App::App()
{


}

void App::start()
{
    using std::cout;
    loadSimulationSettings();
    cout<<"Witaj w symulatorze lekkoatletyki! Co chcesz zrobic?\n";
    cout<<"1. Symuluj zawody\n";
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
