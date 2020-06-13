//https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
#include <iostream>
#include <vector>
using namespace std;

int arr[] = {1,2,3,4};
int n = 4,r=2;
vector<int> output(r);
void printAllCombinations(int length, int index) {
	if(length == r) {
		for (int i = 0 ; i < r ;i++) {
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}
	
	if(index >= n) {
		return;
	}
	output[length] = arr[index];
	printAllCombinations(length+1, index+1);
	printAllCombinations(length, index+1);
}

int main() {
	// your code goes here
	printAllCombinations(0, 0);
	return 0;
}