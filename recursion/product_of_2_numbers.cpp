#include <iostream>
#include <vector> 
using namespace std;

int x= 2, y=32;

void printProduct (int product) {
	if (y == 0) {
		cout << product << endl;
		return;
	}
	
	y--;
	printProduct(product+x);
}

void getProduct () {
	if(x==0 || y==0) {
		cout << 0 << endl;
		return;
	}
	if(y> x) {
		x = x+y;
		y = x-y;
		x = x-y;
	}
	
	printProduct(0);
}

int main() {
	
	getProduct();
}