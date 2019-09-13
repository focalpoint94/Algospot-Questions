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

int matrix[10][16] = { 0, };

void print_clocks(int clocks[]) {
	cout << "*CLOCK*" << endl;
	for (int i = 0; i < 16; ++i) {
		cout << clocks[i] << " ";
	}
}

int ticking(int clocks[], int count, int n) {
	bool finish = true;
	for (int i = 0; i < 16; ++i) {
		if (clocks[i] % 4 != 0) {
			finish = false;
			break;
		}
	}
	if (finish == true) {
		return count;
	}
	if (n >= 10) {
		return 987654321;
	}
	int min = 987654321;
	for (int i = 0; i < 4; ++i) {
		int cand;
		cand = ticking(clocks, i + count, n + 1);
		if (cand < min)
			min = cand;
		for (int j = 0; j < 16; ++j) {
			if (matrix[n][j] == 1) {
				clocks[j] += 1;
			}
		}
	}
	return min;
}



int main()
{
	matrix[0][0] = matrix[0][1] = matrix[0][2] = 1;
	matrix[1][3] = matrix[1][7] = matrix[1][9] = matrix[1][11] = 1;
	matrix[2][4] = matrix[2][10] = matrix[2][14] = matrix[2][15] = 1;
	matrix[3][0] = matrix[3][4] = matrix[3][5] = matrix[3][6] = matrix[3][7] = 1;
	matrix[4][6] = matrix[4][7] = matrix[4][8] = matrix[4][10] = matrix[4][12] = 1;
	matrix[5][0] = matrix[5][2] = matrix[5][14] = matrix[5][15] = 1;
	matrix[6][3] = matrix[6][14] = matrix[6][15] = 1;
	matrix[7][4] = matrix[7][5] = matrix[7][7] = matrix[7][14] = matrix[7][15] = 1;
	matrix[8][1] = matrix[8][2] = matrix[8][3] = matrix[8][4] = matrix[8][5] = 1;
	matrix[9][3] = matrix[9][4] = matrix[9][5] = matrix[9][9] = matrix[9][13] = 1;
	vector<int> answers;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		int clocks[16] = { 0, };
		for (int i = 0; i < 16; ++i) {
			int temp;
			cin >> temp;
			if (temp == 12)
				clocks[i] = 0;
			else if (temp == 3)
				clocks[i] = 1;
			else if (temp == 6)
				clocks[i] = 2;
			else if (temp == 9)
				clocks[i] = 3;
		}
		int answer = ticking(clocks, 0, 0);
		if (answer == 987654321)
			answer = -1;
		answers.push_back(answer);
		count++;
	}
	for (auto i = answers.begin(); i != answers.end(); ++i)
		cout << *i << endl;
	return 0;
}