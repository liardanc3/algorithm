#include <bits/stdc++.h>
using namespace std;

int n, m, cut, cmd, line, amx, bmx;
vector<int> a, b;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	a.push_back(0), b.push_back(0);
	cin >> n >> m >> cut;
	b.push_back(n), a.push_back(m);
	while (cut--) {
		cin >> cmd >> line;
		cmd ? b.push_back(line) : a.push_back(line);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	for (int i = 0; i < a.size() - 1; i++)
		amx = max(amx, a[i + 1] - a[i]);
	for (int i = 0; i < b.size() - 1; i++)
		bmx = max(bmx, b[i + 1] - b[i]);

	cout << amx * bmx;
	return 0;
}
