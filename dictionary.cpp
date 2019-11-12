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
#include <cstring>
#include <algorithm>
#include <utility>
#include <cmath>
#include <limits>

using namespace std;

int num_words;
vector<string> words;

vector<vector<int>> adj;

void make_graph(const vector<string>& words) {
	// Initialize adj with 26 * 26 zeros
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int i = 1; i < words.size(); ++i) {
		int j = i - 1;
		int consider_len = min(words[i].length(), words[j].length());
		for (int k = 0; k < consider_len; ++k) {
			if (words[i][k] != words[j][k]) {
				int from = words[j][k] - 'a';
				int to = words[i][k] - 'a';
				adj[from][to] = 1;
				break;
			}
		}
	}
}

vector<int> visited, orders;

void dfs(int here) {
	visited[here] = 1;
	for (int there = 0; there < adj.size(); ++there) {
		if (adj[here][there] && visited[there] == 0) {
			dfs(there);
		}
	}
	orders.push_back(here);
}

vector<int> solve() {
	int num_points = adj.size();
	visited = vector<int>(num_points, 0);
	orders.clear();
	for (int i = 0; i < num_points; ++i) if (visited[i] == 0) dfs(i);
	reverse(orders.begin(), orders.end());
	for (int i = 0; i < orders.size(); ++i) {
		for (int j = i + 1; j < orders.size(); ++j) {
			if (adj[orders[j]][orders[i]] == 1) {
				return vector<int>();
			}
		}
	}
	return orders;
}

int main()
{
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		words.clear();
		cin >> num_words;
		for (int i = 0; i < num_words; ++i) {
			string temp; cin >> temp; words.push_back(temp);
		}
		make_graph(words);
		vector<int> result = solve();
		if (result.empty())	cout << "INVALID HYPOTHESIS" << endl;
		else {
			for (int i = 0; i < result.size(); ++i)
				cout << char(result[i] + 'a');
			cout << endl;
		}
		count++;
	}

	return 0;
}
