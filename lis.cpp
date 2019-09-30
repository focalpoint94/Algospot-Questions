#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int N;
int arr[500] = { 0, };

int len[500] = { 0, };
int prev_idx[500] = { 0, };

void set() {
	for (int i = 0; i < 500; ++i)
		arr[i] = len[i] = prev_idx[i] = 0;
}

int LIS() {
	len[0] = 1;
	prev_idx[0] = -1;
	for (int i = 1; i < N; ++i) {
		int prev_ = -1;
		int max_ = -1;
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i] && len[j] > max_) {
				max_ = len[j];
				prev_ = j;
			}
		}
		if (prev_ == -1) len[i] = 1;
		else len[i] = len[prev_] + 1;
		prev_idx[i] = prev_;
	}
	int max = -1;
	for (int i = 0; i < N; ++i) {
		if (len[i] > max)
			max = len[i];
	}
	return max;
}

int main()
{
	vector<int> answers;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		set();
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		int ans = LIS();
		answers.push_back(ans);
		count++;
	}
	for (int i = 0; i < answers.size(); ++i)
		cout << answers[i] << endl;
	return 0;
}
