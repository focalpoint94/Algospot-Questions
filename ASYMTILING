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

#define mode 1000000007
int n;
int dp[101];
int cache[101] = { -1, };

void set_() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 101; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % mode;
}

int assym(int width) {
	if (width <= 2)
		return 0;
	int& ret = cache[width];
	if (ret != -1) return ret;
	ret = assym(width - 2) % mode;
	ret = (ret + assym(width - 4)) % mode;
	ret = (ret + dp[width - 3]) % mode;
	ret = (ret + dp[width - 3]) % mode;
	return ret;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	set_();
	while (count < cases) {
		cin >> n;
		for (int i = 0; i < 101; ++i)
			cache[i] = -1;
		ans.push_back(assym(n));
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
