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
string wildcard;
string word;
int cache[101][101];

bool func(int idx1, int idx2) {
	if (idx1 == wildcard.size() && idx2 == word.size()) return true;
	if (idx1 >= wildcard.size()) return false;
	if (idx2 >= word.size()) {
		if (wildcard[idx1] != '*') return false;
	}
	int& ret = cache[idx1][idx2];
	if (ret != -1) return ret;
	if (wildcard[idx1] == '?') {
		return func(idx1 + 1, idx2 + 1);
	}
	if (wildcard[idx1] == '*') {
		for (int i = idx2; i <= word.size(); ++i) {
			if (func(idx1 + 1, i)) return true;
		}
	}
	if (wildcard[idx1] == word[idx2]) {
		return func(idx1 + 1, idx2 + 1);
	}
	return ret = 0;
}

int main()
{
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		vector<string> ans;
		cin >> wildcard;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> word;
			memset(cache, -1, sizeof(cache));
			if (func(0, 0)) ans.push_back(word);
		}
		sort(ans.begin(), ans.end());
		for (auto i : ans)
			cout << i << endl;
		++count;
	}
	return 0;
}
