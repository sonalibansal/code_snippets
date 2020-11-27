//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0
#include <iostream>
#include <queue>
using namespace std;
//int arr[] = {4,3,2,6};
int arr[] = {4, 2, 7, 6, 9};
int n = 5;

void minCost() {
	priority_queue<int> pq;
	
	if(n == 1) {
		cout << arr[0] << endl;
		return;
	}
	for(int i = 0 ; i < n ;i++) {
		pq.push(-arr[i]);
	}
	
	int top1, top2, sum, minCost = 0;
	while(!pq.empty()) {
		
		top1 = pq.top();
		pq.pop();
		if(!pq.empty()) {
			top2 = pq.top();
			pq.pop();
			sum = top1 + top2;
			minCost = minCost-sum;
			pq.push(sum);
		}
	}
	cout << minCost << endl;
}
int main() {
	minCost();
	return 0;
}