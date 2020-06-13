//https://www.geeksforgeeks.org/print-all-combinations-of-given-length/
#include <iostream>
using namespace std;

char arr[] = {'a','b'};
int n = 2, k = 3;
string output = "";

void printAllCombinations(int length) {
	if(length == k) {
		cout << output << endl;
		return;
	}
	for (int i = 0; i < n ; i++) {
		output = output+ arr[i];
		printAllCombinations(length+1);
		output.erase(output.size()-1);
	}
}

int main() {
	// your code goes here
	printAllCombinations(0);
	return 0;
}