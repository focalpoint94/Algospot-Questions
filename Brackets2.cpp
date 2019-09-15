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
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

string brackets;

bool is_matched() {
	stack<char> stacking;
	for (int i = 0; i < brackets.size(); ++i) {
		if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[')
			stacking.push(brackets[i]);
		else {
			if (brackets[i] == ')') {
				if (!stacking.empty() && stacking.top() == '(')
					stacking.pop();
				else return false;
			}
			else if (!stacking.empty() && brackets[i] == '}') {
				if (stacking.top() == '{')
					stacking.pop();
				else return false;
			}
			else {
				if (!stacking.empty() && stacking.top() == '[')
					stacking.pop();
				else return false;
			}
		}
	}
	if (stacking.empty())
		return true;
	return false;
}


int main()
{
	vector<string> ans;
	int cases;
	cin >> cases;
	int count = 0;
	while (count < cases) {
		cin >> brackets;
		if (is_matched())ans.push_back("YES");
		else ans.push_back("NO");
		count++;
	}
	for (auto i = ans.begin(); i != ans.end(); ++i)
		cout << *i << endl;
	return 0;
}
