//https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
#include <iostream>
using namespace std;
int arr[] = {3,34,4,12,5,2};
int n = 6, givenSum = 9;

bool subsetSumProblem(int index, int sum=0) {
	if(sum == givenSum) {
		return true;
	}
	
	if(sum > givenSum || index >=n ) {
		return false;
	}
	return subsetSumProblem(index+1, sum) || subsetSumProblem(index+1, sum+arr[index]);
}

int main() {
	// your code goes here
	if(subsetSumProblem(0)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}