//https://www.geeksforgeeks.org/find-mth-summation-first-n-natural-numbers/
#include<iostream>
using namespace std;

int n = 3, m = 2;

int sum (int n, int m) {
	if (m > 1) {
		return sum (sum (n, m-1), 1);
	}
	return (n * (n+1))/2;	
}

int main () {
	int result = sum (n, m); 
	cout << result << endl;

	return 0;
}