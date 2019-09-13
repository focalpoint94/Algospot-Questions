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

// Boggle 보드
char board[5][5];
// 8방향
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
// 탐색 유효성
int valid[5][5][10];

void print_board() {
	cout << endl << "*Boggle*" << endl;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

void set_valid_to_one() {
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			for (int k = 0; k < 10; ++k)
				valid[i][j][k] = 1;
}

bool is_word_by_idx(int x, int y, const string& word, int idx) {

	// 유효한 좌표인지 확인
	if (x >= 5 || x < 0 || y >= 5 || y < 0)
		return false;
	// 현재 좌표의 글자가 불일치하는지 확인
	if (word[idx] != board[x][y])
	{
		valid[x][y][idx] = 0;
		return false;
	}
	// 글자가 일치한 경우, 마지막 글자였다면 성공
	if (idx + 1 == word.size())
		return true;

	// 글자가 남아있다면, 8방향을 모두 확인
	for (int i = 0; i < 8; ++i) {
		// 다음 좌표 설정
		int x_next = x + dx[i];
		int y_next = y + dy[i];
		// 이전 탐색 기록을 바탕으로, 불필요한 탐색이라면 skip
		if (valid[x_next][y_next][idx + 1] == 0)
			continue;
		// 뒤의 모든 글자가 일치하여 true가 return되었다면, 성공
		if (is_word_by_idx(x_next, y_next, word, idx + 1))
			return true;
	}
	return false;
}

bool is_word(const string& word) {
	set_valid_to_one();
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if (is_word_by_idx(i, j, word, 0) == true)
				return true;
	return false;
}

int main()
{
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				cin >> board[i][j];
		int num_tests;
		cin >> num_tests;
		string *words = new string[num_tests];
		for (int i = 0; i < num_tests; ++i) {
			cin >> words[i];
		}
		for (int i = 0; i < num_tests; ++i) {
			if (is_word(words[i]))
				cout << words[i] << " " << "YES" << endl;
			else
				cout << words[i] << " " << "NO" << endl;
		}
		delete[] words;
		count++;
	}
	return 0;
}