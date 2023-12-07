#include "Random.h"

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
