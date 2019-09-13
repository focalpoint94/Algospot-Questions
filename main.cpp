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
// �� �Լ��� 0~n���� ���Ҹ� �����Ͽ� a1<a2<a3<a4�� �����ϴ� ��츦 ��� ���
// n: 0~n���� ���� �� ����
// vec: �������� ����
// to_pick: ������ �����ؾ� �� ������ ����
*/
void picking(int n, vector<int>& vec, int to_pick) {
	// ���� ���� ���� ���
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