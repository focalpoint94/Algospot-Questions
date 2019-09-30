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
#include <algorithm>
#include <utility>
#include <cmath>
#include <limits>

using namespace std;

int N;
vector<int> fence;

int calc_(int start, int end) {
	if (start == end)
		return fence[start];
	int half = (start + end) / 2;
	int cand1 = calc_(start, half);
	int cand2 = calc_(half + 1, end);
	cand1 = max(cand1, cand2);
	
	int len = 2;
	int min_height = min(fence[half], fence[half + 1]);
	int cand3 = len * min_height;

	int left = half - 1;
	int right = half + 2;
	int temp;
	while (left >= 0 && right <= end) {
		if (fence[left] > fence[right]) {
			++len;
			min_height = min(fence[left], min_height);
			temp = len * min_height;
			cand3 = max(cand3, temp);
			--left;
		}
		else {
			++len;
			min_height = min(fence[right], min_height);
			temp = len * min_height;
			cand3 = max(cand3, temp);
			++right;
		}
	}
	if (left == -1) {
		while (right <= end) {
			++len;
			min_height = min(fence[right], min_height);
			temp = len * min_height;
			cand3 = max(cand3, temp);
			++right;
		}
	}
	else {
		while (left >= 0) {
			++len;
			min_height = min(fence[left], min_height);
			temp = len * min_height;
			cand3 = max(cand3, temp);
			--left;
		}
	}
	return max(cand1, cand3);
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		cin >> N;
		fence.clear();
		for (int i = 0; i < N; ++i) {
			int temp; cin >> temp;
			fence.push_back(temp);
		}
		ans.push_back(calc_(0, N - 1));
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
