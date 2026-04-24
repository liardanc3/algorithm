#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect;
int N, arr[1000001], h, tmp, cross;
int query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return vect[now];
	return query(now * 2, start, (start + end) / 2, left, right) +
		query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int now, int start, int end, int idx) {
	if (idx < start || end < idx)
		return;
	vect[now]++;
	if (start != end) {
		update(now * 2, start, (start + end) / 2, idx);
		update(now * 2 + 1, (start + end) / 2 + 1, end, idx);
	}
	return;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			arr[tmp] = i;
		}
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			cross += query(1, 1, N, arr[tmp] + 1, N);
			update(1, 1, N, arr[tmp]);
		}
	}();
	cout << cross;
	return 0;
}