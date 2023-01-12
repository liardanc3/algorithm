#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;
int n, m, k, arr[51][51], r, c, s, tmp1[51][51], visited[7], mn = 1e9, tmp2[51][51], ck[7];
vector<tii> vect;
void rotate(int _r, int _c, int _s) {
	copy(&tmp1[0][0], &tmp1[50][51], &tmp2[0][0]);

	for (int s = 1; s <= _s; s++) {

		int startR = _r - s;
		int startC = _c - s;

		// 왼쪽위
		tmp2[startR][startC] = tmp1[startR + 1][startC];

		int nowR = startR, nowC = startC + 1;
		while (startR != nowR || startC != nowC) {

			// 윗줄
			if (nowR == startR)
				tmp2[nowR][nowC] = tmp1[nowR][nowC - 1];
			// 오른쪽
			else if (nowC == startC + 2 * s)
				tmp2[nowR][nowC] = tmp1[nowR - 1][nowC];
			// 아래줄
			else if (nowR == startR + 2 * s)
				tmp2[nowR][nowC] = tmp1[nowR][nowC + 1];
			// 왼쪽
			else
				tmp2[nowR][nowC] = tmp1[nowR + 1][nowC];


			// 오른쪽위
			if (nowR == startR && nowC == startC + 2 * s)
				nowR++;
			// 오른쪽아래
			else if (nowR == startR + 2 * s && nowC == startC + 2 * s)
				nowC--;
			// 왼쪽아래
			else if (nowR == startR + 2 * s && nowC == startC)
				nowR--;
			// 윗줄
			else if (nowR == startR)
				nowC++;
			// 오른쪽줄
			else if (nowC == startC + 2 * s)
				nowR++;
			// 아랫줄
			else if (nowR == startR + 2 * s)
				nowC--;
			// 왼쪽줄
			else
				nowR--;
		}
	}

	copy(&tmp2[0][0], &tmp2[50][51], &tmp1[0][0]);
}

void dfs(int cnt) {
	if (cnt == k) {
		copy(&arr[0][0], &arr[50][51], &tmp1[0][0]);
		for (int i = 0; i < k; i++) {
			int _r = get<0>(vect[visited[i]]);
			int _c = get<1>(vect[visited[i]]);
			int _s = get<2>(vect[visited[i]]);

			rotate(_r, _c, _s);
		}
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++)
				sum += tmp1[i][j];
			mn = min(mn, sum);
		}
		return;
	}

	for (int i = 0; i < k; i++) {
		if (!ck[i]) {
			ck[i] = 1;
			visited[cnt] = i;
			dfs(cnt + 1);
			ck[i] = 0;
		}
	}

	return;
}
void init() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		cin >> arr[i][j];
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		vect.push_back({ r,c,s });
	}
}
int main() {
	init();
	dfs(0);
	cout << mn;
	return 0;
}