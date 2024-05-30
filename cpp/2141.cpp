#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

int N, x, a, cnt[100001];
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x >> a;
		vect.push_back({ x,a });
	}
	sort(vect.begin(), vect.end());
	for (int i = 1; i <= N; i++) {
		pii p = vect[i - 1];

		cnt[i] += p.second;
		cnt[i] += cnt[i - 1];
	}

	int mid = cnt[N] / 2 + cnt[N] % 2;
	int idx = lower_bound(&cnt[1], &cnt[N], mid) - &cnt[0];

	cout << vect[idx-1].first;
	return 0;
}