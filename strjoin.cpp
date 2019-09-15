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
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <limits>

using namespace std;

int N;
int length[100];

int concat(const vector<int>& lengths) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < lengths.size(); ++i)
		pq.push(lengths[i]);
	int res = 0;
	while (pq.size() > 1) {
		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();
		pq.push(min1 + min2);
		res += min1 + min2;
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
		cin >> N;
		vector<int> lengths;
		for (int i = 0; i < N; ++i) {
			int temp; cin >> temp;
			lengths.push_back(temp);
		}
		ans.push_back(concat(lengths));
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
