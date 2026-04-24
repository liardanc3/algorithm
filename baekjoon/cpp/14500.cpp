#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;
int arr[501][501] = { 0, };
int tet[501][501] = { 0, };
int dx[] = { 3,0,1,-1,1,1,1,2,2,2,2,1,-1,2,2,2,2,1,-1 };
int dy[] = { 0,3,1,2,2,2,2,1,1,-1,-1,2,2,1,-1,1,-1,2,2 };
ti tx[] = { ti(1,2,3),ti(0,0,0),ti(1,0,1),ti(0,0,-1),ti(0,0,1),ti(1,1,1),ti(1,0,0),
			ti(1,2,0),ti(1,2,2),ti(1,2,2),ti(0,1,2),
			ti(0,1,1),ti(-1,0,-1),ti(1,1,2),ti(1,1,2),ti(1,2,1),ti(1,1,2),ti(0,1,0),ti(-1,0,0) };
ti ty[] = { ti(0,0,0),ti(1,2,3),ti(0,1,1),ti(1,2,2),ti(1,2,2),ti(0,1,2),ti(0,1,2),
			ti(0,0,1),ti(0,0,1),ti(0,0,-1),ti(-1,0,0),
			ti(1,1,2),ti(1,1,2),ti(0,1,1),ti(0,-1,-1),ti(0,0,1),ti(-1,0,0),ti(1,1,2),ti(1,1,2) };
void brute(int N, int M) {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			for (int i = 0; i < 19; i++) {
				int X = x + dx[i]; int Y = y + dy[i];
				if (X >= 0 && X <= M && Y >= 0 && Y <= N) {
					tet[y][x] = max(tet[y][x], arr[y][x] + arr[y + get<0>(ty[i])][x + get<0>(tx[i])] +
						arr[y + get<1>(ty[i])][x + get<1>(tx[i])] + arr[y + get<2>(ty[i])][x + get<2>(tx[i])]);
				}
			}
		}
	}
}
int main() {
	int N, M, tmp; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp;
			arr[i][j] = tmp;
		}
	} brute(N, M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (tmp < tet[i][j])
				tmp = tet[i][j];
		}
	} cout << tmp;
	return 0;
}