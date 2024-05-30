#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;

vector<string> str;
vector<int> vect;
string tmp;
int N, K, dp[100][1 << 16], sz[16], t[1000];
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int dynamic(int now, int sztmp, int visited) {
	if (visited == (1 << N) - 1) 
		return now % K == 0 ? 1 : 0;
	if (dp[now][visited] != -1)
		return dp[now][visited];

	dp[now][visited] = 0;

	for (int i = 0; i < N; i++) {
		if (visited & 1 << i)
			continue;
		int k = now + (vect[i] * t[sztmp]) % K;
		k %= K;

		dp[now][visited] += dynamic(k, sztmp + sz[i], visited + (1 << i));
		/*dp[k][visited + (1 << i)] += dp[now][visited];
		dynamic(k, sztmp + sz[i], visited + (1 << i));*/
	}

	return dp[now][visited];
}

signed main() {
	[&]() {
		fill(&dp[0][0], &dp[99][1 << 16], -1);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			str.push_back(tmp);
			sz[i] = tmp.size();
		}
		cin >> K;
		t[0] = 1 % K;
		for (int i = 1; i <= 50 * 15; i++) {
			t[i] = t[i - 1] * 10;
			t[i] %= K;
		}
		for (int i = 0; i < N; i++) {
			string now = str[i];

			int cnt = 0, totalk = 0;
			int left = max(0LL, (int)now.size() - 3), right = now.size() - 1;
			while (left <= right) {
				string now_tmp = now.substr(left, (right - left + 1));
				int partion = stoi(now_tmp);
				int a = partion % K;
				for (int j = 1; j <= cnt; j++) {
					a *= 1000 % K;
					a %= K;
				}
				totalk += a % K;
				totalk %= K;
				cnt++;
				left = max(0LL, left - 3), right -= 3;
			}
			vect.push_back(totalk);
		}
	}();
	dynamic(0, 0, 0);
	int dn = 1;
	for (int i = 2; i <= N; i++)
		dn *= i;
	int up = dp[0][0];
	int ret = gcd(dn, up);
	cout << up / ret << "/" << dn / ret;
	return 0;
}