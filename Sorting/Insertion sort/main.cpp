#include <iostream>

template <typename T>
void insertion_sort(T* array, int n) {
	int i;
	int j;
	T key = 0;
	for (i = 1; i < n; i++) {
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] < key) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}

template <typename T>
void selection_sort(T* array, int n) {
	int i, j, imin;
	T key = 0;
	for (i = 0; i < n-1; i++) {
		imin = i;

		for (j = i+1; j < n; j++) {
			if (array[j] < array[imin]) { imin = j; }
		}

		// Swap
		key = array[imin];
		array[imin] = array[i];
		array[i] = key;
	}
}

template <typename T>
void print(T* array, int n) {
	for (int i = 0; i < n; i++) { std::cout << array[i] << " "; }
	std::cout << "\n";
}

int main() {
	double array[10]{ 9,10,8,7,6,5,4,3,2,1 };

	//insertion_sort(&array[0], 10);
	selection_sort(&array[0], 10);
	print(&array[0], 10);

	return 0;
}