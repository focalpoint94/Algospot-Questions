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

#define INT_MAX 987654321

string num;
int temp;

int cache[10000];

void set() {
	for (int i = 0; i < 10000; ++i)
		cache[i] = -1;
}

// Ex> 3 3 3 3 
// type(0, 3) = true
bool type1(int start, int end) {
	for (int i = start; i < end; ++i)
		if (num[start] != num[start + 1])
			return false;
	return true;
}

// Ex> 3 4 5 6 7
// type2(0, 4) = true
// Ex> 4 3 2 1 
bool type2(int start, int end) {
	int flag = 1;
	for (int i = start; i < end; ++i) {
		if (num[i] + 1 != num[i + 1]) {
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		return true;
	for (int i = start; i < end; ++i) {
		if (num[i] - 1 != num[i + 1]) {
			return false;
		}
	}
	return true;
}

// Ex> 3 2 3 2 3
// type3(0, 4) = true
bool type3(int start, int end) {
	int a = num[start], b = num[start + 1];
	for (int i = start + 2; i <= end; i += 2)
		if (num[i] != a)
			return false;
	for (int i = start + 3; i <= end; i += 2)
		if (num[i] != b)
			return false;
	return true;
}

// Ex> 1 4 7
// Ex> 8 6 4 2
bool type4(int start, int end) {
	int delta = num[start + 1] - num[start];
	for (int i = start + 1; i < end; ++i)
		if (num[i] + delta != num[i + 1])
			return false;
	return true;
}

int score_checking(int start, int end) {
	if (type1(start, end) == true)
		return 1;
	if (type2(start, end) == true)
		return 2;
	if (type3(start, end) == true)
		return 4;
	if (type4(start, end) == true)
		return 5;
	return 10;
}

int classify(int a, int b) {
	string M = num.substr(a, b - a + 1);
	if (M == string(M.size(), M[0])) return 1;
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; ++i)
		if (M[i + 1] - M[i] != M[1] - M[0])
			progressive = false;
	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;
	bool alternating = true;
	for (int i = 0; i < M.size(); ++i)
		if (M[i] != M[i % 2])
			alternating = false;
	if (alternating) return 4;
	if (progressive) return 5;
	return 10;
}

int memorize(int begin) {
	if(begin == num.size()) return 0;
	int& ret = cache[begin];
	if (ret != -1) return ret;
	ret = INT_MAX;
	for (int L = 3; L <= 5; ++L)
		if (begin + L <= num.size())
			ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
	return ret;
}

int score(int start) {
	if (start >= num.size())
		return 0;
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = INT_MAX;
	for (int len = 3; len <= 5; ++len) {
		if (start + len <= num.size())
			//ret = min(ret, score(start + len) + score_checking(start, start + len - 1));
			ret = min(ret, score(start + len) + classify(start, start + len - 1));
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
		set();
		cin >> num;
		//num = to_string(temp);
		ans.push_back(score(0));
		num.clear();
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
