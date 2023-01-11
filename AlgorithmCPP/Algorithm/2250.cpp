#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
pii tree[10001];
int N, n, a, b, volumnL[10001], volumnR[10001], lev, mx=-1, depth, parent[10001], root;
int totalR[10001];
vector<int> vect[10001];
int makeTree(int now, int level) {
	vect[level].push_back(now);
	depth = max(depth, level);
	int left = tree[now].first;
	int right = tree[now].second;

	if (left != -1) volumnL[now] += makeTree(left, level + 1);
	if (right != -1) volumnR[now] += makeTree(right, level + 1);

	return volumnL[now] + volumnR[now] + 1;
}
void makeTotal(int now, int parentright) {
	totalR[now] += volumnR[now] + parentright;
	
	int left = tree[now].first;
	int right = tree[now].second;

	if (left != -1)
		makeTotal(left, totalR[now] + 1);
	if (right != -1)
		makeTotal(right, parentright);

	return;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for(int i=1; i<=N; i++) {
			cin >> n >> a >> b;
			tree[n] = { a,b };
			if (a != -1) parent[a] = n;
			if (b != -1) parent[b] = n;
		}
	}();
	for (int i = 1; i <= N; i++) {
		if (!parent[i]) {
			root = i;
			break;
		}
	}
	makeTree(root, 1);
	makeTotal(root, 0);
	for (int i = 1; i <= depth; i++) {
		int left = vect[i][0];
		int right = vect[i][vect[i].size() - 1];

		int gap = totalR[left] - totalR[right] + 1;
		if (gap > mx) {
			mx = gap;
			lev = i;
		}
	}
	cout << lev << ' ' << mx;
	return 0;
}