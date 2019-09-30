include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int N;
int triangle[100][100];
int cache[100][100] = { -1, };

void set() {
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			cache[i][j] = -1;
}

int path(int y, int x) {
	if (y == N - 1) {
		return cache[y][x] = triangle[y][x];
	}
	int& res = cache[y][x];
	if (res != -1) return res;
	return res = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int count_path(int y, int x) {
	if (y == N - 1)
		return 1;
	if (cache[y + 1][x] > cache[y + 1][x + 1])
		return count_path(y + 1, x);
	if (cache[y + 1][x] < cache[y + 1][x + 1])
		return count_path(y + 1, x + 1);
	if (cache[y + 1][x] == cache[y + 1][x + 1])
		return count_path(y + 1, x) + count_path(y + 1, x + 1);
}

void print_cache() {
	cout << "Memory: " << endl;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			cout << cache[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		set();
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < i + 1; ++j)
				cin >> triangle[i][j];
		path(0, 0);
		//print_cache();
		ans.push_back(count_path(0, 0));
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
