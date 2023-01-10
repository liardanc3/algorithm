#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tii;
typedef pair<int, int> pii;
int N, M, D, arr[16][16], enemy, a, b, c, mx, _enemy, tmp[16][16], flag, archer;
vector<pii> vect;
void bow(int who) {
	if (arr[N][who]) {
		vect.push_back({ N,who });
		return;
	}
	flag = 1;
	priority_queue<tii, vector<tii>, greater<tii>> pq;
	pq.push({ 1 ,who, N });
	while (!pq.empty() && flag) {
		tii now = pq.top();
		pq.pop();

		int dist = get<0>(now);
		if (dist > D) continue;
		int y = get<2>(now);
		if (y < 1) continue;
		int dxL = get<1>(now) - 1;
		int dxR = get<1>(now) + 1;

		tii straightshot = { dist+1,dxL+1 ,y -1};
		tii leftshot = { dist + 1,dxL,y };
		tii rightshot = { dist + 1,dxR,y };

		if (dist+1 <= D && 1<=dxL && arr[y][dxL]) {
			vect.push_back({ y,dxL });
			flag = 0;
		}
		else if (dist + 1 <= D && y-1 >= 1 && arr[y-1][dxL+1]) {
			vect.push_back({ y-1,dxL+1 });
			flag = 0;
		}
		else if (dist + 1 <= D && dxR <= M && arr[y][dxR]) {
			vect.push_back({ y,dxR });
			flag = 0;
		}

		if (flag) {
			if (dist + 1 <= D && dxL >= 1)
				pq.push(leftshot);
			if (dist+1 <= D && 1 <= y-1)
				pq.push(straightshot);
			if (dist + 1 <= D && dxR <= M)
				pq.push(rightshot);
		}
	}
}
void shot() {
	vect.clear();

	bow(a);
	bow(b);
	bow(c);

	for (pii p : vect) {
		if (arr[p.first][p.second]) {
			_enemy--;
			archer++;
			arr[p.first][p.second] = 0;
		}
	}

	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j]) {
				arr[i][j] = 0;
				if (i == N) {
					_enemy--;
					continue;
				}
				arr[i + 1][j] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp[i][j];
			if (tmp[i][j]) {
				enemy++;
			}
		}
	}
	for (int i = 1; i <= M - 2; i++) {
		for (int j = i + 1; j <= M - 1; j++) {
			for (int k = j + 1; k <= M; k++) {
				a = i, b = j, c = k;
				_enemy = enemy;
				archer = 0;
				copy(&tmp[0][0], &tmp[15][16], &arr[0][0]);
				while (_enemy) {
					shot();
				}
				mx = max(mx, archer);
			}
		}
	}
	cout << mx;
	return 0;
}