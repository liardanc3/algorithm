#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect;
int N, M, arr[100001], h, mx;
void init(int now, int start, int end) {
	if (start == end) {
		vect[now] = start;
		return;
	}
	init(now * 2, start, (start + end) / 2);
	init(now * 2 + 1, (start + end) / 2 + 1, end);
	vect[now] = arr[vect[now * 2]] < arr[vect[now * 2 + 1]] ? vect[now * 2] : vect[now * 2 + 1];
}
int query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return -1;
	if (left <= start && end <= right)
		return vect[now];

	int leftidx = query(now * 2, start, (start + end) / 2, left, right);
	int rightidx = query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return leftidx == -1 ? rightidx : rightidx == -1 ? leftidx : arr[leftidx] < arr[rightidx] ? leftidx : rightidx;
}
void profit(int left, int right) {
	int minidx = query(1, 1, N, left, right);
	mx = max(mx, (right - left + 1) * arr[minidx]);

	if (minidx + 1 <= right)
		profit(minidx + 1, right);
	if (left <= minidx - 1)
		profit(left, minidx - 1);
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	h = (int)ceil(log2(N));
	vect.assign(1 << (h + 1), 0);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	init(1, 1, N);
	profit(1, N);
	cout << mx;
	return 0;
}