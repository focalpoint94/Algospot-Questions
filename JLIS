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
#include <limits>

using namespace std;

int N, M;
int A[101], B[101], cache[101][101];
const long long NEGINF = numeric_limits<long long>::min();

void set() {
	for (int i = 0; i < 101; ++i) {
		A[i] = 0;
		B[i] = 0;
		for (int j = 0; j < 101; ++j) {
			cache[i][j] = -1;
		}
	}
}

int JLIS(int idx_A, int idx_B) {
	int& ret = cache[idx_A + 1][idx_B + 1];
	if (ret != -1) return ret;
	ret = 2;
	long long a = idx_A == -1 ? NEGINF : A[idx_A];
	long long b = idx_B == -1 ? NEGINF : B[idx_B];
	long long maxElem = max(a, b);
	for (int next_A = idx_A + 1; next_A < N; ++next_A) {
		if (A[next_A] > maxElem) {
			ret = max(ret, 1 + JLIS(next_A, idx_B));
		}
	}
	for (int next_B = idx_B + 1; next_B < M; ++next_B) {
		if (B[next_B] > maxElem) {
			ret = max(ret, 1 + JLIS(idx_A, next_B));
		}
	}
	return ret;
}

int main()
{
	vector<int> answers;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		set();
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
			cin >> A[i];
		for (int i = 0; i < M; ++i)
			cin >> B[i];
		answers.push_back(JLIS(-1, -1) - 2);
		count++;
	}
	for (auto i = answers.begin(); i != answers.end(); ++i)
		cout << *i << endl;
	return 0;
}
