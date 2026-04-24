#include <bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	int _0 = 0, _1 = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i + 1]) 
			s[i] == '0' ? _0++ : _1++;
		if (i == s.size() - 2)
			s[i + 1] == '0' ? _0++ : _1++;
	}
	cout << min(_0, _1);
	return 0;
}