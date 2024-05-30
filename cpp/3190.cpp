#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> pic;
typedef pair<int, int> pii;
int n, k, r, c, arr[101][101], L, X, cnt = 0, t = 0;
int dy[]{ -1,0,1,0 }, dx[]{ 0,1,0,-1 };
char C;
int sy, sx;
queue<pic> q;
queue<pii> tail;
void f(int y, int x, int d) {
	if (!q.empty()) {
		pic now = q.front();
		if (now.first == t) {
			if (now.second == 'L')
				d--;
			if (now.second == 'D')
				d++;
			if (d == -1) d = 3;
			if (d == 4) d = 0;
			q.pop();
		}
	}
	int ddy = y + dy[d];
	int ddx = x + dx[d];
	if (!(1 <= ddy && ddy <= n && 1 <= ddx && ddx <= n && !(arr[ddy][ddx]==2)))
		return;
	
	if (arr[ddy][ddx] == 1) {		
		arr[ddy][ddx] = 2;
		tail.push({ ddy,ddx });
		k--;
	}
	else if (arr[ddy][ddx] == 0) {
		arr[ddy][ddx] = 2;
		tail.push({ ddy,ddx });
		arr[sy][sx] = 0;
		sy = tail.front().first;
		sx = tail.front().second;
		tail.pop();
	}

	t++;
	f(ddy, ddx, d);
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		arr[r][c] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		q.push({ X,C });
	}
	arr[1][1] = 2;
	sy = 1, sx = 1;
	f(1, 1, 1);
	cout << t+1;
	return 0;
}