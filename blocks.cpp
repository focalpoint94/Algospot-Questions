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

vector<int> answers;
int answer = 0;
int board[20][20] = { 0 };
const int cover_type[4][3][2] = {
	{{0,0}, {0,1}, {1,0}},
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {1,-1}}
};

void set_zero() {
	answer = 0;
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 20; ++j)
			board[i][j] = 1;
}

void print_board(int H, int W) {
	cout << "*Board*" << endl;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool valid(int x, int y, int H, int W, int type) {
	for (int i = 0; i < 3; ++i) {
		int test_x, test_y;
		test_x = x + cover_type[type][i][0];
		test_y = y + cover_type[type][i][1];
		if (test_x < 0 || test_x >= H || test_y < 0 || test_y >= W || board[test_x][test_y] == 1)
			return false;
	}
	return true;
}

void cover(int H, int W) {
	// �����ϴ� ��ǥ ã��
	int x = -1, y = -1;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == 0) {
				x = i; y = j;
				break;
			}
		}
		if (x != -1)
			break;
	}
	// ����� ��� ä�����ٸ�, answer++
	if (x == -1) {
		answer++;
		return;
	}
	// �װ��� ���⿡ ���� ����
	for (int type = 0; type < 4; ++type) {
		// ���� ĭ ����� ä������ �ʾҰ�, �ֺ� ��ϵ� valid�ϴٸ� ���ȣ��
		if (valid(x, y, H, W, type)) {
			// ����� ä���
			for (int i = 0; i < 3; ++i) {
				int test_x, test_y;
				test_x = x + cover_type[type][i][0];
				test_y = y + cover_type[type][i][1];
				board[test_x][test_y] = 1;
			}
			// ���ȣ��
			cover(H, W);
			// ����� �����Ѵ�
			for (int i = 0; i < 3; ++i) {
				int test_x, test_y;
				test_x = x + cover_type[type][i][0];
				test_y = y + cover_type[type][i][1];
				board[test_x][test_y] = 0;
			}
		}
	}
}

void answering(int H, int W) {
	int whites = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == 0)
				whites++;
		}
	}
	if (whites % 3 != 0) {
		answer = 0;
		return;
	}
	cover(H, W);
}

int main()
{
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		set_zero();
		int H, W;
		char temp;
		cin >> H >> W;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> temp;
				if (temp == '#')
					board[i][j] = 1;
				else if (temp == '.')
					board[i][j] = 0;
			}
		}
		answering(H, W);
		answers.push_back(answer);
		count++;
	}
	for (auto i = answers.begin(); i != answers.end(); ++i) {
		cout << *i << endl;
	}
	return 0;
}
