#include "Random.h"
#include <iostream>
#include <windows.h>

int Random::randomInt(int min, int max)
{
    static std::random_device dev;
   std::uniform_int_distribution<int> rd(min, max);
    return rd(dev);
}

double Random::randomDouble(double min, double max)
{
    srand(time(NULL));
    double rr[50];
    int rrr = randomInt(0, 49);
    for (int i = 0; i <= 49; i++)
    {
        rr[i] = ((double)rand() / RAND_MAX) * (max - min) + min;
    }
    return rr[rrr];
}

double Random::normalRandom(double mid, double a)
{
    srand(time(NULL));
    std::default_random_engine gen;
    std::normal_distribution<double> ndist(mid, a);
    double min, max;
    double rd[1000];
    int nr = randomInt(0, 999);

    for (int i = 0; i < 1000; i++)
    {
        rd[i] = ndist(gen);
        if (i == 0)
        {
            min = rd[i];
            max = rd[i];
        }
        if (rd[i] > max)
            max = rd[i];
        else if (rd[i] < min)
            min = rd[i];
    }

    return rd[nr];
}

void ColorText::write(unsigned short color, std::string text)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    std::cout << text;
    SetConsoleTextAttribute(hcon, 7);
}

void ColorText::write(unsigned short color, double text)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    std::cout << text;
    SetConsoleTextAttribute(hcon, 7);
}
void ColorText::write(unsigned short color, int text)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    std::cout << text;
    SetConsoleTextAttribute(hcon, 7);
}
