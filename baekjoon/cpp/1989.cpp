#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect;
int N, A[100001], h, ret = -1, src, dst, sum[100001];
int init(int now, int start, int end) {
	if (start == end)
		return vect[now] = start;

	int leftidx = init(now * 2, start, (start + end) / 2);
	int rightidx = init(now * 2 + 1, (start + end) / 2 + 1, end);

	return vect[now] = A[leftidx] < A[rightidx] ? leftidx : rightidx;
}
int query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return -1;
	if (left <= start && end <= right)
		return vect[now];
	
	int leftidx = query(now * 2, start, (start + end) / 2, left, right);
	int rightidx = query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);

	return leftidx == -1 ? rightidx : rightidx == -1 ? leftidx : A[leftidx] < A[rightidx] ? leftidx : rightidx;
}
void getmx(int left, int right) {
	int idx = query(1, 1, N, left, right);

	int mx = A[idx] * (sum[right]-sum[left-1]);
	if (mx > ret) {
		ret = mx;
		src = left, dst = right;
	}

	if (idx + 1 <= right)
		getmx(idx + 1, right);
	if (left <= idx - 1)
		getmx(left, idx - 1);
	return;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			sum[i] = sum[i - 1] + A[i];
		}
		init(1, 1, N);
	}();
	getmx(1, N);
	cout << ret << '\n' << src << ' ' << dst;
	return 0;
}