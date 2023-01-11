#include <bits/stdc++.h>
#include <assert.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
int N, arr[502], sz, K;
vector<int> vect;
vector<pii> pvect[501];
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (!vect.size() || vect[vect.size() - 1] < arr[i]) {
			vect.push_back(arr[i]);
			pvect[vect.size()].push_back({ arr[i],i });
		}
		else {
			int idx = lower_bound(vect.begin(), vect.end(), arr[i]) - vect.begin();
			vect[idx] = arr[i];
			pvect[idx + 1].push_back({ arr[i],i });
		}
	}
	sz = vect.size();
	for (int i = 1; i <= sz; i++)
		sort(pvect[i].begin(), pvect[i].end());
}
int ck[502]{ 0, }, cnt = 0;
void bt(int now, int lastidx) {
	if (now == sz + 1) {
		cnt++;
		if (K == cnt) {
			for (int i = 1; i <= sz; i++)
				cout << ck[i] << ' ';
			exit(0);
		}
		if (cnt > K) {
			cout << -1;
			exit(0);
		}
		return;
	}
	for (int i = 0; i < pvect[now].size(); i++) {
		int last = ck[now - 1];
		int next = pvect[now][i].first;
		int nextidx = pvect[now][i].second;
		if (last < next && lastidx < nextidx) {
			ck[now] = next;
			bt(now + 1, nextidx);
		}
	}
	return;
}
signed main() {
	init();
	bt(1, 0);
	cout << -1;
	return 0;
}