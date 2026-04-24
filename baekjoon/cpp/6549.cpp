#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vect;
int n, arr[100001], h, t;
int init(int now, int start, int end) {
	if (start == end)
		return vect[now] = start;

	int leftidx = init(now * 2, start, (start + end) / 2);
	int rightidx = init(now * 2 + 1, (start + end) / 2 + 1, end);

	return vect[now] = arr[leftidx] < arr[rightidx] ? leftidx : rightidx;
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
int getarea(int left, int right) {
	int mnidx = query(1, 1, n, left, right);
	int mx = arr[mnidx] * (right - left + 1);

	if (mnidx + 1 <= right)
		mx = max(mx, getarea(mnidx + 1, right));
	if (left <= mnidx - 1)
		mx = max(mx, getarea(left, mnidx - 1));

	return mx;
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (cin >> n) {
		if (n == 0) 
			break;
		[&]() {
			for (int i = 1; i <= n; i++)
				cin >> arr[i];
			h = (int)ceil(log2(n));
			vect.assign(1 << (h + 1), 0);
			init(1, 1, n);
		}();
		cout << getarea(1, n) << '\n';
	}
	return 0;
}