#include <bits/stdc++.h>
using namespace std;
vector<int> vect;
int dp[100001], N, tmp;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) { 
		cin >> tmp;
		dp[tmp] = i;
	}
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		if (!vect.size() || vect[vect.size() - 1] < dp[tmp]) 
			vect.push_back(dp[tmp]);
		else {
			int idx = lower_bound(vect.begin(), vect.end(), dp[tmp]) - vect.begin();
			vect[idx] = dp[tmp];
		}
	}
	cout << vect.size();
	return 0;
}