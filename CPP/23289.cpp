#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int,int,int> tii;
typedef pair<int, int> pii;
int R, C, K, W, x, y, t, tmp, res[21][21]{ 0, }, dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
tii arr[21][21];
vector<pii> ck,heat;
bool test() {
	for (int i = 0; i < ck.size(); i++) {
		int r = ck[i].first;
		int c = ck[i].second;
		if (res[r][c] < K)
			return false;
	}
	return true;
}
void boundary() {
	for (int i = 1; i <= R; i++) {
		if(res[i][1] > 0) res[i][1]--;
		if(res[i][C] > 0) res[i][C]--;
	}
	for (int i = 2; i <= C - 1; i++) {
		if(res[1][i] > 0) res[1][i]--;
		if(res[R][i] > 0) res[R][i]--;
	}
}
void spread() {
	int res_tmp[21][21]{ 0, };
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			tii now = arr[y][x];
			if (res[y][x] < 4) continue;
			for (int i = 0; i < 4; i++) {
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (i == 0 && get<0>(now) != 1) continue;
				if (i == 1 && get<1>(now) != 1) continue;
				if (i == 2 && get<2>(now) != 1) continue;
				if (i == 3 && get<3>(now) != 1) continue;
				if (1 <= ddy && ddy <= R && 1 <= ddx && ddx <= C && res[y][x] >= res[ddy][ddx] + 4) {
					int gap = (res[y][x] - res[ddy][ddx]) / 4;
					res_tmp[ddy][ddx] += gap;
					res_tmp[y][x] -= gap;
				} // 오른쪽 spread 이상
			}
		}
	}
	for (int y = 1; y <= R; y++) for (int x = 1; x <= C; x++) {
		res[y][x] += res_tmp[y][x];
	}
}
void heater() {
	for (int i = 0; i < heat.size(); i++) {
		int visited[21][21]{ 0, };
		int y = heat[i].first;
		int x = heat[i].second;

		//1오 2왼 3위 4아래
		tii _heat = arr[y][x];
		int direct = get<4>(_heat);
		int air = 5;
		queue<pii> q;
		if (direct == 1) q.push({ y, x + 1 });
		else if (direct == 2) q.push({ y,x - 1 });
		else if (direct == 3) q.push({ y - 1,x });
		else q.push({ y + 1,x });
		while (!q.empty()) {
			int size = q.size();
			for (int j = 0; j < size; j++) {
				int r = q.front().first;
				int c = q.front().second;
				res[r][c] += air;
				q.pop();
				if (air == 1) continue;
				if (direct == 1 && c + 1 <= C) {
					if (get<1>(arr[r][c + 1]) == 1 && visited[r][c+1] == 0) {
						visited[r][c + 1]++;
						q.push({ r,c + 1 });
					}
					if (r-1>=1 && get<1>(arr[r - 1][c + 1]) == 1 && get<0>(arr[r][c]) == 1 && visited[r - 1][c + 1] == 0) {
						visited[r - 1][c + 1]++;
						q.push({ r - 1,c + 1 });
					}
					if (r + 1 <= R && get<1>(arr[r + 1][c + 1]) == 1 && get<3>(arr[r][c]) == 1 && visited[r + 1][c + 1] == 0) {
						visited[r + 1][c + 1]++;
						q.push({ r + 1,c + 1 });
					}
				}
				else if (direct == 2 && c - 1 >= 1) {
					if (get<2>(arr[r][c - 1]) == 1 && visited[r][c - 1] == 0) {
						visited[r][c - 1]++;
						q.push({ r,c - 1 });
					}
					if (r - 1 >= 1 && get<2>(arr[r - 1][c - 1]) == 1 && get<0>(arr[r][c]) == 1 && visited[r - 1][c - 1] == 0) {
						visited[r - 1][c - 1]++;
						q.push({ r - 1,c - 1 });
					}
					if (r + 1 <= R && get<2>(arr[r + 1][c - 1]) == 1 && get<3>(arr[r][c]) == 1 && visited[r + 1][c - 1] == 0) {
						visited[r + 1][c - 1]++;
						q.push({ r + 1,c - 1 });
					}
				}
				else if (direct == 3 && r - 1 >= 1) {
					if (get<3>(arr[r - 1][c]) == 1 && visited[r - 1][c] == 0) {
						visited[r - 1][c]++;
						q.push({ r - 1,c });
					}
					if (c - 1 >= 1 && get<3>(arr[r - 1][c - 1]) == 1 && get<1>(arr[r][c]) == 1 && visited[r - 1][c - 1] == 0) {
						visited[r - 1][c - 1]++;
						q.push({ r - 1,c - 1 });
					}
					if (c + 1 <= C && get<3>(arr[r - 1][c + 1]) == 1 && get<2>(arr[r][c]) == 1 &&  visited[r - 1][c + 1] == 0) {
						visited[r - 1][c + 1]++;
						q.push({ r - 1,c + 1 });
					}
				}
				else if (direct == 4 && r + 1 <= R) {
					if (get<0>(arr[r + 1][c]) == 1 && visited[r + 1][c] == 0) {
						visited[r + 1][c]++;
						q.push({ r + 1,c });
					}
					if (c - 1 >= 1 && get<0>(arr[r + 1][c - 1]) == 1 && get<1>(arr[r][c]) == 1 && visited[r + 1][c - 1] == 0) {
						visited[r + 1][c - 1]++;
						q.push({ r + 1,c - 1 });
					}
					if (c + 1 <= C && get<0>(arr[r + 1][c + 1]) == 1 && get<2>(arr[r][c])==1&& visited[r + 1][c + 1] == 0) {
						visited[r + 1][c + 1]++;
						q.push({ r + 1,c + 1 });
					}
				}
			}
			air--;
		}
	}
}
void init() {
	cin >> R >> C >> K;
	for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) {
		cin >> tmp;
		arr[i][j] = { 1,1,1,1,tmp };
		if (tmp == 5) ck.push_back({ i,j });
		if (tmp < 5 && tmp != 0) heat.push_back({ i,j });
	}
	cin >> W;
	// 벽 처음부터 다시
	while (W--) {
		cin >> x >> y >> t;
		if (t) {
			arr[x][y] = { get<0>(arr[x][y]),get<1>(arr[x][y]),0,get<3>(arr[x][y]),get<4>(arr[x][y]) };
			if (y + 1 <= C)
				arr[x][y + 1] = { get<0>(arr[x][y + 1]),0,get<2>(arr[x][y + 1]),get<3>(arr[x][y + 1]),get<4>(arr[x][y + 1]) };
		}
		else {
			arr[x][y] = { 0,get<1>(arr[x][y]),get<2>(arr[x][y]),get<3>(arr[x][y]),get<4>(arr[x][y]) };
			if (x - 1 >= 1)
				arr[x - 1][y] = { get<0>(arr[x - 1][y]),get<1>(arr[x - 1][y]),get<2>(arr[x - 1][y]),0,get<4>(arr[x - 1][y]) };
		}
	}
}
int main() {
	init();
	bool success = false;
	int chocolate = 0;
	while (!success) {
		heater();
		spread();
		boundary();
		chocolate++;
		success = test();
		if (chocolate == 101)
			success = true;
	}
	cout << chocolate;
	return 0;
}