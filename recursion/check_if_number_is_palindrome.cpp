//https://www.geeksforgeeks.org/check-if-a-number-is-palindrome/
#include <iostream>

using namespace std;


// O(n) where n is the number of digits in the number
int reverse (int &n, int &rev) {

	int rem ;
	if (n < 1) {
		return rev;
	}

	rem = n % 10;
	rev = rev * 10 + rem;
	n = n/10;
	return reverse (n, rev);
}


bool palindrome (int n) {

	if (n < 0) {
		n = -n;
	}
	int rev = 0, number = n;
	rev = reverse (n, rev);

	if (rev == number) {
		return true;
	}

	return false;
}


void checkPalindrome (int n) {
	if (palindrome (n)) {
		cout << "YES" << endl;
	} else {
		cout << "NO " << endl;
	}
}

int main () {
	int n = 55;
	checkPalindrome (n);

	n = 12; 
    checkPalindrome (n);
  
    n = 88; 
    checkPalindrome (n);

    n = 8999; 	
    checkPalindrome (n);
	return 0;
}