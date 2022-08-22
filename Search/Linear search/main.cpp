#include <iostream>

template <typename T>
int linear_search(T array[], int n, T target) {
	for (int i = 0; i < n; i++) {
		if (array[i] == target) { return i; }
	}

	return -1;
}

template <typename T>
void print(T* array, int n) {
	for (int i = 0; i < n; i++) { std::cout << array[i] << " "; }
	std::cout << "\n";
}

int main() {
	int array[]{ 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(array) / sizeof(array[0]);
	int target = 9;

	int value = linear_search(array, n, target);
	if (value != -1) {
		std::cout << "Value found at position " << value << ".\n";
	}
	else {
		std::cout << "Value not found.\n";
	}

	return 0;
}