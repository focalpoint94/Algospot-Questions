#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

#define size 6

void print_arr(int arr[]) {
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void print(int arr[], int n) {
	if (n >= size) {
		print_arr(arr);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		arr[n] = i;
		print(arr, n + 1);
	}
}

int main()
{
	// next_permutation 사용하기
	vector<int> vec(4);
	for (int i = 0; i < 4; ++i)
		vec[i] = i + 1;
	do {
		for (auto i = vec.begin(); i != vec.end(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
	} while (next_permutation(vec.begin(), vec.end()));
	// 순열 찍어내기
	/*
	int arr[size] = { 0, };
	print(arr, 0);
	*/
	return 0;
}