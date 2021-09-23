#include <bits/stdc++.h>
using namespace std;
map<string, int> M;
int main() {
	string tmp;
	int n, m;
	cin >> n >> m;
	while (n--) {
		cin >> tmp;
		M[tmp]++;
	}
	int cnt = 0;
	while (m--) {
		cin >> tmp;
		if (M.find(tmp) != M.end())
			cnt++;
	}
	cout << cnt;
	return 0;
}