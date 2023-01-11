#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tii;
vector<tii> shark;
int R, C, M, r, c, s, d, z, fishmanX = 0, ans = 0;
int water[101][101]{ 0, };
void fishman() {
	fishmanX++;
	for (int i = 1; i <= R; i++) {
		int fish = water[i][fishmanX];
		if (fish != 0) {
			ans += get<2>(shark[fish]);
			water[i][fishmanX] = 0;
			return;
		}
	}
}
void fishmove() {
	int tmp[101][101]{ 0, };
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int fish = water[i][j];
			if (fish != 0) {
				tii sk = shark[fish];
				int velocity = get<0>(sk);
				int direct = get<1>(sk);
				int size = get<2>(sk);

				int rr = i;
				int cc = j;
				if (direct == 1) {
					rr = rr + velocity + 2*(R-rr);
					rr %= (2 * R - 2);
					if (rr == 0) {
						rr = 2;
					}
					else if (rr < R) {
						shark[fish] = { velocity, 2, size };
					}
					else {
						rr = R - (rr - R);
					}
				}
				else if (direct == 2) {
					rr += velocity;
					rr %= (2 * R - 2);
					if (rr == 0) {
						rr = 2;
						shark[fish] = { velocity, 1, size };
					}
					else if (rr >= R) {
						rr = R - (rr - R);
						shark[fish] = { velocity, 1, size };
					}
				}
				else if (direct == 3) {
					cc += velocity;
					cc %= (2 * C - 2);
					if (cc == 0) {
						cc = 2;
						shark[fish] = { velocity, 4, size };
					}
					else if (cc >= C) {
						cc = C - (cc - C);
						shark[fish] = { velocity, 4, size };
					}
				}
				else {
					cc = cc + velocity + 2*(C-cc);
					cc %= (2 * C - 2);
					if (cc == 0) {
						cc = 2;
					}
					else if (cc < C) {
						shark[fish] = { velocity, 3, size };
					}
					else {
						cc = C - (cc - C);
					}
				}

				if (tmp[rr][cc] == 0 || get<2>(shark[tmp[rr][cc]]) < size)
					tmp[rr][cc] = fish;
			}
		}
	}
	copy(&tmp[0][0], &tmp[100][101], &water[0][0]);
}
int main() {
	shark.push_back({ 0,0,0 });
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		cin >> r >> c >> s >> d >> z;
		water[r][c] = i;
		shark.push_back({ s,d,z });
	}
	while (fishmanX < C) {
		fishman();
		fishmove();
	}
	cout << ans;
	return 0;
}