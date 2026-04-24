#include <bits/stdc++.h>
using namespace std;
typedef std::string s;
int N; s t; map<s, int> m;
int main() {
	cin >> N;
	while (N--) {
		cin >> t;
		m[t.substr([&]() { for (int i = 0; i < t.size(); i++) if (t[i] == '.') return i;} () + 1, t.size())]++;
	}
	for (auto it = m.begin(); it != m.end(); it++) 
		cout << it->first << ' ' << it->second << '\n';
	return 0;
}