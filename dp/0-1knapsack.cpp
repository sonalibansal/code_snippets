//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <iostream>
#include <cstring>
using namespace std;
int val[] {60,100,120};
int wt[] = {10,20,30};
int n = 3, W = 50;
int dp[3][1000];

int maxSubset(int index, int weight=0) {
	if(weight > W) {
		return -1000;
	}
	
	if(index>=n) {
		return 0;
	}
	if(dp[index][weight] != -1) {
		return dp[index][weight];
	}
	int maxa = val[index] + maxSubset(index+1, weight+wt[index]);
	int maxb = maxSubset(index+1, weight);
	dp[index][weight] = max(maxa, maxb);
	return dp[index][weight];
}

int main() {
	memset(dp,-1, sizeof(dp));
	cout << maxSubset(0);
	return 0;
}