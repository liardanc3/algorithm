#include <bits/stdc++.h>
using namespace std;
int arr[9][9];
bool width(int y, int x, int now) {
	for (int i = 0; i < 9; i++) {
		if (arr[y][i] == now)
			return false;
	}
	return true;
}
bool length(int y, int x, int now) {
	for (int i = 0; i < 9; i++) {
		if (arr[i][x] == now)
			return false;
	}
	return true;
}
bool quad(int y, int x, int now) {
	for (int i = 3 * (y / 3); i < 3 * (y / 3) + 3; i++) {
		for (int j = 3 * (x / 3); j < 3 * (x / 3) + 3; j++) {
			if (arr[i][j] == now)
				return false;
		}
	}
	return true;
}
void dfs(int y, int x) {
	if (x == 9) {
		x = 0;
		y++;
	}
	if (y == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}
	if (arr[y][x] > 0) 
		dfs(y, x + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (width(y, x, i) && length(y, x, i) && quad(y, x, i)) {
				arr[y][x] = i;
				dfs(y, x + 1);
				arr[y][x] = 0;
			}
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++)
		cin >> arr[i][j];
	dfs(0, 0);
	return 0;
}