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

int N; int M;
int isFriend[10][10];
int isOccupied[10];

void set_arr() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			isFriend[i][j] = 0;
		}
		isOccupied[i] = 0;
	}
}

int solve() {
	int ans = 0;
	int min_num = -1;
	for (int i = 0; i < N; ++i) {
		if (isOccupied[i] == 0) {
			min_num = i;
			break;
		}
	}
	if (min_num == -1) {
		return 1;
	}
	for (int i = min_num + 1; i < N; ++i) {
		if (isFriend[min_num][i] == 1 && isOccupied[i] == 0) {
			isOccupied[min_num] = isOccupied[i] = 1;
			ans += solve();
			isOccupied[min_num] = isOccupied[i] = 0;
		}
	}
	return ans;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		set_arr();
		cin >> N >> M;
		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			isFriend[a][b] = isFriend[b][a] = 1;
		}
		ans.push_back(solve());
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
