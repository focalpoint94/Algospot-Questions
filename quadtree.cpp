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

#define board_size 40

int board[board_size][board_size] = { 0, };

void set_zero() {
	for (int i = 0; i < board_size; ++i)
		for (int j = 0; j < board_size; ++j)
			board[i][j] = 0;
}

void print_board() {
	for (int i = 0; i < board_size; ++i) {
		for (int j = 0; j < board_size; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void decompress(const string& temp, string::iterator &it, int y, int x, int size) {
	if (it != temp.end()) {
		char head = *it;
		it++;
		int half = size / 2;
		if (head == 'w') {
			for (int dy = 0; dy < size; ++dy)
				for (int dx = 0; dx < size; ++dx)
					board[y + dy][x + dx] = 1;
		}
		else if (head == 'b') {
			for (int dy = 0; dy < size; ++dy)
				for (int dx = 0; dx < size; ++dx)
					board[y + dy][x + dx] = 0;
		}
		else {
			decompress(temp, it, y, x, half);
			decompress(temp, it, y, x + half, half);
			decompress(temp, it, y + half, x, half);
			decompress(temp, it, y + half, x + half, half);
		}
	}
}

string reverse(const string& img, string::iterator &it) {
	char temp = *it;
	it++;
	if (temp == 'w' || temp == 'b') {
		string a(1, temp);
		return a;
	}
	else if (temp == 'x') {
		string a = reverse(img, it);
		string b = reverse(img, it);
		string c = reverse(img, it);
		string d = reverse(img, it);
		return string(1, 'x') + c + d + a + b;
	}
}

int main()
{
	vector<string> answers;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		string temp;
		cin >> temp;
		string::iterator it = temp.begin();
		string ans = reverse(temp, it);
		answers.push_back(ans);
		count++;
	}
	for (auto i = answers.begin(); i != answers.end(); ++i)
		cout << *i << endl;
	return 0;
}
