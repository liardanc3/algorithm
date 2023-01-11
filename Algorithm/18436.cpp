#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> vect;
int N, a, b, M, cmd, h, arr[100005];
pii init(int now, int start, int end) {
	if (start == end)
		return vect[now] = { arr[start] % 2 == 1,arr[start] % 2 == 0 };
	pii left = init(now * 2, start, (start + end) / 2);
	pii right = init(now * 2 + 1, (start + end) / 2 + 1, end);
	return vect[now] = { left.first + right.first,left.second + right.second };
}
pii query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return { 0,0 };
	if (left <= start && end <= right) 
		return vect[now];

	pii pleft = query(now * 2, start, (start + end) / 2, left, right);
	pii pright = query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);

	return { pleft.first + pright.first,pleft.second + pright.second };
}
void update(int now, int start, int end, int left, int right, int idx) {
	if (idx < start || end < idx)
		return;
	vect[now] = { vect[now].first + left,vect[now].second + right };
	
	if (start != end) {
		update(now * 2, start, (start + end) / 2, left, right, idx);
		update(now * 2 + 1, (start + end) / 2 + 1, end, left, right, idx);
	}

	return;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		h = (int)ceil(log2(N)) + 1;
		vect.assign(1 << (h + 1), { 0,0 });
		for (int i = 1; i <= N; i++) 
			cin >> arr[i];
		init(1, 1, N);
	}();
	cin >> M;
	while (M--) {
		cin >> cmd >> a >> b;
		if (cmd == 1) {
			int src = arr[a] % 2;
			int dst = b % 2;
			if (src && !dst)
				update(1, 1, N, -1, 1, a);
			else if(!src && dst)
				update(1, 1, N, 1, -1, a);
			arr[a] = b;
		}
		else {
			pii ret = query(1, 1, N, a, b);
			if (cmd == 2)
				cout << ret.second << '\n';
			else
				cout << ret.first << '\n';
		}
	}
	return 0;
}