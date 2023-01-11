#include <bits/stdc++.h>
using namespace std;

int dice[11], horse[5], mx;
int run(int now, int go) {
	if (0 <= now && now <= 40 && now != 10 && now != 20 && now != 30)
		return min(41, now + go * 2);

	if (now == 10) {
		if (go <= 3)
			return (now + go * 3) * 10;
		else if (go == 4)
			return 250;
		else
			return 300;
	}

	if (now == 20) {
		if (go <= 2)
			return (now + go * 2) * 10;
		else if (go == 3)
			return 250;
		else if (go == 4)
			return 300;
		else
			return 350;
	}

	if (now == 30) {
		if (go <= 4)
			return (now - (go + 1)) * 10;
		else
			return 300;
	}

	if (now == 130) {
		if (go == 1) return 160;
		if (go == 2) return 190;
		if (go == 3) return 250;
		if (go == 4) return 300;
		if (go == 5) return 350;
	}

	if (now == 160) {
		if (go == 1) return 190;
		if (go == 2) return 250;
		if (go == 3) return 300;
		if (go == 4) return 350;
		if (go == 5) return 40;
	}

	if (now == 190) {
		if (go == 1) return 250;
		if (go == 2) return 300;
		if (go == 3) return 350;
		if (go == 4) return 40;
		if (go == 5) return 41;
	}

	if (now == 250) {
		if (go == 1) return 300;
		if (go == 2) return 350;
		if (go == 3) return 40;
		return 41;
	}

	if (now == 300) {
		if (go == 1) return 350;
		if (go == 2) return 40;
		return 41;
	}

	if (now == 350) {
		if (go == 1) return 40;
		return 41;
	}

	if (now == 40)
		return 41;

	if (now == 220) {
		if (go == 1)
			return 240;
		else
			return run(160, go);
	}

	if (now == 240)
		return run(190, go);

	if (now == 280) {
		if (go == 1)return 270;
		if (go == 2) return 260;
		return run(130, go);
	}

	if (now == 270) {
		if (go == 1) return 260;
		return run(160, go);
	}

	if (now == 260)
		return run(190, go);
}
void dfs(int turn, int point) {
	mx = max(mx, point);
	if (turn == 11)
		return;

	// pick1
	if (horse[1] != 41) {
		int now = horse[1];
		int go = dice[turn];

		int finish = run(now, go);
		int dst = 1;
		if (finish == 41) 
			dst = 0;
		if ((horse[2] != finish || horse[2] == 41) && (horse[3] != finish || horse[3] == 41) && (horse[4] != finish || horse[4] == 41)) {
			horse[1] = finish;
			dfs(turn + 1, point + dst * (finish < 41 ? finish : finish / 10));
			horse[1] = now;
		}
	}

	// pick2
	if (horse[2] != 41) {
		int now = horse[2];
		int go = dice[turn];

		int finish = run(now, go);
		int dst = 1;
		if (finish == 41)
			dst = 0;
		if ((horse[1] != finish || horse[1] == 41) && (horse[3] != finish || horse[3] == 41) && (horse[4] != finish || horse[4] == 41)) {
			horse[2] = finish;
			dfs(turn + 1, point + dst * (finish < 41 ? finish : finish / 10));
			horse[2] = now;
		}
	}

	// pick3
	if (horse[3] != 41) {
		int now = horse[3];
		int go = dice[turn];

		int finish = run(now, go);
		int dst = 1;
		if (finish == 41)
			dst = 0;
		if ((horse[1] != finish || horse[1] == 41) && (horse[2] != finish || horse[2] == 41) && (horse[4] != finish || horse[4] == 41)) {
			horse[3] = finish;
			dfs(turn + 1, point + dst * (finish < 41 ? finish : finish / 10));
			horse[3] = now;
		}
	}

	// pick4
	if (horse[4] != 41) {
		int now = horse[4];
		int go = dice[turn];

		int finish = run(now, go);
		int dst = 1;
		if (finish == 41)
			dst = 0;
		if ((horse[1] != finish || horse[1] == 41) && (horse[2] != finish || horse[2] == 41) && (horse[3] != finish || horse[3] == 41)) {
			horse[4] = finish;
			dfs(turn + 1, point + dst * (finish < 41 ? finish : finish / 10));
			horse[4] = now;
		}
	}

	return;
}
int main() {
	for (int i = 1; i <= 10; i++)
		cin >> dice[i];
	dfs(1, 0);
	cout << mx;
	return 0;
}