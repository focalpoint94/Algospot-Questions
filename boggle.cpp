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

// Boggle ����
char board[5][5];
// 8����
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
// Ž�� ��ȿ��
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

	// ��ȿ�� ��ǥ���� Ȯ��
	if (x >= 5 || x < 0 || y >= 5 || y < 0)
		return false;
	// ���� ��ǥ�� ���ڰ� ����ġ�ϴ��� Ȯ��
	if (word[idx] != board[x][y])
	{
		valid[x][y][idx] = 0;
		return false;
	}
	// ���ڰ� ��ġ�� ���, ������ ���ڿ��ٸ� ����
	if (idx + 1 == word.size())
		return true;

	// ���ڰ� �����ִٸ�, 8������ ��� Ȯ��
	for (int i = 0; i < 8; ++i) {
		// ���� ��ǥ ����
		int x_next = x + dx[i];
		int y_next = y + dy[i];
		// ���� Ž�� ����� ��������, ���ʿ��� Ž���̶�� skip
		if (valid[x_next][y_next][idx + 1] == 0)
			continue;
		// ���� ��� ���ڰ� ��ġ�Ͽ� true�� return�Ǿ��ٸ�, ����
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