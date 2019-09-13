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

int N;
int microwave[10000];
int eat[10000];

function<bool(pair<int, int>, pair<int, int>)> compFunctor_greater = [](pair<int, int> e1, pair<int, int> e2)
{
	return e1.first > e2.first;
};

int how_much_time() {
	int time =  -1;
	// pair(먹는 시간, 데우는 시간)
	vector<pair<int, int>> order;
	for (int i = 0; i < N; ++i) {
		order.push_back(make_pair(eat[i], microwave[i]));
	}
	// 먹는 시간의 내림차순으로 정렬,
	sort(order.begin(), order.end(), compFunctor_greater);
	int waving_dur = 0;
	for (int i = 0; i < N; ++i) {
		waving_dur += order[i].second;
		int cand = waving_dur + order[i].first;
		time = max(time, cand);
	}
	return time;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> microwave[i];
		for (int i = 0; i < N; ++i)
			cin >> eat[i];
		ans.push_back(how_much_time());
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
