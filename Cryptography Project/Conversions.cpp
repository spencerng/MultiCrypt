#include<vector>
#include <string>
using std::string;
using std::vector;

vector<char> stringToCharVec(string input) {
	vector<char> output;
	for (int i = 0; i < input.size(); i++)
		output.push_back(input[i]);
	return output;

}

//Not finished
vector< vector<int> > toNumbMatrix(vector<char> message) {
	int dimension = message.size();
	while (dimension % 3 != 0)
		dimension++;
	vector< vector<int> > encodedMatrix(3, vector<int>(dimension / 3));
	//Complete function here

	return encodedMatrix;
}

vector<int> charVecToInt(vector<char> input) {
	vector<int> output;
	for (int i = 0; i < input.size(); i++)
		output.push_back(int(input[i]));
	return output;

}

vector<char> intVecToChar(vector<int> input) {
	vector<char> output;
	for (int i = 0; i < input.size(); i++)
		output.push_back(char(input[i]));
	return output;

}
vector< char > toLowerCase(vector<char> charArray) {
	vector<char> output = charArray;
	for (int i = 0; i < charArray.size(); i++) {
		if (output[i] >= 'A' && output[i] <= 'Z')
			output[i] = tolower(output[i]);
	}

	return output;
}