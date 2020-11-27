//https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

#include <iostream>
#include <cstring>
using namespace std;
int arr[] = {3,34,4,12,5,2};
int n = 6, givenSum = 30;
int dp[6][1000];

int subsetSumProblem(int index, int sum=0) {
	if(sum == givenSum) {
		return 1;
	}
	
	if(sum > givenSum || index >=n ) {
		return 0;
	}
	if(dp[index][sum] != -1) return dp[index][sum];
	dp[index][sum] = subsetSumProblem(index+1, sum) || subsetSumProblem(index+1, sum+arr[index]);
	return dp[index][sum];
}

int main() {
	// your code goes here
	memset(dp, -1, sizeof(dp));
	if(subsetSumProblem(0)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}