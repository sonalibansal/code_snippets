//https://www.geeksforgeeks.org/print-all-non-increasing-sequences-of-sum-equal-to-a-given-number/
#include <iostream>
#include <vector>
using namespace std;

int n = 4;
vector<int> output(n, 0);

void printSequences (int index, int remainingSum, int currNum){
	if (remainingSum == 0) {
		for (int i = 0 ; i < index ;i++) {
			cout << output[i] << " ";
		} 
		cout << endl;
		return;
	}
	if(remainingSum <0 || index == n) {
		return;
	}
	
	output[index] = currNum;
	printSequences(index+1,remainingSum-currNum, currNum);
	if(currNum >=1)
	printSequences(index, remainingSum, currNum-1);
}

int main () {
	printSequences(0, n, n);
	return 0;
}