#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx = -1, mn = 1e13;
int k, les[10]{ 0, }, visited[10]{ 0, }, arr[10]{ 0, };
char tmp;
void bt(int now) {
	if (now == k + 1) {
		ll cnt = 1, ans=0;
		for (int i = now - 1; i >= 0; i--) {
			ans += arr[i] * cnt;
			cnt *= 10;
		}
		mn = min(mn, ans), mx = max(mx, ans);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (visited[i]) continue;
		if (now != 0) {
			if (les[now-1] && !(arr[now-1] < i)) continue;
			if (!les[now-1] && !(arr[now-1] > i)) continue;
		}
		visited[i] = 1;
		arr[now++] = i;
		bt(now);
		now--;
		visited[i] = 0;
	}
	return;
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		if (tmp == '<') les[i] = 1;
	}
	bt(0);

	string smx = to_string(mx);
	string smn = to_string(mn);

	if (smx.size() < k + 1)
		cout << "0";
	cout << mx << '\n';
	if (smn.size() < k + 1)
		cout << "0";
	cout << mn;
	return 0;
}