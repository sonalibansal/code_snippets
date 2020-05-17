#include <climits>
#include <iostream>

using namespace std;


class MaxHeap {
	
	int *arr;
	int max_capacity;
	int current_heap_size;

	public:

		MaxHeap (int max_capacity);
		
		//O(1)
		int parent (int i) {
			return ((i-1) / 2);
		 }

		//O(1)
		int left (int i) {
			return ((i*2) + 1);
		 }

		//O(1)
		int right (int i) {
			return ((i*2) + 2);
		 }

		//O(1)
		int getMaxElement () {
			return arr[0];
		 }

		void maxHeapifyDown (int i) ;

		void deleteKey (int position);

		void insert (int key);

		void maxHeapifyUp (int position, int data);

		void printValues () {
			
			cout << "Heap elements till now in the array " << "\n";
			for (int i = 0; i < current_heap_size; i++) {
 				/* code */
 				cout << arr[i] << " ";
 			 }
 			 cout << "\n";

		}


 };

 MaxHeap :: MaxHeap (int max_capacity) {
 	current_heap_size = 0;
 	max_capacity = max_capacity;
 	arr = new int[max_capacity];
 }

// O(1)
 void swap (int *a, int *b) {
 	*a = *a + *b;
 	*b = *a - *b;
 	*a = *a - *b;
 }

// O(logn)
 void MaxHeap :: maxHeapifyUp (int position, int data) {

 	while (position != 0 && arr[parent(position)] < data) {
 		swap (&arr[position], &arr[parent(position)]);
 		position = parent (position);
 	}

 }


// O(logn) as time complexity of maxHeapifyUp function is O(n)
 void MaxHeap :: insert (int key) {

 	if (current_heap_size == max_capacity) {
 		cout << "Heap overflow " << "\n";
 		return;
 	}
 	arr[current_heap_size] = key;
 	current_heap_size ++;
 	maxHeapifyUp (current_heap_size-1, key);
 }

// O(logn) as height of tree is logn 

 void MaxHeap :: maxHeapifyDown (int position) {
 	int lChildPosition = left (position);
 	int rChildPosition = right (position);

 	int greatest = position;
 	if (lChildPosition <=current_heap_size && arr[lChildPosition] < arr[position]) {
 		greatest = lChildPosition;
 	}
 	if (rChildPosition <=current_heap_size && arr[rChildPosition] > arr[lChildPosition]) {
 		greatest = rChildPosition;
 	}

 	if (greatest != position) {
 		swap (&arr[greatest], &arr[position]);
 		maxHeapifyDown (greatest);
 	 } else {
 		for (int i = position; i <= current_heap_size ; i++) {
 			arr [i] = arr[i+1];
 	 	 }
 	}
 	
 }

// O(logn)
 void MaxHeap :: deleteKey (int position) {
 	if (current_heap_size == 0) {
 		cout << "No elements in the heap to remove" << "\n";
 		return;
 	}

 	arr [position] = INT_MIN;
 	current_heap_size --;
 	maxHeapifyDown (position);
 }

 int main()
 {
 	MaxHeap heap(20);
 	heap.insert(35);
 	heap.insert(33);
 	cout << "Max element is " << heap.getMaxElement () << "\n";

 	heap.deleteKey(1);
 	heap.printValues(); //35
 	heap.insert(42);

 	heap.insert(10);
 	heap.insert(14);
 	heap.insert(19);
 	heap.insert(27);

 	heap.insert(44);
 	heap.insert(26);
 	heap.insert(31);
 	heap.deleteKey (4);
 	heap.printValues();

 	cout << "Max element is " << heap.getMaxElement () << "\n";
 
 	return 0;
 }
