#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, arr[100001];
vector<int> maxtree, mintree;
int maxinit(int node, int start, int end) {
	if (start == end)
		return maxtree[node] = arr[start];
	return maxtree[node] = 
		max(maxinit(node * 2, start, (start + end) / 2), 
			maxinit(node * 2 + 1, (start + end) / 2 + 1, end));
}
int mininit(int node, int start, int end) {
	if (start == end)
		return mintree[node] = arr[start];
	return mintree[node] =
		min(mininit(node * 2, start, (start + end) / 2),
			mininit(node * 2 + 1, (start + end) / 2 + 1, end));
}
int getmax(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return -2e9;
	if (left <= start && end <= right)
		return maxtree[node];
	return max(getmax(node * 2, start, (start + end) / 2, left, right),
		getmax(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int getmin(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 2e9;
	if (left <= start && end <= right)
		return mintree[node];
	return min(getmin(node * 2, start, (start + end) / 2, left, right),
		getmin(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int h = (int)ceil(log2(n));
	maxtree.assign((1 << (h+1)) - 1, -2e9);
	mintree.assign((1 << (h+1)) - 1, 2e9);
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	maxinit(1, 1, n);
	mininit(1, 1, n);
	while (m--) {
		cin >> a >> b;
		cout << getmin(1, 1, n , a, b) << ' ' << getmax(1, 1, n , a, b) << '\n';
	}
	return 0;
}