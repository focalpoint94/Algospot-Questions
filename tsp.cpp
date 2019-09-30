#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

double dist[8][8] = { 0, };
vector<double> answers;

void print_distance(int N) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

double TSP(int N, vector<int>& path, int visited[], double current_length) {
	if (path.size() == N) {
		return current_length;
		//return current_length + dist[path.back()][path[0]];
	}
	double min = numeric_limits<double>::max();
	for (int i = 0; i < N; ++i) {
		if (visited[i] == 1)
			continue;
		int now = path.back();
		path.push_back(i);
		visited[i] = 1;
		double cand = TSP(N, path, visited, current_length + dist[now][i]);
		min = cand < min ? cand : min;
		visited[i] = 0;
		path.pop_back();
	}
	return min;
}

int main()
{
	cout << fixed;
	cout.precision(10);
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		int N;
		cin >> N;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				dist[i][j] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> dist[i][j];
			}
		}
		double answer = 987654321.;
		for (int k = 0; k < N; ++k) {
			vector<int> path;
			int * visited = new int[N];
			for (int i = 0; i < N; ++i)
				visited[i] = 0;
			path.push_back(k);
			visited[k] = 1;
			double temp = TSP(N, path, visited, 0.);
			if (temp < answer)
				answer = temp;
			delete[] visited;
		}
		answers.push_back(answer);
		count++;
	}
	for (auto i = answers.begin(); i != answers.end(); ++i)
		cout << *i << endl;
	return 0;
}
