#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

void print_vec(const vector<int>& vec) {
	for (auto i = vec.begin(); i != vec.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

/*
// 이 함수는 0~n개의 원소를 선택하여 a1<a2<a3<a4를 만족하는 경우를 모두 출력
// n: 0~n개의 원소 중 선택
// vec: 순서쌍의 저장
// to_pick: 앞으로 선택해야 할 숫자의 갯수
*/
void picking(int n, vector<int>& vec, int to_pick) {
	// 뽑을 것이 없는 경우
	if (to_pick == 0) {
		print_vec(vec);
		return;
	}
	int min = to_pick == 4 ? 0 : vec.back() + 1;
	for (int i = min; i <= n; ++i) {
		vec.push_back(i);
		picking(n, vec, to_pick - 1);
		vec.pop_back();
	}
}

int main()
{
	vector<int> vec;
	picking(9, vec, 4);

	return 0;
}