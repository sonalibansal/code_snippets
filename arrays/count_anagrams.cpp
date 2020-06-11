//https://www.geeksforgeeks.org/count-occurences-of-anagrams/
#include <iostream>
#include <algorithm>
using namespace std;

string word = "for";
string text = "forxxorfxdofr";
bool isAnagram(string sub) {
	sort(sub.begin(), sub.end());
	sort(word.begin(), word.end());
	
	for(int i = 0 ; i < word.length() ; i++) {
		if(sub[i] != word[i]) {
			return false;
		}
	}
	return true;
}

int countAnagrams() {
	int n = text.length();
	int N = word.length();
	int count = 0;
	for(int i = 0 ; i <= n-N ;i++) {
		if(isAnagram(text.substr(i, N))) {
			count++;
		}
	}
	return count;
}

int main() {
	// your code goes here
	cout << "Number of anagrams = " << countAnagrams() << endl;
	return 0;
}