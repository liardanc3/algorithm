#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[51][51], d, s, cloud[51][51], ans = 0;
int dy[]{ 3,0,-1,-1,-1,0,1,1,1 }, dx[]{ 3,-1,-1,0,1,1,1,0,-1 };
vector<pii> vect;
map<pii, int> deleted;
void step1() {
	int tmp[51][51]{ 0, };
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int ddy = y, ddx = x;
			if (cloud[y][x]) {
				for (int i = 1; i <= s; i++) {
					ddy += dy[d];
					ddx += dx[d];
					if (ddy == 0) ddy = N;
					if (ddy == N + 1) ddy = 1;
					if (ddx == 0) ddx = N;
					if (ddx == N + 1) ddx = 1;
				}
				
				tmp[ddy][ddx] = 1;
			}
		}
	}
	copy(&tmp[0][0], &tmp[50][51], &cloud[0][0]);
}
void step2() {
	vect.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (cloud[i][j]) {
				arr[i][j]++;
				vect.push_back({ i,j });
			}
		}
	}
}
void step3() {
	deleted.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (cloud[i][j]) {
				cloud[i][j] = 0;
				deleted[{ i, j }] = 1;
			}
		}
	}
}
void step4() {
	int tmp[51][51]{ 0, };
	copy(&arr[0][0], &arr[50][51], &tmp[0][0]);
	for (pii point : vect) {
		int y = point.first;
		int x = point.second;

		int exist = 0;
		for (int i = 2; i <= 8; i += 2) {
			int ddy = y + dy[i];
			int ddx = x + dx[i];
			if (ddy > N || ddx > N || ddy < 1 || ddx < 1) continue;
			if (arr[ddy][ddx]) exist++;
		}
		tmp[y][x] += exist;
	}
	copy(&tmp[0][0], &tmp[50][51], &arr[0][0]);
}
void step5() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] >= 2 && !deleted[{i, j}]) {
				arr[i][j] -= 2;
				cloud[i][j] = 1;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		cin >> arr[i][j];
	cloud[N][1] = 1, cloud[N - 1][1] = 1, cloud[N - 1][2] = 1, cloud[N][2] = 1;
	for (int i = 1; i <= M; i++) {
		cin >> d >> s;
		step1();
		step2();
		step3();
		step4();
		step5();
	}
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		ans += arr[i][j];
	cout << ans;
	return 0;
}