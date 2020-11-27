//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
#include <iostream>
#include <cstring>
using namespace std;
//string str1 = "ABCDGH", str2 = "AEDFHR";
string str1= "AA", str2="A";
int n = str1.length(), m = str2.length();
int dp[100][100];
int lcsLength(int i, int j) {
	if(i >=n || j >=m) {
		return 0;
	}
	if(str1[i] == str2[j]) {
		dp[i][j] = 1 + lcsLength(i+1,j+1);
	}
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	dp[i][j] = max (lcsLength(i, j+1), lcsLength(i+1, j));
	return dp[i][j];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << lcsLength(0,0) << endl;
	return 0;
}