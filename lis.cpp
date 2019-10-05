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

int N;
int num[500];
int cache[501];

int LIS_sub(int start) {
	if (start == N) return 0;
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = start + 1; i < N; ++i) {
		if (num[i] > num[start]) {
			ret = max(ret, LIS_sub(i) + 1);
		}
	}
	return ret;
}

int LIS() {
	int ret = 0;
	for (int i = 0; i < N; ++i)
		ret = max(ret, LIS_sub(i));
	return ret;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		cin >> N;
		for (int i = 0; i < N; ++i) cin >> num[i];
		memset(cache, -1, sizeof(cache));
		ans.push_back(LIS());
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
