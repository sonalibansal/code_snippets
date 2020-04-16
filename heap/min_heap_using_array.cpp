#include <iostream>
#include <climits>
using namespace std;

class MinHeap {
	
	int *arr;
	int max_capacity;
	int current_heap_size;

	public:

		MinHeap (int max_capacity);
		
		int parent (int i) {
			return ((i-1) / 2);
		 }

		int left (int i) {
			return ((i*2) + 1);
		 }

		int right (int i) {
			return ((i*2) + 2);
		 }

		int getMinElement () {
			return arr[0];
		 }

		void minHeapifyDown (int i) ;

		void updateKeyValue (int position, int newData);

		int extractAndRemoveMinElement ();

		void deleteKey (int position);

		void insert (int key);

		void minHeapifyUp (int position, int data);


 };


 MinHeap :: MinHeap (int max_capacity) {
 	current_heap_size = 0;
 	max_capacity = max_capacity;
 	arr = new int[max_capacity];
 }

//Time complexity : O(1)
void swap (int *a, int *b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void MinHeap :: minHeapifyUp (int position, int data) {

	while (position != 0 && arr[parent(position)] > data) {
 		swap(& arr[parent(position)], & arr[position]);
 		position = parent(position);
 	 }
}

void MinHeap :: updateKeyValue (int position, int newData) {
 	arr[position] = newData;
 	minHeapifyUp(position, newData);	
 }

 void MinHeap :: insert (int key) {

 	if (current_heap_size == max_capacity) {
 		cout << "Overflow of heap capacity" << "\n";
 		return;
 	 }
 	
 	int i = current_heap_size;
 	arr[i] = key;
 	current_heap_size ++;
 	minHeapifyUp (i, arr[i]);

 	return;
 }


 int MinHeap :: extractAndRemoveMinElement () {

 	if (current_heap_size == 0) {
 		cout << "No elements in heap to remove" ;
 		return INT_MAX;
 	 }
 	if (current_heap_size == 1) {
 		current_heap_size --;
 		return arr[0];
 	 }

 	int rootElement = arr[0];
 	arr[0] = arr[current_heap_size-1];
 	current_heap_size --;
 	minHeapifyDown(0);

 	return rootElement;
 }

 void MinHeap :: minHeapifyDown (int i) {
 	int leftChild = left(i);
 	int rightChild = right(i);
 	int smallest = i;

 	if (leftChild < current_heap_size && arr[leftChild] < arr[smallest]) {
 		smallest = leftChild;
 	 }
 	if (rightChild < current_heap_size && arr[rightChild] < arr[smallest]) {
 		smallest = rightChild;
 	 }

 	if (smallest != i) {
 		swap (& arr[smallest] , & arr[i]);
 		minHeapifyDown (smallest);
 	}
 }

 void MinHeap :: deleteKey (int position) {

 	updateKeyValue (position, INT_MIN);
 	extractAndRemoveMinElement ();
 }

 int main()
 {
 	MinHeap heap(10);
 	heap.insert(3);
 	heap.insert(2);
 	heap.deleteKey(1);
 	heap.insert(15);
 	heap.insert(5);
 	heap.insert(4);
 	heap.insert(45);

 	cout << "Minimum element extracted" << heap.extractAndRemoveMinElement() << "\n";
 	cout << "Min element is" << heap.getMinElement() << "\n";

 	heap.updateKeyValue(2,1);

 	cout << "Min element is" << heap.getMinElement() << "\n";
 	return 0;
 }

