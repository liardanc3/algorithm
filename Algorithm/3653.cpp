#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

vector<int> vect;
int t, n, m, tmp, h, flo[100001];
void update(int now, int start, int end, int left, int right, int diff) {
	if (right < start || end < left)
		return;
	vect[now] += diff * (end - start + 1);
	if (start != end) {
		update(now * 2, start, (start + end) / 2, left, right, diff);
		update(now * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
		vect[now] = vect[now * 2] + vect[now * 2 + 1];
	}
}
int query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return vect[now];
	return query(now * 2, start, (start + end) / 2, left, right) +
		query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	while (t--) {
		[&]() {
			cin >> n >> m;
			//assert(n <= m);
			h = (int)ceil(log2(n+m));
			vect.clear();
			vect.assign(1 << (h + 1), 0);
			for (int i = 1; i <= n; i++)
				flo[i] = n - (i - 1);
			update(1, 1, n+m, 1, n, 1);
			for (int i = n + 1; i < n + 1 + m; i++) {
				cin >> tmp;
				int f = flo[tmp];
				cout << query(1, 1, n+m, f + 1, n+m) << ' ';
				update(1, 1, n+m, f, f, -1);
				update(1, 1, n+m, i, i, 1);
				flo[tmp] = i;
			}
			cout << '\n';
		}();
	}
	return 0;
}