#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

typedef pair<int, int> pii;

string tmp;
int arr[10][10], arr2[10][10];
int dy[]{ -1,0,0,1 }, dx[]{ 0,-1,1,0 }, mn = 1e9;
bool haslight() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr2[i][j])
				return true;
		}
	}
	return false;
}

void bitflip(int y, int x) {
	arr2[y][x] = !arr2[y][x];
	for (int i = 0; i < 4; i++) {
		int ddy = y + dy[i];
		int ddx = x + dx[i];

		if (0 <= ddy && ddy < 10 && 0 <= ddx && ddx < 10)
			arr2[ddy][ddx] = !arr2[ddy][ddx];
	}
	return;
}
void go(int bit) {
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		if (bit & 1 << i)
			bitflip(0, i), cnt++;
	}
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr2[i][j])
				bitflip(i + 1, j), cnt++;
		}
	}

	if (!haslight())
		mn = min(mn, cnt);
}
int main() {
	[&]() {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		for (int i = 0; i < 10; i++) {
			cin >> tmp;
			for (int j = 0; j < 10; j++) {
				if (tmp[j] == 'O')
					arr[i][j] = 1;
			}
		}
	}();

	for (int i = 0; i < 1 << 10; i++) {
		copy(&arr[0][0],&arr[9][10],&arr2[0][0]);
		go(i);
	}
		
	mn == 1e9 ? cout << -1 : cout << mn;
	return 0;
}