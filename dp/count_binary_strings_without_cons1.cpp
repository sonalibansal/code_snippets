//https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
#include <iostream>
#include <cstring>
using namespace std;
int k = 3, dp[3][3];
int countWays(int index, int lastDigit) {
	if(index >= k) {
		return 1;
	}
	if(dp[index][lastDigit] != -1) {
		return dp[index][lastDigit];
	}
	
	if(lastDigit == 1) {
		dp[index][lastDigit] =  countWays(index+1, 0);
		return dp[index][lastDigit];
	}
	
	int count = 0;
	for(int i = lastDigit; i <= 1 ; i++) {
		count = count + countWays(index+1, i);
	}
	dp[index][lastDigit] = count;
	return dp[index][lastDigit];
}

int getCount() {
	if(k == 0) { 
		return 0;
	}
	if(k == 1) {
		return 2;
	}
	return countWays(1, 0) + countWays(1, 1);
}
int main() {
	memset(dp, -1, sizeof(dp));
	cout << getCount();
	return 0;
}