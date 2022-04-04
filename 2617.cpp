#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, a, b, ans = 0;
set<int> L[100], R[100];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
	    L[a].insert(b);
		R[b].insert(a);
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto it = L[j].begin(); it != L[j].end(); it++) {
				int next = *it;
				for (auto iter = L[next].begin(); iter != L[next].end(); iter++)
					L[j].insert(*iter);
			}
			for (auto it = R[j].begin(); it != R[j].end(); it++) {
				int next = *it;
				for (auto iter = R[next].begin(); iter != R[next].end(); iter++)
					R[j].insert(*iter);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (L[i].size() > n / 2 || R[i].size() > n / 2) 
			ans++;
	}
	cout << ans;
	return 0;
}