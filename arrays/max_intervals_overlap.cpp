//https://www.geeksforgeeks.org/find-the-point-where-maximum-intervals-overlap/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// int entryTime [] = {1,2,10,5,5};
// int exitTime[] = {4,5,12,9,12};

int entryTime[] = {13, 28, 29, 14, 40, 17, 3 };
int exitTime[] = {107, 95, 111, 105, 70, 127, 74}; 
int n = 7;

void maxGuests() {
	vector<pair<int, int>> res;
	for(int i = 0; i < n ; i++) {
		res.push_back(make_pair(entryTime[i], 1));
		res.push_back(make_pair(exitTime[i], 0));
	}
	sort(res.begin(), res.end());
	int count = 0, maxCount = 0, time = 0;
	pair<int, int> element1, element2;
	for(int i = 0 ; i < res.size() ; i++) {
		element1 = res[i];
		if(element1.second == 1) {
			count ++;
			if(maxCount < count) {
				maxCount = count;
				time = element1.first;
			}
			continue;
		}
		if(element1.second == 0) {
			if(i < res.size()-1) {
				 element2 = res[i+1];
				 if(element1.first == element2.first) {
				 	continue;
				 }
				 count --;
			}
		}
	}
	
	cout << maxCount << " " << time << endl;
}
int main() {
	maxGuests();
	return 0;
}