////https://practice.geeksforgeeks.org/problems/maximum-profit/0
#include <iostream>
#include <cstring>
using namespace std;

int arr[] = {10,22,5,75,65,80};
//int arr[] = {20, 580, 420, 900};
//int arr[] = {100, 90, 80, 50, 25};
int n = 6, k = 2;
int dp[6][2][2];
int maxProfit(int index, int flag = 0, int count = 0) {
	if((index >= n && flag == 1) || count > k) {
		return -1000;
	}
	if(index >= n && flag == 0) {
		return 0;
	}
	if(dp[index][flag][count] != -1) {
		return dp[index][flag][count];
	}
	int maxa = 0, maxb = 0;
	if(flag == 0) {
		maxa = -arr[index] + maxProfit(index+1, !flag, count);	
	} 
	if(flag == 1) {
		maxa = arr[index] + maxProfit(index+1, !flag, count+1);
	}
	maxb =  maxProfit(index+1, flag, count);
	dp[index][flag][count] = max(maxa, maxb);
	return dp[index][flag][count];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << maxProfit(0) << endl;
	return 0;
}