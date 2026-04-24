#include <bits/stdc++.h>
#define y first
#define x second
using namespace std;

typedef pair<int, int> pii;
typedef tuple<pii, pii, pii> tii;

pii B[3], E[3];

// visited[0][y][x] = y,x중심 세로
// visited[1][y][x] = y,x중심 가로
int N, arr[51][51], b, e, visited[2][51][51];
string tmp;
void bfs() {
	
	queue<tii> q;
	q.push({ B[0],B[1],B[2] });
	int cnt = -1;
	visited[B[0].x + 1 == B[1].x][B[1].y][B[1].x] = 1;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();
		while (sz--) {
			pii a = get<0>(q.front());
			pii b = get<1>(q.front());
			pii c = get<2>(q.front());

			q.pop();

			int wide = a.first == b.first;
			if (a == E[0] && b == E[1] && c == E[2]) {
				cout << cnt;
				return;
			}
			// U
			pii aa = { a.y - 1,a.x };
			pii bb = { b.y - 1,b.x };
			pii cc = { c.y - 1,c.x };
			if (1 <= aa.y && aa.y <= N) {
				if (arr[aa.y][aa.x] != 1 && arr[bb.y][bb.x] != 1 && arr[cc.y][cc.x] != 1) {
					if (!visited[wide][bb.y][bb.x]) {
						visited[wide][bb.y][bb.x] = 1;
						q.push({ aa,bb,cc });
					}
				}
			}
			// D
			aa = { a.y + 1,a.x };
			bb = { b.y + 1,b.x };
			cc = { c.y + 1,c.x };
			if (1 <= cc.y && cc.y <= N) {
				if (arr[aa.y][aa.x] != 1 && arr[bb.y][bb.x] != 1 && arr[cc.y][cc.x] != 1) {
					if (!visited[wide][bb.y][bb.x]) {
						visited[wide][bb.y][bb.x] = 1;
						q.push({ aa,bb,cc });
					}
				}
			}
			// L
			aa = { a.y,a.x - 1 };
			bb = { b.y,b.x - 1 };
			cc = { c.y,c.x - 1 };
			if (1 <= aa.x) {
				if (arr[aa.y][aa.x] != 1 && arr[bb.y][bb.x] != 1 && arr[cc.y][cc.x] != 1) {
					if (!visited[wide][bb.y][bb.x]) {
						visited[wide][bb.y][bb.x] = 1;
						q.push({ aa,bb,cc });
					}
				}
			}
			// R
			aa = { a.y,a.x + 1 };
			bb = { b.y,b.x + 1 };
			cc = { c.y,c.x + 1 };
			if (cc.x <= N) {
				if (arr[aa.y][aa.x] != 1 && arr[bb.y][bb.x] != 1 && arr[cc.y][cc.x] != 1) {
					if (!visited[wide][bb.y][bb.x]) {
						visited[wide][bb.y][bb.x] = 1;
						q.push({ aa,bb,cc });
					}
				}
			}
			// T
			bool flag = true;
			if (wide) {
				if (arr[a.y - 1][a.x] == 1 || arr[a.y - 1][b.x] == 1 || arr[a.y - 1][b.x + 1] == 1)
					flag = false;
				if (arr[a.y + 1][a.x] == 1 || arr[a.y + 1][b.x] == 1 || arr[a.y + 1][b.x + 1] == 1)
					flag = false;
			}
			else {
				if (arr[a.y][a.x - 1] == 1 || arr[b.y][b.x - 1] == 1 || arr[c.y][c.x - 1] == 1)
					flag = false;
				if (arr[a.y][a.x + 1] == 1 || arr[b.y][b.x + 1] == 1 || arr[c.y][c.x + 1] == 1)
					flag = false;
			}
			wide ? aa = { b.y - 1, b.x } : aa = {b.y, b.x - 1 };
			bb = { b.y,b.x };
			wide ? cc = { b.y + 1,b.x } : cc = { b.y, b.x + 1 };
			if (flag && 1 <= aa.y  && aa.y <= N && 1 <= aa.x && aa.x <= N && 1 <= cc.y && cc.y <= N && 1 <= cc.x && cc.x <= N) {
				if (arr[aa.y][aa.x] != 1 && arr[bb.y][bb.x] != 1 && arr[cc.y][cc.x] != 1) {
					if (!visited[!wide][bb.y][bb.x]) {
						visited[!wide][bb.y][bb.x] = 1;
						q.push({ aa,bb,cc });
					}
				}
			}
		}
	}
	cout << 0;
	return;
}
int main() {
	[&]() {
		// B=2 E=3
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> tmp;
			for (int j = 1; j <= N; j++) {
				if (tmp[j - 1] == 'B')
					arr[i][j] = 0, B[b++] = { i,j };
				else if (tmp[j - 1] == 'E') {
					arr[i][j] = 3, E[e++] = { i,j };
				}
				else
					arr[i][j] = tmp[j - 1] - '0';
			}
		}
	}();
	bfs();
	return 0;
}