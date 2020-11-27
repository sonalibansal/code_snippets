//https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define n 4
//int arr[] = {0,0,5,5,0,0}; //output = 6
//int arr[] = {6 , -1, -3, 4, -2, 2, 4, 6, -12, -7}; //output = 4
//int arr[] = {1,2,3,-1,-1,-1}; //output = 1
//int arr[] = {1,2,3,-2,1,-2,3,-3}; //output = 4
//int arr[] = {1,2,3,4,5,6}; //output = 0
//int arr[] = {0,0,0,0,0,0}; //output = 21
//int arr[] = {2,-1,-1}; //output = 1
int arr[] = {1,0,-1,0}; //output = 4
int prefix[n];
unordered_map<int, int> map;
vector<int> adj[n+1];

void calculatePrefixSum() {
	prefix[0] = arr[0];
	for(int i = 1; i < n ;i++) {
		prefix[i] = prefix[i-1] + arr[i];
	}	
}

void makeAdjArray() {
	int c = 0;
	for(int i = 0; i < n ;i++) {
		if(map.count(prefix[i]) == 0) {
			c++;
			map[prefix[i]] = c;
			adj[c].push_back(i);
		} else {
			adj[map[prefix[i]]].push_back(i);
		}
		
	}
}

int binarySearch(int low, int high, int row, int index) {
	if (low> high) {
		return -1;
	}
	if(adj[row][low] >= index) {
		return low;
	}
	int mid = (low + high)/2;
	if(adj[row][mid] == index) {
		return mid;
	}
	if(adj[row][mid] > index) {
		return binarySearch(low, mid, row, index);
	}
	return binarySearch(mid+1, high, row, index);
}

void countSubArrays() {
	int i, count = 0, j, c;
	calculatePrefixSum();
	makeAdjArray();
	for(int i = 0 ; i < n ;i++) {
		if(i == 0) {
			c = map[0];
			count = count + adj[c].size();
			continue;
		}
		c = map[prefix[i-1]];
		int index = binarySearch(0, adj[c].size()-1, c, i);
		if(index != -1) {
			count = count + adj[c].size() -index;
		}
	}
	cout << count << endl;
}

int main() {
	countSubArrays();
	return 0;
}