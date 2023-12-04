#include "Random.h"

int Random::RandomIntInRange(int lower, int upper)
{
	int range = upper - lower + 1;
	int num = std::rand() % range + lower;
	return num;
}