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
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int N;
vector<int> fence;

int solve_via_stack() {
	stack<int> remaining;
	fence.push_back(0);
	int res = 0;
	for (int i = 0; i < fence.size(); ++i) {
		while (!remaining.empty() && fence[i] <= fence[remaining.top()]) {
			int prev = remaining.top();
			remaining.pop();
			int width;
			if (remaining.empty())
				width = i;
			else {
				width = i - remaining.top() - 1;
			}
			res = max(res, width * fence[prev]);
		}
		remaining.push(i);
	}
	return res;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		fence.clear();
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int temp; cin >> temp; fence.push_back(temp);
		}
		ans.push_back(solve_via_stack());
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
