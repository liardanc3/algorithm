#include <bits/stdc++.h>
using namespace std;
int ans = 0, n, m, arr[102][102]{ 0, };
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for(int j=1; j<=m; j++) {
		cin >> arr[i][j];
	}
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];
				if (arr[y][x] > arr[ddy][ddx]) 
					ans += arr[y][x] - arr[ddy][ddx];
			}
		}
	}
	cout << ans + 2 * m * n;
	return 0;
}