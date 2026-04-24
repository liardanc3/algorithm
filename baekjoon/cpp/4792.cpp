#include <bits/stdc++.h>
using namespace std;
int n, m, k, f, t, tree[1001], tree2[1001], r_cnt, b_cnt, rr_cnt, bb_cnt;
char color;
typedef pair<int, int> pii;
queue<pii> rQ, bQ, rrQ, bbQ;

int getRoot(int i) {
	return i == tree[i] ? i : tree[i] = getRoot(tree[i]);
}
int getRoot2(int i) {
	return i == tree2[i] ? i : tree2[i] = getRoot2(tree2[i]);
}

int kruskal() {
	// 파란색 최대
	while (!bQ.empty() && b_cnt < n-1) {
		int a = bQ.front().first;
		int b = bQ.front().second;
		bQ.pop();
	
		if (getRoot(a) == getRoot(b)) continue;
		tree[getRoot(a)] = getRoot(b);
		b_cnt++;
	}
	while (!rQ.empty() && r_cnt + b_cnt < n - 1) {
		int a = rQ.front().first;
		int b = rQ.front().second;
		rQ.pop();

		if (getRoot(a) == getRoot(b)) continue;
		tree[getRoot(a)] = getRoot(b);
		r_cnt++;
	}
	// 파란색 최소
	while (!rrQ.empty() && rr_cnt < n - 1) {
		int a = rrQ.front().first;
		int b = rrQ.front().second;
		rrQ.pop();

		if (getRoot2(a) == getRoot2(b)) continue;
		tree2[getRoot2(a)] = getRoot2(b);
		rr_cnt++;
	}
	while (!bbQ.empty() && rr_cnt + bb_cnt < n - 1) {
		int a = bbQ.front().first;
		int b = bbQ.front().second;
		bbQ.pop();

		if (getRoot2(a) == getRoot2(b)) continue;
		tree2[getRoot2(a)] = getRoot2(b);
		bb_cnt++;
	}

	if (bb_cnt <= k && k <= b_cnt) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n >> m >> k) {
		if (n == 0 && m == 0 && k == 0) break;
		r_cnt = 0, b_cnt = 0, rr_cnt = 0, bb_cnt = 0;
		for (int i = 0; i <= n; i++) {
			tree[i] = i;
			tree2[i] = i;
		}
		for (int i = 0; i < m; i++) {
			cin >> color >> f >> t;
			if (color == 'R') {
				rQ.push({ f,t });
				rrQ.push({ f,t });
			}
			else {
				bQ.push({ f,t });
				bbQ.push({ f,t });
			}
		}
		cout << kruskal() << '\n';
		while (!rQ.empty())
			rQ.pop();
		while (!rrQ.empty())
			rrQ.pop();
		while (!bQ.empty())
			bQ.pop();
		while (!bbQ.empty())
			bbQ.pop();
	}
	return 0;
}