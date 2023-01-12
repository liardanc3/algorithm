#include <bits/stdc++.h>
using namespace std;

int N, M, arr[11][11], mn = 1e9;
string str;

// #0 .1 R2 B3 O4
void dfs(int cnt, int bef) {
	if (cnt+1 >= mn || cnt>=10)
		return;
	int tmp[11][11], flag = 1;
	copy(&arr[0][0], &arr[10][11], &tmp[0][0]);

	// U
	if (bef != 1) {
		[&]() {
		for (int x = 2; x <= M - 1 && flag; x++) {
				stack<int> st;
				for (int y = N - 1; y >= 1 && flag; y--) {
					if (arr[y][x] == 1)
						continue;
					if (arr[y][x] == 2 || arr[y][x] == 3) {
						st.push(arr[y][x]);
						arr[y][x] = 1;
					}
					else if (arr[y][x] == 0) {
						for (int yy = y + 1; !st.empty(); yy++) {
							arr[yy][x] = st.top();
							st.pop();
						}
					}
					else {
						int red = 0, blue = 0;
						while (!st.empty()) {
							int now = st.top(); st.pop();
							if (now == 2) red++;
							if (now == 3) blue++;
						}
						if (blue)
							flag = 0;
						else if (red) { mn = min(mn, cnt + 1); return; }
					}
				}
			}
		}();
		if (flag)
			dfs(cnt + 1, 1);
		copy(&tmp[0][0], &tmp[10][11], &arr[0][0]);
	}

	// L
	if (bef != 2) {
		[&]() {
			flag = 1;
			for (int y = 2; y <= N - 1 && flag; y++) {
				stack<int> st;
				for (int x = M - 1; x >= 1 && flag; x--) {
					if (arr[y][x] == 1)
						continue;
					if (arr[y][x] == 2 || arr[y][x] == 3) {
						st.push(arr[y][x]);
						arr[y][x] = 1;
					}
					else if (arr[y][x] == 0) {
						for (int xx = x + 1; !st.empty(); xx++) {
							arr[y][xx] = st.top();
							st.pop();
						}
					}
					else {
						int red = 0, blue = 0;
						while (!st.empty()) {
							int now = st.top(); st.pop();
							if (now == 2) red++;
							if (now == 3) blue++;
						}
						if (blue) { flag = 0; }
						else if (red) { mn = min(mn, cnt + 1); return; }
					}
				}
			}
		}();
		if (flag)
			dfs(cnt + 1, 2);
		copy(&tmp[0][0], &tmp[10][11], &arr[0][0]);
	}
	
	// D
	if (bef != 3) {
		[&]() {
			flag = 1;
			for (int x = 2; x <= M - 1 && flag; x++) {
				stack<int> st;
				for (int y = 2; y <= N && flag; y++) {
					if (arr[y][x] == 1)
						continue;
					if (arr[y][x] == 2 || arr[y][x] == 3) {
						st.push(arr[y][x]);
						arr[y][x] = 1;
					}
					else if (arr[y][x] == 0) {
						for (int yy = y - 1; !st.empty(); yy--) {
							arr[yy][x] = st.top();
							st.pop();
						}
					}
					else {
						int red = 0, blue = 0;
						while (!st.empty()) {
							int now = st.top(); st.pop();
							if (now == 2) red++;
							if (now == 3) blue++;
						}
						if (blue) { flag = 0; }
						else if (red) { mn = min(mn, cnt + 1); return; }
					}
				}
			}
		}();
		if (flag)
			dfs(cnt + 1, 3);
		copy(&tmp[0][0], &tmp[10][11], &arr[0][0]);
	}
		
	// R
	if (bef != 4) {
		[&]() {
			flag = 1;
			for (int y = 2; y <= N - 1 && flag; y++) {
				stack<int> st;
				for (int x = 2; x <= M && flag; x++) {
					if (arr[y][x] == 1)
						continue;
					if (arr[y][x] == 2 || arr[y][x] == 3) {
						st.push(arr[y][x]);
						arr[y][x] = 1;
					}
					else if (arr[y][x] == 0) {
						for (int xx = x - 1; !st.empty(); xx--) {
							arr[y][xx] = st.top();
							st.pop();
						}
					}
					else {
						int red = 0, blue = 0;
						while (!st.empty()) {
							int now = st.top(); st.pop();
							if (now == 2) red++;
							if (now == 3) blue++;
						}
						if (blue) { flag = 0; }
						else if (red) { mn = min(mn, cnt + 1); return; }
					}
				}
			}
		}();
		if (flag)
			dfs(cnt + 1, 4);
		copy(&tmp[0][0], &tmp[10][11], &arr[0][0]);
	}
	return;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> str;
			for (int j = 1; j <= M; j++) {
				if (str[j - 1] == '#') arr[i][j] = 0;
				if (str[j - 1] == '.') arr[i][j] = 1;
				if (str[j - 1] == 'R') arr[i][j] = 2;
				if (str[j - 1] == 'B') arr[i][j] = 3;
				if (str[j - 1] == 'O') arr[i][j] = 4;
			}
		}
	}();
	dfs(0, -1);
	mn == 1e9 ? cout << -1 : cout << mn;
	return 0;
}