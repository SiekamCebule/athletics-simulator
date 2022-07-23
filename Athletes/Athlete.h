#pragma once
#include <QString>


class Athlete
{
    QString name, nationality;

protected:
    double result;
public:
    Athlete(const QString &name = "", const QString &nationality = "");

    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getNationality() const;
    void setNationality(const QString &newNationality);

    double getResult() const;
    void setResult(double newResult);
};

