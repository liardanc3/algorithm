#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
vector<pii> arr;
vector<int> vect;

int N, h, ans, tmp;
void update(int now, int start, int end, int idx) {
	if (idx < start || end < idx)
		return;
	
	vect[now]++;
	
	if (start == end)
		return;

	update(now * 2, start, (start + end) / 2, idx);
	update(now * 2 + 1, (start + end) / 2 + 1, end, idx);
	
	return;
}
int query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return vect[now];

	int ret = 0;
	ret += query(now * 2, start, (start + end) / 2, left, right);
	ret += query(now * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return ret;
}
signed main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		h = (int)ceil(log2(N));
		vect.assign(1 << (h + 1), 0);
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			arr.push_back({ tmp,i });
		}
		sort(arr.begin(), arr.end());
	}();
	for (int i = 1; i <= N; i++) {
		ans += query(1, 1, N, arr[i-1].second + 1, N);
		update(1, 1, N, arr[i-1].second);
	}
	cout << ans;
	return 0;
}