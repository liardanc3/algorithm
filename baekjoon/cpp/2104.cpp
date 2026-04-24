#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
vector<pii> vect;

int N, A[100001], h;
pii init(int now, int start, int end) {
	if (start == end)
		return vect[now] = { A[start], start };

	pii left = init(now * 2, start, (start + end) / 2);
	pii right = init(now * 2 + 1, (start + end) / 2 + 1, end);

	int mnidx = A[left.second] < A[right.second] ? left.second : right.second;
	return vect[now] = { left.first + right.first,mnidx };
}
pii query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return { 0,0 };

	if (left <= start && end <= right)
		return vect[now];

	pii pleft = query(now * 2, start, (start + end) / 2, left, right);
	pii pright = query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);
	
	int mnidx = A[pleft.second] < A[pright.second] ? pleft.second : pright.second;
	return { pleft.first + pright.first, mnidx };
}
int point(int left, int right) {
	pii ret = query(1, 1, N, left, right);
	int mx = ret.first * A[ret.second];

	if (ret.second + 1 <= right) 
		mx = max(mx,point(ret.second + 1, right));
	if (left <= ret.second - 1)
		mx = max(mx, point(left, ret.second - 1));

	return mx;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), { 0,0 });
		A[0] = 1e9;
		for (int i = 1; i <= N; i++)
			cin >> A[i];
		init(1, 1, N);
	}();
	cout << point(1, N);
	return 0;
}