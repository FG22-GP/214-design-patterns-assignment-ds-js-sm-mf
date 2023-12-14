#pragma once
#include <iostream>
#include <random>

class Random
{
public:
    static int RandomIntInRange(int lower, int upper);
    static bool RandomBool();
    static float RandomFloat(float min, float max);
    
};
