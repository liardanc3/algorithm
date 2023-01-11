#include <bits/stdc++.h>
using namespace std;

vector<int> vect;

int N, tmp, in[100002], h, ans[100002], tree[100002];
int getRoot(int i) {
	return tree[i] == i ? i : tree[i] = getRoot(tree[i]);
}
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
		for (int i = 1; i <= N; i++)
			tree[i] = i;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			in[i] = i - 1 - tmp;
		}
	}();
	for (int i = N; i >= 1; i--) {
		int left = 1, right = N, mid, idx;
		while (left <= right) {
			mid = (left + right) / 2;
			int cnt = query(1, 1, N, 1, mid);

			if (mid - cnt - 1 >= in[i]) {
				idx = mid;
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		update(1, 1, N, idx);
		ans[idx] = i;
	}
	for (int i = 1; i <= N; i++)
		cout << ans[i] << ' ';
	return 0;
}