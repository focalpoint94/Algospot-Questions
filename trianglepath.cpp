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

#define max_size 100

int triangle[max_size][max_size] = { 0, };
int N;
int cache[max_size][max_size] = { -1, };

void set() {
	for (int i = 0; i < max_size; ++i) {
		for (int j = 0; j < max_size; ++j) {
			triangle[i][j] = 0;
			cache[i][j] = -1;
		}
	}
}

int max_path() {
	cache[0][0] = triangle[0][0];
	for (int i = 1; i < N; ++i) {
		cache[i][0] = cache[i - 1][0] + triangle[i][0];
		for (int j = 1; j < i + 1; ++j) {
			cache[i][j] = max(cache[i - 1][j - 1], cache[i - 1][j]) + triangle[i][j];
		}
	}
	int max = -1;
	for (int i = 0; i < N; ++i) {
		if (cache[N - 1][i] > max)
			max = cache[N - 1][i];
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
			for (int j = 0; j < i + 1; ++j)
				cin >> triangle[i][j];
		answers.push_back(max_path());
		count++;
	}
	for (int i = 0; i < answers.size(); ++i)
		cout << answers[i] << endl;
	return 0;
}
