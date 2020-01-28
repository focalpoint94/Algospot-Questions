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
	
vector<pair<double, int>> g[20001];
// graph 생성, 각 원소: (가중치, 이어지는 정점)의 pair

int V, E, st;
// 정점의 수, 간선의 수, 시작점
double min_dist[10001];
// 시작점에서 각 정점까지의 최단거리
bool check[10001];
// 각 정점의 방문 여부

const double max_value = numeric_limits<double>::max();
// 비교를 위한 큰 수

void dijkstra() {
	priority_queue<pair<double, int>>pq;
	min_dist[st] = 1;
	int nowv, nextv;
	double noww, nextw;
	double nextdist;
	pq.push(make_pair(-1, st));
	// 곱셈이 진행되므로 시작점에 1을 부여
	while (!pq.empty()) {
		nowv = pq.top().second;
		noww = -1 * pq.top().first;
		pq.pop();
		if (check[nowv]) continue;
		// 이미 방문한 정점은 pass
		check[nowv] = true;

		sort(g[nowv].begin(), g[nowv].end());
		// 현재 정점과 연결되는 정점들에 대한 인접 리스트를 정렬

		for (pair<double, int> node : g[nowv]) {
			// 현재 정점과 연결되는 모든 정점에 대해,
			nextv = node.second;
			nextw = node.first;
			nextdist = noww * nextw;
			if (min_dist[nextv] > nextdist) {
				// min_dist를 갱신
				min_dist[nextv] = nextdist;
				pq.push(make_pair(-nextdist, nextv));
			}
		}
	}

}

int main()
{
	int cases = 0;
	cin >> cases;
	while (cases > 0) {
		cin >> V >> E;
		st = 0;
		int u, v;
		double w;
		// 모든 정점에 대해 min_dist, graph, 방문 여부 init
		for (int i = 0; i < V; ++i) {
			min_dist[i] = max_value;
			g[i].clear();
			check[i] = false;
		}
		// 무방향 그래프임을 고려하여 graph 입력
		for (int i = 0; i < E; ++i) {
			cin >> u >> v >> w;
			g[u].push_back(make_pair(w, v));
			g[v].push_back(make_pair(w, u));
		}
		dijkstra();
		cout << fixed;
		cout.precision(10);
		cout << min_dist[V - 1] << endl;

		cases--;
	}
	return 0;
}
