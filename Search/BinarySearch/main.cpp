#include <iostream>

template <typename T>
int binary_search(T array[], int l, int r, T target) {
	if (l <= r) {
		int mid = (l + r) / 2;
		if (array[mid] == target) { return mid; }
		if (array[mid] > target) { return binary_search(array, l, mid - 1, target); }
		if (array[mid] < target) { return binary_search(array, mid + 1, r, target); }
	}

	return -1;
}

template <typename T>
void print(T* array, int n) {
	for (int i = 0; i < n; i++) { std::cout << array[i] << " "; }
	std::cout << "\n";
}

int main() {
	int array[]{ 8,9 };
	int n = sizeof(array) / sizeof(array[0]);
	int x = 9;

	int value = binary_search(array, 0, n - 1, x);
	if (value != -1) {
		std::cout << "Value found at position " << value << ".\n";
	}
	else {
		std::cout << "Value not found.\n";
	}

	return 0;
}
