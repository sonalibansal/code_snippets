//https://www.geeksforgeeks.org/combinations-string-digits/
#include <iostream>
using namespace std;


void printCombinations (string input, string output, int index) {

	if(index == input.length()) {
		cout << output << endl;
		return;
	}

	output = output+ input[index];
	printCombinations (input, output+' ', index+1);

	if(index+1 < input.length()) {
		printCombinations (input, output, index+1);
	} 

}

int main () {
	string input = "1234";
	printCombinations(input, "", 0);

	return 0;
}