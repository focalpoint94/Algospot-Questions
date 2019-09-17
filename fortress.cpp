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
int x[100], y[100], r[100];

struct TreeNode {
	int label;
	vector<TreeNode*> children;
};

int dist_square(int a, int b) {
	return pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2);
}

bool encompass(int a, int b) {
	return r[a] > r[b] && (dist_square(a, b) < pow(r[a] - r[b], 2));
}

bool is_direct_Child(int parent, int child) {
	if (!encompass(parent, child))
		return false;
	for (int i = 0; i < N; ++i)
		if (i != parent && i != child && encompass(parent, i) && encompass(i, child))
			return false;
	return true;
}

TreeNode* get_Tree(int root) {
	TreeNode* ret = new TreeNode();
	ret->label = root;
	for (int i = 0; i < N; ++i)
		if (is_direct_Child(root, i))
			ret->children.push_back(get_Tree(i));
	return ret;
}

void print_Labels(TreeNode* root) {
	cout << root->label << " ";
	for (int i = 0; i < root->children.size(); ++i) {
		print_Labels(root->children[i]);
	}
}

int longest;
int height(TreeNode* root) {
	vector<int> heights;
	for (int i = 0; i < root->children.size(); ++i)
		heights.push_back(height(root->children[i]));
	if (heights.empty()) return 0;
	sort(heights.begin(), heights.end());
	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	return heights.back() + 1;
}

int solve(TreeNode* root) {
	longest = 0;
	int cand = height(root);
	longest = max(longest, cand);
	return longest;
}

void return_Tree(TreeNode* root) {
	for (int i = 0; i < root->children.size(); ++i)
		return_Tree(root->children[i]);
	delete root;
}

int main()
{
	vector<int> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> x[i] >> y[i] >> r[i];
		TreeNode * root = get_Tree(0);
		ans.push_back(solve(root));
		return_Tree(root);
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;

	return 0;
}