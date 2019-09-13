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

int answer;
int taken[10];

void print_friend_matrix(int **arr, int n) {
	cout << "Friend Matrix" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

void set_zero() {
	answer = 0;
	for (int i = 0; i < 10; ++i)
		taken[i] = 0;
}

void count_pairs(int **arr, int n) {
	int min_idx = -1;
	for (int i = 0; i < n; ++i) {
		if (taken[i] == 0) {
			min_idx = i;
			break;
		}
	}
	if (min_idx == -1) {
		answer++;
		return;
	}
	for (int i = min_idx + 1; i < n; ++i) {
		if (arr[min_idx][i] == 1 && taken[i] == 0) {
			taken[min_idx] = taken[i] = 1;
			count_pairs(arr, n);
			taken[min_idx] = taken[i] = 0;
		}
	}
}

int main()
{
	vector<int> answers;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		// n: 학생의 수
		int n;
		cin >> n;
		// pairs: 친구 쌍의 수
		int pairs;
		cin >> pairs;
		// 친구 관계 기록 배열
		int **arr = new int*[n];
		for (int i = 0; i < n; ++i)
			arr[i] = new int[n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				arr[i][j] = 0;
		int check = 0;
		while (check < pairs) {
			int temp1, temp2;
			cin >> temp1 >> temp2;
			arr[temp1][temp2] = 1;
			arr[temp2][temp1] = 1;
			check++;
		}
		set_zero();
		count_pairs(arr, n);
		answers.push_back(answer);
		for (int i = 0; i < n; ++i)
			delete[] arr[i];
		delete[] arr;
		count++;
	}
	for (auto i = answers.begin(); i != answers.end(); ++i)
		cout << *i << endl;
	return 0;
}
