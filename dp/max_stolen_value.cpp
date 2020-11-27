//https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/
#include <iostream>
#include <cstring>
using namespace std;
//int arr[] = {6, 7, 1, 3, 8, 2, 4};
int arr[] = {5, 3, 4, 11, 2};
int n = 5, dp[5];

int maxStolenValue(int index) {
	if(index >=n) {
		return 0;
	}
	if(dp[index] != -1) {
		return dp[index];
	}
	int maxa = arr[index] + maxStolenValue(index+2);
	int maxb = maxStolenValue(index+1);
	dp[index] =  max(maxa, maxb);
	return dp[index];
}
int main() {
	memset(dp, -1, sizeof(dp));
	cout << maxStolenValue(0);
	return 0;
}