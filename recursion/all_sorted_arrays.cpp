//https://www.geeksforgeeks.org/generate-all-possible-sorted-arrays-from-alternate-elements-of-two-given-arrays/
#include <iostream>
using namespace std;


void printArray (int C[], int len) {
	for (int i = 0 ; i < len ; i++) {
		cout << C[i] << " ";
	}
	cout << endl;
}

void generateUtil (int A[], int B[], int C[], int i, int j, int m, int n, int len, bool flag) {

	if (flag) {

		if (len) {
			printArray (C, len+1);
		}

		for (int k = i ; k < m ; k++) {

			if (len == 0) {

				C[len] = A[k];
				generateUtil(A, B, C, i+1, j, m, n, len, !flag); 

			} else if (A[k] > C[len]) {

				C[len+1] = A[k];
				generateUtil (A, B, C, i+1, j, m, n, len+1,!flag);
			
			}
		}
	} else {
		for (int l = j ; l < n ;l++) {

			if (B[l] > C[len]) {
				C[len+1] = B[l];
				generateUtil (A, B, C, i, j+1, m, n, len+1,!flag);
			}
		}
	}
}

void generate (int A[], int B[], int m, int n) {
	int C[m+n]; 
    generateUtil(A, B, C, 0, 0, m, n, 0, true); 
}

int main () {
	int A[] = {10,15,25};
	int B[] = {1,5,20,30};

	int m = 3, n = 4;

	generate (A, B , m ,n);
}