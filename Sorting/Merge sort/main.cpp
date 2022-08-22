// Adapted from pseudo-code in Introduction to Algorithms (Cormen, Stein, Leiserson, Rivest)
#include <iostream>
#include <memory>
#include <limits>

// Merge to sub-arrays
void merge(int array[], int const p, int const q, int const r) {
	// Sizes of new subarrays
	const int nLeft = q - p + 1;
	const int nRight = r - q;

	// Create temp arrays with memory being released at end of scope
	std::unique_ptr<int[]> leftArray(new int[nLeft+1]);
	std::unique_ptr<int[]> rightArray(new int[nRight+1]);

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < nLeft; i++) { leftArray[i] = array[p + i]; }
	for (auto j = 0; j < nRight; j++) { rightArray[j] = array[q + j + 1]; }

	// Sentinel values 
	leftArray[nLeft] = std::numeric_limits<int>::max();
	rightArray[nRight] = std::numeric_limits<int>::max();

	int i = 0; // Initial index of first sub-array
	int j = 0; // Initial index of second sub-array

	for (int k = p; k < r+1; k++) {
		if (leftArray[i] <= rightArray[j]) { 
			array[k] = leftArray[i]; i++; }
		else {
			array[k] = rightArray[j]; j++;
		}
	}
}

// Recursive merge sort (Divide and conquer)
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// Print array
template <typename T>
void print(T array[], int n) {
	for (int i = 0; i < n; i++) { std::cout << array[i] << " "; }
	std::cout << "\n";
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7, 11, 14 };
	int n = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Given array is \n";
	print(arr, n);

	mergeSort(arr, 0, n - 1);

	std::cout << "\nSorted array is \n";
	print(arr, n);

	return 0;
}