#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

#define MODE 1000000007
int N;
int cache[101] = { -1, };

int calc(int N) {
	int& res = cache[N];
	if (res != -1) return res;
	return res = (calc(N - 1) + calc(N - 2)) % MODE;
}

void set() {
	for (int i = 0; i < 101; ++i)
		cache[i] = -1;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		set();
		cin >> N;
		cache[0] = 0;
		cache[1] = 1;
		cache[2] = 2;
		ans.push_back(calc(N));
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
