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

#define max_size 100

int board[max_size][max_size] = { 0, };
int board_size;
int cache[max_size][max_size] = { -1, };

void set_board() {
	for (int i = 0; i < max_size; ++i) {
		for (int j = 0; j < max_size; ++j) {
			board[i][j] = 0;
			cache[i][j] = -1;
		}
	}
}

void print_board(int N) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int jumpgame(int y, int x) {
	if (y < 0 || x < 0 || y >= board_size || x >= board_size)
		return 0;
	if (board[y][x] == 0)
		return 1;
	int &ret = cache[y][x];
	if (ret != -1)
		return ret;
	int jump_size = board[y][x];
	return ret = jumpgame(y + jump_size, x) || jumpgame(y, x + jump_size);
}

int main()
{
	vector<string> answers;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		set_board();
		int N;
		cin >> N;
		board_size = N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> board[i][j];
		bool ans = jumpgame(0, 0);
		if (ans == 1) answers.push_back("YES");
		else answers.push_back("NO");
		count++;
	}
	for (auto i = answers.begin(); i != answers.end(); ++i)
		cout << *i << endl;
	return 0;
}
