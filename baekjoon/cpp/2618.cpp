#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
vector<pii> vecta, vectb;

int N, W, a, b, dp[1001][1001], trace[1001][1001];
int dynamic(int aa, int bb, int now) {
	if (now > W)
		return 0;
	if (dp[aa][bb] != 1e16)
		return dp[aa][bb];

	int aa_start = dynamic(now, bb, now + 1) +
		abs(vecta[aa].first - vecta[now].first) + abs(vecta[aa].second - vecta[now].second);
	int bb_start = dynamic(aa, now, now + 1) +
		abs(vectb[bb].first - vectb[now].first) + abs(vectb[bb].second - vectb[now].second);

	//cout << "now : " << now << ", aa = " << aa << ", bb = " << bb << '\n';
	//cout << "aa_start == " << aa_start << ", bb_start == " << bb_start << '\n';
	trace[aa][bb] = aa_start < bb_start ? 1 : 2;
	//cout << "trace[" << aa << "][" << bb << "] = " << trace[aa][bb] << '\n';
	//cout << "-------------------------------------------------------\n";
	return dp[aa][bb] = min(aa_start, bb_start);
}
void dfs(int aa, int bb, int now) {
	if (now >= W)
		return;
	cout << trace[aa][bb] << '\n';
	if (trace[aa][bb] == 1)
		dfs(now + 1, bb, now + 1);
	else
		dfs(aa, now + 1, now + 1);
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> W;
		fill(&dp[0][0], &dp[1000][1001], 1e16);
		vecta.push_back({ 1,1 });
		vectb.push_back({ N,N });
		for (int i = 1; i <= W; i++) {
			cin >> a >> b;
			vecta.push_back({ a,b });
			vectb.push_back({ a,b });
		}
	}();
	cout << dynamic(0, 0, 1) << '\n';
	dfs(0, 0, 0);
	return 0;
}