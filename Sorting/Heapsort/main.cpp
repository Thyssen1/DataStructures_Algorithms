#include <iostream>


// Maintain heap property
void maxHeapify(int array[], int i, int n) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max = i;

	if (l < n && array[l] > array[max]) { max = l; }
	if (r < n && array[r] > array[max]) { max = r; }

	if (max != i) {
		std::swap(array[i], array[max]);
		maxHeapify(array, max, n);
	}
}

void heapsort(int array[], int n) {
	// Convert array into max heap
	for (int i = n / 2 - 1; i >= 0; i--) { maxHeapify(array, i, n); }

	//
	for (int i = n - 1; i >= 0; i--) {
		std::swap(array[0], array[i]);	
		maxHeapify(array, 0, i);		// Call on reduced heap
	}
}

// Print array
template <typename T>
void print(T array[], int n) {
	for (int i = 0; i < n; i++) { std::cout << array[i] << " "; }
	std::cout << "\n";
}

int main() {
	int A[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(A) / sizeof(A[0]);

	heapsort(A, n);
	print(A, n);

	return 0;
}