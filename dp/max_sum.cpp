#include <iostream>
#include <vector>
using namespace std;
int arr[] = {1,5,3,4,5};
int n = 5;
int dp[5];

int maxSumElements(int index) {
	if(index >= n) {
		return 0;
	}
	if(dp[index] != -1) {
		return dp[index];
	}
	
	int maxa = arr[index] + maxSumElements(index+2);
	int maxb = maxSumElements(index+1);
	dp[index] = max(maxa, maxb);
	return dp[index];
}

int main() {
	for(int i = 0 ; i < n; i++) {
		dp[i] = -1;
	}
	cout << 	maxSumElements(0) << endl;
	return 0;
}