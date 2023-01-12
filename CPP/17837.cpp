#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tii;

tii horse[11];
// 0Èò 1»¡ 2ÆÄ
stack<int> st[13][13];
int N, K, board[13][13], yy, xx, d, t;
int dy[]{ 0,0,0,-1,1 }, dx[]{ 0,1,-1,0,0 };
void move(int k, int depth) {
	int y = get<0>(horse[k]);
	int x = get<1>(horse[k]);
	int d = get<2>(horse[k]);

	int ddy = y + dy[d];
	int ddx = x + dx[d];
	
	if (ddy<1 || ddy>N || ddx < 1 || ddx>N || board[ddy][ddx]==2) {
		if (depth == 2)
			return;
		horse[k] = { y,x,d % 2 ? d + 1 : d - 1 };
		move(k, depth + 1);
	}
	else if (board[ddy][ddx] == 1) {
		bool flag = false;
		vector<int> tmp;
		while (!flag) {
			int top = st[y][x].top();
			st[y][x].pop();
			flag = top == k;
			horse[top] = { ddy,ddx,get<2>(horse[top]) };
			tmp.push_back(top);
		}
		for(int i=0; i<tmp.size(); i++) 
			st[ddy][ddx].push(tmp[i]);
		if ((int)st[ddy][ddx].size() >= 4) {
			cout << t;
			exit(0);
		}
	}
	else {
		bool flag = false;
		vector<int> tmp;
		while (!flag) {
			int top = st[y][x].top();
			st[y][x].pop();
			flag = top == k;
			horse[top] = { ddy,ddx,get<2>(horse[top]) };
			tmp.push_back(top);
		}
		for (int i = tmp.size()-1; i >= 0; i--) 
			st[ddy][ddx].push(tmp[i]);
		if ((int)st[ddy][ddx].size() >= 4) {
			cout << t;
			exit(0);
		}
	}
	return;
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				cin >> board[i][j];
		}
		for (int i = 1; i <= K; i++) {
			cin >> yy >> xx >> d;
			horse[i] = { yy,xx,d };
			st[yy][xx].push(i);
		}
	}();
	for (t = 1; t <= 1000; t++) {
		[&]() {
			for (int i = 1; i <= K; i++)
				move(i, 1);
		}();
	}
	cout << -1;
	return 0;
}