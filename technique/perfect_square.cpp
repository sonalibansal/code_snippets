//https://www.geeksforgeeks.org/check-if-a-given-number-is-a-perfect-square-using-binary-search/?ref=leftbar-rightbar
#include <iostream>
using namespace std;
int N  = 490;
// int N  = 4900;
// int N = 81;
//int N = 7;

bool perfectSquare(int low, int high) {
	if(low > high) {
		return false;
	}
	int mid = (low + high)/2;
	if(mid * mid == N) {
		return true;
	}
	if(mid*mid < N) {
		return perfectSquare(mid+1, high);
	} else {
		return perfectSquare(low, mid-1);
	}
}


int main() {
	if(perfectSquare(1, N) ){
		cout << "YES" << endl;
	}else {
		cout << "NO " << endl;
	}
	return 0;
}