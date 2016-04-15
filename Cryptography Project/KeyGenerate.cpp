#include "Headers/KeyGenerate.h"


vector< vector<unsigned long long> > randomMatrix() {
	srand(time(NULL));
	printf("\n\tEncrypting");
	vector< vector<unsigned long long> > randomM;	
		
		randomM = unimodMatrix();
		int iterations = rand() % 500+500; // 500-1000 iterations
		for (int i = 1; i <= iterations; i++) {
			int isInverted = rand();
			if (isInverted % 2 == 0) // Randomly invert for complexity
				randomM = inverseInt(randomM);
			
			randomM = multiply(randomM, unimodMatrix());
			if (i % 10 == 0)
				
				printf(".");
		}
		
		printf("\n");
	return randomM;
}

vector< vector<unsigned long long> > unimodMatrix() {
	return multiply(randomL(), randomU());
}

vector< vector<unsigned long long> > randomL() {
	srand(time(NULL));
	vector< vector<unsigned long long> > randomM(3, vector<unsigned long long>(3, 0));
	randomM[0][0] = 1;
	randomM[1][1] = 1;
	randomM[2][2] = 1;
	randomM[0][1] = rand() % 1000000 + 1; // Generates entries 1-1000000
	randomM[0][2] = rand() % 1000000 + 1;
	randomM[1][2] = rand() % 1000000 + 1;
	return randomM;

}

vector< vector<unsigned long long> > randomU() {
	srand(time(NULL));
	vector< vector<unsigned long long> > randomM(3, vector<unsigned long long>(3, 0));
	randomM[0][0] = 1;
	randomM[1][1] = 1;
	randomM[2][2] = 1;
	randomM[1][0] = rand() % 1000000 + 1;
	randomM[2][0] = rand() % 1000000 + 1;
	randomM[2][1] = rand() % 1000000 + 1;
	return randomM;

}