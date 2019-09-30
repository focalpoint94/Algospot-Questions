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
#include <utility>
#include <cmath>
#include <limits>

using namespace std;

// multiply({3, 2, 1}, {6, 5, 4}) = 123 * 456
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];
	return c;
}

// a += b*power(10, k)
void addTo(vector<int>& a, const vector<int>& b, int k) {
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < b.size(); i++)
		a[i + k] += b[i];
}

// a -= b (Assumed that a > b)
void subFrom(vector<int>& a, const vector<int>& b) {
	a.resize(max(a.size(), b.size()) + 1);
	for (int i = 0; i < b.size(); i++)
		a[i] -= b[i];
}

// 빠른 정수 곱셈 알고리즘
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(); int bn = b.size();
	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an < 50) return multiply(a, b);

	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min(half, (int)b.size()));
	vector<int> b1(b.begin() + min(half, (int)b.size()), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0); addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0); subFrom(z1, z0); subFrom(z1, z2);
	
	vector<int> ret;
	addTo(ret, z0, 0); addTo(ret, z1, half); addTo(ret, z2, 2 * half);
	return ret;
}

string members;
string fans;

int hugs() {
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; ++i) A[i] = (members[i] == 'M');
	for (int i = 0; i < M; ++i) B[M - i - 1] = (fans[i] == 'M');
	vector<int> C = karatsuba(A, B);
	int total = 0;
	for (int i = N - 1; i < M; ++i)
		if (C[i] == 0)
			++total;
	return total;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		cin >> members >> fans;
		ans.push_back(hugs());
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
