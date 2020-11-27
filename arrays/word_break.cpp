//https://practice.geeksforgeeks.org/problems/word-break/0
#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

#define n 8
unordered_set<string> dict = { "i", "like", "sam", "sung", "samsung", "mobile", "ice",
  "cream", "icecream", "man", "go", "mango"};
string str = "isamsung";
int dp[n][n];

//O(n^2)
int wordBreak(int index, int startIndex) {
	string curr = str.substr(startIndex, index-startIndex);
	if(dict.find(curr) != dict.end() && index >= str.length()) {
		return 1;
	}
	if(dict.find(curr) == dict.end()) {
		if(index == str.length())
		return 0;
		
		if(dp[index][startIndex] != -1) {
			return dp[index][startIndex];
		}
		dp[index][startIndex] = wordBreak(index+1, startIndex);
		return dp[index][startIndex];
	}
	dp[index][startIndex] = wordBreak(index+1, startIndex) || 	wordBreak(index+1, index);
	return dp[index][startIndex];
}

int main() {
	memset(dp, -1, sizeof(dp));
	if(wordBreak(0, 0)) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
	return 0;
}