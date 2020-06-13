//https://www.geeksforgeeks.org/print-increasing-sequences-length-k-first-n-natural-numbers/
#include <iostream>
#include <vector>
using namespace std;

int n = 3, k =2;
vector<int> output(k);
void printIncreaseSequence(int length, int number) {
	if(length == k) {
		for (int i = 0 ; i < k ;i++) {
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}
	
	if(number > n) {
		return;
	}
	output[length] = number;
	printIncreaseSequence(length+1, number+1);
	printIncreaseSequence(length, number+1);
}

int main() {
	// your code goes here
	printIncreaseSequence(0, 1);
	return 0;
}