//https://www.geeksforgeeks.org/counts-paths-point-reach-origin/
#include <iostream>
using namespace std;
int n = 3, m = 6;

int countPaths(int i, int j) {
	if(i==0 && j==0) {
		return 0;
	}
	if(i==0 || j==0) {
		return 1;
	}
	return countPaths(i-1,j) + countPaths(i, j-1);
}
int main() {
	cout << countPaths(n, m)<< endl;
	return 0;
}