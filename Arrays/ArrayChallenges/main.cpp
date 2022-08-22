#include <algorithm>
#include <iostream>
#include <map>

void print(int A[], int n) {
	for (int i = 0; i < n; i++) { std::cout << A[i] << " "; }
	std::cout << "\n";
}

int main() {
	int arr1[] = { 5, 6, 7, 100, 57 };
	int arr2[] = { 1, 2, 3, 5, 7, 99 };
	const int n1 = sizeof(arr1) / sizeof(arr1[0]);
	const int n2 = sizeof(arr2) / sizeof(arr2[0]);

	// Find second minimum element in array by sorting
	std::sort(&arr1[0], &arr1[n1]);
	std::cout << "Second smallest element in array 1: " << arr1[1] << "\n";

	// Merge to arrays and sort
	const int n3 = n1 + n2;
	int arr3[n3] = { 0 };
	for (int i = 0; i < n1; i++) { arr3[i] = arr1[i]; }
	for (int i = 0; i < n2; i++) { arr3[i + n1] = arr2[i]; }
	std::cout << "Print unsorted, merged list: \n";
	print(arr3, n3);

	std::sort(&arr3[0], &arr3[n3]);
	std::cout << "Print sorted, merged list: \n";
	print(arr3, n3);

	// Find first non-repeating number in an integer array
	std::map<int, std::pair<int, int>> counts;	// Map of value and pair(index, count)
	for (int i = 0; i < n3; i++) {
		counts[arr3[i]].first = i;
		counts[arr3[i]].second++;
	}

	int tempIndex = n3;
	for (auto& it : counts) {
		if (it.second.first < tempIndex && it.second.second == 1) { tempIndex = it.second.first; }
	}
	try { 
		if (tempIndex < 0 || tempIndex >= n3) { 
			throw std::out_of_range("Out of range!"); 
		}
		else {
			std::cout << "The first non-repeating number is: " << arr3[tempIndex] << "\n";
		}
	}
	catch (std::out_of_range& e) { 
		std::cout << e.what(); 
	}

	return 0;
}