#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <limits>

using namespace std;

#define mode 10000000

int N;
int cache[101][101];

void set_cache() {
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 101; ++j)
			cache[i][j] = -1;
}

int poly(int n, int first) {
	if (n == first)
		return 1;
	int& res = cache[n][first];
	if (res != -1) return res;
	res = 0;
	for (int second = 1; second <= n - first; ++second) {
		int temp = (second + first - 1) * poly(n - first, second);
		temp %= mode;
		res += temp;
		res %= mode;
	}
	return res;
}

int calc() {
	int total = 0;
	for (int i = 1; i <= N; ++i) {
		total += poly(N, i);
		total %= mode;
	}
	return total;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		set_cache();
		cin >> N;
		ans.push_back(calc());
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
