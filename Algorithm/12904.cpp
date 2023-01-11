#include <bits/stdc++.h>
using namespace std;
string s, t;
void dynamic(string str) {
	if (str.size() < s.size())
		return;
	if (str == s) {
		cout << 1;
		exit(0);
	}
	if (str[str.size() - 1] == 'A')
		dynamic(str.substr(0, str.size() - 1));
	if (str[str.size() - 1] == 'B') {
		str = str.substr(0, str.size() - 1);
		reverse(str.begin(), str.end());
		dynamic(str);
	}
}
int main() {
	cin >> s >> t;
	dynamic(t);
	cout << 0;
	return 0;
}