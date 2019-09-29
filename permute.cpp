#include <iostream>
#include <algorithm>

using namespace std;

#define size 6

int main()
{
	int arr[10];
	for (int i = 0; i < size; ++i)
		arr[i] = i + 1;
	do {
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
		cout << endl;
	} while (next_permutation(arr, arr + size));

	return 0;
}


