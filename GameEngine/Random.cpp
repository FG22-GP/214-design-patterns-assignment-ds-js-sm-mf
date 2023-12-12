#include "Random.h"

#include <random>

int Random::RandomIntInRange(int lower, int upper)
{
    int range = upper - lower + 1;
    int num = std::rand() % range + lower;
    return num;
}

bool Random::RandomBool()
{
    if (std::rand() % 2 == 0)
    {
        return true;
    }
    return false;
}

float Random::RandomFloat(float min, float max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);

    return dis(gen);
}
