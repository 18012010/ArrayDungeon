#include "Random.h"

int Random::range(int min, int max) {
	int range = max - min + 1;

	return rand() % range + min;
}