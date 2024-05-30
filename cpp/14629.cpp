#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gap = 1e14, ans = 9876543221111;
ll n;
int visited[10]{ 0, };
void dfs(ll now, ll idx) {
	if (now != 0) {
		ll _gap = abs(now - n);
		if (_gap == gap) 
			ans = min(ans,now);
		if (_gap < gap) {
			ans = now;
			gap = _gap;
		}
	}
	
	if (now >= n) return;

	for (ll i = 0; i < 10; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(now + i*idx, idx*10);
			visited[i] = 0;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	if (n >= 9876543210)
		cout << "9876543210";
	else {
		dfs(0, 1);
		cout << ans;
	}
	return 0;
}