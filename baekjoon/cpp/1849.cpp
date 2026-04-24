#include <bits/stdc++.h>
using namespace std;

vector<int> vect;

int N, in[100001], h, ans[100001], tmp;
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
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			in[i] = N - i - tmp;
		}
	}();
	for (int i = 1; i <= N; i++) {
		int left = 1, right = N, idx, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			int cnt = query(1, 1, N, mid, N);

			if (N - mid + 1 - cnt - 1>= in[i]) {
				idx = mid;
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
		ans[idx] = i;
		update(1, 1, N, idx);
	}
	for (int i = 1; i <= N; i++)
		cout << ans[i] << '\n';
	return 0;
}