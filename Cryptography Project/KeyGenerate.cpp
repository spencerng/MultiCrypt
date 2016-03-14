#include "headers\KeyGenerate.h"
#include "headers\MatrixMath.h"
#include <ctime>
using std::vector;

vector< vector<int> > randomMatrix() {
	srand(time(NULL));
	int seed;
	vector< vector<int> > randomM;
	do {
		seed = rand() % 7 + 1;
		randomM = unimodMatrix(seed);
		int iterations = rand() % 15 + 5;
		for (int i = 0; i < iterations; i++) {
			int isInverted = rand();
			if (isInverted % 2 == 0)
				randomM = inverseInt(randomM);
			seed = rand() % 7 + 1;
			randomM = multiply(randomM, unimodMatrix(seed));


		}
	} while (inverseInt(randomM)[0][0] > 100000 || inverseInt(randomM)[0][0] < -1000000);


	return randomM;
}

vector< vector<int> > unimodMatrix(int n) {
	vector< vector<int> > randomM(3, vector<int>(3));
	randomM[0][0] = 8 * n*n + 8 * n;
	randomM[0][1] = 2 * n + 1;
	randomM[0][2] = 4 * n;
	randomM[1][0] = 4 * n*n + 4 * n;
	randomM[1][1] = n + 1;
	randomM[1][2] = 2 * n + 1;
	randomM[2][0] = 4 * n*n + 4 * n + 1;
	randomM[2][1] = n;
	randomM[2][2] = 2 * n - 1;

	return randomM;
}