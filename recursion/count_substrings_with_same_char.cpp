//https://www.geeksforgeeks.org/recursive-solution-count-substrings-first-last-characters/
#include <iostream>
using namespace std;

int countSubstringsUtil (string s, string output, int count, int len, int j) {
	output = output + s[j];
	if (j == s.length ()) {
		return count;
	}
	if (output[len] == output[0]) {
		count++;
	}
	return countSubstringsUtil (s, output, count, len+1, j+1);
}

void countSubstrings (string s, int count, int len, int i) {
	for (int i = 0 ; i < s.length () ; i ++) {
		count = countSubstringsUtil (s, "", count, 0, i);
	}
	cout << count << endl;
}

int countSubstrs(string str, int i, int j, int len) 
{ 
    // base cases 
    if (len == 1) 
        return 1; 
    if (len <= 0) 
        return 0; 
  
    int res =  countSubstrs(str, i + 1, j, len - 1) +   
               countSubstrs(str, i, j - 1, len - 1) - 
               countSubstrs(str, i + 1, j - 1, len - 2);             
  
    if (str[i] == str[j]) 
        res++;  
  
    return res; 
} 

int main () {
	string s = "abcab";

	int count = 0, len = 0, i = 0;
	countSubstrings (s, count, len, i);
	len = s.length ();

	count = countSubstrs (s, 0, len-1, len);

	cout << count << endl;
}