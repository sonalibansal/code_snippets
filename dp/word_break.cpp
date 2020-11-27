//https://practice.geeksforgeeks.org/problems/word-break/0
#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

#define n 9
#define ALPHABET_SIZE 26
string dict[] = { "i", "like", "sam", "sung", "samsung", "mobile", "ice",
  "cream", "icecream", "man", "go", "mango"};
string str = "isamsung";
int dp[n][n];

class TrieNode {
	public :
	bool isEndOfWord;
	TrieNode* children[ALPHABET_SIZE];
};

TrieNode* getNewNode() {
	TrieNode* temp = new TrieNode();
	
	temp -> isEndOfWord = false;
	for(int i = 0 ; i < ALPHABET_SIZE; i++) {
		temp -> children[i] = NULL;
	}
	return temp;
}

TrieNode* root = getNewNode();

void insert(TrieNode* root, string key){
	TrieNode* pcrawl = root;
	
	for(int i = 0 ; i < key.size() ; i++) {
		int index = key[i]-'a';
		if(!pcrawl -> children[index]) {
			pcrawl -> children[index] = getNewNode();
		}
		pcrawl = pcrawl -> children[index];
	}
	pcrawl -> isEndOfWord = true;
}

//O(key.length()
bool search(TrieNode* root, string key) {
	TrieNode* pcrawl = root;
	
	for(int i = 0 ; i < key.size() ; i++) {
		int index = key[i]-'a';
		if(!pcrawl -> children[index]) {
			return false;
		}
		pcrawl = pcrawl -> children[index];
	}
	return (pcrawl != NULL && pcrawl -> isEndOfWord);
}


int wordBreak(int index, int startIndex) {
	string curr = str.substr(startIndex, index-startIndex);
	if(search(root, curr) && index >= str.length()) {
		return 1;
	}
	if(!search(root, curr)) {
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
	
	for(int i = 0 ; i < 12; i++) {
		insert(root, dict[i]);
	}
	
	if(wordBreak(0, 0)) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
	return 0;
}