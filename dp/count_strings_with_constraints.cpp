//https://www.geeksforgeeks.org/count-strings-can-formed-using-b-c-given-constraints/
#include <iostream>
using namespace std;

char arr[] ={'a','b','c'};
int size = 3, n = 4 ;

// O()
int countStrings(int index, int length, int countb, int countc) {
	if(index >= size || length > n || countb >1 || countc >2) {
		return 0;
	}
	if(length ==n) {
		return 1;
	}
	int count = 0;
	for(int i = 0 ; i < size ;i++) {
		if(arr[i] == 'b') {
			count = count + countStrings(i, length+1, countb+1, countc);
			continue;
		}
		if(arr[i] == 'c') {
			count = count + countStrings(i, length+1, countb, countc+1);
			continue;
		}
		count = count + countStrings(i, length+1, countb, countc);
		
	}
	return count;
}
int main() {
	cout << countStrings(0, 0, 0, 0);
	return 0;
}