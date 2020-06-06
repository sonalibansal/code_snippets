//https://www.geeksforgeeks.org/count-consonants-string-iterative-recursive-methods/
#include <iostream>
using namespace std;


bool isConsonant(char character) {
	if (character != 'a'
		&& character != 'e'
		&& character != 'i'
		&& character != 'o'
		&& character != 'u'
		&& ((character >= 65 && character <= 90)
		|| (character >= 97 && character <= 122) )) {
		return true;
	}
	return false;
}
int countConsonants (string s, int index, int count) {
	if (index == s.length()) {
		return count;
	}

	if(isConsonant(s[index])) {
		count ++;
	}

	return countConsonants (s, index+1, count);
}

int main () {
	string s = "abc de";

	int count = countConsonants(s, 0 , 0);

	cout << count << endl;

	return 0;
}