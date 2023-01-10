#include <bits/stdc++.h>
using namespace std;
int mn = 2e9, mx = -2e9;
int N, a, s, m, d, all;
vector<int> vect;
void bt(string now, int ans) {
	if (now.length() == N - 1) {
		mn = min(mn, ans);
		mx = max(mx, ans);
		return;
	}
	if (a > 0) {
		a--;
		bt(now + "+", ans+vect[now.size()+1]);
		a++;
	}
	if (s > 0) {
		s--;
		bt(now + "-", ans- vect[now.size() + 1]);
		s++;
	}
	if (m > 0) {
		m--;
		bt(now + "*", ans*vect[now.size() + 1]);
		m++;
	}
	if (d > 0) {
		d--;
		bt(now + "/", ans/vect[now.size() + 1]);
		d++;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vect.push_back(tmp);
	}
	cin >> a >> s >> m >> d;
	bt("",vect[0]);
	cout << mx << '\n' << mn;
	return 0;
}