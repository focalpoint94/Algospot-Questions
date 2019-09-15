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

int N, S;
int num[100];
int sum_1[100];
int sum_2[100];

void precalc() {
	sum_1[0] = num[0];
	sum_2[0] = num[0] * num[0];
	for (int i = 1; i < N; ++i) {
		sum_1[i] = sum_1[i - 1] + num[i];
		sum_2[i] = sum_2[i - 1] + num[i] * num[i];
	}
}

int minerror(int a, int b) {
	int sum_1st = (a == 0) ? sum_1[b] - 0 : sum_1[b] - sum_1[a - 1];
	int sum_2nd = (a == 0) ? sum_2[b] - 0 : sum_2[b] - sum_2[a - 1];
	int avg = int(0.5 + (double)sum_1st / (b - a + 1));
	return sum_2nd - 2 * sum_1st * avg + avg * avg * (b - a + 1);
}

int cache[101][10] = { -1, };

void set() {
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 10; ++j)
			cache[i][j] = -1;
}

int Quantize(int from, int parts) {
	if (from == N)
		return 0;
	if (parts == 0)
		return 987654321;
	int& res = cache[from][parts];
	if (res != -1) return res;
	res = 987654321;
	for (int len = 1; len <= N - from; ++len) {
		res = min(res, minerror(from, from + len - 1) + Quantize(from + len, parts - 1));
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
		cin >> N >> S;
		for (int i = 0; i < N; ++i)
			cin >> num[i];
		sort(num, num + N);
		precalc();
		set();
		ans.push_back(Quantize(0, S));
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
