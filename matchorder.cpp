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

int russia[100];
int korea[100];
int N;

int winning() {
	// 내림차순으로 정렬,
	sort(russia, russia + N, greater<int>());
	sort(korea, korea + N, greater<int>());
	int win = 0;
	int rus_idx = 0;
	for (int kor_idx = 0; kor_idx < N; ++kor_idx) {
		while (korea[kor_idx] < russia[rus_idx] && rus_idx < N) {
			++rus_idx;
		}
		if (rus_idx < N) {
			++win;
			++rus_idx;
		}
		else return win;
	}
	return win;
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
			cin >> russia[i];
		for (int i = 0; i < N; ++i)
			cin >> korea[i];
		ans.push_back(winning());
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
