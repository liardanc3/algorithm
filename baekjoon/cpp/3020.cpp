#include <bits/stdc++.h>
using namespace std;
int N, H, tmp, mn = 1e9, mncnt = 0;
vector<int> a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (i % 2)
			b.push_back(tmp);
		else
			a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	double h, _h;
	for (int i = 0; i < H; i++) {
		h = i + 0.5;
		_h = H - (i + 0.5);
		int aidx = upper_bound(a.begin(), a.end(), h) - a.begin();
		int alen = a.size() - aidx;
		int bidx = upper_bound(b.begin(), b.end(), _h) - b.begin();
		int blen = b.size() - bidx;
		if (alen + blen < mn) {
			mn = alen + blen;
			mncnt = 1;
		}
		else if (alen + blen == mn)
			mncnt++;
	}
	cout << mn << ' ' << mncnt;
	return 0;
}