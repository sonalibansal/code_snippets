//https://www.geeksforgeeks.org/generate-passwords-given-character-set/
#include <iostream>
#include <vector> 
using namespace std;


char arr[] = {'a','b'};
string output = "";
int k = 2;
int n = 2;

void printPassword (int index, string output) {
	if(index == 0) {
		cout << output << endl;
		return;
	}
	
	for (int j = 0 ; j < k ; j++) {
		printPassword(index-1, output+arr[j]);
	}
	
}

int main() {
	
	for (int i = 1; i <=k ;i++) {
		printPassword(i, "");
	}
	
	return 0;
}