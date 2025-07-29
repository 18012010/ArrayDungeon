#include <iostream>
#include <queue>
#include "Random.h"

int avilable = 15;

int map[100] = {0};
queue<int> cellQueue;

int getNeighbours(int index) {
	return map[index - 10] + map[index - 1] + map[index + 1] + map[index + 10];
}

bool visitCell(int index) {
	if (avilable == 0 || getNeighbours(index) > 1 || map[index] != 0 || Random::range(0, 100) < 30)
		return false;

	map[index] = 1;
	avilable--;
	cellQueue.push(index);

	return true;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	visitCell(44);

	while (cellQueue.size() > 0) {
		bool cell = false;

		int index = cellQueue.front();
		cellQueue.pop();
		int x = index % 10;

		if (x > 1) cell |= visitCell(index - 1);
		if (x < 9) cell |= visitCell(index + 1);
		if (index > 20) cell |= visitCell(index - 10);
		if (index < 70) cell |= visitCell(index + 10);
	}

	int c = 0;

	for (int number : map) {
		if (c == 10) {
			c = 0;
			std::cout << endl;
		}

		std::cout << number;
		c++;
	}
}