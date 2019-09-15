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
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int N, K;

void josephus() {
	list<int> alive;
	for (int i = 0; i < N; ++i)
		alive.push_back(i + 1);
	list<int>::iterator killer = alive.begin();
	int count = N;
	while (count > 2) {
		killer = alive.erase(killer);
		if (killer == alive.end())
			killer = alive.begin();
		for (int i = 1; i <= K - 1; ++i) {
			++killer;
			if (killer == alive.end())
				killer = alive.begin();
		}
		--count;
	}
	cout << alive.front() << " " << alive.back() << endl;
}


int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		cin >> N >> K;
		josephus();
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
