//https://www.geeksforgeeks.org/longest-common-subsequence-with-at-most-k-changes-allowed/
#include <iostream>
using namespace std;

//int P[] = {8,3}, Q[] = {1,3};
int P[] = { 1, 2, 3, 4, 5 };
int Q[] = { 5, 3, 1, 4, 2 };
int k = 1, n = 5, m = 5;

int lcs(int i, int j, int k) {
	if(i >= n || j >= m) {
		return 0;
	}
	if(P[i] == Q[j]) {
		return 1+ lcs(i+1, j+1, k);
	}
	int maxa = max(lcs(i, j+1, k), lcs(i+1, j, k));
	if(k > 0) {
		int maxb = 1 + lcs(i+1, j+1, k-1);
		//cout << maxa << " "<< maxb << endl;
		return max(maxa, maxb);
	}
	return maxa;
}

int main() {
	cout << lcs(0,0,k);
	return 0;
}