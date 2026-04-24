#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect;

int N, arr[100001], h, mx;
int init(int now, int start, int end) {
	if (start == end)
		return vect[now] = start;

	int leftidx = init(now * 2, start, (start + end) / 2);
	int rightidx = init(now * 2 + 1, (start + end) / 2 + 1, end);

	if (arr[leftidx] < arr[rightidx])
		return vect[now] = leftidx;
	return vect[now] = rightidx;
}
int query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 1e9;
	if (left <= start && end <= right)
		return vect[now];

	int leftres = query(now * 2, start, (start + end) / 2, left, right);
	int rightres = query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);

	if (leftres == 1e9)
		return rightres;
	if (rightres == 1e9)
		return leftres;

	return arr[leftres] < arr[rightres] ? leftres : rightres;
}
int solve(int left, int right) {
	int minidx = query(1, 1, N, left, right);
	int mx = arr[minidx] * (right - left + 1);

	if (minidx + 1 <= right)
		mx = max(mx, solve(minidx + 1, right));
	if (left <= minidx - 1)
		mx = max(mx, solve(left, minidx - 1));
	
	return mx;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		init(1, 1, N);
		// 2 1 4 5 1 3 3
	}();
	cout << solve(1, N);
	return 0;
}