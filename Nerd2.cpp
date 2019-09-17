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
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int N;
int p, q;
map<int, int> coords;

bool is_Dominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.end()) return false;
	return (it->second > y);
}

void remove_Dominated(int x, int y) {
	if (coords.size() == 0) return;
	map<int, int>::iterator it = coords.lower_bound(x);
	// *it이 가장 작은 점이라면, 
	if (it == coords.begin()) return;
	--it;
	while (true) {
		if (it->second > y)
			break;
		// 점이 하나 남아있으며, 그 점 또한 지배당한 경우
		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else {
			auto jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		}
	}
}

int registering(int x, int y) {
	if (is_Dominated(x, y)) return coords.size();
	remove_Dominated(x, y);
	coords[x] = y;
	return coords.size();
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		coords.clear();
		cin >> N;
		int total = 0;
		for (int i = 0; i < N; ++i) {
			cin >> p >> q;
			total += registering(p, q);
		}
		ans.push_back(total);
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}