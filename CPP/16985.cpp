#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;

int arr[5][5][5], mn = 1e9, tmp[5][5][5], visited[5][5][5];
int dz[]{ -1,0,0,0,0,1 }, dy[]{ 0,-1,0,0,1,0 }, dx[]{ 0,0,-1,1,0,0 };
vector<int> vect;

void rotate(int f1, int f2, int f3, int f4, int f5) {
	int num[5]{ f1,f2,f3,f4,f5 };
	for (int i = 0; i < 5; i++) {
		int n = num[i];
		if (n == 0) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++)
					tmp[i][j][k] = arr[i][j][k];
			}
		}
		else if (n == 1) {
			for (int j = 0, x=4; j < 5; j++, x--) {
				for (int k = 0, y = 0; k < 5; k++, y++)
					tmp[i][y][x] = arr[i][j][k];
			}
		}
		else if (n == 2) {
			for (int j = 0, y = 4; j < 5; j++, y--) {
				for (int k = 0, x = 4; k < 5; k++, x--)
					tmp[i][y][x] = arr[i][j][k];
			}
		}
		else {
			for (int j = 0, x = 0; j < 5; j++, x++) {
				for (int k = 0, y = 4; k < 5; k++, y--)
					tmp[i][y][x] = arr[i][j][k];
			}
		}
	}
	return;
}

void bfs(int yy, int xx, int dsty, int dstx) {
	memset(visited, 0, sizeof(visited));
	queue<tii> q;
	q.push({ 4,yy,xx });
	visited[vect[4]][yy][xx] = 1;
	int cnt = -1;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();
		while (sz--) {
			int z = get<0>(q.front());
			int y = get<1>(q.front());
			int x = get<2>(q.front());

			q.pop();

			for (int i = 0; i < 6; i++) {
				int ddz = z + dz[i];
				int ddy = y + dy[i];
				int ddx = x + dx[i];

				if (0 <= ddz && ddz <= 4 && 0 <= ddy && ddy <= 4 && 0 <= ddx && ddx <= 4){
					if (tmp[vect[ddz]][ddy][ddx] && !visited[vect[ddz]][ddy][ddx]) {
						visited[vect[ddz]][ddy][ddx] = 1;
						q.push({ ddz,ddy,ddx });
					}
					if (ddy == dsty && ddx == dstx && ddz == 0) {
						mn = min(mn, cnt+1);
						return;
					}
				}
			}
		}
	}
	return;
}

void solution(int f1, int f2, int f3, int f4, int f5) {
	rotate(f1, f2, f3, f4, f5);

	vect.clear();
	for (int i = 0; i < 5; i++)
		vect.push_back(i);

	[&]() {
		do {
			if (tmp[vect[4]][0][0] && tmp[vect[0]][4][4])
				bfs(0, 0, 4, 4);
			if (tmp[vect[4]][0][4] && tmp[vect[0]][4][0])
				bfs(0, 4, 4, 0);
			if (tmp[vect[4]][4][0] && tmp[vect[0]][0][4])
				bfs(4, 0, 0, 4);
			if (tmp[vect[4]][4][4] && tmp[vect[0]][0][0])
				bfs(4, 4, 0, 0);
		} while (next_permutation(vect.begin(), vect.end()));
	}();
	
	return;
}

void init() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> arr[i][j][k];
}

int main() {
	init();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int s = 0; s < 4; s++) {
					for (int t = 0; t < 4; t++) {
						solution(i, j, k, s, t);
						//cout << i << j << k << s << t << '\n';
					}
				}
			}
		}			
	}
	mn == 1e9 ? cout << -1 : cout << mn;
	return 0;
}