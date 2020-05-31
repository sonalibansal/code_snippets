#include <iostream>
using namespace std;

void generateBinaryStringsUtil (int k , char str[], int n) {

	if (n == k) {
		str[n] = '\0';
		cout << str << " ";
		return;
	}

	if (str[n-1] == '1') {
		str[n] = '0';
		generateBinaryStringsUtil (k, str, n+1);

	}

	if (str[n-1] == '0') {
		str[n] = '0';
		generateBinaryStringsUtil (k, str, n+1);
		
		str[n] = '1';
		generateBinaryStringsUtil (k, str, n+1);

	}
}

void generateBinaryStrings (int k) {

	if (k <= 0) {
		return;
	}

	char str[k+1];

	str[0] = '0';
	generateBinaryStringsUtil (k, str, 1);

	str[0] = '1';
	generateBinaryStringsUtil (k, str, 1);

}


int main () {
	int K = 3;
	generateBinaryStrings (K);

	return 0;
}