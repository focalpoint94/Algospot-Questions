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
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int K, N;

struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = (seed * 214013u) + 2531011u;
		return ret % 10000 + 1;
	}
};

int count_cases() {
	int count = 0;
	RNG rng;
	queue<int> numbers;
	int temppp = rng.next();
	numbers.push(temppp);
	int sum = temppp;
	if (sum == K) {
		++count;
		sum = 0;
		numbers.pop();
	}
	if (sum > K) {
		sum = 0;
		numbers.pop();
	}
	for (int i = 1; i < N; ++i) {
		// 다음 난수 생성
		int temp = rng.next();
		sum += temp;
		numbers.push(temp);
		if (sum < K)
			continue;
		if (sum == K) {
			++count;
			sum -= numbers.front();
			numbers.pop();
			continue;
		}
		if (sum > K) {
			do {
				sum -= numbers.front();
				numbers.pop();
			} while (sum > K && !numbers.empty());
			if (sum == K) {
				++count;
				continue;
			}
		}
	}
	return count;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		cin >> K >> N;
		ans.push_back(count_cases());
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
