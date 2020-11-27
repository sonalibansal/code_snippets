//https://practice.geeksforgeeks.org/problems/remove-b-and-ac-from-a-given-string/0
#include <iostream>
using namespace std;
//string str = "acbac";
//string str = "aababc";
//string str = "abc";
string str = "dog";

void removeElement() {
	int i=-1, j = 0;
	while(j < str.length()) {
		if(str[j] == 'a') {
			if(j +1 < str.length() && str[j+1] == 'c') {
				j = j+2;
				continue;
			}
		}
		if(str[j] == 'b') {
			j ++;
			continue;
		}
		str[i+1] = str[j];
		i++;
		j++;
	}
	
	for(j= 0 ; j <= i ;j++) {
		cout << str[j];
	}
}
int main() {
	removeElement();
	return 0;
}