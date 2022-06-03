#include <bits/stdc++.h>
#define int long long
using namespace std;
string tmp;
map<string, int> dp;
int cnt;
int dfs(int len, string now) {
	if (len == tmp.size()) 
		return dp[now] = 1;

	if (dp[now])
		return dp[now];

	if (tmp[len] == '0') return 0;

	string one = now + tmp[len];
	dp[now] += dfs(len + 1, one);

	if (len + 1 < tmp.size()) {
		int two = (tmp[len] - '0') * 10 + (tmp[len + 1] - '0');
		if (1 <= two && two <= 34) 
			dp[now] += dfs(len + 2, now + tmp[len] + tmp[len+1]);
	}

	return dp[now];
}
signed main() {
	cin >> tmp;
	dfs(0, "-");
	cout << dp["-"];
	return 0;
}