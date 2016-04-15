#include "Headers/Conversions.h"

vector< vector<int> > toNumbMatrix(string message) {

	int dimension = message.length();
	while (dimension % 3 != 0)
	{
		dimension++;
		message.push_back(' '); // Appends extra whitespaces to the message so it can fit in a 3 x m matrix
	}

	vector< vector<int> > encodedMatrix(3, vector<int>(dimension / 3)); // Initializes the matrix
	int counter = 0;
	for (int j = 0; j < encodedMatrix[0].size(); j++)
		for (int i = 0; i < 3; i++)
		{

			encodedMatrix[i][j] = message[counter++];

		}
	return encodedMatrix;
}

// Should be deprecated
string matrixToString(vector< vector<int> > input) {
	string output = "";
	
	for (int j = 0; j < input[0].size(); j++)
		for (int i = 0; i < 3; i++)
		{

			output += input[i][j] ; 

		}
	return output;
}

string matrixToString(vector< vector<unsigned long long> > input) {
	string output = "";

	for (int j = 0; j < input[0].size(); j++)
		for (int i = 0; i < 3; i++)
		{

			output += input[i][j]; // Appends each character to output, column by column

		}
	return output;
}

// Deprecated
vector< char > toLowerCase(vector<char> charArray) {
	vector<char> output = charArray;
	for (int i = 0; i < charArray.size(); i++) {
		if (output[i] >= 'A' && output[i] <= 'Z')
			output[i] = tolower(output[i]); //  tolower is a system function
	}

	return output;
}

string keyOutputString(vector< vector<unsigned long long> > input) {
	string output = "";

	for (int i = 0; i < input[0].size(); i++) {
		for (int j = 0; j < 3; j++)
			output += to_string(input[i][j]) + " "; // to_string converts an int to a string, dependant on the string class
	}
	return output;
}

string messageOutputString(vector< vector<unsigned long long> > input) {
	string output = to_string(input[0].size()) + " "; // Outputs the number of columns, useful for recreating the matrix while decrypting

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < input[0].size(); j++)
			output += to_string(input[i][j]) + " ";
	return output;
}

vector<vector<unsigned long long>> keyInputMatrix(string input) {
	vector<vector<unsigned long long> > output(3, vector<unsigned long long>(3));
	
	//Stringstreams use the stream operator, which uses a whitespace as a delimiting character, to direct the contents of a string to a variable
	stringstream buffer(input); 
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			
			//The space-separated numbers are stored in output
			buffer >> output[i][j];
	return output;

}

vector<vector<unsigned long long>> messageInputMatrix(string input) {

	stringstream buffer(input);
	int col;
	buffer >> col;

	// col is the number of columns in the message matrix, used to declare the matrix output
	vector<vector<unsigned long long> > output(3, vector<unsigned long long>(col));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < col; j++)
			buffer >> output[i][j];
	return output;

}
