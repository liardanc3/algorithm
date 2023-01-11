#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int ans, visited[25], tmp[7], ck[5][5], erase;
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 };
string s;
char arr[5][5];

void dfs(int y, int x) {
	ck[y][x] = 0;
	erase--;
	for (int i = 0; i < 4; i++) {
		int ddy = y + dy[i];
		int ddx = x + dx[i];
		if (0 <= ddy && ddy < 5 && 0 <= ddx && ddx < 5 && ck[ddy][ddx])
			dfs(ddy, ddx);
	}
	return;
}
void bt(int start, int cnt, int S) {
	if (cnt - S > 3) 
		return;
	if (cnt == 7 && S>=4) {
		memset(ck, 0, sizeof(ck));
		for (int i = 0; i < cnt; i++) {
			int y = tmp[i] / 5;
			int x = tmp[i] % 5;
			ck[y][x] = 1;
		}
		erase = 7;
		dfs(tmp[0] / 5, tmp[0] % 5);
		if (!erase) 
			ans++;
		/*cout << ans << " : ";
		for (int i = 0; i < 7; i++) 
			cout << tmp[i] << ' ';*/
		return;
	}
	
	for (int i = start; i < 25; i++) {
		int next = i;
		if (!visited[next]) {
			tmp[cnt] = next;
			if (arr[next / 5][next % 5] == 'S')
				bt(next + 1, cnt + 1, S + 1);
			else
				bt(next + 1, cnt + 1, S);
		}
	}
	return;
}

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> s;
		for (int j = 0; j < 5; j++)
			arr[i][j] = s[j];
	}
	bt(0, 0, 0);
	cout << ans;
	return 0;
}