#include <bits/stdc++.h>
using namespace std;

vector<int> vect;
int w, n, tmp, dp[800001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	[&]() {
		cin >> w >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			vect.push_back(tmp);
		}
	}();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (w-vect[i]-vect[j] >= 0 && dp[w - vect[i] - vect[j]]) {
				cout << "YES";
				return 0;
			}
		}
		for (int j = 0; j < i; j++) {
			if (vect[j] + vect[i] < w)
				dp[vect[j] + vect[i]] = 1;
		}
	}
	cout << "NO";
	return 0;
}