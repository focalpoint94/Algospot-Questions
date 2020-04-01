#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int C;
const string encoded[7] = { "20", "21", "24", "25", "28", "29", "2a" };
const string characters[7] = { " ", "!", "$", "%", "(", ")", "*" };

void reverse_URL(string& URL, int length) {
	for (int idx = 0; idx < length - 2; ++idx) {
		char temp = URL[idx];
		if (temp == '%') {
			string type = URL.substr(idx + 1, 2);
			int i = -1;
			for (i = 0; i < 7; ++i) {
				if (type == encoded[i]) {
					break;
				}
			}
			if (i == -1) continue;
			URL.replace(idx, 3, characters[i]);
		}
	}
}

int main() {
	cin >> C;
	for (int count = 0; count < C; ++count) {
		string URL;
		cin >> URL;
		reverse_URL(URL, URL.length());
		cout << URL << endl;
	}
	return 0;
}
