//https://www.geeksforgeeks.org/recursive-program-prime-number/
#include <iostream>
using namespace std;

int n = 15;

bool checkIfPrime(int i) {
	if(n <=1) {
		return false;
	}
	if(n ==2) {
		return true;
	}

	if(n%2 == 0) {
		return false;
	}

	if (n%i ==0) {
		return false;
	}

	if(i*i > n) {
		return true;
	}

	return checkIfPrime(i+1);
}


int main () {

	if(checkIfPrime(2)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}