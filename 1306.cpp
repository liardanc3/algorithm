#include <bits/stdc++.h>
using namespace std;

vector<int> vect, arr, ans;
int N, M, h;
int init(int now, int start, int end) {
	if (start == end)
		return vect[now] = arr[start];
	return vect[now] = max(
		init(now * 2, start, (start + end) / 2),
		init(now * 2 + 1, (start + end) / 2 + 1, end)
	);
}
int query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return vect[now];
	return max(
		query(now * 2, start, (start + end) / 2, left, right),
		query(now * 2 + 1, (start + end) / 2 + 1, end, left, right)
	);
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cin >> N >> M;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		arr.assign(N + 1, 0);
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		init(1, 1, N);
	}();
	for (int i = M; i <= N - M + 1; i++) 
		ans.push_back(query(1, 1, N, i - (M - 1), i + (M - 1)));
	for (int i : ans)
		cout << i << ' ';
	return 0;
}