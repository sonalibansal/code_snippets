#include <iostream>
using namespace std;

#define n 5
// int coins [] = {11,5,7};
// int energy[] = {2,1,7};
int coins [] = {3,23,9,2,2};
int energy[] = {1,5,3,3,1};
// int coins [] = {5,5,5};
// int energy[] = {12,2,2};
int initialEnergy = 1;
int getMaxCoins(int index, int currEnergy) {
	if(index >= n || currEnergy < 0) {
		return 0;
	}
	int maxa, maxb ;
	maxa =  max(getMaxCoins(index+1, currEnergy+energy[index]), coins[index]);
	if(currEnergy == 0) {
		return maxa;
	}
	maxb = coins[index]+getMaxCoins(index+1, currEnergy-1);
	return max(maxa, maxb);
}
int main() {
	cout << getMaxCoins(0, initialEnergy) << endl;
	return 0;
}