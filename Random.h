#pragma once
#include <random>


class Random
{
public:
    static int randomInt(int min, int max);
    static double randomDouble(double min, double max);
    static double normalRandom(double mid, double a);
};

class ColorText
{
public:
    static void write(unsigned short color, std::string text);
    static void write(unsigned short color, double text);
    static void write(unsigned short color, int text);
};
