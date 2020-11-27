//https://www.geeksforgeeks.org/number-n-digits-non-decreasing-integers/
#include <iostream>
#include <cstring>
using namespace std;
int n = 4;
int dp[4][10];
int countCombinations(int index, int lastDigit = 0) {
	if(index >= n) {
		return 1;
	}
	if(dp[index][lastDigit] != -1) {
		return dp[index][lastDigit];
	}
	int count = 0;
	for(int i = lastDigit; i <= 9 ; i++) {
		count = count + countCombinations(index+1, i);
	}
	dp[index][lastDigit] = count;
	return count;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << countCombinations(0) << endl;
	return 0;
}