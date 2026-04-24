#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, cnt;
string tmp;
vector<int> vect[21];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vect[tmp.size()].push_back(i+1);
	}
	for (int i = 1; i <= 20; i++) {
		if (vect[i].size() <= 1) continue;

		int right = 0;
		for (int j = 0; j < vect[i].size() - 1; j++) {
			while (right+1 < vect[i].size() && vect[i][right+1] - vect[i][j] <= k)
				right++;

			cnt += (right) - j;
		}
	}
	cout << cnt;
	return 0;
}