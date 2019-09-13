#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <limits>

using namespace std;

int N, D, ST;
double prob[50][101];
double t_prob[50];
int connect[50][50];

void calculate_probs() {
	for (int i = 2; i <= D; ++i) {
		for (int j = 0; j < N; ++j) {
			prob[j][i] = 0.;
			for (int k = 0; k < N; ++k) {
				if (connect[j][k] == 1) {
					prob[j][i] += prob[k][i - 1] * t_prob[k];
				}
			}
		}
	}
}

void print() {
	cout << "Connect array" << endl;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << connect[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Transition prob" << endl;
	for (int i = 0; i < N; ++i) {
		cout << t_prob[i] << " ";
	}
	cout << endl;
	cout << "Start prob" << endl;
	for (int i = 0; i < N; ++i) {
		cout << prob[i][0] << " ";
	}
	cout << endl;
}

int main()
{
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		cin >> N >> D >> ST;
		for (int i = 0; i < N; ++i) {
			double denom = 0.;
			for (int j = 0; j < N; ++j) {
				int temp; cin >> temp; connect[i][j] = temp; connect[j][i] = temp;
				if (temp == 1) denom += 1.;
			}
			t_prob[i] = (double)1 / denom;
		}
		for (int i = 0; i < N; ++i) {
			if (connect[ST][i] == 0) prob[i][1] = 0;
			else prob[i][1] = t_prob[ST];
		}
		//print();
		calculate_probs();
		cout.precision(11);
		int num_villages; cin >> num_villages;
		for (int i = 0; i < num_villages; ++i) {
			int village_no; cin >> village_no;
			cout << prob[village_no][D] << " ";
		}
		cout << endl;
		count++;
	}
	return 0;
}
