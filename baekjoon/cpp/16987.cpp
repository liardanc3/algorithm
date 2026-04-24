#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

int n, a, b, mx;
void bt(int idx) {
	if (idx >= n) {
		int cnt = 0;
		for (int i = 0; i < vect.size(); i++) {
			if (vect[i].first <= 0)
				cnt++;
		}
		mx = max(mx, cnt);
		return;
	}

	if (vect[idx].first <= 0) {
		bt(idx + 1);
		return;
	}

	if (idx < n) {
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (idx == i)
				continue;
			if (vect[i].first > 0) {
				flag = 1;

				vect[i].first -= vect[idx].second;
				vect[idx].first -= vect[i].second;
				bt(idx + 1);
				vect[i].first += vect[idx].second;
				vect[idx].first += vect[i].second;
			}
		}
		if (!flag && idx == n - 1) {
			bt(idx + 1);
			return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a >> b;
		vect.push_back({ a,b });
	}
	bt(0);
	cout << mx;
	return 0;
}