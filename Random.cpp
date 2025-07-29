#include "Random.h"

int Random::range(int min, int max) {
	bool seeded = false;

	int range = max - min + 1;

	return rand() % range + min;
}