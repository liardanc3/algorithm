#include <bits/stdc++.h>
#define DIV 1'000'000'007
#define int long long
using namespace std;
int t, L, dp[5001], idx=0;
map<string, int> m;
void dynamic(int left, int right, string tmp, int k) {
	if (left < right || left+right>k) return;

	if (left + right == k && right == left && m[tmp]==0) {
		cout << ++idx << " : " << tmp << '\n';
		m[tmp] = 1;
	}
		
	dynamic(left + 1, right, tmp + "(",k);
	dynamic(left, right + 1, tmp + ")",k);
}
int POW(int a, int b) {
	if (b == 0) return 1;
	int hf = POW(a, b / 2);
	hf = hf * hf % DIV;
	if (b % 2) return (a * hf) % DIV;
	return hf % DIV;
}
signed main() {

	//for (int i = 2; i <= 12; i += 2)
		//dynamic(0, 0,"",i);

	dp[1] = 1;
	for (int i = 2; i <= 5000; i++)
		dp[i] = (dp[i - 1] * i) % DIV;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> L;
		if (L % 2) cout << 0 << '\n';
		else cout << (dp[L] * POW((dp[L/2]*dp[L/2+1])%DIV,DIV-2))%DIV << '\n';
	}
	return 0;
}