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

const long long NEGINF = numeric_limits<long long>::min();

int N, M;
int arr1[101];
int arr2[101];
int cache[101][101];

int JLIS(int idx1, int idx2) {
	int& ret = cache[idx1 + 1][idx2 + 1];
	if (ret != -1) return ret;
	long long num1 = (idx1 == -1) ? NEGINF : arr1[idx1];
	long long num2 = (idx2 == -1) ? NEGINF : arr2[idx2];
	long long boundary = max(num1, num2);
	ret = 2;
	for (int i = idx1 + 1; i < N; ++i) {
		if (arr1[i] > boundary) {
			ret = max(ret, JLIS(i, idx2) + 1);
		}
	}
	for (int i = idx2 + 1; i < M; ++i) {
		if (arr2[i] > boundary) {
			ret = max(ret, JLIS(idx1, i) + 1);
		}
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
		cin >> N >> M;
		for (int i = 0; i < N; ++i) cin >> arr1[i];
		for (int i = 0; i < M; ++i) cin >> arr2[i];
		memset(cache, -1, sizeof(cache));
		ans.push_back(JLIS(-1, -1) - 2);
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
