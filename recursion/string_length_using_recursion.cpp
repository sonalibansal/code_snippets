#include <iostream>
using namespace std;

string s = "abcd";

int stringLength(int index) {
	if(s[index] == '\0') {
		return 0;
	}
	return 1+ stringLength(index+1);
}

int main() {
	// your code goes here
	cout << "String length = " << stringLength(0) << endl;
	return 0;
}