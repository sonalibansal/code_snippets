//https://www.geeksforgeeks.org/program-for-sum-of-the-digits-of-a-given-number/
#include <iostream>
#include <vector> 
using namespace std;


int n = 2468;
void printSum (int number,int rem, int sum) {

	if (number == 0) {
		cout << sum ;
		return;
		
	}
	rem = number%10;
	number = number/10;
	
	printSum(number,rem, sum + rem);
}

int main() {

	printSum(n, 0, 0);
}