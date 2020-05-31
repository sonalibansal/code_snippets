//https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<string > > allParts;

vector<string> currPart;

// O(n)
bool palindrom (string s, int low , int high) {
	for (int i = low , j = high; i != j; i++, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	} 
	return true;
}


// O(n^2)
void allPalindromicPartition (int n , int start , string str) {

	if (start >= n) {
		allParts.push_back (currPart);
		return;
	}

	for (int i = start ; i < n ; i++) {

		if (palindrom (str, start, i)) {

			currPart.push_back (str.substr (start, i-start +1)) ;

			allPalindromicPartition (n, i+1, str);

			currPart.pop_back ();
		}
	}
}

int main () {

	string s = "nitin";

	allPalindromicPartition (s.size(), 0 , s );

	for (int i = 0 ; i < allParts.size() ; i++) {
		for (int j = 0 ; j < allParts[i].size() ; j++) {
			cout << allParts[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}