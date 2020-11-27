//https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
	int value;
	int row;
	int column;

	Node(int value, int row, int column) {
		this -> value = value;
		this -> row = row;
		this -> column = column;
	}
};

priority_queue<Node> pq;
vector<int> res;
// int arr[3][3] ={{ 1,2,3},
// 				{4,5,6},
// 				{7,8,9}};
				
int arr[4][4] = {{1, 2, 3, 4},
				{2, 2, 3, 4},
				{5, 5, 6, 6},
				{7, 8, 9, 9}
				};
int k = 4;

bool operator< (Node A, Node B) {
	if (A.value != B.value) {
		return A.value > B.value;
	}
	return A.row > B.row;
}

void addElement(int value, int row, int column) {
	pq.push (Node (value, row, column));
}

void mergeKSorted() {
	
	for(int i = 0 ; i < k; i++) {
		addElement(arr[i][0], i, 0);
	}
	
	while(!pq.empty()) {
		Node element = pq.top();
		pq.pop();
		
		int value = element.value;
		int rowNumber = element.row;
		int colNumber = element.column;
		res.push_back(value);
		
		if(colNumber < k-1) {
			addElement(arr[rowNumber][colNumber+1], rowNumber, colNumber+1);
		}
	}
	for(int i = 0 ; i < res.size() ;i++) {
		cout << res[i] << " ";
	}
}
int main() {
	mergeKSorted();
	return 0;
}