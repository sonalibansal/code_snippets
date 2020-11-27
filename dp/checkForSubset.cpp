//https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include <iostream>
#include <cstring>
using namespace std;
#define n 4
int arr[] = {1,5,11,5};
//int arr[] = {1,3, 5 };
int dp[n][100];
int totalSum = 0;

int subsetProblem(int index, int sum) {
	if(sum == (totalSum -sum)) {
		return 1;
	}
	if(index >= n || (2*sum > totalSum)) {
		return 0;
	}
	if(dp[index][sum] != -1) {
		return dp[index][sum];
	}
	dp[index][sum] = subsetProblem(index+1, sum+arr[index]) || subsetProblem(index+1, sum);
	return dp[index][sum];
}

int main() {
	memset(dp, -1, sizeof(dp));
	for(int i = 0 ; i < n ; i++) {
		totalSum = totalSum + arr[i];
	}
	if(subsetProblem(0, 0)) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
	return 0;
}