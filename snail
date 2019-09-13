#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <array>
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

const double eps = 0.000000000000001;

int n, m;

double cache[1000][2001] = { -1., };

void set() {
	for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 2001; ++j)
			cache[i][j] = -1.;
}
 
double calc(int days, int climbed) {
	if (days == 0)
		return climbed >= n ? 1. : 0.;
	double& res = cache[days][climbed];
	if (res != -1.) return res;
	return res = 0.25 * calc(days - 1, climbed + 1) + 0.75 * calc(days - 1, climbed + 2);
}

int main()
{
	vector<double> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		set();
		cin >> n >> m;
		ans.push_back(calc(m, 0));
		count++;
	}
	cout.precision(11);
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
