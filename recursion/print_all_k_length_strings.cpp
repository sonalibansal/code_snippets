//https://www.geeksforgeeks.org/print-all-combinations-of-given-length/
#include <iostream>
using namespace std;

//O(n^k) where n is the set size and k is the length wanted for the string
void printAllKLengthStringsUtil (char set[], string prefix, int n, int k) {
	if (k == 0) {
		cout << prefix << endl;
		return;
	}

	for (int i = 0 ; i < n ; i++) {
		prefix = prefix + set[i];
		printAllKLengthStringsUtil (set, prefix , n, k-1);
		prefix.erase (prefix.length() -1);
	}

}

void printAllKLengthStrings (char set[], int k, int n) {

	string prefix = "";

	printAllKLengthStringsUtil (set, prefix, n , k);

}

int main () {

	char set[] = {'a','b'};

	int k = 3;
	printAllKLengthStrings (set, k, 2);

	char set2[] = {'a', 'b', 'c', 'd'}; 
    k = 1; 
    printAllKLengthStrings(set2, k, 4); 

}