#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//string str = "kayakracecartenet";
//string str = "aardvark";
//string str = "aaaaa";
//string str ="nitinaaaaa";
//string str = "aaaaaaaaaaaaa";
string str = "aa";
int n = str.length(), K = 3, dp[1000][1000], dpp[1000][3];
vector<string> res;


int isPalindrome(int start, int end) {
	if(start >= end) {
		return 1;
	}
	if(dp[start][end] != -1) {
		return dp[start][end];
	}
	if(str[start] != str[end]) {
		dp[start][end] = 0;
		return dp[start][end];
	}
	dp[start][end] = isPalindrome(start+1, end-1);
	return dp[start][end];
}
bool getPalindromicPartitions(int index, int k) {
	if(index >= n && k == K) {
		return true;
	}
	if(k >= K) {
		return false;
	}
	if(dpp[index][k] != -1) {
		return dpp[index][k];
	}
	bool result = false;
	for(int i = index; i < n ;i++){
		if(isPalindrome(index, i)) {
			result = getPalindromicPartitions(i+1, k+1);
			if(result) {
				res.push_back(str.substr(index, i-index+1));
				break;
			}
		}
	}
	dpp[index][k] =  result;
	return dpp[index][k];
}
int main() {
	memset(dp, -1, sizeof(dp));
	memset(dpp, -1, sizeof(dpp));
	if(!getPalindromicPartitions(0, 0)) {
		res.push_back("Impossible");
	}
	for(int i = 0; i < res.size() ;i++) {
		cout << res[i] << endl;
	}
	return 0;
}