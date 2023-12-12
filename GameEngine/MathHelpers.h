#pragma once
#include <cmath>
#include <random>
#include "Random.h"


class MathHelpers
{
public:
    static constexpr double PI =  3.14159265358979323846264338327950288;
    
    static double LocationToAngleInRadians(float x, float y)
    {
        return std::atan2(y, x);
    }

    static double LocationToAngle(float x, float y)
    {
        return (LocationToAngleInRadians(x,y) / PI) * 180;
    }

    static double AngleToRadians(float angle)
    {
        return angle * (PI / 180.0f);
    }

};
