#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int a, b, n, m, x, y, direct, robot, repeat, dy[]{ 9,1,0,-1,0 }, dx[]{ 9,0,-1,0,1 };
char d, cmd;
pii arr[101][101];
bool flag = true;
map<int, pii> M;
void L(int num) {
	int y = M[num].first;
	int x = M[num].second;
	
	direct = arr[y][x].second;
	direct++;
	if (direct==5) direct = 1;

	arr[y][x] = { num,direct };
}
void R(int num) {
	int y = M[num].first;
	int x = M[num].second;

	int direct = arr[y][x].second;
	direct--;
	if (direct == 0) direct = 4;

	arr[y][x] = { num,direct };
}
void F(int num) {
	int y = M[num].first;
	int x = M[num].second;

	int direct = arr[y][x].second;
	int ddy = y + dy[direct];
	int ddx = x + dx[direct];

	if (ddx<1 || ddx>a || ddy<1 || ddy>b) {
		cout << "Robot " << num << " crashes into the wall";
		flag = false;
		return;
	}
	if (arr[ddy][ddx].first != 0) {
		cout << "Robot " << num << " crashes into robot " << arr[ddy][ddx].first;
		flag = false;
		return;
	}

	arr[ddy][ddx] = arr[y][x];
	arr[y][x] = { 0,0 };
	M[num] = { ddy,ddx };
}
int main() {
	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> d;
		if (d == 'N') direct = 1;
		if (d == 'W') direct = 2;
		if (d == 'S') direct = 3;
		if (d == 'E') direct = 4;
		arr[y][x] = { i,direct };
		M[i] = { y,x };
	}
	for (int i = 1; i <= m; i++) {
		cin >> robot >> cmd >> repeat;
		while (repeat--) {
			if (flag) {
				if (cmd == 'L') L(robot);
				if (cmd == 'R') R(robot);
				if (cmd == 'F') F(robot);
			}
		}
	}
	if (flag) cout << "OK";
	return 0;
}