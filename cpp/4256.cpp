#include <bits/stdc++.h>
using namespace std;

int T, n, pre[1001], in[1001], root, L[1001], R[1001], r;
void maketree(int inleft, int inright, int rootidx, int preidx) {
	
	// 왼쪽 서브트리
	int cnt = 0;
	if (inleft < rootidx) {
		cnt = rootidx - inleft;

		int next = pre[preidx + 1];
		L[in[rootidx]] = next;

		for (int i = inleft; i < rootidx; i++) {
			if (in[i] == next) {
				maketree(inleft, rootidx - 1, i, preidx + 1);
				break;
			}
		}
	}

	// 오른쪽 서브트리
	if (rootidx < inright) {
		int next = pre[preidx + 1 + cnt];
		R[in[rootidx]] = next;

		for (int i = rootidx + 1; i <= inright; i++) {
			if (in[i] == next) {
				maketree(rootidx + 1, inright, i, preidx + 1 + cnt);
				break;
			}
		}
	}
}
void postorder(int node) {
	if (L[node])
		postorder(L[node]);
	if (R[node])
		postorder(R[node]);
	cout << node << ' ';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n;
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		for (int i = 1; i <= n; i++)
			cin >> pre[i];
		for (int i = 1; i <= n; i++) {
			cin >> in[i];
			if (in[i] == pre[1])
				r = i;
		}
		maketree(1, n, r, 1);
		postorder(pre[1]);
		cout << '\n';
	}
	return 0;
}