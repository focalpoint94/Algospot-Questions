#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <cmath>
#include <limits>

using namespace std;

#define INF 987654321
int N, S;
int arr[101], psum[101], psqsum[101];
int cache[101][11];

void precalc() {
	sort(arr, arr + N);
	psum[0] = arr[0];
	psqsum[0] = arr[0] * arr[0];
	for (int i = 1; i < N; ++i) {
		psum[i] = psum[i - 1] + arr[i];
		psqsum[i] = psqsum[i - 1] + arr[i] * arr[i];
	}
}

int minerror(int lo, int hi) {
	int sum = psum[hi] - (lo == 0 ? 0 : psum[lo - 1]);
	int sqsum = psqsum[hi] - (lo == 0 ? 0 : psqsum[lo - 1]);
	int m = int(0.5 + (double)sum / (hi - lo + 1));
	int ret = sqsum - 2 * m * sum + m * m * (hi - lo + 1);
	return ret;
}

int quantize(int from, int parts) {
	if (from == N) return 0;
	if (parts == 0) return INF;
	int& ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF;
	for (int part_size = 1; part_size <= N - from; ++part_size) {
		ret = min(ret, minerror(from, from + part_size - 1) + quantize(from + part_size, parts - 1));
	}
	return ret;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		cin >> N >> S;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		precalc();
		memset(cache, -1, sizeof(cache));
		ans.push_back(quantize(0, S));
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
