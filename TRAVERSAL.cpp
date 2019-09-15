// https://algospot.com/judge/problem/read/TRAVERSAL

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
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int N;

vector<int> postorder;

vector<int> slicing(const vector<int>& vec, int L, int R) {
	return vector<int>(vec.begin() + L, vec.begin() + R);
}

void calc_postorder(const vector<int>& preorder, const vector<int>& inorder) {
	if (preorder.empty()) {
		return;
	}
	int me = preorder.front();
	int num_left = find(inorder.begin(), inorder.end(), me) - inorder.begin();
	vector<int> left_preorder = slicing(preorder, 1, num_left + 1);
	vector<int> right_preorder = slicing(preorder, num_left + 1, preorder.size() );
	vector<int> left_inorder = slicing(inorder, 0, num_left);
	vector<int> right_inorder = slicing(inorder, num_left + 1, inorder.size());
	calc_postorder(left_preorder, left_inorder);
	calc_postorder(right_preorder, right_inorder);
	postorder.push_back(me);
}

int main()
{
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		postorder.clear();
		cin >> N;
		vector<int> preorder;
		vector<int> inorder;
		for (int i = 0; i < N; ++i) {
			int temp; cin >> temp; preorder.push_back(temp);
		}
		for (int i = 0; i < N; ++i) {
			int temp; cin >> temp; inorder.push_back(temp);
		}
		calc_postorder(preorder, inorder);
		for (auto i = postorder.begin(); i != postorder.end(); ++i)
			cout << *i << " ";
		cout << endl;
		count++;
	}
	return 0;
}
