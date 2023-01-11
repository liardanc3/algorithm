#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, Q, A[66][66], tmp[66][66], mx=0, sum=0, L, powN, powL;
int movey[]{ -1,0,0,1 }, movex[]{ 0,-1,1,0 };
void rotate(int y, int x, int L) {
	double Oy = (1.f * y + 1.f * y - 1 + powL) / 2;
	double Ox = (1.f * x + 1.f * x - 1 + powL) / 2;
	int gap = pow(2, L);
	for (int i = y; i < y + powL; i++) {
		for (int j = x; j < x + powL; j++) {
			double dy = i - Oy, dx = j - Ox;
			double ny = dx + Oy;
			double nx = -dy + Ox;
			tmp[(int)ny][(int)nx] = A[i][j];
		}
	}
}
void melt() {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 1; i <= powN; i++) {
		for (int j = 1; j <= powN; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ddy = i + movey[k];
				int ddx = j + movex[k];
				if (1<=ddy&&ddy<=powN &&1<=ddx&&ddx<=powN && A[ddy][ddx]) cnt++;
			}
			if (cnt < 3)
				tmp[i][j]++;
		}
	}
	for (int i = 1; i <= powN; i++) {
		for (int j = 1; j <= powN; j++) {
			A[i][j] -= tmp[i][j];
			A[i][j] = max(A[i][j], 0);
		}
	}
}
void firestorm(int L) {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 1; i <= powN; i += powL) {
		for (int j = 1; j <= powN; j += powL)
			rotate(i, j, L);
	}
	copy(&tmp[0][0], &tmp[64][65], &A[0][0]);
	melt();
}
void bfs(int yy, int xx) {
	int h = 0;
	queue<pii> q;
	q.push({ yy,xx });
	h++;
	tmp[yy][xx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ddy = y + movey[i];
			int ddx = x + movex[i];
			if (1 <= ddy && ddy <= powN && 1 <= ddx && ddx <= powN && A[ddy][ddx] && !tmp[ddy][ddx]) {
				tmp[ddy][ddx] = 1;
				h++;
				q.push({ ddy,ddx });
			}
		}
	}
	mx = max(mx, h);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	powN = pow(2, N);
	for (int i = 1; i <= powN; i++) for (int j = 1; j <= powN; j++)
		cin >> A[i][j];
	for (int i = 1; i <= Q; i++) {
		cin >> L;
		powL = pow(2, L);
		firestorm(L);
	}
	for (int i = 1; i <= powN; i++) for (int j = 1; j <= powN; j++)
		sum += A[i][j];
	memset(tmp, 0, sizeof(tmp));
	for (int i = 1; i <= powN; i++) {
		for (int j = 1; j <= powN; j++) {
			if (!tmp[i][j] && A[i][j]) bfs(i, j);
		}
	}
	cout << sum << '\n' << mx;
	return 0;
}