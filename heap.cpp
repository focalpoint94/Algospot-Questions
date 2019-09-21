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
#include <cmath>
#include <limits>

using namespace std;

void push_heap(vector<int>& heap, int newValue) {
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}
void pop_heap(vector<int>& heap) {
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0;
	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= heap.size()) break;
		int next = here;
		if (heap[next] < heap[left])
			next = left;
		if (right < heap.size() && heap[next] < heap[right])
			next = right;
		if (next == here) break;
		swap(heap[here], heap[next]);
		here = next;
	}
}

int main()
{
	vector<int> heap;
	for(int i = 0; i < 10; ++i)
		push_heap(heap, i);
	for (int i = 0; i < heap.size(); ++i)
		cout << heap[i] << endl;
	cout << endl;
	for (int i = 0; i < 10; ++i) {
		cout << heap[0] << endl;
		pop_heap(heap);
	}

	return 0;
}