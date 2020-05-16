//https://www.geeksforgeeks.org/recursive-implementation-of-atoi/
#include <iostream>
using namespace std;


// O(n) where n is the length of the string
int atoiUtil (string s, int index, int n) {

	if (index == s.length()) {
		return n;
	}
	return atoiUtil (s, index+1 , n * 10 + s[index]-'0');
}


int main () {

	string s = "123";

	int num = atoiUtil (s,0, 0);

	cout << num << " " << endl;

	string s1 = "1";

	num = atoiUtil (s1,0,0);
	cout << num << " " << endl;

}