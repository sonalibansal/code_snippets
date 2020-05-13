//https://www.geeksforgeeks.org/number-of-simple-graph-with-n-vertices-and-m-edges/
#include <iostream>
using namespace std;

//O(n)
int factorial (int n ) {
	if( n == 0 || n == 1) {
		return 1;
	}
	return n * factorial(n-1);
}

//O(n)
int countNumberOfSimpleGraphs (int n, int m) {

	int p = (n* (n-1))/2; //O(1)

	int fact = factorial (p)/ (factorial(p-m) * factorial(m));

	return fact;
}

int main () {
	int N = 5 , M = 2;

	cout << "Number of simple graph " << countNumberOfSimpleGraphs(N, M) << endl;
}