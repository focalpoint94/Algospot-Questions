#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

#define arr_size 10

void print_arr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout.width(2);
		cout << arr[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;
}

int __binary_search(int arr[], int size, int key) {
	int low = 0, high = size - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key > arr[mid])
			low = mid + 1;
		else if (key < arr[mid])
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int arr[arr_size];
	for (int i = 0; i < arr_size; i++) {
		arr[i] = rand() % arr_size;
	}
	sort(arr, arr + arr_size);
	print_arr(arr, sizeof(arr)/sizeof(int));

	cout << __binary_search(arr, arr_size, 5) << endl;

	return 0;
}