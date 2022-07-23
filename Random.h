#pragma once
#include <random>


class Random
{
public:
    Random();
    static int randomInt(int min, int max);
    static double randomDouble(double min, double max);
    static double normalRandom(double mid, double a);
};

