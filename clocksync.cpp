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
#include <cmath>
#include <limits>

#define INF 987654321

using namespace std;

const string clock_link[10] = {
	"oooxxxxxxxxxxxxx",
	"xxxoxxxoxoxoxxxx",
	"xxxxoxxxxxoxxxoo",
	"oxxxooooxxxxxxxx",
	"xxxxxxoooxoxoxxx",
	"oxoxxxxxxxxxxxoo",
	"xxxoxxxxxxxxxxoo",
	"xxxxooxoxxxxxxoo",
	"xoooooxxxxxxxxxx",
	"xxxoooxxxoxxxoxx"
};

void click_switch(vector<int>& clocks, int swt) {
	for (int i = 0; i < 16; ++i) {
		if (clock_link[swt][i] == 'o') {
			clocks[i] += 3;
			if (clocks[i] == 15)
				clocks[i] = 3;
		}
	}
}

int calc_(vector<int>& clocks, int idx) {
	bool finish = true;
	for (int i = 0; i < 16; ++i) {
		if (clocks[i] != 12) {
			finish = false;
			break;
		}
	}
	if (finish) return 0;
	if (idx == 10) return INF;
	
	int ret = INF;
	for (int i = 0; i < 4; ++i) {
		ret = min(ret, calc_(clocks, idx + 1) + i);
		click_switch(clocks, idx);
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
		vector<int> clocks;
		for (int i = 0; i < 16; ++i) {
			int temp; cin >> temp;
			clocks.push_back(temp);
		}
		int cand = calc_(clocks, 0);
		if (cand != INF) ans.push_back(cand);
		else ans.push_back(-1);

		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
